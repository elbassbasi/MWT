/*
 *  frame.c
 *
 *  Created on: 13-07-2023
 *  Author: azeddine El Bassbasi
 */
#include "frame.h"
#include "toolkit.h"
DWORD win_frame_widget_extstyle(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args) {
	DWORD bits = win_widget_widget_extstyle(widget,priv,args);
	bits &= ~WS_EX_CLIENTEDGE;
	MUInt64 style = args->style;
	if ((style & MSTYLE_FRAME_NO_TRIM) != 0)
		return bits;
	if ((style & MSTYLE_FRAME_RESIZE) != 0)
		return bits;
	if ((style & MSTYLE_BORDER) != 0)
		bits |= WS_EX_DLGMODALFRAME;
	if ((style & MSTYLE_FRAME_TOOL) != 0)
		bits |= WS_EX_TOOLWINDOW;

	MContainer *parent = args->parent;
	if (parent == 0) {
		if ((style & MSTYLE_FRAME_ON_TOP) != 0) {
			int trim = MSTYLE_FRAME_TITLE | MSTYLE_FRAME_CLOSE | MSTYLE_FRAME_MIN | MSTYLE_FRAME_MAX;
			if ((style & MSTYLE_FRAME_NO_TRIM) != 0 || (style & trim) == 0) {
				bits |= WS_EX_TOOLWINDOW;
			}
		}
	}
	if (parent != 0) {
		if (WIN32_VERSION(priv) < VERSION(4, 10)) {
			return bits;
		}
	}
	if ((style & MSTYLE_FRAME_ON_TOP) != 0)
		bits |= WS_EX_TOPMOST;
	return bits;
}
DWORD win_frame_widget_style(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args) {
	DWORD bits = win_widget_widget_style(widget,priv,args);
	bits |= WS_CLIPCHILDREN;
	bits &= ~(WS_TABSTOP | WS_VISIBLE | WS_BORDER);
	MUInt64 style = args->style;

	// Set the title bits and no-trim bits
	if ((style & MSTYLE_FRAME_NO_TRIM) != 0) {
		if (args->parent == 0) {
			bits |= WS_SYSMENU | WS_MINIMIZEBOX;
		}
		return bits;
	}
	if ((style & MSTYLE_FRAME_TITLE) != 0)
		bits |= WS_CAPTION;

	// Set the min and max button bits
	if ((style & MSTYLE_FRAME_MIN) != 0)
		bits |= WS_MINIMIZEBOX;
	if ((style & MSTYLE_FRAME_MAX) != 0)
		bits |= WS_MAXIMIZEBOX;

	// Set the resize, dialog border or border bits
	if ((style & MSTYLE_FRAME_RESIZE) != 0) {
		bits |= WS_THICKFRAME;
	} else {
		if ((style & MSTYLE_BORDER) == 0)
			bits |= WS_BORDER;
	}

	// Set the system menu and close box bits
	if ((style & MSTYLE_FRAME_CLOSE) != 0)
		bits |= WS_SYSMENU;
	if (args->reserved != 0)
		return bits | WS_CHILD;
	bits &= ~WS_CHILD;
	return bits | WS_OVERLAPPED | WS_CAPTION;
}

MResult win_frame_class_init_0(WinToolkit *toolkit,struct _MWidgetClass* clazz){
	MResult ret = win_widget_class_init_0(toolkit,clazz);
	WinWidgetPrivClass* privClazz = WIN_CLASS_PRIV(clazz);
	privClazz->widget_style = win_frame_widget_style;
	privClazz->widget_extstyle = win_frame_widget_extstyle;
	return ret;
}
MResult win_frame_class_init(WinToolkit *toolkit,MClassID clazz_id,struct _MResourceClass* clazz){
	clazz->m_classID = clazz_id;
	clazz->m_PlatClass = clazz;
	clazz->reserved[0] = &toolkit->privFrame;
	return win_frame_class_init_0(toolkit,_MWIDGET_CLASS(clazz));
}
