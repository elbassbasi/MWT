/*
 * item.h
 *
 *  Created on: 30-07-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWT_WIDGETS_ITEM_H_
#define MWT_WIDGETS_ITEM_H_
#include "widget.h"
#ifdef __cplusplus
	class MItem;
#else
	typedef struct _MItem MItem;
#endif

struct _MItem {
	struct _MItemClass* m_clazz;
	MWidget* widget;
};

struct _MItemClass {
	MToolkit* m_toolkit;
	MResult (*close)(MItem *item);
	MResult (*copy)(MItem *from, MItem *to);
	MResult (*equals)(MItem *item1, MItem *item2);
};

#define _MITEM(x) ((struct _MItem*)x)
#define _MITEM_CLASS(x) ((struct _MItemClass*)x)
#define _MITEM_GETCLASS(x) _MITEM_CLASS(_MITEM(x)->m_clazz)

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#ifdef MINLINE


#endif

#endif /* MWT_WIDGETS_ITEM_H_ */
