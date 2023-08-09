/*
 *  toolkit.h
 *
 *  Created on: 12-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_CORE_TOOLKIT_H_
#define MWT_CORE_TOOLKIT_H_
#include "resource.h"
#ifdef __cplusplus
	class MToolkit;
#else
	typedef struct _MToolkit MToolkit;
#endif

struct _MToolkit {
	struct _MResource resource;
	const char* name;
	int version;
	struct _MToolkit* platformToolkit;
};

struct _MToolkitClass {
	struct _MResourceClass m_resource;
	MResult (*get_class)(MToolkit *toolkit,MClassID clazz_id,struct _MResourceClass** clazz);
	MResult (*run)(MToolkit* toolkit,int flags);
	MResult (*is_gui_thread)(MToolkit* toolkit);
};

#define _MTOOLKIT(x) ((struct _MToolkit*)x)
#define _MTOOLKIT_CLASS(x) ((struct _MToolkitClass*)x)
#define _MTOOLKIT_GETCLASS(x) _MTOOLKIT_CLASS(((struct _MResource*)x)->m_clazz)

#ifdef __cplusplus
extern "C" {
#endif
MEXPORT MResult m_toolkit_create_resource(MToolkit *toolkit,MResource* resource,MClassID clazz_id,void* args);

#ifdef __cplusplus
}
#endif

#ifdef MINLINE
MINLINE MResult m_toolkit_get_class(MToolkit *toolkit,MClassID clazz_id
			,struct _MResourceClass** clazz){
	_MRESOURCE_INVOKE_R_2(_MTOOLKIT,get_class,toolkit,clazz_id,clazz);
}
MINLINE MResult m_toolkit_run(MToolkit *toolkit,int flags){
	_MRESOURCE_INVOKE_R_1(_MTOOLKIT,run,toolkit,flags);
}
#endif
#endif /* MWT_CORE_TOOLKIT_H_ */
