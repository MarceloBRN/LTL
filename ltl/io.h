#ifndef LAMBDA_IO_H
#define LAMBDA_IO_H


#ifdef _MSC_VER
#include <Windows.h>
#elif __GNUC__
#include <windows.h>
#endif

#pragma once

namespace lambda {
	template<typename ...Args>
	void printf(const char * _Format, Args ...args)
	{

	}

	bool __cdecl putchar(const char character);
	bool __cdecl puts(const char * str);

	template<typename ...Args>
	void scanf(const char * _Format, Args ...args)
	{

	}

}

#endif // OSTDIO_H




