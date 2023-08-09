/*
 *  widget.c
 *
 *  Created on: 23-07-2023
 *  Author: azeddine El Bassbasi
 */
#include "../common.h"
MResult m_widget_create(MWidget* widget,MToolkit* toolkit,MClassID clazz_id,
		MContainer* parent,MUInt64 style){
	if(toolkit == 0){
		if(parent == 0){
			toolkit = m_app_get_default_toolkit(m_app_get());
		}else toolkit = m_resource_get_toolkit(_MRESOURCE(parent));
	}
	if(toolkit == 0) return MERROR_NULL_ARGS;
	struct _MWidgetCreate create;
	create.parent = parent;
	create.style = style;
	create.reserved = 0;
	return m_toolkit_create_resource(toolkit,_MRESOURCE(widget),clazz_id,&create);
}
MResult m_widget_post_event(MWidget* widget,MEvent *e){
	return MFALSE;
}

