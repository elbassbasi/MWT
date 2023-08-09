/*
 *  MToolkit.h
 *
 *  Created on: 13-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWTP_CORE_MTOOLKIT_H_
#define MWTP_CORE_MTOOLKIT_H_
#include "MResource.h"
#include "MIterator.h"

class MToolkit : public MResource{
private:
	MToolkit(){
		init();
	}
	~MToolkit(){

	}
	void init(){
	}
public:
	MResult getClass(MClassID clazz_id,_MResourceClass** clazz){
		return m_toolkit_get_class(this,clazz_id,clazz);
	}
	MResult run(int flags = 0){
		return m_toolkit_run(this,flags);
	}
private:
};
#endif /* MWTP_CORE_MTOOLKIT_H_ */
