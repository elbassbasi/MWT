/*
 *  resource.c
 *
 *  Created on: 12-07-2023
 *  Author: azeddine El Bassbasi
 */
#include "../common.h"

MResult _m_resource_set_style(MResource *resource,MUInt64 style){
	resource->m_style = style;
	return MTRUE;
}



