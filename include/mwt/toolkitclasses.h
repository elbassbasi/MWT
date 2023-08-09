/*
 *  toolkitclasses.h
 *
 *  Created on: 13-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_TOOLKITCLASSES_H_
#define MWT_TOOLKITCLASSES_H_
#include "mwt.h"

struct _MToolkitAllClasses {
	struct _MResourceClass* classes[MCLASS_LAST];
	struct _MToolkitClass m_toolkit;
	struct _MFrameClass m_frame;
};

#ifdef __cplusplus
extern "C" {
#endif

MEXPORT void m_toolkit_init_classes(struct _MToolkitAllClasses* classes);
#ifdef __cplusplus
}
#endif


#endif /* MWT_TOOLKITCLASSES_H_ */
