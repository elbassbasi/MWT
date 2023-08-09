/*
 * MContainer.hpp
 *
 *  Created on: 29-07-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWTP_WIDGETS_MCONTAINER_HPP_
#define MWTP_WIDGETS_MCONTAINER_HPP_
#include "MWidget.hpp"

class MContainer : public MWidget {
public:
	MContainer(){
	}
	MContainer(MUInt64 style) : MWidget(style){
	}
	void add(MWidget* widget){
		widget->create(this);
	}
	void add(MWidget* widget,MUInt64 style){
		widget->create(this,style);
	}
protected:
	MClassID _getClassID(){
		return MCLASS_CONTAINER;
	}
private:
};


#endif /* MWTP_WIDGETS_MCONTAINER_HPP_ */
