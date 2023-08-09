/*
 *  resource.h
 *
 *  Created on: 12-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_CORE_RESOURCE_H_
#define MWT_CORE_RESOURCE_H_
#include "object.h"
#include "classes.h"
#include "error.h"
#include "utf8.h"
#include "iterator.h"
#ifdef __cplusplus
	class MResource;
	class MToolkit;
#else
	typedef struct _MResource MResource;
	typedef struct _MToolkit MToolkit;
#endif

struct _MResourceClass {
	MClassID m_classID;
	MUShort m_pSize;
	MToolkit* m_toolkit;
	struct _MResourceClass* m_PlatClass;
	void *reserved[2];
	MResult (*create)(MResource *resource,MToolkit* toolkit,struct _MResourceClass* clazz,void* args);
	MResult (*dispose)(MResource *resource);
	MResult (*set_style)(MResource *resource,MUInt64 style);
};
struct _MResource {
	struct _MObject m_object;
	struct _MResourceClass* m_clazz;
	void* m_handle;
	MUInt64 m_style; // style and states
};

#define _MRESOURCE(x) ((struct _MResource*)x)
#define _MRESOURCE_CLASS(x) ((struct _MResourceClass*)x)
#define _MRESOURCE_GETCLASS(x) (_MRESOURCE(x)->m_clazz)

#define _MRESOURCE_CHECK(x)

#define _RETURN_RESULT(result) result
#define _RETURN_INT(result)

#define _MRESOURCE_INVOKE_R_0(CLASS,FUN,resource) 	\
				MResult result; \
				if(resource == 0) result = MERROR_NULL_ARGS;\
				else{\
					result = CLASS##_GETCLASS(resource)->FUN(resource);\
				}\
				return _RETURN_RESULT(result);

#define _MRESOURCE_INVOKE_R_1(CLASS,FUN,resource,args1) 	\
				MResult result; \
				if(resource == 0) result = MERROR_NULL_ARGS;\
				else{\
					result = CLASS##_GETCLASS(resource)->FUN(resource,args1);\
				}\
				return _RETURN_RESULT(result);

#define _MRESOURCE_INVOKE_R_2(CLASS,FUN,resource,args1,args2) 	\
				MResult result; \
				if(resource == 0) result = MERROR_NULL_ARGS;\
				else{\
					result = CLASS##_GETCLASS(resource)->FUN(resource,args1,args2);\
				}\
				return _RETURN_RESULT(result);
#define _MRESOURCE_INVOKE_R_3(CLASS,FUN,resource,args1,args2,args3) 	\
				MResult result; \
				if(resource == 0) result = MERROR_NULL_ARGS;\
				else{\
					result = CLASS##_GETCLASS(resource)->FUN(resource,args1,args2,args3);\
				}\
				return _RETURN_RESULT(result);

#ifdef __cplusplus
extern "C" {
#endif
MEXPORT extern void* _nullMResourceClass[];

#ifdef __cplusplus
}
#endif

#ifdef MINLINE
MINLINE void m_resource_init(MResource* resource){
	_MRESOURCE(resource)->m_clazz = _MRESOURCE_CLASS(_nullMResourceClass);
}
MINLINE MResult m_resource_dispose(MResource* resource){
	_MRESOURCE_INVOKE_R_0(_MRESOURCE,dispose,resource)
}
MINLINE MResult m_resource_set_style(MResource* resource,MUInt64 style){
	_MRESOURCE_INVOKE_R_1(_MRESOURCE,set_style,resource,style);
}
MINLINE MUInt64 m_resource_get_style(MResource* resource){
	if(resource == 0) return 0;
	else return _MRESOURCE(resource)->m_style;
}
MINLINE MToolkit* m_resource_get_toolkit(MResource* resource){
	if(resource == 0) return 0;
	else{
		return _MRESOURCE_GETCLASS(resource)->m_toolkit;
	}
}
#endif

#endif /* MWT_CORE_RESOURCE_H_ */
