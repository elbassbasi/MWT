/*
 * MBox.hpp
 *
 *  Created on: 09-08-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWTP_WIDGETS_MBOX_HPP_
#define MWTP_WIDGETS_MBOX_HPP_
#include "MContainer.hpp"
class MBox : public MContainer {
public:
	MBox(){
		init();
	}
	MBox(MUInt64 style) : MContainer(style){
		init();
	}
protected:
	void init(){
	}
	MClassID _getClassID(){
		return MCLASS_BOX;
	}
};

#endif /* MWTP_WIDGETS_MBOX_HPP_ */
