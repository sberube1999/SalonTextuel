#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

static class Utilities
{
public:
	static void CrypterDecrypter(string &message, string key);
	static string GetMessageIn(char *buffer, size_t size);
	static void CleanBuffer(char *buffer, size_t size);
	static string GetCodeIn(char *buffer);
};
