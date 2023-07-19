// Process SchedulersView.h : interface of the CProcessSchedulersView class
//


#pragma once
#include "afxcmn.h"
#include "afxwin.h"

struct JOBQueue
{
	int Process_ID;
	int CPU_Burst;
	int ArrivalTime;
	int Priority;
	JOBQueue *pNext; //input file entry ORDER....
};

struct READYQueue
{
	int Process_ID;
	int CPU_Burst;
	int current_CPU_Burst;
	int ArrivalTime;
	int Priority;
	int Response_Time;
	int Completion_Time;
	
	READYQueue *pNext;  //Order based on Arrival time
	READYQueue *pNextCPUBurst;//CPUBurst order ... processing required order...
	READYQueue *pNextPriority;//Priority order ... ...

};
struct RunningJob
{
	int Process_ID;
	int CPU_Burst;
	int current_CPU_Burst;
	int ArrivalTime;
	int Priority;
	int Response_Time;
	int Completion_Time;
	int No_of_ContextSwitch;
};

struct CompletdJobQueue
{
	int Process_ID;
	int CPU_Burst;
	int current_CPU_Burst;
	int ArrivalTime;
	int Priority;
	int Response_Time;
	int Completion_Time;
	int No_of_ContextSwitch;
};


class CProcessSchedulersView : public CFormView
{

public:
	JOBQueue *pJOBQueue;
	READYQueue *pREADYQueue;
	bool isLoaded;
	bool isJobSchedulerStarted;
	RunningJob m_RunningJob;
	bool isCPURunning;
	int total_waiting_time;
	int total_turnarround_time;
	int total_context_swithes;
	int total_processes_completed;
	float avg_waiting_time;
	float avg_turnarround_time;
	float avg_context_swithes;
protected: // create from serialization only
	CProcessSchedulersView();
	afx_msg void OnTimer(UINT nIDEvent);
	DECLARE_DYNCREATE(CProcessSchedulersView)

public:
	enum{ IDD = IDD_PROCESSSCHEDULERS_FORM };

// Attributes
public:
	CProcessSchedulersDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CProcessSchedulersView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl m_List;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedShowjobqueue();
	CListCtrl m_ListJOBQueue;
	CButton cStartJobSchedulers;
	afx_msg void OnBnClickedPauseJobscheduler();
	afx_msg void OnBnClickedStopJobScheduling();
	afx_msg void OnBnClickedReadyqueue();
	CListCtrl cReadyQueue;
	CButton cStopJobSchedulers;
	CComboBox cScheduleScheme;
	CString vScheduleScheme;
	afx_msg void OnBnClickedStartCpu();
	afx_msg void OnBnClickedAutoRefresh();
	afx_msg void OnBnClickedStopCpu();
	CButton cStartCPU;
	CButton cStopCPU;
	CStatic cJOBStatus;
	afx_msg void OnLvnItemchangedListInputTable(NMHDR *pNMHDR, LRESULT *pResult);
	CButton cAutoRefresh;
	CStatic cRunningProcessStatus;
	afx_msg void OnBnClickedCompletedJobStatistics();
	CListCtrl cCompletedList;
	afx_msg void OnBnClickedStoreStatisticsToFile();
	CStatic cTotals;
};

#ifndef _DEBUG  // debug version in Process SchedulersView.cpp
inline CProcessSchedulersDoc* CProcessSchedulersView::GetDocument() const
   { return reinterpret_cast<CProcessSchedulersDoc*>(m_pDocument); }
#endif

