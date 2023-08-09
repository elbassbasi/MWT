/*
 *  widget.h
 *
 *  Created on: 09-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_WIDGETS_WIDGET_H_
#define MWT_WIDGETS_WIDGET_H_
#include "events.h"
#ifdef __cplusplus
	class MWidget;
	class MMenu;
	class MEvent;
	class MContainer;
	class MImage;
#else
	typedef struct _MWidget MWidget;
	typedef struct _MMenu MMenu;
	typedef struct _MEvent MEvent;
	typedef struct _MContainer MContainer;
	typedef struct _MImage MImage;
#endif
typedef struct _MSignal MSignal;
typedef MResult (*MCallback)(MWidget* widget,MSignal *signal,MEvent* e);
struct _MSignal {
	MUShort m_id;
	MUShort m_flags;
	MCallback m_callback;
	void (*m_destroy)(struct _MSignal* signal);
	void* m_userdata;
	void* m_reserved[3];
};

typedef struct _MSignalTable {
	struct _MSignalTable* next;
	MUInt count;
	struct _MSignal signals[0x10];
}MSignalTable;

enum {
	MSTYLE_BORDER= 1 << 0,
	MSTYLE_CLIP_CHILDREN = 1 << 1,
	MSTYLE_CLIP_SIBLINGS = 1 << 2,
	MSTYLE_LEFT_TO_RIGHT = 1 << 3,
	MSTYLE_RIGHT_TO_LEFT = 1 << 4,
	MSTYLE_HORIZONTAL = 1 << 5,
	MSTYLE_VERTICAL = 0 << 5,
};

struct _MWidget {
	struct _MResource resource;
	MSignalTable* m_signals;
	MWidget* m_parent;
	MWidget* m_nextSibling;
	MWidget* m_prevSibling;
	MWidget* m_firstChild;
	MCursor* m_cursor;
	MFont* m_font;
	MUInt m_childCount;
	struct _MRect m_bounds;
	MColor background;
	MColor foreground;
	void* m_pData[10];//reserved for platform
	void* m_lData[10];//reserved for layout
};

struct _MWidgetClass {
	struct _MResourceClass m_resource;
	MResult (*set_visible)(MWidget *widget, int visible);
};

#define _MWIDGET(x) ((struct _MWidget*)x)
#define _MWIDGET_CLASS(x) ((struct _MWidgetClass*)x)
#define _MWIDGET_GETCLASS(x) _MWIDGET_CLASS(_MRESOURCE_GETCLASS(x))

struct _MWidgetCreate{
	MContainer* parent;
	MUInt64 style;
	void *reserved;
};
#ifdef __cplusplus
extern "C" {
#endif
MEXPORT MResult m_widget_create(MWidget* widget,MToolkit* toolkit,MClassID clazz_id,MContainer* parent,MUInt64 style);
MEXPORT MResult m_widget_post_event(MWidget* widget,MEvent *e);
#ifdef __cplusplus
}
#endif
#ifdef MINLINE

MINLINE MResult m_widget_set_visible(MWidget *widget, int visible){
	_MRESOURCE_INVOKE_R_1(_MWIDGET,set_visible,widget,visible);
}

#endif

#endif /* MWT_WIDGETS_WIDGET_H_ */
