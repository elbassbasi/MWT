/*
 *  error.h
 *
 *  Created on: 09-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_CORE_ERROR_H_
#define MWT_CORE_ERROR_H_
#include "defs.h"

enum {
	MTRUE = 1,
	MFALSE = 0,
	MNOINDEX = -1,
	MERROR_NULL_ARGS = -3,
	MERROR_NULL_CLASS = -4,
	MERROR_NOT_IMPL = -5,
	MERROR_INVALID_TOOLKIT = -6,
	MERROR_NO_HANDLES = -7,
};




#endif /* MWT_CORE_ERROR_H_ */
