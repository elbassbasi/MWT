/*
 *  rect.h
 *
 *  Created on: 23-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_GRAPHICS_RECT_H_
#define MWT_GRAPHICS_RECT_H_
#include "../core/resource.h"
#ifdef __cplusplus
	class MPoint;
	class MPointF;
	class MSize;
	class MSizeF;
	class MRect;
	class MRectF;
	class MRange;
#else
	typedef struct _MPoint MPoint;
	typedef struct _MPointF MPointF;
	typedef struct _MSize MSize;
	typedef struct _MSizeF MSizeF;
	typedef struct _MRect MRect;
	typedef struct _MRectF MRectF;
	typedef struct _MRange MRange;
#endif

struct _MPoint {
	int x;
	int y;
};
struct _MPointF {
	float x;
	float y;
};
struct _MSize {
	int width;
	int height;
};
struct _MSizeF {
	float width;
	float height;
};
struct _MRect {
	struct _MPoint pt;
	struct _MSize sz;
};
struct _MRectF {
	float x;
	float y;
	float width;
	float height;
};
struct _MRange {
	int start;
	int end;
};



#endif /* MWT_GRAPHICS_RECT_H_ */
