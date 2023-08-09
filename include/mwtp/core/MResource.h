/*
 *  MResource.h
 *
 *  Created on: 12-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWTP_CORE_MRESOURCE_H_
#define MWTP_CORE_MRESOURCE_H_
#include "MObject.hpp"

class MResource : public MObject{
public:
	MResource(){
		init();
	}
	~MResource(){
		dispose();
	}
	MResult dispose(){
		return m_resource_dispose(this);
	}
	MClassID getClassID(){
		return this->m_clazz->m_classID;
	}
	bool isOk(){
		return getClassID() != MCLASS_UNKNOWN;
	}
	MResult setStyle(MUInt64 style){
		return m_resource_set_style(this,style);
	}
	MUInt64 getStyle(){
		return m_resource_get_style(this);
	}
	MToolkit* getToolkit(){
		return m_resource_get_toolkit(this);
	}
protected:
	void init(){
		m_resource_init(this);
	}
	virtual MClassID _getClassID()=0;
private:
	struct _MResourceClass* m_clazz;
	void* m_handle;
	MUInt64 m_style;
};

#endif /* MWTP_CORE_MRESOURCE_H_ */
