#define HEADER 8

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define DISABLE_NEWLINE_AUTO_RETURN  0x0008
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define ENTER 13
#define BACKSPACE 8
#define ESCAPE 27

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
#include <cctype>
#pragma comment(lib, "Ws2_32.lib")

#include "Buffer.h"


using namespace std;


class Connection
{
public:

	SOCKET socket;
	Buffer buffer;
	int bytesReceived;
	int length;

	Connection()
	{
		socket = INVALID_SOCKET;
		buffer.Clear();
		bytesReceived = 0;
		length = 0;
	}
	Connection(SOCKET s)
	{
		socket = s;
		buffer = Buffer(512);
		bytesReceived = 0;
		length = 0;
	}

};


enum MessageType
{
	JoinRoom,
	LeaveRoom,
	MessageRoom,
	ReceiveMessage,
	CreateAccount,
	AuthenticateAccount
};

string message;

Connection* serverConn = new Connection(INVALID_SOCKET);

WSAData	wsaData;

int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
void HandleUserInput();
void Connect();
void Disconnect();
void SerializeMsg(MessageType type, string arg, string msg);
void DeserializeMsg(Connection* con);
void main()
{
	DWORD l_mode;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleMode(hStdout, &l_mode);
	SetConsoleMode(hStdout, l_mode |ENABLE_VIRTUAL_TERMINAL_PROCESSING |DISABLE_NEWLINE_AUTO_RETURN);

	int ch;
	printf("\x1B[2K\r~");

	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();

			switch (ch)
			{
			case ENTER:
				printf("\x1B[2K\r");
				HandleUserInput();
				message = "";
				printf("\x1B[2K\r~ %s", message.c_str());
				break;
			case BACKSPACE:
				if (!message.empty())
				{
					message = message.substr(0, message.length() - 1);
				}
				printf("\x1B[2K\r~ %s", message.c_str());
				break;
			default:
				message.push_back(ch);
				printf("\x1B[2K\r~ %s", message.c_str());
				break;
			}
		}

		if (serverConn->socket == INVALID_SOCKET) continue;

		int result = recv(serverConn->socket, &((char&)(serverConn->buffer[serverConn->bytesReceived])), 512, 0);
		if (result == SOCKET_ERROR)
		{
			if (WSAGetLastError() == WSAEWOULDBLOCK) continue;
			serverConn->socket = INVALID_SOCKET;
			continue;
		}
		if (result == 0)
		{
			closesocket(serverConn->socket);
			continue;
		}

		serverConn->bytesReceived += result;

		if (serverConn->bytesReceived >= 4 && serverConn->length == 0)
		{
			serverConn->length |= serverConn->buffer[0];
			serverConn->length |= serverConn->buffer[1] << 8;
			serverConn->length |= serverConn->buffer[2] << 16;
			serverConn->length |= serverConn->buffer[3] << 24;
		}

		if (serverConn->bytesReceived == serverConn->length && serverConn->bytesReceived != 0)
		{
			serverConn->length = 0;
			serverConn->bytesReceived = 0;
			DeserializeMsg(serverConn);
			serverConn->buffer.Clear();
		}

		//printf("%s", message.c_str());

		printf("\x1B[2K\r$ %s", message.c_str());
		
	}

}

