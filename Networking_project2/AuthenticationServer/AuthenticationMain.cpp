#include <winsock2.h>
#include <Windows.h>

#include <ws2tcpip.h>
#include <iphlpapi.h>

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <conio.h>
#include<openssl/sha.h>
#pragma comment(lib, "Ws2_32.lib")
#include<cppconn/driver.h>
#include<cppconn/exception.h>
#include<cppconn/prepared_statement.h>
#include<cppconn/connection.h>
#include <cppconn/resultset.h>

#include<string>
#include<iostream>
#include"protocol.pb.h"


using namespace gProtocol2;


using namespace sql;

using namespace std;


class Connection1
{
public:

	SOCKET socket;
	int bytesReceived;
	int length;

	Connection1()
	{
		socket = INVALID_SOCKET;
		bytesReceived = 0;
		length = 0;
	}
	Connection1(SOCKET s)
	{
		socket = s;
		bytesReceived = 0;
		length = 0;
	}

};


Driver* driver;
Connection* con;
Statement* stmt;
PreparedStatement* pstmt;
ResultSet* rs;

string buffer;
string server = "127.0.0.1:3306";
string username = "root";
string password = "root";
string schema = "project2";

SOCKET listenSocket = INVALID_SOCKET;
SOCKET acceptSocket = INVALID_SOCKET;
WSAData wsaData;
SOCKADDR_IN	addr;

int iResult;
int result;
int port = 9898;
FD_SET readSet;

void ParseMessage(string buf);
bool CreateAccount(GoogleBuffer* msg);
bool Authenticate(GoogleBuffer* msg);
void CreateTable();
void main()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("Failed to load WinSock library! Error %d\n", WSAGetLastError());
	}
	listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);

	result = bind(listenSocket, (PSOCKADDR)&addr, sizeof(addr));
	result = listen(listenSocket, 5);
	unsigned long nBlock = 1;
	result = ioctlsocket(listenSocket, FIONBIO, &nBlock);

	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		cout << "Successfully connected to database !!" << endl;

		con->setSchema(schema);
		cout << "Successfully set our schema !!" << endl;
	}
	catch (SQLException & execption)
	{
		cout << " # ERR: SQLException in " << __FILE__ << endl;
		cout << "(" << __FUNCTION__ << ") on Line " << __LINE__ << endl;
		cout << "# ERR :" << execption.what() << endl;
		cout << "(MySQL erro code:  " << execption.getErrorCode() << endl;
		cout << " SQLState = " << execption.getSQLState() << endl;
		return;
	}

	while (true)
	{
		if (_kbhit())
		{
			int ch = _getch();
			if (ch == 27) break;
		}

		FD_ZERO(&readSet);
		FD_SET(listenSocket, &readSet);

		int Total = select(0, &readSet, NULL, NULL, NULL);

		if (Total == SOCKET_ERROR)
		{
			return;
		}
		acceptSocket = accept(listenSocket, NULL, NULL);
		unsigned long nBlock = 1;

		int result = ioctlsocket(acceptSocket, FIONBIO, &nBlock);

		result = recv(acceptSocket, &buffer[0] , 512, 0);

		if (result == SOCKET_ERROR)
		{
			int WSAErrorCode = WSAGetLastError();

			if (WSAErrorCode != WSAEWOULDBLOCK)
			{
				continue;
			}
			if (WSAErrorCode == WSAEHOSTUNREACH)
			{
				printf("Disconnected from client...\n");
			}
			return;
		}

		ParseMessage(buffer);
	
	}

}

