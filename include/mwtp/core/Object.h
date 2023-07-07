/*
 * HObject.h
 *
 *  Created on: 4 juil. 2023
 *      Author: elbas
 */

#ifndef MWTP_CORE_OBJECT_H_
#define MWTP_CORE_OBJECT_H_
#include "../../mwt/core/object.h"
class MObject {
public:
	MObject(){
		m_object_init(this);
	}
	virtual ~MObject();
private:
	int ref;
	int weak;
	void* priv;
};

template <typename T>
class MPtr {
	MPtr(){
		this->p = nullptr;
	}
	MPtr(T *p){
		this->p = p;
	}
private:
	T* p;
};

template <typename T>
class MWeakPtr {
	MWeakPtr(){
		this->p = nullptr;
	}
	MWeakPtr(T *p){
		this->p = p;
	}
private:
	T* p;
};


#endif /* MWTP_CORE_OBJECT_H_ */
