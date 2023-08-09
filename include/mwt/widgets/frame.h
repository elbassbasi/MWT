/*
 *  frame.h
 *
 *  Created on: 09-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_WIDGETS_FRAME_H_
#define MWT_WIDGETS_FRAME_H_
#include "window.h"
#ifdef __cplusplus
	class MFrame;
	class MToolBar;
	class MButton;
#else
	typedef struct _MFrame MFrame;
	typedef struct _MToolBar MToolBar;
	typedef struct _MButton MButton;
#endif

enum {
	MSTYLE_FRAME_POPUP = 1 << 19,
	MSTYLE_FRAME_SHEET = 1 << 20,
	MSTYLE_FRAME_NO_MOVE = 1 << 21,
	MSTYLE_FRAME_TOOL = 1 << 22,

	MSTYLE_FRAME_NO_TRIM = 1 << 23,
	MSTYLE_FRAME_ON_TOP = 1 << 24,
	MSTYLE_FRAME_MODAL = 1 << 25,
	MSTYLE_FRAME_DISPOSE_ON_CLOSE = 1 << 26,
	MSTYLE_FRAME_TITLE = 1 << 27,
	MSTYLE_FRAME_CLOSE = 1 << 28,
	MSTYLE_FRAME_MIN = 1 << 29,
	MSTYLE_FRAME_MAX = 1 << 30,
	MSTYLE_FRAME_RESIZE = 1 << 31,
	MSTYLE_FRAME_TRIM = MSTYLE_FRAME_CLOSE | MSTYLE_FRAME_MIN | MSTYLE_FRAME_MAX | MSTYLE_FRAME_RESIZE,
	MSTYLE_DIALOG_TRIM = MSTYLE_FRAME_CLOSE | MSTYLE_BORDER,
};

struct _MFrame {
	struct _MWindow widget;
	void* m_pData[20];//reserved for platform
};

struct _MFrameClass {
	struct _MWindowClass m_widget;
};

#define _MFRAME(x) ((struct _MFrame*)x)
#define _MFRAME_CLASS(x) ((struct _MFrameClass*)x)
#define _MFRAME_GETCLASS(x) _MFRAME_CLASS(_MRESOURCE_GETCLASS(x))

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
#ifdef MINLINE


#endif
#endif /* MWT_WIDGETS_FRAME_H_ */
