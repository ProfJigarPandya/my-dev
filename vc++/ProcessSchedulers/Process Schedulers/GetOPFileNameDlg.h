#pragma once


// CGetOPFileNameDlg dialog

class CGetOPFileNameDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetOPFileNameDlg)

public:
	CGetOPFileNameDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGetOPFileNameDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_OPFileName;
};
