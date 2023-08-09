/*
 *  defs.h
 *
 *  Created on: 08-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_CORE_DEFS_H_
#define MWT_CORE_DEFS_H_
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdint.h>

typedef long long MIntPtr;
typedef unsigned char MUChar;
typedef wchar_t MWChar;
typedef unsigned int MUnichar;
typedef short MShort;
typedef unsigned short MUShort;
typedef int MInt;
typedef unsigned int MUInt;
typedef long long int MInt64;
typedef unsigned long long int MUInt64;
typedef MIntPtr MResult;

/*
 * DLL_EXPORT
 */
#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
    #ifdef __GNUC__
      #define DLL_EXPORT __attribute__ ((dllexport))
    #else
      #define DLL_EXPORT __declspec(dllexport)
    #endif
    #ifdef __GNUC__
      #define DLL_IMPORT __attribute__ ((dllimport))
    #else
      #define DLL_IMPORT __declspec(dllimport)
    #endif
#else
#if __GNUC__ >= 4
#define DLL_EXPORT __attribute__ ((visibility ("default")))
#define DLL_IMPORT
#else
    #define DLL_EXPORT
    #define DLL_IMPORT
  #endif
#endif


#ifdef MBUILD
#define MEXPORT DLL_EXPORT
#else
#define MEXPORT
#endif

#define MINLINE static inline
#define _ARGINT(x) ((void*)((MIntPtr)((int)x)))



#endif /* MWT_CORE_DEFS_H_ */
