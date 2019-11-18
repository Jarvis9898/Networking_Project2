#define HEADER 8
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
	ReceiveMessage
};

map<string, vector<Connection*>> m_Rooms;

FD_SET readSet;

SOCKET listenSocket = INVALID_SOCKET;
SOCKET acceptSocket = INVALID_SOCKET;

Connection* allConnections[FD_SETSIZE];
int totalS;
int port = 5858;
WSAData wsaData;
SOCKADDR_IN	addr;
int result;

int iResult;

bool CheckNewConnection();
void ReceiveMsg(Connection *con, int i);
void NewClient(SOCKET s);
void ParseMsg(Connection *con);
void RemoveClient(int index);
void BroadcastMsg(string roomName, string msg);
void SendMsg(Connection* con, string s1, string s2);
void main()
{
	

	FD_ZERO(&readSet);

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("Failed to load WinSock library! Error %d\n", WSAGetLastError());
	}


	listenSocket = socket(AF_INET, SOCK_STREAM , IPPROTO_TCP);

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);

	result = bind(listenSocket, (PSOCKADDR)&addr, sizeof(addr));
	result = listen(listenSocket, 5);
	unsigned long nBlock = 1;
	result = ioctlsocket(listenSocket, FIONBIO, &nBlock);

	while (true)
	{
		if (_kbhit())
		{
			int ch = _getch();
			if (ch == 27) break;
		}

		int result;

		
		FD_ZERO(&readSet);
		FD_SET(listenSocket, &readSet);

		
		for (int i = 0; i < totalS; i++)
		{
			FD_SET(allConnections[i]->socket, &readSet);
		}

		int Total = select(0, &readSet, NULL, NULL, NULL);

		if (Total == SOCKET_ERROR)
		{
			return;
		}
		
		if (CheckNewConnection())
		{
			Total--;
		}

		for (int i = 0; Total > 0 && i <totalS; i++) 
		{	
			Connection* con = allConnections[i];

			if (FD_ISSET(con->socket, &readSet)) 
			{
				Total--;
				ReceiveMsg(con, i);
			}
		}
	}

	system("Pause");

	return;
}

bool CheckNewConnection()
{
	if (!FD_ISSET(listenSocket, &readSet)) return false;

	acceptSocket = accept(listenSocket, NULL, NULL);

	unsigned long nBlock = 1;

	int result = ioctlsocket(acceptSocket, FIONBIO, &nBlock);
	NewClient(acceptSocket);
	
}

void NewClient(SOCKET s)
{
	Connection* con = new Connection(s);

	allConnections[totalS] = con;
	totalS++;

	printf("Client Connected on Stocket %d!\n", s);

	SendMsg(con, "Chat Server", "Welcome to the Chat Room Server!!!!");
}

void RemoveClient(int index)
{
	Connection* con = allConnections[index];
	printf("[%d] Disconnected!\n", con->socket);

	map<string, vector<Connection*>>::iterator roomIt;
	vector<Connection*>::iterator conIt;
	for (roomIt = m_Rooms.begin(); roomIt != m_Rooms.end(); roomIt++)
	{
		conIt = find(roomIt->second.begin(), roomIt->second.end(), con);
		if (conIt != roomIt->second.end())
		{
			roomIt->second.erase(conIt);
		}
	}
	closesocket(con->socket);
	delete con;
	for (int i = index; i < totalS; i++)
	{
		allConnections[i] = allConnections[i + 1];
	}

	totalS--;
}

void ReceiveMsg(Connection* con, int i)
{
	int result = recv(con->socket, &((char&)(con->buffer[con->bytesReceived])), 512, 0);

	if (result == SOCKET_ERROR)
	{
		int WSAErrorCode = WSAGetLastError();

		if (WSAErrorCode != WSAEWOULDBLOCK)
		{
			RemoveClient(i);
			return;
		}
		if (WSAErrorCode == WSAEHOSTUNREACH)
		{
			printf("Disconnected from client...\n");
		}
		return;
	}
	if (result == 0)
	{
		RemoveClient(i);
		return;
	}
	con->bytesReceived += result;
	if (con->bytesReceived >= 4 && con->length == 0)
	{
		con->length |= con->buffer[0];
		con->length |= con->buffer[1] << 8;
		con->length |= con->buffer[2] << 16;
		con->length |= con->buffer[3] << 24;
	}
	if (con->bytesReceived == con->length && con->bytesReceived != 0)
	{
		con->length = 0;
		con->bytesReceived = 0;

		ParseMsg(con);
		con->buffer.Clear();
	}
}

void ParseMsg(Connection* con)
{
	int packetSize = con->buffer.deserializeInt();
	int msgId = con->buffer.deserializeInt();

	switch (msgId)
	{
		case MessageType::JoinRoom:
		{
			int roomLength = con->buffer.deserializeInt();
			string roomName = con->buffer.deserializeString(roomLength);

			stringstream ss;
			ss << " " << con->socket << " ";
			BroadcastMsg(roomName, ss.str() + " has joined the room ");
			SendMsg(con, roomName, "Room Joined ");
			m_Rooms[roomName].push_back(con);
			break;
		}
		case MessageType::LeaveRoom:
		{
			int roomLength = con->buffer.deserializeInt();
			string roomName = con->buffer.deserializeString(roomLength);

			vector<Connection*>::iterator it = find(m_Rooms[roomName].begin(), m_Rooms[roomName].end(), con);
			SendMsg(con, roomName, "Room Left ");
			m_Rooms[roomName].erase(it);
			stringstream ss;
			ss << " " << con->socket << " ";
			BroadcastMsg(roomName,ss.str()+" has left the room ");
			break;
		}

		case  MessageType::MessageRoom:
		{
			int roomLength = con->buffer.deserializeInt();
			string roomName = con->buffer.deserializeString(roomLength);
			int msgLength = con->buffer.deserializeInt();
			string msg = con->buffer.deserializeString(msgLength);
			stringstream ss;
			ss << " " << con->socket << " ";
			BroadcastMsg(roomName, ss.str() + msg);
			break;
		}
	}
}

void BroadcastMsg(string roomName, string msg)
{
	printf(" Message to all --- %s %s \n", roomName.c_str(), msg.c_str());

	vector<Connection*> roomPopulation = m_Rooms[roomName];
	for (vector<Connection*>::iterator it = roomPopulation.begin(); it != roomPopulation.end(); it++)
	{
		SendMsg(*it, roomName, msg);	
	}
}
void SendMsg(Connection* con, string s1, string s2)
{
	int roomLength = s1.length();
	int messageLength = s2.length();
	int packetSize = HEADER + sizeof(int) + roomLength + sizeof(int) + messageLength;

	con->buffer.Clear();
	con->buffer.serializeInt(packetSize);
	con->buffer.serializeInt(MessageType::ReceiveMessage);
	con->buffer.serializeInt(s1.length());
	con->buffer.serializeString(s1);
	con->buffer.serializeInt(s2.length());
	con->buffer.serializeString(s2);

	int result = send(con->socket, &((char&)con->buffer[0]), con->buffer.writePointer, 0);
}