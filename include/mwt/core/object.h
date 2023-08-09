/*
 * object.h
 *
 *  Created on: 05-082023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWT_CORE_OBJECT_H_
#define MWT_CORE_OBJECT_H_
#include "defs.h"
#ifdef __cplusplus
	class MRef;
	class MObject;
#else
	typedef struct _MRef MRef;
	typedef struct _MObject MObject;
#endif
struct _MRef {
	int m_ref;
	int m_weak;
};

struct _MObject {
	void* m_vtbl;//reserved for c++
	struct _MRef m_ref;
};



#endif /* MWT_CORE_OBJECT_H_ */
