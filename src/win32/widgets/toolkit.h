/*
 *  toolkit.h
 *
 *  Created on: 13-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef SRC_WIN32_CORE_TOOLKIT_H_
#define SRC_WIN32_CORE_TOOLKIT_H_
#include <mwt/toolkitclasses.h>
#include "frame.h"
struct _WinToolkit {
	MToolkit m_toolkit;
	struct _MToolkitAllClasses classes;
	int win32_version;
	int comctrl32_version;
	int shell32_version;
	WinWidgetPrivClass privWidget;
	WinFramePrivClass privFrame;
	MUChar wm_msg[WM_USER + 0x10];
};

enum {
	_WINDOW_CLASS,
	_WINDOW_SHADOW_CLASS,
	_WINDOW_OWNDC_CLASS,
};
extern WCHAR *WindowClasses[];
extern WinToolkit* _wintoolkit;
extern HINSTANCE hinst;

#endif /* SRC_WIN32_CORE_TOOLKIT_H_ */
