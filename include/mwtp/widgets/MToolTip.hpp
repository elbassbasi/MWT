/*
 * MToolTip.hpp
 *
 *  Created on: 04-08-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWTP_WIDGETS_MTOOLTIP_HPP_
#define MWTP_WIDGETS_MTOOLTIP_HPP_
#include "MWidget.hpp"
class MToolTip :public MWidget {
public:
	MToolTip(){
		init();
	}
	MResult create(MToolkit* toolkit,MFrame* parent,MUInt64 style){
		return m_widget_create(this,toolkit,MCLASS_TOOLTIP,parent,style);
	}
	MResult create(MFrame* parent,MUInt64 style){
		return create(MApp::defaultToolkit(),parent,style);
	}
protected:
	void init(){

	}
private:
};

#endif /* MWTP_WIDGETS_MTOOLTIP_HPP_ */
