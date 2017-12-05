// SocketClient.cpp : définit le point d'entrée pour l'application console.
//
//Inclusion des librairies
#include "stdafx.h"
#include "Transactions.h"
#include <iostream>
#include <string>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void DrawInfos(char buffer[])
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
}

int RecieveServerInfos()
{
    ////Recevoir une information du serveur
    //int retour = recv(sock, buffer, sizeof(buffer), 0);
    ////Si la valeur reçue contient quelque chose
    //if (retour > 0)
    //{
    //    for (size_t i = 0; i < sizeof(buffer); i++)
    //    {
    //        if (isalnum(buffer[i]) || buffer[i] == ' ')
    //        {
    //            std::cout << buffer[i];
    //        }
    //        else
    //        {
    //            break;
    //        }

    //    }
    //    std::cout << std::endl;
    //    send(sock, "11Y", strlen("11Y"), 0);
    //}
    return 0;
}

//Méthode main du client
int main()
{
    //Déclaration des variables de base
    WSADATA WSAData;
    SOCKET sock;
    SOCKADDR_IN sin;
    //SetLocal pour les accents envoyés en message ou autres caractères spéciaux
    setlocale(LC_ALL, "");

    //Le buffer, tab qui contiendra le message reçus ou le message envoyé
    char buffer[255];

    //Startup, avant de commencer
    WSAStartup(MAKEWORD(2, 0), &WSAData);

    //Création du socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    //Valider que le socket est bien créé:
    if (sock == -1) //-1 est la valeur en cas d'échec
        std::cout << "Socket creation failed." << endl;

    //Ajout de l'adresse de connection //smasson "10.200.74.156" //sberube "10.200.13.37"
    sin.sin_addr.s_addr = inet_addr("10.200.74.156");
    //Famille de connexion
    sin.sin_family = AF_INET;
    //Port de connexion
    sin.sin_port = htons(80);

    //Connecter le socket
    if (connect(sock, (SOCKADDR *)&sin, sizeof(sin)) == -1)
    {
        //Message d'échec
        std::cout << "Failed to connect to the ip adress: " << "10.200.13.37" << endl;
    }
    else
    {
        //Message de succès
        std::cout << "La tentative de connexion au serveur est un succès." << endl;
        //On entre dans la boucle...
        bool isRunning = true;
        while (isRunning)
        {
            //temp
            //Déclaration des variables
            char message[250];
            //On attend un message à envoyer au serveur
            cin.getline(message, 250);
            //Ajouter "11" au début du message
            char addon[] = "11";
            int length = strlen(message) + strlen(addon);
            char * temp = new char[length];
            int i = 0;
            for (; i < strlen(addon); ++i)
            {
                temp[i] = addon[i];
            }
            for (; i < length; ++i)
            {
                temp[i] = message[i];
            }
            //On envoi le message au serveur
            if (send(sock, temp, strlen(temp), 0) == -1)
            {
                cout << "Failed to send the message." << endl;
            }
            //CleanUp
            delete temp;
            temp = nullptr;
            //**
        }
    }

    //Fermeture du socket
    closesocket(sock);
    //CleanUp
    WSACleanup();
    //Message de fin de programme
    cout << "End of the Client App." << endl;
    //Fin du programme
    return 0;
}

