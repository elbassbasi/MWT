/*
 * box.h
 *
 *  Created on: 09-08-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWT_WIDGETS_BOX_H_
#define MWT_WIDGETS_BOX_H_
#include "container.h"
#ifdef __cplusplus
	class MBox;
#else
	typedef struct _MBox MBox;
#endif

struct _MBox {
	struct _MContainer widget;
};

struct _MBoxClass {
	struct _MContainerClass m_widget;
};

#define _MBOX(x) ((struct _MBox*)x)
#define _MBOX_CLASS(x) ((struct _MBoxClass*)x)
#define _MBOX_GETCLASS(x) _MBOX_CLASS(_MRESOURCE_GETCLASS(x))

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
#ifdef MINLINE


#endif




#endif /* MWT_WIDGETS_BOX_H_ */