void Connect()
{
	struct sockaddr_in server;
	struct hostent* host;

	serverConn->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	server.sin_family = AF_INET;
	server.sin_port = htons(5858);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (server.sin_addr.s_addr == INADDR_NONE)
	{
		host = gethostbyname("127.0.0.1");
		CopyMemory(&server.sin_addr, host->h_addr_list[0], host->h_length);
	}
	int result = connect(serverConn->socket, (struct sockaddr*) & server, sizeof(server));
	if (result == SOCKET_ERROR)
	{
		if (WSAGetLastError() == WSAEWOULDBLOCK)
		{
			pollfd poll;
			poll.fd = serverConn->socket;
			poll.events = POLLRDNORM | POLLWRNORM;

			int pollResult;	
			pollResult = WSAPoll(&poll, 1, 5000);
			if (!pollResult)
			{
				serverConn->socket = INVALID_SOCKET;
				return;
			}
		}				
		else
		{
			serverConn->socket = INVALID_SOCKET;
			return;
		}
		
	}
	unsigned long nBlock = 1;
	int status = ioctlsocket(serverConn->socket, FIONBIO, &nBlock);
}
void SerializeMsg(MessageType type, string arg, string msg)
{
	serverConn->buffer.Clear();
	serverConn->buffer.serializeInt(0);	
	serverConn->buffer.serializeInt(type);

	switch (type)
	{
	case JoinRoom:
		serverConn->buffer.serializeInt(arg.length());
		serverConn->buffer.serializeString(arg);
		break;

	case LeaveRoom:
		serverConn->buffer.serializeInt(arg.length());
		serverConn->buffer.serializeString(arg);
		break;

	case MessageRoom:
		serverConn->buffer.serializeInt(arg.length());
		serverConn->buffer.serializeString(arg);
		serverConn->buffer.serializeInt(msg.length());
		serverConn->buffer.serializeString(msg);
		break;

	case CreateAccount:
		serverConn->buffer.serializeInt(arg.length());
		serverConn->buffer.serializeString(arg);
		serverConn->buffer.serializeInt(msg.length());
		serverConn->buffer.serializeString(msg);
		break;

	case AuthenticateAccount:
		serverConn->buffer.serializeInt(arg.length());
		serverConn->buffer.serializeString(arg);
		serverConn->buffer.serializeInt(msg.length());
		serverConn->buffer.serializeString(msg);
		break;

	default:
		break;
	}

	serverConn->buffer.serializeInt(serverConn->buffer.writePointer,0);

	int result = send(serverConn->socket, &(char&)(serverConn->buffer[0]), serverConn->buffer.writePointer, 0);
	
}
void DeserializeMsg(Connection* con)
{
	int packetSize = con->buffer.deserializeInt();
	int messageId = con->buffer.deserializeInt();

	switch (messageId)
	{
	case  MessageType::ReceiveMessage:
	{
		int roomLength = con->buffer.deserializeInt();
		string roomName = con->buffer.deserializeString(roomLength);
		int msgLength = con->buffer.deserializeInt();
		string msg = con->buffer.deserializeString(msgLength);
		printf("\x1B[2K\r %s  %s\n", roomName.c_str(), msg.c_str());
		break;
	}
		
	default:
		break;
	}
}

void HandleUserInput()
{
	string cmd, arg, msg;

	int spaces = 0;
	char ch;
	int len = message.length();

	for (int i = 0; i < len; i++)
	{
		ch = message[i];
		if (spaces < 3 && message[i] == ' ')
		{
			spaces++;
			if (spaces <= 2)
				continue;
		}
		if (spaces == 0)
		{
			cmd.push_back(toupper(ch));
		}
		else if (spaces == 1)
		{
			arg.push_back(ch);
		}
		else if (spaces >= 2)
		{
			msg.push_back(ch);
		}
	}

	if (cmd.compare("CONNECT") == 0)
	{
		Connect();
	}
	else if(cmd.compare("DISCONNECT") == 0)
	{
		Disconnect();
	}
	else if (cmd.compare("JOIN") == 0)
	{
		SerializeMsg(JoinRoom, arg, msg);
	}
	else if (cmd.compare("LEAVE") == 0)
	{
		SerializeMsg(LeaveRoom, arg, msg);
	}
	else if (cmd.compare("<<") == 0)
	{
		SerializeMsg(MessageRoom, arg, msg);
	}
	else if (cmd.compare("SIGNUP") == 0)
	{
		SerializeMsg(CreateAccount, arg, msg);
	}
	else if (cmd.compare("LOGIN") == 0)
	{
		SerializeMsg(AuthenticateAccount, arg, msg);
	}
}

void Disconnect()
{
	int result = closesocket(serverConn->socket);
	serverConn->socket = INVALID_SOCKET;
}
