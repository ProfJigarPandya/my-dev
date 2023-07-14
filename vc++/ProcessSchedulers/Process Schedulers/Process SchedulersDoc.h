// Process SchedulersDoc.h : interface of the CProcessSchedulersDoc class
//


#pragma once
struct PCBWithTiming
{
	int Process_ID;
	int CPU_Burst;
	int ArrivalTime;
	int Priority;
};

class CProcessSchedulersDoc : public CDocument
{
protected: // create from serialization only
	CProcessSchedulersDoc();
	DECLARE_DYNCREATE(CProcessSchedulersDoc)

// Attributes
public:
	CFile *pFile;
	int current_cpu_clock_time;
	int m_TotalProcesses;
	PCBWithTiming *pPCBWithTiming;
	bool isOpenDoc;
	
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CProcessSchedulersDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


