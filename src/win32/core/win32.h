/*
 *  win32.h
 *
 *  Created on: 20-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef SRC_WIN32_CORE_WIN32_H_
#define SRC_WIN32_CORE_WIN32_H_
#include "_windows.h"

MINLINE BOOL _GetMessage(WinToolkit* toolkit,LPMSG lpMsg,HWND  hWnd,UINT  wMsgFilterMin,UINT  wMsgFilterMax){
	return GetMessageW(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax);
}
MINLINE BOOL _TranslateMessage(WinToolkit* toolkit,const MSG *lpMsg){
	return TranslateMessage(lpMsg);
}
MINLINE LRESULT _DispatchMessage(WinToolkit* toolkit,const MSG *lpMsg){
	return DispatchMessageW(lpMsg);
}
MINLINE ATOM _RegisterClassEx(WinToolkit* toolkit,const WNDCLASSEX *unnamedParam1){
	return RegisterClassExW(unnamedParam1);
}

MINLINE HICON _LoadIcon(WinToolkit* toolkit,HINSTANCE hInstance,LPCSTR lpIconName){
	return LoadIconW(hInstance,lpIconName);
}

HCURSOR MINLINE _LoadCursor(WinToolkit* toolkit,HINSTANCE hInstance,LPCSTR lpCursorName){
	return LoadCursorW(hInstance,lpCursorName);
}

MINLINE int _MultiByteToWideChar(WinToolkit* toolkit,UINT CodePage,DWORD dwFlags,const char* lpMultiByteStr,
			int cbMultiByte,WCHAR* lpWideCharStr,int cchWideChar){
	return MultiByteToWideChar(CodePage,dwFlags,lpMultiByteStr,cbMultiByte,lpWideCharStr,cchWideChar);
}

MINLINE LONG_PTR _GetWindowLongPtr(WinToolkit* toolkit,HWND hWnd,int nIndex){
	return GetWindowLongPtrW(hWnd,nIndex);
}
MINLINE LONG_PTR _SetWindowLongPtr(WinToolkit* toolkit,HWND hWnd,int nIndex,LONG_PTR dwNewLong){
	return SetWindowLongPtrW(hWnd,nIndex,dwNewLong);
}
MINLINE LRESULT _DefWindowProc(WinToolkit* toolkit,HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam){
	return DefWindowProcW(hWnd,Msg,wParam,lParam);
}


MINLINE HWND _CreateWindowEx(WinToolkit* toolkit,DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,
					DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,
					HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam){
	return CreateWindowExW(dwExStyle,lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,
			hWndParent,hMenu,hInstance,lpParam);
}
MINLINE BOOL _ShowWindow(WinToolkit* toolkit,HWND hWnd,int nCmdShow){
	return ShowWindow(hWnd,nCmdShow);
}

#endif /* SRC_WIN32_CORE_WIN32_H_ */
