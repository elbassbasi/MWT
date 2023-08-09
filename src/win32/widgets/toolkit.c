/*
 *  toolkit.c
 *
 *  Created on: 13-07-2023
 *  Author: azeddine El Bassbasi
 */
#include "toolkit.h"
//#include <windows.h>
WCHAR *WindowClasses[] = {L"MWT_Window",L"MWT_WindowShadow",L"MWT_WindowOwnDC"};
int WindowClassesFlags[] = {CS_DBLCLKS,CS_DBLCLKS,CS_DBLCLKS | CS_OWNDC};
HINSTANCE hinst = 0;
WinToolkit* _wintoolkit = 0;
LRESULT win_toolkit_window_proc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam);

void win_toolkit_registre_class(WinToolkit *toolkit) {
	//_WCHAR clazzName[50];
	WNDCLASSEX wincl;
	ATOM atom;
	for(int i=0;i<sizeof(WindowClasses)/sizeof(WindowClasses[0]);i++){
		wincl.hInstance = hinst;
		wincl.lpfnWndProc = win_toolkit_window_proc;
		wincl.style = WindowClassesFlags[i];
		wincl.cbSize = sizeof(WNDCLASSEX);
		wincl.hIcon = _LoadIcon(toolkit,NULL, IDI_APPLICATION);
		wincl.hIconSm = _LoadIcon(toolkit,NULL, IDI_APPLICATION);
		wincl.hCursor = _LoadCursor(toolkit,NULL, IDC_ARROW);
		wincl.lpszMenuName = NULL;
		wincl.cbClsExtra = 0;
		wincl.cbWndExtra = 0;
		wincl.hbrBackground = (HBRUSH) (COLOR_3DFACE + 1);
		wincl.lpszClassName = WindowClasses[i];
		atom = _RegisterClassEx(toolkit,&wincl);
		if (atom == 0) {
			fprintf(stderr, "Error registre Atom %s", WindowClasses[i]);
			exit(0);
		}
	}
}
MResult win_toolkit_run(MToolkit* toolkit,int flags){
	MSG msg;
	while(_GetMessage(WINTOOLKIT(toolkit),&msg, NULL, 0, 0)){
		_TranslateMessage(WINTOOLKIT(toolkit),&msg);
		_DispatchMessage(WINTOOLKIT(toolkit),&msg);
	}
	return MTRUE;
}
typedef MResult (*__class_init)(WinToolkit *toolkit,MClassID clazz_id,struct _MResourceClass* clazz);
__class_init __classes_init[MCLASS_LAST] = {
		[MCLASS_FRAME] = win_frame_class_init,

};
MResult win_toolkit_get_class(MToolkit *toolkit,MClassID clazz_id,struct _MResourceClass** clazz){
	MResult ret = MERROR_NOT_IMPL;
	*clazz = 0;
	if(((MUInt)clazz_id) < MCLASS_LAST){
		WinToolkit* winToolkit = (WinToolkit*) toolkit;
		struct _MResourceClass* _clazz = winToolkit->classes.classes[clazz_id];
		if(_clazz != 0){
			if(_clazz->m_classID == MCLASS_UNKNOWN){
				// init class
				__class_init _init = __classes_init[clazz_id];
				_init(winToolkit,clazz_id,_clazz);
			}
			*clazz = _clazz;
			ret = MTRUE;
		}
	}
	return ret;
}
MResult win_toolkit_init_classes(WinToolkit* toolkit){
	_MRESOURCE(toolkit)->m_clazz = _MRESOURCE_CLASS(&toolkit->classes.m_toolkit);
	struct _MToolkitClass* clazz = _MTOOLKIT_GETCLASS(toolkit);
	clazz->run = win_toolkit_run;
	clazz->get_class = win_toolkit_get_class;
	return MTRUE;
}

MToolkit* win_create_toolkit(MApp* app,const char* toolkitName,const char* params,int flags){
	if(_wintoolkit != 0){
		return _MTOOLKIT(_wintoolkit);
	}
	WinToolkit* winToolkit = (WinToolkit*)calloc(1,sizeof(WinToolkit));
	win_toolkit_init_classes(winToolkit);
	m_toolkit_init_classes(&winToolkit->classes);
	win_toolkit_registre_class(winToolkit);
	win_widget_init_messages(winToolkit);
	_wintoolkit = winToolkit;
	winToolkit->m_toolkit.platformToolkit = _MTOOLKIT(winToolkit);
	return (MToolkit*)winToolkit;
}
#define _DLL_PROCESS_ATTACH 1
#define _DLL_THREAD_ATTACH 2
#define _DLL_THREAD_DETACH 3
#define _DLL_PROCESS_DETACH 0
#define _DLL_PROCESS_VERIFIER 4
int APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpvReserved) {
	switch (dwReason) {
	case _DLL_PROCESS_ATTACH:
		hinst = hInstance;
		break;
	case _DLL_PROCESS_DETACH:
		hinst = 0;
		break;
	case _DLL_THREAD_ATTACH:
		break;
	case _DLL_THREAD_DETACH:
		break;
	}
	return MTRUE;
}
