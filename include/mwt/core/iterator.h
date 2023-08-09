/*
 * iterator.h
 *
 *  Created on: 06-08-2023
 *      Author: azeddine El Bassbasi
 */

#ifndef MWT_CORE_ITERATOR_H_
#define MWT_CORE_ITERATOR_H_
#include "object.h"
#ifdef __cplusplus
	class _MIterator;
#else
	typedef struct __MIterator _MIterator;
#endif
struct __MIterator {
	struct _MIIteratorClass* clazz;
	void *reserved[0x10];
};
typedef struct _MIIteratorClass {
	void (*close)(_MIterator *it);
	MResult (*move_to)(_MIterator *it, _MIterator *to);
	MResult (*copy_to)(_MIterator *it, _MIterator *to);
	MResult (*reset)(_MIterator *it);
	MResult (*count)(_MIterator *it);
	MResult (*next)(_MIterator *it,void* obj);
} _MIIteratorClass;

#define __MITERATOR(x) ((struct __MIterator*)x)
#define _MITERATOR(x) ((_MIterator*)x)
#define _MITERATOR_CLASS(x) ((struct _MIIteratorClass*)x)
#define _MITERATOR_GETCLASS(x) _MITERATOR_CLASS(__MITERATOR(x)->clazz)
#ifdef __cplusplus
extern "C" {
#endif
MEXPORT extern struct _MIIteratorClass _nullMIIteratorClass;

#ifdef __cplusplus
}
#endif
#ifdef MINLINE

MINLINE void m_iterator_init(_MIterator *it){
	__MITERATOR(it)->clazz = &_nullMIIteratorClass;
}
MINLINE void m_iterator_close(_MIterator *it){
	_MITERATOR_GETCLASS(it)->close(it);
}
MINLINE MResult m_iterator_move_to(_MIterator *it, _MIterator *to){
	return _MITERATOR_GETCLASS(it)->move_to(it,to);
}
MINLINE MResult m_iterator_copy_to(_MIterator *it, _MIterator *to){
	return _MITERATOR_GETCLASS(it)->copy_to(it,to);
}
MINLINE MResult m_iterator_reset(_MIterator *it){
	return _MITERATOR_GETCLASS(it)->reset(it);
}
MINLINE MResult m_iterator_count(_MIterator *it){
	return _MITERATOR_GETCLASS(it)->count(it);
}
MINLINE MResult m_iterator_next(_MIterator *it,void* obj){
	return _MITERATOR_GETCLASS(it)->next(it,obj);
}
#endif
#endif /* MWT_CORE_ITERATOR_H_ */
