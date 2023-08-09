/*
 *  widget.c
 *
 *  Created on: 13-07-2023
 *  Author: azeddine El Bassbasi
 */
#include "widget.h"
#include "toolkit.h"
MResult win_widget_create_handle(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args){
	HWND hwndParent = priv->widget_parent(widget, priv,args);
	WCHAR *_clazz = priv->window_class(widget, priv,args);
	DWORD style, extstyle;
	style = priv->widget_style(widget, priv,args);
	extstyle = priv->widget_extstyle(widget, priv,args);
	HWND handle = _CreateWindowEx(priv->toolkit,extstyle, _clazz, 0, style, CW_USEDEFAULT, 0,
	CW_USEDEFAULT, 0, hwndParent, 0, hinst, 0);
	if (handle == 0)
		return MERROR_NO_HANDLES;
	_SetWindowLongPtr(priv->toolkit,handle, GWLP_USERDATA,(LONG_PTR) widget);
	_MRESOURCE(widget)->m_handle = handle;
	priv->add_parent(widget,priv,args);
	/*priv->subclass(control, priv);
	if (win_toolkit->IsDBLocale && hwndParent != 0) {
		HIMC hIMC = ImmGetContext(hwndParent);
		ImmAssociateContext(handle, hIMC);
		ImmReleaseContext(hwndParent, hIMC);
	}*/
	return MTRUE;
}
MResult win_widget_create_widget(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args){
	return priv->create_handle(widget,priv,args);
}
HWND win_widget_widget_parent(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args) {
	MWidget* parent = _MWIDGET(args->parent);
	if(parent == 0) return 0;
	else return (HWND)parent->resource.m_handle;
}
WCHAR* win_widget_window_class(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args) {
	return WindowClasses[_WINDOW_CLASS];
}
DWORD win_widget_widget_style(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args) {
	MUInt64 style = args->style;
	// Force clipping of siblings by setting WS_CLIPSIBLINGS
	DWORD bits = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS;
	if ((style & MSTYLE_BORDER) != 0)
		bits |= WS_BORDER;
	return bits;
}
DWORD win_widget_widget_extstyle(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args) {
	DWORD bits = 0;
	MUInt64 style = args->style;
	if ((style & MSTYLE_BORDER) != 0)
		bits |= WS_EX_CLIENTEDGE;
	if (WIN32_VERSION(priv) < VERSION(4, 10)) {
		return bits;
	}
	return bits;
}
MResult win_widget_add_parent(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args){
	return MTRUE;
}
HWND win_widget_handle_top(MWidget *widget,WinWidgetPrivClass *priv){
	return (HWND)_MRESOURCE(widget)->m_handle;
}
MResult win_widget_set_visible(MWidget *widget, int visible) {
	WinWidgetPrivClass *priv = win_get_priv(_MRESOURCE(widget));
	HWND tophandle = priv->handle_top(widget,priv);
	int v;
	if (visible)
		v = SW_SHOWDEFAULT;
	else
		v = SW_HIDE;

	_ShowWindow(priv->toolkit,tophandle, v);
	return MTRUE;
}
MResult win_widget_post_event(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e){
	e->result = _DefWindowProc(priv->toolkit,e->hwnd,e->msg,e->wparam,e->lparam);
	return MTRUE;
}
LRESULT win_widget_window_proc(MWidget *widget,WinWidgetPrivClass *priv,HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam){
	return 0;
}
LRESULT win_widget_call_window_proc(MWidget *widget,WinWidgetPrivClass *priv,HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam){
	return _DefWindowProc(priv->toolkit,hwnd, msg, wparam, lparam);
}
MResult win_widget_create(MResource *resource,MToolkit* toolkit,struct _MResourceClass* clazz,void* args){
	struct _MResourceClass* platformClazz = clazz->m_PlatClass;
	if(platformClazz->m_toolkit != (MToolkit*)_wintoolkit){
		return MERROR_INVALID_TOOLKIT;
	}
	WinWidgetPrivClass* privClazz = WIN_CLASS_PRIV(platformClazz);
	MResult ret = privClazz->create_widget(_MWIDGET(resource),privClazz,(struct _MWidgetCreate*)args);
	if(ret > 0){
		resource->m_clazz = clazz;
	}
	return ret;
}
MResult win_widget_class_init_0(WinToolkit *toolkit,struct _MWidgetClass* clazz){
	WinWidgetPrivClass* privClazz = WIN_CLASS_PRIV(clazz);
	privClazz->toolkit = toolkit;
	privClazz->create_widget = win_widget_create_widget;
	privClazz->create_handle = win_widget_create_handle;
	privClazz->widget_parent = win_widget_widget_parent;
	privClazz->window_class = win_widget_window_class;
	privClazz->widget_style = win_widget_widget_style;
	privClazz->widget_extstyle = win_widget_widget_extstyle;
	privClazz->add_parent = win_widget_add_parent;
	privClazz->handle_top = win_widget_handle_top;
	privClazz->post_event = win_widget_post_event;
	privClazz->window_proc = win_widget_window_proc;
	privClazz->call_window_proc = win_widget_call_window_proc;

	clazz->set_visible = win_widget_set_visible;
	_MRESOURCE_CLASS(clazz)->m_toolkit = _MTOOLKIT(toolkit);
	_MRESOURCE_CLASS(clazz)->m_PlatClass = _MRESOURCE_CLASS(clazz);
	_MRESOURCE_CLASS(clazz)->create = win_widget_create;

	// messages
	WinDispatchMessage *msg = privClazz->messages;
	for (size_t i = 0; i < _WM_LAST; i++) {
		msg[i] = _WIDGET_WM_NULL;
	}
	msg[_WM_DESTROY] = _WIDGET_WM_DESTROY;
	msg[_WM_SIZE] = _WIDGET_WM_SIZE;
	msg[_WM_TIMER] = _WIDGET_WM_TIMER;
	msg[_WM_CREATE] = _WIDGET_WM_CREATE;
	msg[_WM_CTLCOLOR] = _WIDGET_WM_CTLCOLOR;
	msg[_WM_CAPTURECHANGED] = _WIDGET_WM_CAPTURECHANGED;
	msg[_WM_CHANGEUISTATE] = _WIDGET_WM_CHANGEUISTATE;
	msg[_WM_CHAR] = _WIDGET_WM_CHAR;
	msg[_WM_COMMAND] = _WIDGET_WM_COMMAND;
	msg[_WM_CONTEXTMENU] = _WIDGET_WM_CONTEXTMENU;
	msg[_WM_DRAWITEM] = _WIDGET_WM_DRAWITEM;
	msg[_WM_ERASEBKGND] = _WIDGET_WM_ERASEBKGND;
	msg[_WM_GETOBJECT] = _WIDGET_WM_GETOBJECT;
	msg[_WM_HELP] = _WIDGET_WM_HELP;
	msg[_WM_HSCROLL] = _WIDGET_WM_HSCROLL;
	msg[_WM_IME_CHAR] = _WIDGET_WM_IME_CHAR;
	msg[_WM_INPUTLANGCHANGE] = _WIDGET_WM_INPUTLANGCHANGE;
	msg[_WM_KEYDOWN] = _WIDGET_WM_KEYDOWN;
	msg[_WM_KEYUP] = _WIDGET_WM_KEYUP;
	msg[_WM_KILLFOCUS] = _WIDGET_WM_KILLFOCUS;
	msg[_WM_MEASUREITEM] = _WIDGET_WM_MEASUREITEM;
	msg[_WM_MOVE] = _WIDGET_WM_MOVE;
	msg[_WM_NCHITTEST] = _WIDGET_WM_NCHITTEST;
	msg[_WM_NOTIFY] = _WIDGET_WM_NOTIFY;
	msg[_WM_PAINT] = _WIDGET_WM_PAINT;
	msg[_WM_SETCURSOR] = _WIDGET_WM_SETCURSOR;
	msg[_WM_SETFOCUS] = _WIDGET_WM_SETFOCUS;
	msg[_WM_SYSCHAR] = _WIDGET_WM_SYSCHAR;
	msg[_WM_SYSCOMMAND] = _WIDGET_WM_SYSCOMMAND;
	msg[_WM_SYSKEYDOWN] = _WIDGET_WM_SYSKEYDOWN;
	msg[_WM_SYSKEYUP] = _WIDGET_WM_SYSKEYUP;
	msg[_WM_TABLET_FLICK] = _WIDGET_WM_TABLET_FLICK;
	msg[_WM_TOUCH] = _WIDGET_WM_TOUCH;
	msg[_WM_VSCROLL] = _WIDGET_WM_VSCROLL;
	msg[_WM_WINDOWPOSCHANGED] = _WIDGET_WM_WINDOWPOSCHANGED;
	msg[_WM_WINDOWPOSCHANGING] = _WIDGET_WM_WINDOWPOSCHANGING;
	msg[_WM_CTLCOLORCHILD] = _WIDGET_WM_CTLCOLORCHILD;
	msg[_WM_GETDLGCODE] = _WIDGET_WM_GETDLGCODE;

	//mouse message
	msg[_WM_LBUTTONDBLCLK] = _WIDGET_WM_LBUTTONDBLCLK;
	msg[_WM_LBUTTONDOWN] = _WIDGET_WM_LBUTTONDOWN;
	msg[_WM_LBUTTONUP] = _WIDGET_WM_LBUTTONUP;
	msg[_WM_MBUTTONDBLCLK] = _WIDGET_WM_MBUTTONDBLCLK;
	msg[_WM_MBUTTONDOWN] = _WIDGET_WM_MBUTTONDOWN;
	msg[_WM_MBUTTONUP] = _WIDGET_WM_MBUTTONUP;
	msg[_WM_MOUSEHOVER] = _WIDGET_WM_MOUSEHOVER;
	msg[_WM_MOUSELEAVE] = _WIDGET_WM_MOUSELEAVE;
	msg[_WM_MOUSEMOVE] = _WIDGET_WM_MOUSEMOVE;
	msg[_WM_MOUSEWHEEL] = _WIDGET_WM_MOUSEWHEEL;
	msg[_WM_RBUTTONDBLCLK] = _WIDGET_WM_RBUTTONDBLCLK;
	msg[_WM_RBUTTONDOWN] = _WIDGET_WM_RBUTTONDOWN;
	msg[_WM_RBUTTONUP] = _WIDGET_WM_RBUTTONUP;
	msg[_WM_XBUTTONDBLCLK] = _WIDGET_WM_XBUTTONDBLCLK;
	msg[_WM_XBUTTONDOWN] = _WIDGET_WM_XBUTTONDOWN;
	msg[_WM_XBUTTONUP] = _WIDGET_WM_XBUTTONUP;
	/*msg[_WM_MENUCHAR] = _WIDGET_WM_MENUCHAR;
	msg[_WM_MENUSELECT] = _WIDGET_WM_MENUSELECT;
	msg[_WM_MENUCOMMAND] = _WIDGET_WM_MENUCOMMAND;
	msg[_WM_INITMENUPOPUP] = _WIDGET_WM_INITMENUPOPUP;
	msg[_WM_UNINITMENUPOPUP] = _WIDGET_WM_UNINITMENUPOPUP;*/
	return MTRUE;
}
MResult win_widget_class_init(WinToolkit *toolkit,MClassID clazz_id,struct _MResourceClass* clazz){
	clazz->m_classID = clazz_id;
	clazz->m_PlatClass = clazz;
	clazz->reserved[0] = &toolkit->privWidget;
	return win_frame_class_init_0(toolkit,_MWIDGET_CLASS(clazz));
}
