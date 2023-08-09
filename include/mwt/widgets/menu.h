/*
 * menu.h
 *
 *  Created on: 04-08-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWT_WIDGETS_MENU_H_
#define MWT_WIDGETS_MENU_H_
#include "widget.h"

struct _MMenu {
	struct _MWidget m_widget;
};

struct _MMenuClass {
	struct _MWidgetClass m_widget;
};

#define _MMENU(x) ((struct _MMenu*)x)
#define _MMENU_CLASS(x) ((struct _MMenuClass*)x)
#define _MMENU_GETCLASS(x) _MMENU_CLASS(_MRESOURCE_GETCLASS(x))

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
#ifdef MINLINE


#endif




#endif /* MWT_WIDGETS_MENU_H_ */
