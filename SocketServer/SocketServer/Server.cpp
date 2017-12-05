#include "stdafx.h"
#include "Server.h"
Server::Server()
{
	WSAStartup(MAKEWORD(2, 0), &WSAData);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	bind(sock, (SOCKADDR *)&sin, sizeof(sin));

	Utilities::CleanBuffer(buffer, size);
}

void Server::WaitClient()
{
	int sinsize = sizeof(csin);
	while (true)
	{
		std::cout << "Waiting for connection..." << std::endl;
		listen(sock, 0);
		if (!((csock = accept(sock, (SOCKADDR *)&csin, &sinsize)) != INVALID_SOCKET))
		{
			std::cout << "connected!" << std::endl;
			send(csock, "You are connected!", 18, 0);
			break;
		}
		else
		{
			std::cout << "Connection failed." << std::endl;
		}

	}
}
void Server::recvMessage()
{
	retour = recv(csock, buffer, sizeof(buffer), 0);
}