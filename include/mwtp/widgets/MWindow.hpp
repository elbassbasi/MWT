/*
 * MWindow.hpp
 *
 *  Created on: 06-08-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWTP_WIDGETS_MWINDOW_HPP_
#define MWTP_WIDGETS_MWINDOW_HPP_
#include "MContainer.hpp"
class MWindow : public MContainer {
public:
	enum {
		POPUP = MSTYLE_FRAME_POPUP,
		SHEET = MSTYLE_FRAME_SHEET,
		NO_MOVE = MSTYLE_FRAME_NO_MOVE,
		TOOL = MSTYLE_FRAME_TOOL,

		NO_TRIM = MSTYLE_FRAME_NO_TRIM,
		ON_TOP = MSTYLE_FRAME_ON_TOP,
		MODAL = MSTYLE_FRAME_MODAL,
		DISPOSE_ON_CLOSE = MSTYLE_FRAME_DISPOSE_ON_CLOSE,
		TITLE = MSTYLE_FRAME_TITLE,
		CLOSE = MSTYLE_FRAME_CLOSE,
		MIN = MSTYLE_FRAME_MIN,
		MAX = MSTYLE_FRAME_MAX,
		RESIZE = MSTYLE_FRAME_RESIZE,
		FRAME_TRIM = MSTYLE_FRAME_TRIM,
		DIALOG_TRIM = MSTYLE_DIALOG_TRIM,
	};
	MWindow(){
		init();
	}
	MWindow(MUInt64 style) : MContainer(style){
		init();
	}
protected:
	void init(){
	}
	MClassID _getClassID(){
		return MCLASS_WINDOW;
	}
};




#endif /* MWTP_WIDGETS_MWINDOW_HPP_ */
