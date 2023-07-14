// GetOPFileNameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Process Schedulers.h"
#include "GetOPFileNameDlg.h"


// CGetOPFileNameDlg dialog

IMPLEMENT_DYNAMIC(CGetOPFileNameDlg, CDialog)

CGetOPFileNameDlg::CGetOPFileNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetOPFileNameDlg::IDD, pParent)
	, m_OPFileName(_T(""))
{

}

CGetOPFileNameDlg::~CGetOPFileNameDlg()
{
}

void CGetOPFileNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_OUTPUT_FILE_NAME, m_OPFileName);
}


BEGIN_MESSAGE_MAP(CGetOPFileNameDlg, CDialog)
END_MESSAGE_MAP()


// CGetOPFileNameDlg message handlers
