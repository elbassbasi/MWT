/*
 * toolkit.c
 *
 *  Created on: 06-08-2023
 *      Author: azeddine El Bassbasi
 */
#include <mwt/mwt.h>
#include <mwt/toolkitclasses.h>

void m_toolkit_init_classes(struct _MToolkitAllClasses* classes){
	classes->classes[MCLASS_FRAME] =_MRESOURCE_CLASS(&classes->m_frame);
}

MResult m_toolkit_create_resource(MToolkit *toolkit,MResource* resource,MClassID clazz_id,void* args){
	struct _MResourceClass* clazz = 0;
	MResult ret = m_toolkit_get_class(toolkit,clazz_id,&clazz);
	if(clazz != 0){
		return clazz->create(resource,toolkit,clazz,args);
	}
	return ret;
}

