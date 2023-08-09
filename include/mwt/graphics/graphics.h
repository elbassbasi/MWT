/*
 *  graphics.h
 *
 *  Created on: 23-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_GRAPHICS_GRAPHICS_H_
#define MWT_GRAPHICS_GRAPHICS_H_
#include "rect.h"
#ifdef __cplusplus
	class MCursor;
	class MFont;
	class MGraphics;
	class MRegion;
#else
	typedef struct _MCursor MCursor;
	typedef struct _MFont MFont;
	typedef struct _MGraphics MGraphics;
	typedef struct _MRegion MRegion;
#endif
typedef MUInt MColor;


#endif /* MWT_GRAPHICS_GRAPHICS_H_ */
