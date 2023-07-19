// Process Schedulers.h : main header file for the Process Schedulers application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CProcessSchedulersApp:
// See Process Schedulers.cpp for the implementation of this class
//

class CProcessSchedulersApp : public CWinApp
{
public:
	CProcessSchedulersApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProcessSchedulersApp theApp;