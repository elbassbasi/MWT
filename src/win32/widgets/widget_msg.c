/*
 * widget_msg.c
 *
 *  Created on: 25-07-2023
 *      Author: azeddine El Bassbasi
 */
#include "widget.h"
#include "toolkit.h"
//#include <windows.h>
LRESULT win_toolkit_window_proc(HWND hwnd, UINT msg, WPARAM wparam,
		LPARAM lparam) {
	struct _MResourceClass *platClazz = 0;
	WinToolkit *winToolkit;
	MWidget *widget = (MWidget*) _GetWindowLongPtr(_wintoolkit, hwnd,
			GWLP_USERDATA);
	if (widget != 0) {
		struct _MResourceClass *clazz = _MRESOURCE_GETCLASS(widget);
		if (clazz != 0 && clazz->m_PlatClass != 0) {
			platClazz = clazz->m_PlatClass;
			winToolkit = (WinToolkit*) platClazz->m_toolkit;
			if(winToolkit != _wintoolkit) platClazz = 0;
		}
	}
	if (platClazz != 0) {
		WinWidgetPrivClass *privClass = _WIN_WIDGET_CLASS(
				platClazz->reserved[0]);
		const int wm_msg_size = sizeof(winToolkit->wm_msg)
				/ sizeof(winToolkit->wm_msg[0]);
		if (msg < wm_msg_size) {
			struct _WinEventPlatform e;
			e.msgId = winToolkit->wm_msg[msg];
			e.event.type = MEVENT_PLATFORM;
			e.event.widget = widget;
			e.event.platform_event = 0;
			e.event.data = 0;
			e.hwnd = hwnd;
			e.msg = msg;
			e.wparam = wparam;
			e.lparam = lparam;
			e.result = 0;
			privClass->post_event(widget, privClass, &e);
			return e.result;
		} else {
			return privClass->call_window_proc(widget, privClass, hwnd, msg,
					wparam, lparam);
		}
	} else {
		return _DefWindowProc(_wintoolkit, hwnd, msg, wparam, lparam);
	}
}
MUShort _wm_msg[] = { //
	[_WM_ACTIVATE] = WM_ACTIVATE, //
	[_WM_CAPTURECHANGED] = WM_CAPTURECHANGED, //
	[_WM_CHANGEUISTATE] = WM_CHANGEUISTATE, //
	[_WM_CHAR] = WM_CHAR, //
	[_WM_CLEAR] = WM_CLEAR, //
	[_WM_CLOSE] = WM_CLOSE, //
	[_WM_COMMAND] = WM_COMMAND, //
	[_WM_CONTEXTMENU] = WM_CONTEXTMENU, //
	[_WM_CUT] = WM_CUT, //
	[_WM_DESTROY] = WM_DESTROY, //
	[_WM_DRAWITEM] = WM_DRAWITEM, //
	[_WM_ENDSESSION] = WM_ENDSESSION, //
	[_WM_ENTERIDLE] = WM_ENTERIDLE, //
	[_WM_ERASEBKGND] = WM_ERASEBKGND, //
	//[_WM_GESTURE] = WM_GESTURE,//
	[_WM_GETDLGCODE] = WM_GETDLGCODE,			//
	[_WM_GETFONT] = WM_GETFONT,			//
	[_WM_GETOBJECT] = WM_GETOBJECT,			//
	[_WM_GETMINMAXINFO] = WM_GETMINMAXINFO,			//
	[_WM_HELP] = WM_HELP,			//
	[_WM_HSCROLL] = WM_HSCROLL,			//
	[_WM_IME_CHAR] = WM_IME_CHAR,			//
	[_WM_IME_COMPOSITION] = WM_IME_COMPOSITION,			//
	//[_WM_IME_COMPOSITION_START] = WM_IME_COMPOSITION_START,//
	[_WM_IME_ENDCOMPOSITION] = WM_IME_ENDCOMPOSITION,			//
	[_WM_INITMENUPOPUP] = WM_INITMENUPOPUP,			//
	[_WM_INPUTLANGCHANGE] = WM_INPUTLANGCHANGE,			//
	[_WM_HOTKEY] = WM_HOTKEY,			//
	[_WM_KEYDOWN] = WM_KEYDOWN,			//
	[_WM_KEYUP] = WM_KEYUP,			//
	[_WM_KILLFOCUS] = WM_KILLFOCUS,			//
	[_WM_LBUTTONDBLCLK] = WM_LBUTTONDBLCLK,			//
	[_WM_LBUTTONDOWN] = WM_LBUTTONDOWN,			//
	[_WM_LBUTTONUP] = WM_LBUTTONUP,			//
	[_WM_MBUTTONDBLCLK] = WM_MBUTTONDBLCLK,			//
	[_WM_MBUTTONDOWN] = WM_MBUTTONDOWN,			//
	[_WM_MBUTTONUP] = WM_MBUTTONUP,			//
	[_WM_MEASUREITEM] = WM_MEASUREITEM,			//
	[_WM_MENUCHAR] = WM_MENUCHAR,			//
	[_WM_MENUSELECT] = WM_MENUSELECT,			//
	[_WM_MOUSEACTIVATE] = WM_MOUSEACTIVATE,			//
	[_WM_MOUSEHOVER] = WM_MOUSEHOVER,			//
	[_WM_MOUSELEAVE] = WM_MOUSELEAVE,			//
	[_WM_MOUSEMOVE] = WM_MOUSEMOVE,			//
	[_WM_MOUSEWHEEL] = WM_MOUSEWHEEL,			//
	[_WM_MOUSEHWHEEL] = WM_MOUSEHWHEEL,			//
	[_WM_MOVE] = WM_MOVE,			//
	[_WM_NCACTIVATE] = WM_NCACTIVATE,			//
	[_WM_NCCALCSIZE] = WM_NCCALCSIZE,			//
	[_WM_NCHITTEST] = WM_NCHITTEST,			//
	[_WM_NCLBUTTONDOWN] = WM_NCLBUTTONDOWN,			//
	[_WM_NCPAINT] = WM_NCPAINT,			//
	[_WM_NOTIFY] = WM_NOTIFY,			//
	[_WM_PAINT] = WM_PAINT,			//
	[_WM_PALETTECHANGED] = WM_PALETTECHANGED,			//
	[_WM_PARENTNOTIFY] = WM_PARENTNOTIFY,			//
	[_WM_PASTE] = WM_PASTE,			//
	[_WM_PRINT] = WM_PRINT,			//
	[_WM_PRINTCLIENT] = WM_PRINTCLIENT,			//
	[_WM_QUERYENDSESSION] = WM_QUERYENDSESSION,			//
	[_WM_QUERYNEWPALETTE] = WM_QUERYNEWPALETTE,			//
	[_WM_QUERYOPEN] = WM_QUERYOPEN,			//
	[_WM_RBUTTONDBLCLK] = WM_RBUTTONDBLCLK,			//
	[_WM_RBUTTONDOWN] = WM_RBUTTONDOWN,			//
	[_WM_RBUTTONUP] = WM_RBUTTONUP,			//
	[_WM_SETCURSOR] = WM_SETCURSOR,			//
	[_WM_SETFOCUS] = WM_SETFOCUS,			//
	[_WM_SETFONT] = WM_SETFONT,			//
	[_WM_SETTINGCHANGE] = WM_SETTINGCHANGE,			//
	[_WM_SETREDRAW] = WM_SETREDRAW,			//
	[_WM_SHOWWINDOW] = WM_SHOWWINDOW,			//
	[_WM_SIZE] = WM_SIZE,			//
	[_WM_SYSCHAR] = WM_SYSCHAR,			//
	[_WM_SYSCOLORCHANGE] = WM_SYSCOLORCHANGE,			//
	[_WM_SYSCOMMAND] = WM_SYSCOMMAND,			//
	[_WM_SYSKEYDOWN] = WM_SYSKEYDOWN,			//
	[_WM_SYSKEYUP] = WM_SYSKEYUP,			//
	//[_WM_TABLET_FLICK] = WM_TABLET_FLICK,//
	[_WM_TIMER] = WM_TIMER,			//
	[_WM_TOUCH] = WM_TOUCH,			//
	[_WM_UNDO] = WM_UNDO,			//
	[_WM_UNINITMENUPOPUP] = WM_UNINITMENUPOPUP,			//
	[_WM_UPDATEUISTATE] = WM_UPDATEUISTATE,			//
	[_WM_VSCROLL] = WM_VSCROLL,			//
	[_WM_WINDOWPOSCHANGED] = WM_WINDOWPOSCHANGED,			//
	[_WM_WINDOWPOSCHANGING] = WM_WINDOWPOSCHANGING,			//
	[_WM_XBUTTONDBLCLK] = WM_XBUTTONDBLCLK,			//
	[_WM_XBUTTONDOWN] = WM_XBUTTONDOWN,			//
	[_WM_XBUTTONUP] = WM_XBUTTONUP,			//
	//[_WM_DPICHANGED] = WM_DPICHANGED,//
	[_WM_MENUCOMMAND] = WM_MENUCOMMAND,			//
};

