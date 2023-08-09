/*
 * MObject.hpp
 *
 *  Created on: 05-08-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWTP_CORE_MOBJECT_HPP_
#define MWTP_CORE_MOBJECT_HPP_
#include "../../mwt/mwt.h"
class MRef {
public:
	int ref;
	int weak;
	//reference
	void refInc(){

	}
	void refDec(){

	}
	//weak ref
	void refWeakInc(){

	}
	void refWeakDec(){

	}
};

class MObject{
public:
	MObject(){
		init();
	}
	virtual ~MObject(){
	}
	//reference
	void refInc(){
		m_ref.refInc();
	}
	void refDec(){
		m_ref.refDec();
	}
	//weak ref
	void refWeakInc(){
		m_ref.refWeakInc();
	}
	void refWeakDec(){
		m_ref.refWeakDec();
	}
protected:
	void init(){
	}
private:
	MRef m_ref;
	void* m_handle;
};


template <typename T>
class MPtr {
	MPtr(){
		this->p = nullptr;
	}
	MPtr(T *p){
		this->p = p;
	}
	T* get(){
		return p;
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



#endif /* MWTP_CORE_MOBJECT_HPP_ */
