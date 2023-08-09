/*
 *  app.h
 *
 *  Created on: 08-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_CORE_APP_H_
#define MWT_CORE_APP_H_
#include "resource.h"
#include "toolkit.h"
#ifdef __cplusplus
	class MApp;
#else
	typedef struct _MApp MApp;
#endif

struct _MApp {
	struct _MResource resource;
	int m_argc;
	char **m_argv;
	MToolkit *m_platToolkit;
	MToolkit *m_defToolkit;
	MToolkit *m_cusToolkit;
	void* pData[5];//reserved for platform
};

struct _MAppClass {
	struct _MResourceClass m_resource;
};

typedef MToolkit* (*_createToolkit)(MApp* app,const char* toolkitName,const char* params,int flags);

#define _MAPP(x) ((struct _MApp*)x)
#define _MAPP_CLASS(x) ((struct _MAppClass*)x)
#define _MAPP_GETCLASS(x) _MAPP_CLASS(_MRESOURCE_GETCLASS(x))

#ifdef __cplusplus
extern "C" {
#endif
	MEXPORT MResult m_app_init(MApp* app,int args, char **argv);
	MEXPORT MApp* m_app_get();
	MEXPORT MToolkit* m_app_load_platform_toolkit(MApp* app,const char* toolkitName);
	MEXPORT MToolkit* m_app_get_platform_toolkit(MApp* app);
	MEXPORT MToolkit* m_app_get_default_toolkit(MApp* app);
#ifdef __cplusplus
}
#endif

#ifdef MINLINE
	MINLINE MResult m_app_run(MApp* app,int flags){
		return m_toolkit_run(m_app_get_default_toolkit(app),flags);
	}
#endif
#endif /* MWT_CORE_APP_H_ */
