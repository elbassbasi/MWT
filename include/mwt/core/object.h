/*
 * hobject.h
 *
 *  Created on: 4 juil. 2023
 *      Author: elbas
 */

#ifndef MWT_CORE_OBJECT_H_
#define MWT_CORE_OBJECT_H_
#include "defs.h"
typedef MIntPtr MResult;
typedef MUint MId;

struct _MObject {
	void* vtbl;//reserved for c++
	struct _MObjectClass* clazz;
	MInt ref;
	MInt weak;
	void* priv;
};
#ifdef __cplusplus
	class MObject;
#else
	typedef struct _MObject MObject;
#endif

struct _MObjectClass {
	MId id;

};

#ifdef __cplusplus
extern "C" {
#endif
MResult m_object_init(MObject* obj);

MEXPORT MResult m_object_get_data(MObject* obj,MId dataId,void** data);
MEXPORT MResult m_object_set_data(MObject* obj,MId dataId,void* data);
MEXPORT MResult m_object_add_ref(MObject* obj);
MEXPORT MResult m_object_add_weak_ref(MObject* obj);
MEXPORT MResult m_object_ref(MObject* obj);
MEXPORT MResult m_object_unref(MObject* obj);
MEXPORT MResult m_object_weak_ref(MObject* obj);
MEXPORT MResult m_object_weak_unref(MObject* obj);

MEXPORT MResult m_object_connect(MObject* obj,MId signalId,void* callback,void* data[4]);
#ifdef __cplusplus
}
#endif
#endif /* MWT_CORE_OBJECT_H_ */
