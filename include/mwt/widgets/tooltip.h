/*
 * tooltip.h
 *
 *  Created on: 04-08-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWT_WIDGETS_TOOLTIP_H_
#define MWT_WIDGETS_TOOLTIP_H_
#include "widget.h"

struct _MToolTip {
	struct _MWidget m_widget;
};

struct _MToolTipClass {
	struct _MWidgetClass m_widget;
};

#define _MTOOLTIP(x) ((struct _MToolTip*)x)
#define _MTOOLTIP_CLASS(x) ((struct _MToolTipClass*)x)
#define _MTOOLTIP_GETCLASS(x) _MTOOLTIP_CLASS(_MRESOURCE_GETCLASS(x))

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
#ifdef MINLINE


#endif



#endif /* MWT_WIDGETS_TOOLTIP_H_ */
