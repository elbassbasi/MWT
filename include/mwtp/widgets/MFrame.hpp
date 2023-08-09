/*
 *  MFrame.h
 *
 *  Created on: 09-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWTP_WIDGETS_MFRAME_HPP_
#define MWTP_WIDGETS_MFRAME_HPP_
#include "MWindow.hpp"
class MFrame : public MWindow {
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
	MFrame(){
		init();
	}
	MFrame(MUInt64 style) : MWindow(style){
		init();
	}
	MResult create(MToolkit* toolkit,MFrame* parent,MUInt64 style){
		return m_widget_create(this,toolkit,MCLASS_FRAME,parent,style);
	}
	MResult create(MFrame* parent,MUInt64 style){
		return create(MApp::defaultToolkit(),parent,style);
	}
	MResult create(MUInt64 style){
		return create(MApp::defaultToolkit(),0,style);
	}
	MResult create(){
		return create(MApp::defaultToolkit(),0,FRAME_TRIM);
	}
protected:
	void init(){
	}
	MClassID _getClassID(){
		return MCLASS_FRAME;
	}
private:
	MMenu* m_menuBar;
	MToolBar* m_toolbar;
	MWidget* m_content;
	MButton* m_defaultButton;
};

#endif /* MWTP_WIDGETS_MFRAME_HPP_ */
