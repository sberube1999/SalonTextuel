#pragma once
#include <iostream>
#include "Utilities.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)
using namespace std;

class Server
{
public:
	Server();
	void WaitClient();
	void recvMessage();
private:
	WSADATA WSAData;
	SOCKET sock;
	SOCKET csock;
	SOCKADDR_IN sin;
	SOCKADDR_IN csin;

	const size_t size = 255;
	char *buffer = new char[size];

	string code;
	string message;
	int retour;

	int port = 80;
};