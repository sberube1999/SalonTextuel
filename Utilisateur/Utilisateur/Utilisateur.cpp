// Utilisateur.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <string>
using namespace std;

string Crypter(string msg, string cle)
{
	string msgCrypte = "";
	//for (int i = 0; i < msg.length; i++)
	//{
	//	int chiffreMsg = (int)msg[i];
	//	int chiffreCle = (int)cle[i % (cle.length - 1)];
	//	int resultatXOR = chiffreMsg ^ chiffreCle;
	//	char lettreEncodee = (char)resultatXOR;
	//	msgCrypte += lettreEncodee;
	//}
	return msgCrypte;
}

int main()
{
	cout << "Entrez l'adresse de connection:" << endl;
	char adresse[] = "";
	cin >> adresse;

	WSADATA WSAData;
	SOCKET sock;
	SOCKADDR_IN sin;
	char buffer[255];
	WSAStartup(MAKEWORD(2, 0), &WSAData);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	sin.sin_addr.s_addr = inet_addr(adresse);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(80);
	if (connect(sock, (SOCKADDR *)&sin, sizeof(sin)))
	{
		cout << "Connection établie" << endl;

		//On lance les threads
	}
	else
	{
		cout << "La connection est introuvable, voulez vous héberger le serveur? (o/n)" << endl;
		char reponse = ' ';
		cin >> reponse;
		if (reponse == 'o')
		{
			// lance le serveur
		}
		else
		{
			cout << "Au revoir" << endl;
			system("pause");
			return 0;
		}
	}
	
	//closesocket(sock);
	//WSACleanup();

	return 0;
}

