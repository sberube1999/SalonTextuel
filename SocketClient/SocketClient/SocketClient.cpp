// SocketClient.cpp : définit le point d'entrée pour l'application console.
//
//
#include "stdafx.h"
#include <iostream>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")


int main()
{
	WSADATA WSAData;
	SOCKET sock;
	SOCKADDR_IN sin;
	char buffer[255];
	WSAStartup(MAKEWORD(2, 0), &WSAData);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	sin.sin_addr.s_addr = inet_addr("10.200.13.37");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(80);
	connect(sock, (SOCKADDR *)&sin, sizeof(sin));
	int retour = recv(sock, buffer, sizeof(buffer), 0);
	if (retour > 0)
	{
		for (size_t i = 0; i < sizeof(buffer); i++)
		{
			if (isalnum(buffer[i]) || buffer[i] == ' ')
			{
				std::cout << buffer[i];
			}
			else
			{
				break;
			}
			
		}
		std::cout << std::endl;
		send(sock, "11Y", strlen("11Y"), 0);
	}
	closesocket(sock);
	WSACleanup();
	system("pause");
	return 0;
}

