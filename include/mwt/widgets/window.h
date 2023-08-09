/*
 * window.h
 *
 *  Created on: 06-08-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWT_WIDGETS_WINDOW_H_
#define MWT_WIDGETS_WINDOW_H_
#include "container.h"
#ifdef __cplusplus
	class MWindow;
#else
	typedef struct _MWindow MWindow;
#endif

struct _MWindow {
	struct _MContainer widget;
	void* m_pData[20];//reserved for platform
};

struct _MWindowClass {
	struct _MContainerClass m_widget;
};

#define _MWINDOW(x) ((struct _MWindow*)x)
#define _MWINDOW_CLASS(x) ((struct _MWindowClass*)x)
#define _MWINDOW_GETCLASS(x) _MWINDOW_CLASS(_MRESOURCE_GETCLASS(x))

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
#ifdef MINLINE


#endif
#endif /* MWT_WIDGETS_WINDOW_H_ */
