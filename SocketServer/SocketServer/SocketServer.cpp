/*SocketServer.cpp*/

#include "stdafx.h"
#include <iostream>
#include "Utilities.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)
using namespace std;

int main()
{
	WSADATA WSAData;
	SOCKET sock;
	SOCKET csock;
	SOCKADDR_IN sin;
	SOCKADDR_IN csin;

	const size_t size = 255;
	char *buffer = new char[size];
	Utilities::CleanBuffer(buffer, size);

	string code;
	string message;
	int retour;
	// construxteur
	WSAStartup(MAKEWORD(2, 0), &WSAData);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(80);
	bind(sock, (SOCKADDR *)&sin, sizeof(sin));

	std::cout << "Waiting for connection..." << std::endl;
	listen(sock, 0);
	int sinsize = sizeof(csin);
	while ((csock = accept(sock, (SOCKADDR *)&csin, &sinsize)) != INVALID_SOCKET)
	{
				std::cout << "connected!" << std::endl;
				//send(csock, "You are connected!", 18, 0);
				retour = recv(csock, buffer, sizeof(buffer), 0);
				if (retour > 0)
				{
					code = Utilities::GetCodeIn(buffer);
					message = Utilities::GetMessageIn(buffer, size);
					// Si il y a un message de fin
					if (code == "99" && message == "FIN")
					{
						// on arrête le programme
						std::cout << "Fin de l'utilisation" << " (code: 99)" << std::endl;
						system("pause");
						return 0;
					}
					else
					{
						std::cout << message << " (message de type " << code[0] << code[1] << ")" << std::endl;
					}
					Utilities::CleanBuffer(buffer, size);
				}
				else if (retour == 0)
				{
					std::cout << "recv interrupted" << std::endl;
				}
				else
				{
					std::cout << "recv failed" << std::endl;
				}
				closesocket(csock);
	}
	return 0;
}