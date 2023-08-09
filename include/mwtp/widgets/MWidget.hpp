/*
 *  MWidget.h
 *
 *  Created on: 09-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWTP_WIDGETS_MWIDGET_H_
#define MWTP_WIDGETS_MWIDGET_H_
#include "../core/MApp.h"

class MWidget : public MResource {
public:
	MWidget(){
		init(0);
	}
	MWidget(MUInt64 style){
		init(style);
	}
	MResult create(MToolkit* toolkit,MContainer* parent,MUInt64 style){
		return m_widget_create(this,toolkit,_getClassID(),parent,style);
	}
	MResult create(MContainer* parent,MUInt64 style){
		return create(0,parent,style);
	}
	virtual MResult create(MContainer* parent){
		return create(parent,this->getStyle());
	}
	MResult setVisible(bool visible){
		return m_widget_set_visible(this,visible);
	}
protected:
	void init(MUInt64 style){
		this->setStyle(style);
	}
	MClassID _getClassID(){
		return MCLASS_WIDGET;
	}
	virtual _cdecl bool postEvent(MEvent &e){
		return m_widget_post_event(this,&e);
	}
	virtual bool onPlatformEvent(MEvent &e){
		return false;
	}
	virtual bool onFreeMemory(MEvent &e, MWidget *widget){
		return false;
	}
	virtual bool onDispose(MEvent &e){
		return false;
	}
private:
	MWidget* m_parent;
	MWidget* m_nextSibling;
	MWidget* m_prevSibling;
	MWidget* m_firstChild;
	MCursor* m_cursor;
	MMenu* m_menu;
	MFont* m_font;
	MSignalTable* m_signals;
	MUInt m_childCount;
	struct _MRect m_bounds;
	MColor background;
	MColor foreground;
	void* m_pData[10];//reserved for platform
	void* m_lData[5];//reserved for layout
};
#endif /* MWTP_WIDGETS_MWIDGET_H_ */
