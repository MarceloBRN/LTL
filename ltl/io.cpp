#include "io.h"

bool lambda::putchar(const char character)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD cWritten;

	if (hStdout == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, TEXT("GetStdHandle"), TEXT("Console Error"), MB_OK);
		return false;
	}

	if (!WriteConsole(
		hStdout,               // output handle 
		&character,           // prompt string 
		1,						// string length 
		&cWritten,             // bytes written 
		nullptr))                // not overlapped 
	{
		MessageBox(NULL, TEXT("WriteConsole"), TEXT("Console Error"),	MB_OK);
		return false;
	}

	return true;
}

bool lambda::puts(const char * str)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD cWritten;

	if (hStdout == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, TEXT("GetStdHandle"), TEXT("Console Error"), MB_OK);
		return false;
	}

	if (!WriteConsole(
		hStdout,            // output handle 
		str,				// prompt string 
		lstrlenA(str),		// string length 
		&cWritten,          // bytes written 
		nullptr))           // not overlapped 
	{
		MessageBox(NULL, TEXT("WriteConsole"), TEXT("Console Error"), MB_OK);
		return false;
	}
	return false;
}
