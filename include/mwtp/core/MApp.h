/*
 *  MApp.h
 *
 *  Created on: 08-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWTP_CORE_MAPP_H_
#define MWTP_CORE_MAPP_H_
#include "MResource.h"

class MApp : public MResource{
public:
	MApp(int args, char **argv){
		m_app_init(this,args,argv);
	}
	static MApp* get(){
		return m_app_get();
	}

	static MToolkit* defaultToolkit(){
		return get()->getDefaultToolkit();
	}

	MToolkit* getDefaultToolkit(){
		return m_app_get_default_toolkit(this);
	}
	MToolkit* getPlatformToolkit(){
		return m_app_get_platform_toolkit(this);
	}
	MToolkit* getCustomToolkit(){
		return this->m_cusToolkit;
	}
	char **args(int &argc){
		argc = m_argc;
		return this->m_argv;
	}


	MResult run(int flags = 0){
		return m_app_run(this,flags);
	}
protected:
	MClassID _getClassID(){
		return MCLASS_APP;
	}
private:
	int m_argc;
	char **m_argv;
	MToolkit *m_platToolkit;
	MToolkit *m_defToolkit;
	MToolkit *m_cusToolkit;
	void* pData[5];//reserved for platform
};




#endif /* MWTP_CORE_MAPP_H_ */
