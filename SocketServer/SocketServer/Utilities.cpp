#include "stdafx.h"
#include "Utilities.h"

// Permet d'encrypter / decrypter un message a l'aide d'une clee.
void Utilities::CrypterDecrypter(string &message, string key)
{
	for (int i = 0; i < message.size(); i++)
		message[i] = message[i] ^ key[i%key.size()];
}

// Fonction qui permet d'extraire le message envoyé du buffer.
string Utilities::GetMessageIn(char *buffer, size_t size)
{
	string message = "";
	for (size_t i = 2; i < size; i++)
	{
		if (buffer[i] != ' ') // []
		{
			message += buffer[i];
		}
		else
		{
			break;
		}
	}
	return message;
}

// Permet mettre des ' ' dans un tableau dynamique de char
void Utilities::CleanBuffer(char *buffer, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = ' ';
	}
}
// Fonction qui permet d'extraire le code du message envoyé du buffer.
string Utilities::GetCodeIn(char *buffer)
{
	string code = "";
	code += buffer[0];
	code += buffer[1];
	return code;
}