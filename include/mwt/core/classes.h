/*
 *  classes.h
 *
 *  Created on: 08-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_CORE_CLASSES_H_
#define MWT_CORE_CLASSES_H_
#include "defs.h"

typedef enum MClassID {
	MCLASS_UNKNOWN = 0,
	MCLASS_APP,
	MCLASS_WIDGET,
	MCLASS_MENU,
	MCLASS_TOOLTIP,
	MCLASS_WIDGET0,//reserved
	MCLASS_WIDGET1,//reserved
	MCLASS_WIDGET2,//reserved
	MCLASS_WIDGET3,//reserved
	MCLASS_CONTROL,
	MCLASS_CONTROL0,//reserved
	MCLASS_CONTROL1,//reserved
	MCLASS_CONTROL2,//reserved
	MCLASS_CONTROL3,//reserved
	MCLASS_CONTROL4,//reserved
	MCLASS_CONTROL5,//reserved
	MCLASS_CONTAINER,
	MCLASS_BOX,
	MCLASS_WINDOW,
	MCLASS_FRAME,
	MCLASS_LAST,
}MClassID;




#endif /* MWT_CORE_CLASSES_H_ */