void win_widget_init_messages(WinToolkit *toolkit) {
	MUChar *wm_msg = toolkit->wm_msg;
	for (int i = 0; i < sizeof(_wm_msg) / sizeof(_wm_msg[0]); i++) {
		wm_msg[_wm_msg[i]] = i;
	}
	wm_msg[0] = 0;
	wm_msg[WM_CTLCOLORMSGBOX] = _WM_CTLCOLOR;
	wm_msg[WM_CTLCOLOREDIT] = _WM_CTLCOLOR;
	wm_msg[WM_CTLCOLORLISTBOX] = _WM_CTLCOLOR;
	wm_msg[WM_CTLCOLORBTN] = _WM_CTLCOLOR;
	wm_msg[WM_CTLCOLORDLG] = _WM_CTLCOLOR;
	wm_msg[WM_CTLCOLORSCROLLBAR] = _WM_CTLCOLOR;
	wm_msg[WM_CTLCOLORSTATIC] = _WM_CTLCOLOR;

}
MResult _WIDGET_WM_NULL(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_DESTROY(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_CREATE(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_CTLCOLOR(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_CHANGEUISTATE(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_COMMAND(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_DRAWITEM(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_ERASEBKGND(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_GETOBJECT(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_GETDLGCODE(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_HELP(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_HSCROLL(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_INPUTLANGCHANGE(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_MEASUREITEM(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_MOVE(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_NCHITTEST(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_NOTIFY(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_PAINT(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_SETCURSOR(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_SIZE(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_SYSCOMMAND(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_TABLET_FLICK(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_TOUCH(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_TIMER(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_VSCROLL(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_WINDOWPOSCHANGED(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_WINDOWPOSCHANGING(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_CTLCOLORCHILD(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_NOTIFYCHILD(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_CAPTURECHANGED(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_CHAR(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_CONTEXTMENU(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_IME_CHAR(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_KEYDOWN(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_KEYUP(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_KILLFOCUS(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_SETFOCUS(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_SYSCHAR(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_SYSKEYDOWN(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_SYSKEYUP(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_MOUSEMOVE(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_LBUTTONDBLCLK(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_LBUTTONDOWN(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_LBUTTONUP(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_MBUTTONDBLCLK(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_MBUTTONDOWN(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_MBUTTONUP(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_MOUSEHOVER(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_MOUSELEAVE(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_MOUSEWHEEL(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_MOUSEHWHEEL(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_RBUTTONDBLCLK(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_RBUTTONDOWN(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_RBUTTONUP(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_XBUTTONDBLCLK(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_XBUTTONDOWN(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
MResult _WIDGET_WM_XBUTTONUP(MWidget *widget, WinWidgetPrivClass *priv,
		WinEventPlatform *e) {
	return MFALSE;
}
