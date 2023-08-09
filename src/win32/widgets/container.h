/*
 * container.h
 *
 *  Created on: 29-07-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef SRC_WIN32_WIDGETS_CONTAINER_H_
#define SRC_WIN32_WIDGETS_CONTAINER_H_
#include "widget.h"
struct _WinContainerPrivClass {
	WinWidgetPrivClass widget;
};
typedef struct _WinContainerPrivClass WinContainerPrivClass;
#define WIN_CONTAINER_PRIV(x) ((WinContainerPrivClass*)x)



#endif /* SRC_WIN32_WIDGETS_CONTAINER_H_ */
