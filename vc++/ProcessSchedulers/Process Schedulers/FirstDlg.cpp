// FirstDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Process Schedulers.h"
#include "FirstDlg.h"


// FirstDlg dialog

IMPLEMENT_DYNAMIC(FirstDlg, CDialog)

FirstDlg::FirstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FirstDlg::IDD, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	EnableAutomation();

}

FirstDlg::~FirstDlg()
{
}

void FirstDlg::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void FirstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FirstDlg, CDialog)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(FirstDlg, CDialog)
END_DISPATCH_MAP()

// Note: we add support for IID_IFirstDlg to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {AC98D793-1853-40B2-98A7-AA07536698CE}
static const IID IID_IFirstDlg =
{ 0xAC98D793, 0x1853, 0x40B2, { 0x98, 0xA7, 0xAA, 0x7, 0x53, 0x66, 0x98, 0xCE } };

BEGIN_INTERFACE_MAP(FirstDlg, CDialog)
	INTERFACE_PART(FirstDlg, IID_IFirstDlg, Dispatch)
END_INTERFACE_MAP()


// FirstDlg message handlers
