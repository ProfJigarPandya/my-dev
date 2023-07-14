#pragma once

#include "Resource.h"
// FirstDlg dialog

class FirstDlg : public CDialog
{
	DECLARE_DYNAMIC(FirstDlg)

public:
	FirstDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FirstDlg();

	virtual void OnFinalRelease();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};
