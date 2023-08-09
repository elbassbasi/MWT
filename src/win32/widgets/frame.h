/*
 *  frame.h
 *
 *  Created on: 13-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef SRC_WIN32_WIDGETS_FRAME_H_
#define SRC_WIN32_WIDGETS_FRAME_H_
#include "container.h"

struct _WinFramePrivClass {
	WinContainerPrivClass container;
};
typedef struct _WinFramePrivClass WinFramePrivClass;
#define WIN_FRAME_PRIV(x) ((WinFramePrivClass*)x)

MResult win_frame_class_init_0(WinToolkit *toolkit,struct _MWidgetClass* clazz);
MResult win_frame_class_init(WinToolkit *toolkit,MClassID clazz_id,struct _MResourceClass* clazz);

#endif /* SRC_WIN32_WIDGETS_FRAME_H_ */
