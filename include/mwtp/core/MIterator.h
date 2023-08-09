/*
 * MIterator.h
 *
 *  Created on: 06-08-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWTP_CORE_MITERATOR_H_
#define MWTP_CORE_MITERATOR_H_
#include "MObject.hpp"
class _MIterator;
class MIIterator {
public:
	inline void *operator new(size_t size,_MIterator* i);
	virtual ~MIIterator(){

	}
	virtual MResult moveTo(_MIterator& it){
		return MFALSE;
	};
	virtual MResult copyTo(_MIterator& it){
		return MFALSE;
	};
	virtual MResult reset(){
		return MFALSE;
	};
	virtual MResult count(){
		return MFALSE;
	};
	virtual MResult next(void* obj){
		return MFALSE;
	};
};

class _MIterator : public MIIterator {
public:
	void *reserved[0x10];
};

inline void* MIIterator::operator new(size_t size, _MIterator *i) {
	if(size > sizeof(_MIterator)){

	}
	return (void*)i;
}

template<typename T>
class MIterator {
public:
	union{
		struct __MIterator _it;
		_MIterator it;
	};
public:
	MIterator() {
		m_iterator_init(_MITERATOR(&_it));
	}
	MIterator(const MIterator<T> &it) {
		m_iterator_copy_to(_MITERATOR(&it._it),_MITERATOR(&_it));
	}
	MIterator(const MIterator<T> &&it) {
		m_iterator_move_to(_MITERATOR(&it._it),_MITERATOR(&_it));
	}
	~MIterator() {
	}
	void operator=(const MIterator<T> &it) {
		m_iterator_copy_to(_MITERATOR(&it._it),_MITERATOR(&_it));
	}
	void operator=(const MIterator<T> &&it) {
		m_iterator_copy_to(_MITERATOR(&it._it),_MITERATOR(&_it));
	}
	MResult reset(){
		return m_iterator_reset(_MITERATOR(&_it));
	};
	MResult count(){
		return m_iterator_count(_MITERATOR(&_it));
	};
	MResult next(T& obj){
		return m_iterator_next(_MITERATOR(&_it),&obj);;
	};
	size_t ToArray(T *array, size_t length) {
		size_t i = 0;
		while (i < length && next(array[i]) > 0)
			i++;
		return i;
	}
};
#endif /* MWTP_CORE_MITERATOR_H_ */
