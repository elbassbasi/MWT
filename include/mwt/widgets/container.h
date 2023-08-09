/*
 * container.h
 *
 *  Created on: 29-07-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWT_WIDGETS_CONTAINER_H_
#define MWT_WIDGETS_CONTAINER_H_
#include "widget.h"

struct _MContainer {
	struct _MWidget m_widget;
};

struct _MContainerClass {
	struct _MWidgetClass m_widget;
};

#define _MCONTAINER(x) ((struct _MContainer*)x)
#define _MCONTAINER_CLASS(x) ((struct _MContainerClass*)x)
#define _MCONTAINER_GETCLASS(x) _MCONTAINER_CLASS(_MRESOURCE_GETCLASS(x))

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
#ifdef MINLINE


#endif



#endif /* MWT_WIDGETS_CONTAINER_H_ */
