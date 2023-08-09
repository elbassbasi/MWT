/*
 * events.h
 *
 *  Created on: 25-07-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWT_WIDGETS_EVENTS_H_
#define MWT_WIDGETS_EVENTS_H_
#include "../graphics/graphics.h"
#ifdef __cplusplus
	class MEvent;
	class MEventPlatform;
	class MEvent;
	class MEventMouse;
	class MEventKey;
#else
	typedef struct _MEvent MEvent;
	typedef struct _MEventPlatform MEventPlatform;
	typedef struct _MEvent MEvent;
	typedef struct _MEventMouse MEventMouse;
	typedef struct _MEventKey MEventKey;
#endif
enum {
	/*
	 * event type
	 */
	MEVENT_NONE = 0,
	MEVENT_PLATFORM,
	MEVENT_NOTIFYCHANGE,
	MEVENT_FREE_MEMORY,
	MEVENT_DISPOSE,
	MEVENT_KEYDOWN,
	MEVENT_KEYUP,
	MEVENT_MOUSEDOWN,
	MEVENT_MOUSEUP,
	MEVENT_MOUSEMOVE,
	MEVENT_MOUSEENTER,
	MEVENT_MOUSEEXIT,
	MEVENT_MOUSEDOUBLECLICK,
	MEVENT_PAINT,
	MEVENT_MOVE,
	MEVENT_RESIZE,
	MEVENT_SELECTION,
	MEVENT_DEFAULTSELECTION,
	MEVENT_FOCUSIN,
	MEVENT_FOCUSOUT,
	MEVENT_TOOLTIP_TEXT,
	MEVENT_ICONIFY,
	MEVENT_DEICONIFY,
	MEVENT_CLOSE,
	MEVENT_SHOW,
	MEVENT_HIDE,
	MEVENT_MODIFY,
	MEVENT_VERIFY,
	MEVENT_ACTIVATE,
	MEVENT_DEACTIVATE,
	MEVENT_HELP,
	MEVENT_DRAGDETECT,
	MEVENT_ARM,
	MEVENT_TRAVERSE,
	MEVENT_MOUSEHOVER,
	MEVENT_HARDKEYDOWN,
	MEVENT_HARDKEYUP,
	MEVENT_MENUDETECT,
	MEVENT_SETDATA,
	MEVENT_MOUSEVERTICALWHEEL,
	MEVENT_MOUSEHORIZONTALWHEEL,
	MEVENT_MOUSEWHEEL = MEVENT_MOUSEVERTICALWHEEL,
	MEVENT_SETTINGS,
	MEVENT_IMECOMPOSITION,
	MEVENT_ORIENTATIONCHANGE,
	MEVENT_SKIN,
	MEVENT_OPENDOCUMENT,
	MEVENT_TOUCH,
	MEVENT_GESTURE,
	MEVENT_ITEM_GET_TEXT,
	MEVENT_ITEM_SET_TEXT,
	MEVENT_ITEM_GET_ATTR,
	MEVENT_ITEM_SET_ATTR,
	MEVENT_ITEM_SELECTION,
	MEVENT_ITEM_DEFAULTSELECTION,
	MEVENT_ITEM_HELP,
	MEVENT_ITEM_DISPOSE,
	MEVENT_ITEM_ARM,
	MEVENT_ITEM_GET_CONTROL,
	MEVENT_ITEM_SET_CONTROL,
	MEVENT_ITEM_GET_MENU,
	MEVENT_ITEM_SET_MENU,
	MEVENT_ITEM_MEASURE,
	MEVENT_ITEM_ERASE,
	MEVENT_ITEM_PAINT,
	MEVENT_ITEM_CLOSE,
	MEVENT_ITEM_EXPAND,
	MEVENT_ITEM_COLLAPSE,
	MEVENT_ITEM_RESIZE,
	MEVENT_ITEM_SHOW,
	MEVENT_ITEM_HIDE,
	MEVENT_ITEM_MOVE,
	MEVENT_HSCROLL,
	MEVENT_VSCROLL,
	MEVENT_COMPUTE_SIZE,
	MEVENT_COMPUTE_TRIM,
	MEVENT_CLIENT_AREA,
	MEVENT_LAYOUTDETECT,
	MEVENT_TIMER,
	MEVENT_NOTIFY,
	/*
	 * Event Details
	 *
	 **/
	MCOMPOSITION_CHANGED = 1,
	MCOMPOSITION_OFFSET = 2,
	MCOMPOSITION_SELECTION = 3,
	MDRAG = 1,
	MTRAVERSE_MASK = 0xFFFC,
	MTRAVERSE_NONE = 0,
	MTRAVERSE_ESCAPE = 1 << 2,
	MTRAVERSE_RETURN = 1 << 3,
	MTRAVERSE_TAB_PREVIOUS = 1 << 4,
	MTRAVERSE_TAB_NEXT = 1 << 5,
	MTRAVERSE_ARROMPREVIOUS = 1 << 6,
	MTRAVERSE_ARROMNEXT = 1 << 7,
	MTRAVERSE_MNEMONIC = 1 << 8,
	MTRAVERSE_PAGE_PREVIOUS = 1 << 9,
	MTRAVERSE_PAGE_NEXT = 1 << 10,
	MGESTURE_BEGIN = 1 << 1,
	MGESTURE_END = 1 << 2,
	MGESTURE_ROTATE = 1 << 3,
	MGESTURE_SWIPE = 1 << 4,
	MGESTURE_MAGNIFY = 1 << 5,
	MGESTURE_PAN = 1 << 6,
	MTOUCHSTATE_DOWN = 1 << 0,
	MTOUCHSTATE_MOVE = 1 << 1,
	MTOUCHSTATE_UP = 1 << 2,
	MMENU_MOUSE = 0,
	MMENU_KEYBOARD = 1,
	MCHANGED = 1 << 1,
	MDEFER = 1 << 2,
	MNONE = 0,
	MDEFAULT = -1,
	MOFF = 0,
	MON = 1,
	MLOW = 1,
	MHIGH = 2,
};
struct _MEvent {
	MUInt type;
	MUInt time;
	struct _MEventPlatform *platform_event;
	struct _MWidget *widget;
	void *data; //reserved
};
#define _MEVENT(x) ((struct _MEvent*)x)
struct _MEventPlatform {
	struct _MEvent event;
	unsigned int msg;
	unsigned int result;
	void *handle;
	void *args[3];
};
#define _MEVENT_PLATFORM(x) ((struct _MEventPlatform*)x)

struct _MEventMouse {
	struct _MEvent event;
	union {
		struct {
			unsigned doit :1;
			unsigned unused :14;
			unsigned alt :1;
			unsigned shift :1;
			unsigned ctrl :1;
			unsigned button1 :1;
			unsigned button2 :1;
			unsigned button3 :1;
			unsigned command :1;
			unsigned button4 :1;
			unsigned button5 :1;
		};
		int detail;
	};
	MUShort clickcount;
	MUShort button;
	int x;
	int y;
};
struct _MEventKey {
	struct _MEvent event;
	union {
		struct {
			unsigned doit :1;
			unsigned unused :14;
			unsigned alt :1;
			unsigned shift :1;
			unsigned ctrl :1;
			unsigned button1 :1;
			unsigned button2 :1;
			unsigned button3 :1;
			unsigned command :1;
			unsigned button4 :1;
			unsigned button5 :1;
		};
		int detail;
	};
	int character;
	int keycode;
	int keylocation;
};



#endif /* MWT_WIDGETS_EVENTS_H_ */
