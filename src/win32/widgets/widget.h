/*
 *  widget.h
 *
 *  Created on: 13-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef SRC_WIN32_WIDGETS_WIDGET_H_
#define SRC_WIN32_WIDGETS_WIDGET_H_
#include <mwt/mwt.h>
#include "../core/win32.h"
//#include <windows.h>
typedef enum WinMsgId {
	_WM_UNKNOWN = 0,
	// Keyboard messages
	_WM_KEYDOWN = 1,
	_WM_KEYUP,
	_WM_CHAR,
	_WM_IME_CHAR,
	_WM_SYSKEYDOWN,
	_WM_SYSKEYUP,
	_WM_SYSCHAR,
	// Mouse messages
	_WM_LBUTTONDBLCLK,
	_WM_LBUTTONDOWN,
	_WM_LBUTTONUP,
	_WM_MBUTTONDBLCLK,
	_WM_MBUTTONDOWN,
	_WM_MBUTTONUP,
	_WM_RBUTTONDBLCLK,
	_WM_RBUTTONDOWN,
	_WM_RBUTTONUP,
	_WM_XBUTTONDBLCLK,
	_WM_XBUTTONDOWN,
	_WM_XBUTTONUP,
	_WM_MOUSEACTIVATE,
	_WM_MOUSEHOVER,
	_WM_MOUSELEAVE,
	_WM_MOUSEMOVE,
	_WM_MOUSEWHEEL,
	_WM_MOUSEHWHEEL,
	// Scroll messages
	_WM_HSCROLL,
	_WM_VSCROLL,
	_WM_SCROLLCHILD,
	// Other messages
	_WM_ACTIVATE,
	_WM_CAPTURECHANGED,
	_WM_CHANGEUISTATE,
	_WM_CLEAR,
	_WM_CLOSE,
	_WM_COMMAND,
	_WM_CONTEXTMENU,
	_WM_CTLCOLOR,
	_WM_CUT,
	_WM_CREATE,
	_WM_DESTROY,
	_WM_DRAWITEM,
	_WM_ENDSESSION,
	_WM_ENTERIDLE,
	_WM_ERASEBKGND,
	_WM_GESTURE,
	_WM_GETDLGCODE,
	_WM_GETFONT,
	_WM_GETOBJECT,
	_WM_GETMINMAXINFO,
	_WM_HELP,
	_WM_IME_COMPOSITION,
	_WM_IME_COMPOSITION_START,
	_WM_IME_ENDCOMPOSITION,
	_WM_INITMENUPOPUP,
	_WM_INPUTLANGCHANGE,
	_WM_HOTKEY,
	_WM_KILLFOCUS,
	_WM_MEASUREITEM,
	_WM_MENUCHAR,
	_WM_MENUSELECT,
	_WM_MOVE,
	_WM_NCACTIVATE,
	_WM_NCCALCSIZE,
	_WM_NCHITTEST,
	_WM_NCLBUTTONDOWN,
	_WM_NCPAINT,
	_WM_NOTIFY,
	_WM_PAINT,
	_WM_PALETTECHANGED,
	_WM_PARENTNOTIFY,
	_WM_PASTE,
	_WM_PRINT,
	_WM_PRINTCLIENT,
	_WM_QUERYENDSESSION,
	_WM_QUERYNEWPALETTE,
	_WM_QUERYOPEN,
	_WM_SETCURSOR,
	_WM_SETFOCUS,
	_WM_SETFONT,
	_WM_SETTINGCHANGE,
	_WM_SETREDRAW,
	_WM_SHOWWINDOW,
	_WM_SIZE,
	_WM_SYSCOLORCHANGE,
	_WM_SYSCOMMAND,
	_WM_TABLET_FLICK,
	_WM_TIMER,
	_WM_TOUCH,
	_WM_UNDO,
	_WM_UNINITMENUPOPUP,
	_WM_UPDATEUISTATE,
	_WM_WINDOWPOSCHANGED,
	_WM_WINDOWPOSCHANGING,
	_WM_DPICHANGED,
	_WM_MENUCOMMAND,
	_WM_CTLCOLORCHILD,
	_WM_NOTIFYCHILD,
	_WM_COMMANDCHILD,
	_WM_DRAWCHILD,
	_WM_MEASURECHILD,
	_WM_LAST
} WinMsgId;
struct _WinEventPlatform {
	struct _MEvent event;
	WinMsgId msgId;
	MUInt msg;
	LRESULT result;
	HWND hwnd;
	WPARAM wparam;
	LPARAM lparam;
};
typedef struct _WinEventPlatform WinEventPlatform;
typedef struct _WinWidgetPrivClass WinWidgetPrivClass;
#define WIN_WIDGET_PRIV(x) ((WinWidgetPrivClass*)x)
#define WINTOOLKIT(x) ((WinToolkit*)x)

#define WIN_CLASS_PRIV(clazz) WIN_WIDGET_PRIV(_MRESOURCE_CLASS(clazz)->reserved[0])

MINLINE WinWidgetPrivClass *win_get_priv(MResource* resource){
	return (WinWidgetPrivClass *)resource->m_clazz->m_PlatClass->reserved[0];
}

typedef MResult (*WinDispatchMessage)(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
struct _WinWidgetPrivClass {
	int flags;
	WinToolkit* toolkit;
	WNDPROC def_window_proc;
	void (*destroy)(MWidget *widget);
	WinDispatchMessage messages[_WM_LAST];
	MResult (*post_event)(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
	LRESULT (*window_proc)(MWidget *widget,WinWidgetPrivClass *priv,HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam);
	LRESULT (*call_window_proc)(MWidget *widget,WinWidgetPrivClass *priv,HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam);
	WNDPROC* (*get_def_window_proc)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*create_widget)(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
	MResult (*create_handle)(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
	HWND (*widget_parent)(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
	WCHAR* (*window_class)(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
	DWORD (*widget_style)(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
	DWORD (*widget_extstyle)(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
	MResult (*add_parent)(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
	HWND (*handle_top)(MWidget *widget,WinWidgetPrivClass *priv);
	HWND (*handle_border)(MWidget *widget,WinWidgetPrivClass *priv);
	MUInt64 (*check_style)(MWidget *widget,struct _MWidgetCreate* args);
	MResult (*check_orientation)(MWidget *widget,WinWidgetPrivClass *priv, MContainer *parent);
	MResult (*subclass)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*unsubclass)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*check_background)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*check_buffered)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*check_composited)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*set_default_font)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*check_mirrored)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*check_border)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*check_gesture)(MWidget *widget,WinWidgetPrivClass *priv);
	void (*draw_background)(MWidget *widget,WinWidgetPrivClass *priv, HDC hDC, RECT *rect, int pixel,
			int tx, int ty);
	void (*fill_background)(MWidget *widget,WinWidgetPrivClass *priv, HDC hDC, int pixel, RECT *rect);
	int (*get_background_pixel)(MWidget *widget,WinWidgetPrivClass *priv);
	int (*get_foreground_pixel)(MWidget *widget,WinWidgetPrivClass *priv);
	int (*default_background)(MWidget *widget,WinWidgetPrivClass *priv);
	int (*default_foreground)(MWidget *widget,WinWidgetPrivClass *priv);
	HFONT (*default_font)(MWidget *widget,WinWidgetPrivClass *priv);
	MWidget* (*find_background_control)(MWidget *widget,WinWidgetPrivClass *priv);
	MWidget* (*find_image_control)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*set_background)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*compute_size)(MWidget *widget,WinWidgetPrivClass *priv, MSize* size);
	MResult (*get_client_area)(MWidget *widget,WinWidgetPrivClass *priv, MRect* area);
	MResult (*compute_trim)(MWidget *widget,WinWidgetPrivClass *priv, MRect* rect,MRect* result);
	MResult (*set_cursor_0)(MWidget *widget,WinWidgetPrivClass *priv);
	MCursor* (*find_cursor)(MWidget *widget,WinWidgetPrivClass *priv);
	MResult (*translate_accelerator)(MWidget *widget,WinWidgetPrivClass *priv, MSG *msg);
	MResult (*translate_mnemonic)(MWidget *widget,WinWidgetPrivClass *priv, MSG *msg);
	MResult (*translate_traversal)(MWidget *widget,WinWidgetPrivClass *priv, MSG *msg);
	MResult (*traverse)(MWidget *widget,WinWidgetPrivClass *priv, struct _MEventKey *event);
	MResult (*traverse_mnemonic)(MWidget *widget,WinWidgetPrivClass *priv, int key);
	MResult (*mnemonic_hit)(MWidget *widget,WinWidgetPrivClass *priv, int key);
};

//#define _WIN_WIDGET(x) ((MWIDGET*)x)
#define _WIN_WIDGET_CLASS(x) ((WinWidgetPrivClass*)x)

typedef struct WinWidgetPriv {

}WinWidgetPriv;


void win_widget_init_messages(WinToolkit *toolkit);
MResult win_widget_class_init_0(WinToolkit *toolkit,struct _MWidgetClass* clazz);
MResult win_widget_class_init(WinToolkit *toolkit,MClassID clazz_id,struct _MResourceClass* clazz);

MResult win_widget_create_0(WinToolkit* toolkit,MClassID clazz_id,MResource* resource,void* args,WinWidgetPrivClass* priv);

MResult win_widget_check_background(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_check_border(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_check_buffered(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_check_composited(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_check_gesture(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_check_mirrored(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_check_orientation(MWidget *widget,WinWidgetPrivClass *priv, MContainer *parent);
MUInt64 win_widget_check_style(MWidget *widget, MUInt64 style);
MResult win_widget_create_handle(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
MResult win_widget_create_widget(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
MResult win_widget_dispose(MWidget *widget);
MResult win_widget_drag_detect(MWidget *widget, MEventMouse *event);
MResult win_widget_force_focus(MWidget *widget);
HBRUSH win_widget_find_brush(ULONG_PTR value, int lbStyle);
MResult win_widget_get_background(MWidget *widget, MColor *background);
MResult win_widget_get_background_image(MWidget *widget, MImage *image);
MResult win_widget_get_border_width(MWidget *widget);
MResult win_widget_get_bounds(MWidget *widget, struct _MPoint *location,
		struct _MSize *size);
MResult win_widget_get_client_area(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_get_cursor(MWidget *widget, MCursor **cursor);
MResult win_widget_get_drag_detect(MWidget *widget);
MResult win_widget_get_drawing(MWidget *widget);
MResult win_widget_get_enabled(MWidget *widget);
MResult win_widget_get_font(MWidget *widget, MFont **font);
MResult win_widget_get_foreground(MWidget *widget, MColor *foreground);
MResult win_widget_get_graphics(MWidget *widget, MGraphics *gc);
MResult win_widget_get_layout_data(MWidget *widget, void **data);
MResult win_widget_get_menu(MWidget *widget, MMenu **menu);
MResult win_widget_get_orientation(MWidget *widget);
MResult win_widget_get_parent(MWidget *widget, MContainer **parent);
MResult win_widget_get_region(MWidget *widget, MRegion *region);
MResult win_widget_get_frame(MWidget *widget, MFrame **shell);
MResult win_widget_get_tab(MWidget *widget);
MResult win_widget_get_text_direction(MWidget *widget);
MResult win_widget_get_touch_enabled(MWidget *widget);
MResult win_widget_get_visible(MWidget *widget);
HWND win_widget_handle(MWidget *widget);
void win_widget_init_graphics(MWidget *widget, MGraphics *gc, HDC hDC,
		int style);
MResult win_widget_is_enabled(MWidget *widget);
MResult win_widget_is_focus_control(MWidget *widget);
MResult win_widget_is_reparentable(MWidget *widget);
MResult win_widget_is_visible(MWidget *widget);
MResult win_widget_kill_timer(MWidget *widget, MUShort id);
MResult win_widget_move_above(MWidget *widget, MWidget *_control);
MResult win_widget_move_below(MWidget *widget, MWidget *_control);
MResult win_widget_new_layout_data(MWidget *widget, void **data,
		size_t size);
MResult win_widget_pack(MWidget *widget, int flags);
MResult win_widget_print(MWidget *widget, MGraphics *gc);
MResult win_widget_request_layout(MWidget *widget);
MResult win_widget_redraw(MWidget *widget, struct _MRect *rect, int all);
MResult win_widget_set_background(MWidget *widget, MColor color);
MResult win_widget_set_background_0(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_set_background_image(MWidget *widget, MImage *image);
MResult win_widget_set_bounds(MWidget *widget, struct _MPoint *location,
		struct _MSize *size);
MResult win_widget_set_capture(MWidget *widget, int capture);
MResult win_widget_set_cursor(MWidget *widget, MCursor *cursor);
MResult win_widget_set_default_font(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_set_drag_detect(MWidget *widget, int dragDetect);
MResult win_widget_set_enabled(MWidget *widget, int enabled);
MResult win_widget_set_focus(MWidget *widget);
MResult win_widget_set_font(MWidget *widget, MFont *font);
MResult win_widget_set_foreground(MWidget *widget, MColor color);
MResult win_widget_set_menu(MWidget *widget, MMenu *menu);
MResult win_widget_set_orientation(MWidget *widget, int orientation);
MResult win_widget_set_parent(MWidget *widget, MContainer *parent);
MResult win_widget_set_redraw(MWidget *widget, int redraw);
MResult win_widget_set_region(MWidget *widget, MRegion *region);
MResult win_widget_set_tab(MWidget *widget, int tab);
MResult win_widget_set_text_direction(MWidget *widget, int textDirection);
MResult win_widget_set_timer(MWidget *widget, MUInt64 ms, MUShort id);
MResult win_widget_set_tooltip_text(MWidget *widget, const char *text,
		int length, int enc);
MResult win_widget_set_touch_enabled(MWidget *widget, int enabled);
MResult win_widget_set_visible(MWidget *widget, int visible);
MResult win_widget_subclass(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_to_control(MWidget *widget, struct _MPoint *result,
		struct _MPoint *point);
MResult win_widget_to_display(MWidget *widget, struct _MPoint *result,
		struct _MPoint *point);
MResult win_widget_translate_accelerator(MWidget *widget,WinWidgetPrivClass *priv, MSG *msg);
MResult win_widget_traverse(MWidget *widget, int traversal,
		MEventKey *event);
MResult win_widget_unsubclass(MWidget *widget,WinWidgetPrivClass *priv);
MResult win_widget_update(MWidget *widget);
DWORD win_widget_widget_style(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
DWORD win_widget_widget_extstyle(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
HWND win_widget_widget_parent(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
WCHAR* win_widget_window_class(MWidget *widget,WinWidgetPrivClass *priv,struct _MWidgetCreate* args);
/*
 * messages
 */
