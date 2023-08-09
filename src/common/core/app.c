/*
 *  app.c
 *
 *  Created on: 09-07-2023
 *  Author: azeddine El Bassbasi
 */
#include "../common.h"
static MApp* defaultApp = 0;
extern struct _MAppClass _appClass;
void* _nullMResourceClass[100];
struct MToolkitName {
	const char * name;
	_createToolkit createFn;
};

MToolkit* win_create_toolkit(MApp* app,const char* toolkitName,const char* params,int flags);
struct MToolkitName toolkits[]={
#if defined _WIN32 || defined _WIN64
		{
			.name = "win32",
			.createFn = win_create_toolkit,
		},
#endif
};
MResult m_app_null(MResource *resource){
	return MERROR_NULL_CLASS;
}
MResult m_app_init(MApp* app,int argc, char **argv){
	if(defaultApp != 0){
		exit(0);
	}
	defaultApp = app;
	_MRESOURCE(app)->m_clazz = _MRESOURCE_CLASS(&_appClass);
	_MAPP(app)->m_argc = argc;
	_MAPP(app)->m_argv = argv;
	_MAPP(app)->m_platToolkit = 0;
	_MAPP(app)->m_defToolkit = 0;
	_MAPP(app)->m_cusToolkit = 0;
	// init null classes
	struct _MResourceClass* _nullClass =_MRESOURCE_CLASS(_nullMResourceClass);
	void** _addr = (void**)&_nullClass->create;
	for(int i=0;i<80;i++){
		_addr[i] = m_app_null;
	}
	_nullClass->set_style = _m_resource_set_style;
	return MTRUE;
}
MApp* m_app_get(){
	return defaultApp;
}
MToolkit* m_app_load_platform_toolkit(MApp* app,const char* toolkitName){
	int toolkitIndex = -1;
	if(toolkitName == 0) toolkitIndex = 0;
	else{
		int toolkitCount = sizeof(toolkits)/sizeof(toolkits[0]);
		for(int i=0;i<toolkitCount;i++){
			if(!strcmp(toolkitName,toolkits[i].name)){
				toolkitIndex = i;
				break;
			}
		}
	}
	if(toolkitIndex < 0) toolkitIndex = 0;
	MToolkit* platToolkit = toolkits[toolkitIndex].createFn(app,toolkitName,0,0);
	return platToolkit;
}
MToolkit* m_app_get_platform_toolkit(MApp* app){
	if(app->m_platToolkit == 0){
		app->m_platToolkit = m_app_load_platform_toolkit(app,0);
		if(app->m_platToolkit == 0){
			exit(0);
		}
	}
	return app->m_platToolkit;
}
MToolkit* m_app_get_default_toolkit(MApp* app){
	if(app->m_defToolkit == 0)
		return m_app_get_platform_toolkit(app);
	else return app->m_defToolkit;
}
MResult m_app_dispose(MResource* app){
	return MTRUE;
}
struct _MAppClass _appClass = {
		.m_resource = {
				.m_classID = MCLASS_APP,
				.m_pSize = sizeof(struct _MApp),
				.m_PlatClass = _MRESOURCE_CLASS(&_appClass),
				.m_toolkit = 0,
				.dispose=m_app_dispose,
		},
};

