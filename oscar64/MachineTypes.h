#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef	unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned int		uint32;
typedef	signed char			int8;
typedef signed short		int16;
typedef signed short		int32;
#ifdef _WIN32
typedef __int64				int64;
typedef unsigned __int64	uint64;
#define MAXPATHLEN	_MAX_PATH
#else
#include "linux/limits.h"

typedef long long			int64;
typedef unsigned long long	uint64;

#define _access access
#define _strdup strdup

#define MAXPATHLEN	PATH_MAX

inline char* strcat_s(char* c, const char* d)
{
	return strcat(c, d);
}

inline char* strcat_s(char* c, int n, const char* d)
{
	return strcat(c, d);
}

inline char* strcpy_s(char* c, const char* d)
{
	return strcpy(c, d);
}

inline char* strcpy_s(char* c, int n, const char* d)
{
	return strcpy(c, d);
}

inline int fopen_s(FILE** f, const char* fname, const char* mode)
{
	*f = fopen(fname, mode);
	return *f ? 0 : -1;
}

inline char* _fullpath(char* absPath, const char* relPath, size_t maxLength)
{
	return realpath(relPath, absPath);
}

inline int sprintf_s(char* buffer, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	int n = vsprintf(buffer, format, args);
	va_end(args);
	return n;
}

inline int sprintf_s(char* buffer, int size, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	int n = vsprintf(buffer, format, args);
	va_end(args);
	return n;
}

#endif

static const uint8 BC_REG_WORK = 0x03;
static const uint8 BC_REG_IP = 0x19;
static const uint8 BC_REG_ACCU = 0x1b;
static const uint8 BC_REG_ADDR = 0x1f;
static const uint8 BC_REG_STACK = 0x23;
static const uint8 BC_REG_LOCALS = 0x25;

static const uint8 BC_REG_TMP = 0x43;
static const uint8 BC_REG_TMP_SAVED = 0x53;