MResult _WIDGET_WM_NULL(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_DESTROY(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_CREATE(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_CTLCOLOR(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_CHANGEUISTATE(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_COMMAND(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_DRAWITEM(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_ERASEBKGND(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_GETOBJECT(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_GETDLGCODE(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_HELP(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_HSCROLL(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_INPUTLANGCHANGE(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_MEASUREITEM(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_MOVE(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_NCHITTEST(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_NOTIFY(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_PAINT(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_SETCURSOR(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_SIZE(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_SYSCOMMAND(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_TABLET_FLICK(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_TOUCH(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_TIMER(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_VSCROLL(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_WINDOWPOSCHANGED(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_WINDOWPOSCHANGING(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_CTLCOLORCHILD(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_NOTIFYCHILD(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_CAPTURECHANGED(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_CHAR(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_CONTEXTMENU(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_IME_CHAR(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_KEYDOWN(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_KEYUP(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_KILLFOCUS(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_SETFOCUS(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_SYSCHAR(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_SYSKEYDOWN(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_SYSKEYUP(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_MOUSEMOVE(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_LBUTTONDBLCLK(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_LBUTTONDOWN(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_LBUTTONUP(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_MBUTTONDBLCLK(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_MBUTTONDOWN(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_MBUTTONUP(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_MOUSEHOVER(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_MOUSELEAVE(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_MOUSEWHEEL(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_MOUSEHWHEEL(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_RBUTTONDBLCLK(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_RBUTTONDOWN(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_RBUTTONUP(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_XBUTTONDBLCLK(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_XBUTTONDOWN(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
MResult _WIDGET_WM_XBUTTONUP(MWidget *widget,WinWidgetPrivClass *priv,WinEventPlatform* e);
#endif /* SRC_WIN32_WIDGETS_WIDGET_H_ */