void ParseMessage(string buf)
{
	GoogleBuffer msg;


	msg.ParseFromString(buf);

	GoogleBuffer_msgType typ;


	typ = msg.type();

	if (typ == GoogleBuffer::CREATE)
	{
		if (!CreateAccount(&msg))
		{
			
			msg.set_r(GoogleBuffer::INTERNAL_SERVER_ERROR);
			buf = msg.SerializeAsString();
			result = send(acceptSocket, &buf[0], 512, 0);
			return;
		}
		msg.set_type(GoogleBuffer::SIGNUP_SUCCESS);
		buf = msg.SerializeAsString();
		result = send(acceptSocket, &buf[0], 512, 0);
	}
	else if (typ == GoogleBuffer::AUTHENTICATE)
	{
		if (!Authenticate(&msg))
		{
			msg.set_r(GoogleBuffer::INVALID_CREDENTIALS);
			buf = msg.SerializeAsString();
			result = send(acceptSocket, &buf[0], 512, 0);
			return;
		}
		msg.set_type(GoogleBuffer::LOGIN_SUCCESS);
		buf = msg.SerializeAsString();
		result = send(acceptSocket, &buf[0], 512, 0);
	}
	
}
bool Authenticate(GoogleBuffer* msg)
{
	string hashed_pass = msg->plaintextpassword();
	string email = msg->email();

	stringstream ss;
	ss << "SELECT * From web_auth where email="<<email<<";";

	try
	{
		//Prepare
		pstmt = con->prepareStatement(ss.str());

		//execute
		rs = pstmt->executeQuery();

		string tempPass = rs->getString(3);
		if (tempPass == hashed_pass)
		{
			return true;
		}

		return false;

	}
	catch (SQLException & execption)
	{
		cout << " # ERR: SQLException in " << __FILE__ << endl;
		cout << "(" << __FUNCTION__ << ") on Line " << __LINE__ << endl;
		cout << "# ERR :" << execption.what() << endl;
		cout << "(MySQL erro code:  " << execption.getErrorCode() << endl;
		cout << " SQLState = " << execption.getSQLState() << endl;
		return false;
	}
}
bool CreateAccount(GoogleBuffer* msg)
{
	string hashed_pass;

	hashed_pass = msg->plaintextpassword();
	string email = msg->email();
	string salt = "For later";
	
	stringstream ss;
	ss << "INSERT INTO `project2`.`web_auth` (`email`, `salt`, `hashed_password`) VALUES ('" << email << "','" << salt << "','" << hashed_pass << "');";
	
	try
	{
		//Prepare
		pstmt = con->prepareStatement(ss.str());
		
		//Execute
		int result = pstmt->executeUpdate();
		
	}
	catch (SQLException & execption)
	{
		cout << " # ERR: SQLException in " << __FILE__ << endl;
		cout << "(" << __FUNCTION__ << ") on Line " << __LINE__ << endl;
		cout << "# ERR :" << execption.what() << endl;
		cout << "(MySQL erro code:  " << execption.getErrorCode() << endl;
		cout << " SQLState = " << execption.getSQLState() << endl;
		return false;
	}

	return true;
	
}
void CreateTable()
{
	try
	{
		//Prepare
		pstmt = con->prepareStatement("CREATE TABLE `project2`.`web_auth` (`id` BIGINT NOT NULL AUTO_INCREMENT,`email` VARCHAR(255) NULL,`salt` CHAR(64) NULL,`hashed_password` CHAR(64) NULL,`userId` BIGINT NULL, PRIMARY KEY(`id`)); ");

		//Execute
		int result = pstmt->executeUpdate();

	}
	catch (SQLException & execption)
	{
		cout << " # ERR: SQLException in " << __FILE__ << endl;
		cout << "(" << __FUNCTION__ << ") on Line " << __LINE__ << endl;
		cout << "# ERR :" << execption.what() << endl;
		cout << "(MySQL erro code:  " << execption.getErrorCode() << endl;
		cout << " SQLState = " << execption.getSQLState() << endl;
		return;
	}

	try
	{
		//Prepare
		pstmt = con->prepareStatement("CREATE TABLE `project2`.`user` (  `id` BIGINT NOT NULL AUTO_INCREMENT,  `last_login` TIMESTAMP NULL,  `creationn_date` DATETIME NULL,  PRIMARY KEY (`id`));");

		//Execute
		int result = pstmt->executeUpdate();

		//Check
		//cout << " Number of Rows affected " << result;
	}
	catch (SQLException & execption)
	{
		cout << " # ERR: SQLException in " << __FILE__ << endl;
		cout << "(" << __FUNCTION__ << ") on Line " << __LINE__ << endl;
		cout << "# ERR :" << execption.what() << endl;
		cout << "(MySQL erro code:  " << execption.getErrorCode() << endl;
		cout << " SQLState = " << execption.getSQLState() << endl;
		return;
	}	
}