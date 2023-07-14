// Process SchedulersView.cpp : implementation of the CProcessSchedulersView class
//

#include "stdafx.h"
#include "FirstDlg.h"
#include "Process Schedulers.h"

#include "Process SchedulersDoc.h"
#include "Process SchedulersView.h"
#include "AtlBase.h"
#include "AtlConv.h"
#include "GetOPFileNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProcessSchedulersView

IMPLEMENT_DYNCREATE(CProcessSchedulersView, CFormView)

BEGIN_MESSAGE_MAP(CProcessSchedulersView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CProcessSchedulersView::OnBnClickedButton1)	
	ON_BN_CLICKED(IDC_BUTTON2, &CProcessSchedulersView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_SHOWJOBQUEUE, &CProcessSchedulersView::OnBnClickedShowjobqueue)
	ON_WM_TIMER()
	
	ON_BN_CLICKED(IDC_STOP_JOB_SCHEDULING, &CProcessSchedulersView::OnBnClickedStopJobScheduling)
	ON_BN_CLICKED(IDC_READYQUEUE, &CProcessSchedulersView::OnBnClickedReadyqueue)
	ON_BN_CLICKED(IDC_START_CPU, &CProcessSchedulersView::OnBnClickedStartCpu)
	ON_BN_CLICKED(IDC_AUTO_REFRESH, &CProcessSchedulersView::OnBnClickedAutoRefresh)
	ON_BN_CLICKED(IDC_STOP_CPU, &CProcessSchedulersView::OnBnClickedStopCpu)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_INPUT_TABLE, &CProcessSchedulersView::OnLvnItemchangedListInputTable)
	ON_BN_CLICKED(IDC_COMPLETED_JOB_STATISTICS, &CProcessSchedulersView::OnBnClickedCompletedJobStatistics)
	ON_BN_CLICKED(IDC_STORE_STATISTICS_TO_FILE, &CProcessSchedulersView::OnBnClickedStoreStatisticsToFile)
END_MESSAGE_MAP()

// CProcessSchedulersView construction/destruction

CProcessSchedulersView::CProcessSchedulersView()
	: CFormView(CProcessSchedulersView::IDD)
	, vScheduleScheme(_T(""))
{
	// TODO: add construction code here
	//Efficient node for Job queue...
	pJOBQueue = new JOBQueue;
	pJOBQueue->ArrivalTime = 32767;
	pJOBQueue->pNext = pJOBQueue;
	isLoaded = false;

	pREADYQueue = new READYQueue;
	pREADYQueue->ArrivalTime = 32767;
	pREADYQueue->pNext = pREADYQueue;
	
	pREADYQueue->CPU_Burst = 32767;
	pREADYQueue->pNextCPUBurst = pREADYQueue;


	pREADYQueue->Priority = 32767;
	pREADYQueue->pNextPriority = pREADYQueue;
	
	
   
	isJobSchedulerStarted=false;
	isCPURunning=false;

	total_waiting_time=0;
	total_processes_completed=0;
	total_turnarround_time=0;
	total_context_swithes = 0;
	
}

CProcessSchedulersView::~CProcessSchedulersView()
{
}

void CProcessSchedulersView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_INPUT_TABLE, m_List);
	DDX_Control(pDX, IDC_LIST_JOBQUEUE, m_ListJOBQueue);
	DDX_Control(pDX, IDC_BUTTON2, cStartJobSchedulers);
	DDX_Control(pDX, IDC_READY_QUEUE, cReadyQueue);
	DDX_Control(pDX, IDC_STOP_JOB_SCHEDULING, cStopJobSchedulers);
	DDX_Control(pDX, IDC_SCH_ALGO, cScheduleScheme);
	DDX_CBString(pDX, IDC_SCH_ALGO, vScheduleScheme);
	DDX_Control(pDX, IDC_START_CPU, cStartCPU);
	DDX_Control(pDX, IDC_STOP_CPU, cStopCPU);
	DDX_Control(pDX, IDC_JOBSCHE_STATUS, cJOBStatus);
	DDX_Control(pDX, IDC_AUTO_REFRESH, cAutoRefresh);
	DDX_Control(pDX, IDC_RUNNING_PROCESS_STATUS, cRunningProcessStatus);
	DDX_Control(pDX, IDC_COMPLETED_LIST, cCompletedList);
	DDX_Control(pDX, IDC_Totals, cTotals);
}

BOOL CProcessSchedulersView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	



	return CFormView::PreCreateWindow(cs);
}


void CProcessSchedulersView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	if(GetDocument()->isOpenDoc==false)
	{
		FirstDlg dlg;
		dlg.DoModal();
	}
	

 

}


// CProcessSchedulersView diagnostics

#ifdef _DEBUG
void CProcessSchedulersView::AssertValid() const
{
	CFormView::AssertValid();
}

void CProcessSchedulersView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CProcessSchedulersDoc* CProcessSchedulersView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProcessSchedulersDoc)));
	return (CProcessSchedulersDoc*)m_pDocument;
}
#endif //_DEBUG


// CProcessSchedulersView message handlers

void CProcessSchedulersView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	//static char* color[] = {"PROCESS ID", "CPU BURST", "ARRIVAL TIME", "PRIORITY"};
	/*if(m_List.IsWindowVisible()==false)
	{
		m_List.ShowWindow(SW_SHOWDEFAULT);
		//m_List.ShowWindow(SW_HIDE);
	}*/

	
	CProcessSchedulersDoc *pDoc = GetDocument();
	
	if( pDoc->isOpenDoc == true)
	{
	
		m_List.DeleteAllItems();
		
	    //if(m_List.IsWindowVisible() == false)	
		{
			m_List.InsertColumn(0,(LPCTSTR)(CString("Process ID")),0,50,-1);
			m_List.InsertColumn(1,(LPCTSTR)(CString("CPU Burst")),0,50,-1);
			m_List.InsertColumn(2,(LPCTSTR)(CString("Arrival Time")),0,50,-1);
			m_List.InsertColumn(3,(LPCTSTR)(CString("Priority")),0,50,-1);
			m_List.EnableWindow(true);
		}
		//else
		//{
			//MessageBox((LPCTSTR)(CString("Already opened... Now Data may change as per newly opened document. ")));
		//}
	
		int i;
		int nItem;
		CString str;
		for(i =(( (GetDocument()->m_TotalProcesses ) )-1); i >= 0 ;i--)
		{
	
				str.Format(_T("%d"),pDoc->pPCBWithTiming[i].Process_ID);
				nItem = m_List.InsertItem(0,(LPCTSTR)(str));
		
				str.Format(_T("%d"),pDoc->pPCBWithTiming[i].CPU_Burst);
				m_List.SetItemText(nItem, 1, (LPCTSTR)(str));

				str.Format(_T("%d"),pDoc->pPCBWithTiming[i].ArrivalTime);
				m_List.SetItemText(nItem, 2, (LPCTSTR)(str) );

				str.Format(_T("%d"),pDoc->pPCBWithTiming[i].Priority);
				m_List.SetItemText(nItem, 3,(LPCTSTR)(str) );
		}

		pDoc->isOpenDoc = false;
		m_List.ShowWindow(SW_SHOWDEFAULT);

		CEdit *pEB = (CEdit *)GetDlgItem(IDC_TIME_COUNT);
		CString strr;
		strr.Format(_T("Read input file and job pool created..."));
		pEB->SetWindowText(strr);
	}
	else
	{
		//MessageBox((LPCTSTR)(CString("New Test Data Sets not selected .... ")));
		//m_List.ShowWindow(SW_SHOW);
	}

}

void CProcessSchedulersView::OnBnClickedButton2()//Run Job Scheduler...
{
	// TODO: Add your control notification handler code here
	// Job Scheduler....  Job Queue based on their arrival time...
	// Achieved basically only via sorting the input file content based on ArrivalTime
	CProcessSchedulersDoc *pDoc = GetDocument();
	if(pDoc->m_TotalProcesses == 0)
	{
		 MessageBox((LPCTSTR)(CString("New Test Data Sets not selected .... ")));
		 return;
	}

    isJobSchedulerStarted=true;	
	SetTimer(3,70,NULL);	
	//insert into job queue 
	PCBWithTiming *traverse_Input = pDoc->pPCBWithTiming;
	JOBQueue *prev, *curr, *new_node;
	int i;

	CEdit *pEB = (CEdit *)GetDlgItem(IDC_TIME_COUNT);
	CString strr;
	strr.Format(_T("Job Scheduler started..."));
	pEB->SetWindowText(strr);
	
	for(i=0;i<pDoc->m_TotalProcesses;i++)
	{

		prev = pJOBQueue;
		curr = pJOBQueue->pNext;

		while( traverse_Input->ArrivalTime >= curr->ArrivalTime)//? =
		{
			prev = curr;
			curr = curr->pNext;
		}

		new_node = new JOBQueue;
		
		new_node->Process_ID = traverse_Input->Process_ID;
		new_node->CPU_Burst = traverse_Input->CPU_Burst;
		new_node->ArrivalTime = traverse_Input->ArrivalTime;
		new_node->Priority = traverse_Input->Priority;
		
		prev->pNext = new_node;
		new_node->pNext = curr;

		traverse_Input++;
				
	}
	
	cStartJobSchedulers.EnableWindow(false);



	//Put into ready queue when arrival time goes same as ready queue
		SetTimer(1,10,NULL);	

		cStopJobSchedulers.EnableWindow(true);
		cStartJobSchedulers.EnableWindow(false);
		//pDoc->current_cpu_clock_time=0;

	
}

void CProcessSchedulersView::OnBnClickedShowjobqueue()
{
	// TODO: Add your control notification handler code here
	//m_List.ShowWindow(SW_HIDE);
 //if(isLoaded==false)
 
 {
	m_ListJOBQueue.DeleteAllItems();
	
	CProcessSchedulersDoc *pDoc = GetDocument();
	if( pJOBQueue->pNext != pJOBQueue )
	{
	
		if(m_ListJOBQueue.IsWindowEnabled() == false)
	    {
			m_ListJOBQueue.InsertColumn(0,(LPCTSTR)(CString("Arrival Time")),0,50,-1);
			m_ListJOBQueue.InsertColumn(1,(LPCTSTR)(CString("Process ID")),0,50,-1);
			m_ListJOBQueue.InsertColumn(2,(LPCTSTR)(CString("CPU Burst")),0,50,-1);
			m_ListJOBQueue.InsertColumn(3,(LPCTSTR)(CString("Priority")),0,50,-1);
			
			m_ListJOBQueue.EnableWindow(true);
		}
		//else
		//{
			//MessageBox((LPCTSTR)(CString("Already opened... Now Data may change as per newly opened document. ")));
		//}
	
		int i;
		int nItem;
		CString str;
		JOBQueue *traverse_job_queue = pJOBQueue->pNext;

		m_ListJOBQueue.DeleteAllItems();
		nItem = 0;
		while( traverse_job_queue!= pJOBQueue )
		{
			str.Format(_T("%d"),traverse_job_queue->ArrivalTime);
			nItem = m_ListJOBQueue.InsertItem(nItem,(LPCTSTR)(str));
				
				

			str.Format(_T("%d"),traverse_job_queue->Process_ID);
			m_ListJOBQueue.SetItemText(nItem, 1, (LPCTSTR)(str) );


			str.Format(_T("%d"),traverse_job_queue->CPU_Burst);
			m_ListJOBQueue.SetItemText(nItem, 2, (LPCTSTR)(str));


			str.Format(_T("%d"),traverse_job_queue->Priority);
			m_ListJOBQueue.SetItemText(nItem, 3,(LPCTSTR)(str) );

			traverse_job_queue = traverse_job_queue->pNext;
			nItem++;
		}
		pDoc->isOpenDoc = false;
		m_ListJOBQueue.ShowWindow(SW_SHOWDEFAULT);
		isLoaded = true;
	}
	//else
	{
		//MessageBox((LPCTSTR)(CString("New Test Data Sets not selected .... ")));
		//m_ListJOBQueue.ShowWindow(SW_SHOWDEFAULT);
	}

	
	
 }

}


void CProcessSchedulersView::OnTimer(UINT nIDEvent) 
{
		CEdit *pEB = (CEdit *)GetDlgItem(IDC_TIME_COUNT);
		//str.Format(_T("AT %d   CPC %d"),pJOBQueue->pNext->ArrivalTime,pDoc->current_cpu_clock_time  );
		//pEB->SetWindowText(str);
CProcessSchedulersDoc *pDoc = GetDocument();
	if(nIDEvent==1) //JobScheduler
	{
		CString str;
		
   
		//str.Format(_T("%d"),pDoc->current_cpu_clock_time);

		//pEB->SetWindowText(str);
	
		

		if(pJOBQueue->pNext != pJOBQueue) //If jobs are in job queue
		{
			
		
			int jj=0;
			while( (((pJOBQueue->pNext->ArrivalTime)*10) == (pDoc->current_cpu_clock_time)) &&( pJOBQueue->pNext != pJOBQueue) )
			{
		
			JOBQueue *frontjob = pJOBQueue->pNext;

			pJOBQueue->pNext = pJOBQueue->pNext->pNext;

			READYQueue *new_ready_job = new READYQueue;
			new_ready_job->ArrivalTime = frontjob->ArrivalTime;
			new_ready_job->CPU_Burst=new_ready_job->current_CPU_Burst = frontjob->CPU_Burst;
			new_ready_job->Process_ID = frontjob->Process_ID;
			new_ready_job->Priority = frontjob->Priority;
			
			
			

			READYQueue *getrear = pREADYQueue->pNext;

			while(getrear->pNext!=pREADYQueue)
				getrear = getrear->pNext;
			
			getrear->pNext = new_ready_job; 
			new_ready_job->pNext = pREADYQueue;

			

			
			////////////////
			READYQueue *prv, *cur;
			prv = pREADYQueue;
			cur=prv->pNextCPUBurst;


			

			while( new_ready_job->CPU_Burst >= cur->CPU_Burst)//? =
		    {
			   prv = cur;
			   cur = cur->pNextCPUBurst;
		    }

		
			
			prv->pNextCPUBurst = new_ready_job;
			new_ready_job->pNextCPUBurst = cur;

			/////////////////////
			READYQueue *prvpr, *curpr;
			prvpr = pREADYQueue;
			curpr=prvpr->pNextPriority;


			

			while( new_ready_job->Priority > curpr->Priority)
		    {
			   prvpr = curpr;
			   curpr = curpr->pNextPriority;
		    }

		
			
			prvpr->pNextPriority = new_ready_job;
			new_ready_job->pNextPriority = curpr;

			////////////////////

			str.Format(_T("Process %d removed from Job Pool and Placed in Ready Queue."), frontjob->Process_ID);
		    cJOBStatus.SetWindowText(str);

			delete frontjob;

			}	
		}
		else
		{
			str.Format(_T("No more jobs in Job Queue."));
		    cJOBStatus.SetWindowText(str);
		}



	



	}
	else if (nIDEvent==2) //FCFS cpu 
	{
     	CString str;	
		
	    if(isCPURunning==false)
		{

			if(pREADYQueue!=pREADYQueue->pNext) //if jobs in ready queue
			{
				READYQueue *frontjob;
				frontjob = pREADYQueue->pNext;

			
		          
				//remove job from ready queue
				pREADYQueue->pNext = pREADYQueue->pNext->pNext;
                

				isCPURunning= true;

				//take it as running job
				m_RunningJob.Process_ID = frontjob->Process_ID;
				m_RunningJob.CPU_Burst = frontjob->CPU_Burst;
				m_RunningJob.ArrivalTime = frontjob->ArrivalTime;
				m_RunningJob.Priority = frontjob->Priority;
				m_RunningJob.No_of_ContextSwitch = 0;
				m_RunningJob.current_CPU_Burst = m_RunningJob.CPU_Burst*10;
				m_RunningJob.Response_Time = pDoc->current_cpu_clock_time/10;


				
			}
			else
			{
				str.Format(_T(" No jobs in Ready Queue. CPU Idle."));
 				cRunningProcessStatus.SetWindowText(str);
				return;
			}
		}
		
		
				//process job
				int i=0;
				//for(i=0;i<m_RunningJob.CPU_Burst;i++)
				{
					m_RunningJob.current_CPU_Burst--;
					str.Format(_T("|ID %d | ResponseTime %d |Cur CPU Burst %d |"), m_RunningJob.Process_ID, m_RunningJob.Response_Time, m_RunningJob.current_CPU_Burst);
					cRunningProcessStatus.SetWindowText(str);
					
				}

				if(m_RunningJob.current_CPU_Burst == 0)
				{
					m_RunningJob.Completion_Time = (pDoc->current_cpu_clock_time/10)  + 0.5;
					str.Format(_T("|ID %d | ResponseTime %d |Cur CPU Burst %d | Completion Time %d |"), m_RunningJob.Process_ID, m_RunningJob.Response_Time, m_RunningJob.current_CPU_Burst, m_RunningJob.Completion_Time);
 					cRunningProcessStatus.SetWindowText(str);

					
				
					int nItem;
					CString string;
				
					/*cCompletedList.InsertColumn(0,(LPCTSTR)(CString("Process ID")),0,125,-1);
			cCompletedList.InsertColumn(1,(LPCTSTR)(CString("CPUBurst")),0,125,-1);
			cCompletedList.InsertColumn(2,(LPCTSTR)(CString("Priority")),0,125,-1);
			cCompletedList.InsertColumn(3,(LPCTSTR)(CString("ArrivalTime")),0,125,-1);
			cCompletedList.InsertColumn(4,(LPCTSTR)(CString("ResponseTime")),0,125,-1);
			cCompletedList.InsertColumn(5,(LPCTSTR)(CString("WaitingTime")),0,125,-1);
			cCompletedList.InsertColumn(6,(LPCTSTR)(CString("CompletionTime")),0,125,-1);
			cCompletedList.InsertColumn(7,(LPCTSTR)(CString("TurnAroundTime")),0,125,-1);*/

					nItem = cCompletedList.GetItemCount();
					nItem+=1;

					string.Format(_T("%d"),m_RunningJob.Process_ID);
					nItem = cCompletedList.InsertItem(nItem,(LPCTSTR)(string));
					string.Format(_T("%d"),m_RunningJob.CPU_Burst);
					cCompletedList.SetItemText(nItem, 1, (LPCTSTR)(string) );
					string.Format(_T("%d"),m_RunningJob.Priority);
					cCompletedList.SetItemText(nItem, 2, (LPCTSTR)(string));
					string.Format(_T("%d"),m_RunningJob.ArrivalTime);
					cCompletedList.SetItemText(nItem, 3,(LPCTSTR)(string) );
					string.Format(_T("%d"),m_RunningJob.Response_Time);
					cCompletedList.SetItemText(nItem, 4, (LPCTSTR)(string));
					
					total_waiting_time+=(m_RunningJob.Response_Time-m_RunningJob.ArrivalTime);

					string.Format(_T("%d"),m_RunningJob.Response_Time-m_RunningJob.ArrivalTime);
					cCompletedList.SetItemText(nItem, 5, (LPCTSTR)(string));
					string.Format(_T("%d"),m_RunningJob.Completion_Time);
					cCompletedList.SetItemText(nItem, 6,(LPCTSTR)(string) );
					
					total_turnarround_time+=(m_RunningJob.Completion_Time-m_RunningJob.ArrivalTime);

					string.Format(_T("%d"),m_RunningJob.Completion_Time-m_RunningJob.ArrivalTime);
					cCompletedList.SetItemText(nItem, 7,(LPCTSTR)(string) );

					total_context_swithes+=m_RunningJob.No_of_ContextSwitch;

					string.Format(_T("%d"),m_RunningJob.No_of_ContextSwitch);
					cCompletedList.SetItemText(nItem, 8,(LPCTSTR)(string) );



					cCompletedList.ShowWindow(SW_SHOWDEFAULT);
					cCompletedList.UpdateWindow();
					isCPURunning = false;

					total_processes_completed++;
					avg_waiting_time = (float) total_waiting_time / total_processes_completed;
					avg_turnarround_time = (float) total_turnarround_time / total_processes_completed;
					avg_context_swithes  = (float ) total_context_swithes / total_processes_completed;

					
					string.Format(_T("|   %10d    |    %10.6f   |   %10.6f    |   %10.6f    |   %10.6f    |"), total_processes_completed, avg_waiting_time, avg_turnarround_time, avg_context_swithes, ((float)total_processes_completed/(pDoc->current_cpu_clock_time/10)));
					cTotals.SetWindowText(string);



				}
	}
	else if(nIDEvent == 3)//CPU clock update
	{
		pDoc->current_cpu_clock_time++;
		CString str;
		str.Format(_T("CPU %d"),pDoc->current_cpu_clock_time/10  );
		pEB->SetWindowText(str);
	}else if (nIDEvent==4)//AutoRefresh
	{
		OnBnClickedButton1();
		OnBnClickedShowjobqueue();
		OnBnClickedReadyqueue();
	}
	else if (nIDEvent==5) //SPN cpu 
	{
     	CString str;	
		
	    if(isCPURunning==false)
		{

			if(pREADYQueue!=pREADYQueue->pNextCPUBurst) //if jobs in ready queue
			{
				READYQueue *frontjob;
				frontjob = pREADYQueue->pNextCPUBurst;

			
		
				//remove job from ready queue
				pREADYQueue->pNextCPUBurst = pREADYQueue->pNextCPUBurst->pNextCPUBurst;
				//crucial 1
				READYQueue *prev_at, *curr_at;
				prev_at = pREADYQueue;
				curr_at = pREADYQueue->pNext;
				while( curr_at != frontjob)
				{
					prev_at = curr_at;
					curr_at = curr_at->pNext;
				}
				prev_at->pNext = curr_at->pNext;
                ////


				


				isCPURunning= true;

				//take it as running job
				m_RunningJob.Process_ID = frontjob->Process_ID;
				m_RunningJob.CPU_Burst = frontjob->CPU_Burst;
				m_RunningJob.ArrivalTime = frontjob->ArrivalTime;
				m_RunningJob.Priority = frontjob->Priority;
				m_RunningJob.No_of_ContextSwitch = 0;
				m_RunningJob.current_CPU_Burst = m_RunningJob.CPU_Burst*10;
				m_RunningJob.Response_Time = pDoc->current_cpu_clock_time/10;


				
			}
			else
			{
				str.Format(_T(" No jobs in Ready Queue. CPU Idle."));
 				cRunningProcessStatus.SetWindowText(str);
				return;
			}
		}
		
		
				//process job
				int i=0;
				//for(i=0;i<m_RunningJob.CPU_Burst;i++)
				{
					m_RunningJob.current_CPU_Burst--;
					str.Format(_T("|ID %d | ResponseTime %d |Cur CPU Burst %d |"), m_RunningJob.Process_ID, m_RunningJob.Response_Time, m_RunningJob.current_CPU_Burst);
					cRunningProcessStatus.SetWindowText(str);
					
				}

				if(m_RunningJob.current_CPU_Burst == 0)
				{
					m_RunningJob.Completion_Time = (pDoc->current_cpu_clock_time/10)  + 0.5;
					str.Format(_T("|ID %d | ResponseTime %d |Cur CPU Burst %d | Completion Time %d |"), m_RunningJob.Process_ID, m_RunningJob.Response_Time, m_RunningJob.current_CPU_Burst, m_RunningJob.Completion_Time);
 					cRunningProcessStatus.SetWindowText(str);

					
				
					int nItem;
					CString string;
				
					/*cCompletedList.InsertColumn(0,(LPCTSTR)(CString("Process ID")),0,125,-1);
			cCompletedList.InsertColumn(1,(LPCTSTR)(CString("CPUBurst")),0,125,-1);
			cCompletedList.InsertColumn(2,(LPCTSTR)(CString("Priority")),0,125,-1);
			cCompletedList.InsertColumn(3,(LPCTSTR)(CString("ArrivalTime")),0,125,-1);
			cCompletedList.InsertColumn(4,(LPCTSTR)(CString("ResponseTime")),0,125,-1);
			cCompletedList.InsertColumn(5,(LPCTSTR)(CString("WaitingTime")),0,125,-1);
			cCompletedList.InsertColumn(6,(LPCTSTR)(CString("CompletionTime")),0,125,-1);
			cCompletedList.InsertColumn(7,(LPCTSTR)(CString("TurnAroundTime")),0,125,-1);*/

					nItem = cCompletedList.GetItemCount();
					nItem+=1;

					string.Format(_T("%d"),m_RunningJob.Process_ID);
					nItem = cCompletedList.InsertItem(nItem,(LPCTSTR)(string));
					string.Format(_T("%d"),m_RunningJob.CPU_Burst);
					cCompletedList.SetItemText(nItem, 1, (LPCTSTR)(string) );
					string.Format(_T("%d"),m_RunningJob.Priority);
					cCompletedList.SetItemText(nItem, 2, (LPCTSTR)(string));
					string.Format(_T("%d"),m_RunningJob.ArrivalTime);
					cCompletedList.SetItemText(nItem, 3,(LPCTSTR)(string) );
					string.Format(_T("%d"),m_RunningJob.Response_Time);
					cCompletedList.SetItemText(nItem, 4, (LPCTSTR)(string));
					
					total_waiting_time+=(m_RunningJob.Response_Time-m_RunningJob.ArrivalTime);

					string.Format(_T("%d"),m_RunningJob.Response_Time-m_RunningJob.ArrivalTime);
					cCompletedList.SetItemText(nItem, 5, (LPCTSTR)(string));
					string.Format(_T("%d"),m_RunningJob.Completion_Time);
					cCompletedList.SetItemText(nItem, 6,(LPCTSTR)(string) );
					
					total_turnarround_time+=(m_RunningJob.Completion_Time-m_RunningJob.ArrivalTime);

					string.Format(_T("%d"),m_RunningJob.Completion_Time-m_RunningJob.ArrivalTime);
					cCompletedList.SetItemText(nItem, 7,(LPCTSTR)(string) );

					total_context_swithes+=m_RunningJob.No_of_ContextSwitch;

					string.Format(_T("%d"),m_RunningJob.No_of_ContextSwitch);
					cCompletedList.SetItemText(nItem, 8,(LPCTSTR)(string) );



					cCompletedList.ShowWindow(SW_SHOWDEFAULT);
					cCompletedList.UpdateWindow();
					isCPURunning = false;

					total_processes_completed++;
					avg_waiting_time = (float) total_waiting_time / total_processes_completed;
					avg_turnarround_time = (float) total_turnarround_time / total_processes_completed;
					avg_context_swithes  = (float ) total_context_swithes / total_processes_completed;

					
					string.Format(_T("|   %10d    |    %10.6f   |   %10.6f    |   %10.6f    |   %10.6f    |"), total_processes_completed, avg_waiting_time, avg_turnarround_time, avg_context_swithes, ((float)total_processes_completed/(pDoc->current_cpu_clock_time/10)));
					cTotals.SetWindowText(string);



				}
	}
	else if (nIDEvent==6) //Priority based cpu 
	{
     	CString str;	
		
	    if(isCPURunning==false)
		{

			if(pREADYQueue!=pREADYQueue->pNextPriority) //if jobs in ready queue
			{
				READYQueue *frontjob;
				frontjob = pREADYQueue->pNextPriority;

			
		
				//remove job from ready queue
				pREADYQueue->pNextPriority = pREADYQueue->pNextPriority->pNextPriority;
				//crucial 2
				READYQueue *prev_at, *curr_at;
				prev_at = pREADYQueue;
				curr_at = pREADYQueue->pNext;
				while( curr_at != frontjob)
				{
					prev_at = curr_at;
					curr_at = curr_at->pNext;
				}
				prev_at->pNext = curr_at->pNext;
                ////


				isCPURunning= true;

				//take it as running job
				m_RunningJob.Process_ID = frontjob->Process_ID;
				m_RunningJob.CPU_Burst = frontjob->CPU_Burst;
				m_RunningJob.ArrivalTime = frontjob->ArrivalTime;
				m_RunningJob.Priority = frontjob->Priority;
				m_RunningJob.No_of_ContextSwitch = 0;
				m_RunningJob.current_CPU_Burst = m_RunningJob.CPU_Burst*10;
				m_RunningJob.Response_Time = pDoc->current_cpu_clock_time/10;


				
			}
			else
			{
				str.Format(_T(" No jobs in Ready Queue. CPU Idle."));
 				cRunningProcessStatus.SetWindowText(str);
				return;
			}
		}
		
		
				//process job
				int i=0;
				//for(i=0;i<m_RunningJob.CPU_Burst;i++)
				{
					m_RunningJob.current_CPU_Burst--;
					str.Format(_T("|ID %d | ResponseTime %d |Cur CPU Burst %d |"), m_RunningJob.Process_ID, m_RunningJob.Response_Time, m_RunningJob.current_CPU_Burst);
					cRunningProcessStatus.SetWindowText(str);
					
				}

				if(m_RunningJob.current_CPU_Burst == 0)
				{
					m_RunningJob.Completion_Time = (pDoc->current_cpu_clock_time/10)  + 0.5;
					str.Format(_T("|ID %d | ResponseTime %d |Cur CPU Burst %d | Completion Time %d |"), m_RunningJob.Process_ID, m_RunningJob.Response_Time, m_RunningJob.current_CPU_Burst, m_RunningJob.Completion_Time);
 					cRunningProcessStatus.SetWindowText(str);

					
				
					int nItem;
					CString string;
				
				
					nItem = cCompletedList.GetItemCount();
					nItem+=1;

					string.Format(_T("%d"),m_RunningJob.Process_ID);
					nItem = cCompletedList.InsertItem(nItem,(LPCTSTR)(string));
					string.Format(_T("%d"),m_RunningJob.CPU_Burst);
					cCompletedList.SetItemText(nItem, 1, (LPCTSTR)(string) );
					string.Format(_T("%d"),m_RunningJob.Priority);
					cCompletedList.SetItemText(nItem, 2, (LPCTSTR)(string));
					string.Format(_T("%d"),m_RunningJob.ArrivalTime);
					cCompletedList.SetItemText(nItem, 3,(LPCTSTR)(string) );
					string.Format(_T("%d"),m_RunningJob.Response_Time);
					cCompletedList.SetItemText(nItem, 4, (LPCTSTR)(string));
					
					total_waiting_time+=(m_RunningJob.Response_Time-m_RunningJob.ArrivalTime);

					string.Format(_T("%d"),m_RunningJob.Response_Time-m_RunningJob.ArrivalTime);
					cCompletedList.SetItemText(nItem, 5, (LPCTSTR)(string));
					string.Format(_T("%d"),m_RunningJob.Completion_Time);
					cCompletedList.SetItemText(nItem, 6,(LPCTSTR)(string) );
					
					total_turnarround_time+=(m_RunningJob.Completion_Time-m_RunningJob.ArrivalTime);

					string.Format(_T("%d"),m_RunningJob.Completion_Time-m_RunningJob.ArrivalTime);
					cCompletedList.SetItemText(nItem, 7,(LPCTSTR)(string) );

					total_context_swithes+=m_RunningJob.No_of_ContextSwitch;

					string.Format(_T("%d"),m_RunningJob.No_of_ContextSwitch);
					cCompletedList.SetItemText(nItem, 8,(LPCTSTR)(string) );



					cCompletedList.ShowWindow(SW_SHOWDEFAULT);
					cCompletedList.UpdateWindow();
					isCPURunning = false;

					total_processes_completed++;
					avg_waiting_time = (float) total_waiting_time / total_processes_completed;
					avg_turnarround_time = (float) total_turnarround_time / total_processes_completed;
					avg_context_swithes  = (float ) total_context_swithes / total_processes_completed;

					
					string.Format(_T("|   %10d    |    %10.6f   |   %10.6f    |   %10.6f    |   %10.6f    |"), total_processes_completed, avg_waiting_time, avg_turnarround_time, avg_context_swithes, ((float)total_processes_completed/(pDoc->current_cpu_clock_time/10)));
					cTotals.SetWindowText(string);



				}
	}


	//CString str;
	//str.Format(_T("Current Clock Time is %d"),pDoc->current_cpu_clock_time  );
   // pEB->SetWindowText(str);
		
	
}


void CProcessSchedulersView::OnBnClickedPauseJobscheduler()
{
	// TODO: Add your control notification handler code here

}

void CProcessSchedulersView::OnBnClickedStopJobScheduling()
{
	// TODO: Add your control notification handler code here

	KillTimer(1);
	cStartJobSchedulers.EnableWindow(true);
	cStopJobSchedulers.EnableWindow(false);

}
//dISPLAYS READY QUEUE WITH ARRIVAL ORDER 
void CProcessSchedulersView::OnBnClickedReadyqueue()
{
	// TODO: Add your control notification handler code here



		// TODO: Add your control notification handler code here
	//m_List.ShowWindow(SW_HIDE);
 //if(isLoaded==false)
 
 {
	cReadyQueue.DeleteAllItems();
	
	CProcessSchedulersDoc *pDoc = GetDocument();
	if( pREADYQueue->pNext != pREADYQueue )
	{
	
		if(cReadyQueue.IsWindowEnabled() == false)
	    {
			cReadyQueue.InsertColumn(0,(LPCTSTR)(CString("Arrival Time")),0,50,-1);
			cReadyQueue.InsertColumn(1,(LPCTSTR)(CString("Process ID")),0,50,-1);
			cReadyQueue.InsertColumn(2,(LPCTSTR)(CString("C CPUBurst")),0,50,-1);
			cReadyQueue.InsertColumn(3,(LPCTSTR)(CString("Priority")),0,50,-1);
			cReadyQueue.EnableWindow(true);
			
		}
		//else
		{
			//MessageBox((LPCTSTR)(CString("Already opened... Now Data may change as per newly opened document. ")));
		}
	
		int i;
		int nItem;
		CString str;
		READYQueue *traverse_ready_queue = pREADYQueue->pNext;

		cReadyQueue.DeleteAllItems();
		nItem = 0;
		while( traverse_ready_queue!= pREADYQueue )
		{
			str.Format(_T("%d"),traverse_ready_queue->ArrivalTime);
			nItem = cReadyQueue.InsertItem(nItem,(LPCTSTR)(str));
				
				

			str.Format(_T("%d"),traverse_ready_queue->Process_ID);
			cReadyQueue.SetItemText(nItem, 1, (LPCTSTR)(str) );


			str.Format(_T("%d"),traverse_ready_queue->current_CPU_Burst);
			cReadyQueue.SetItemText(nItem, 2, (LPCTSTR)(str));


			str.Format(_T("%d"),traverse_ready_queue->Priority);
			cReadyQueue.SetItemText(nItem, 3,(LPCTSTR)(str) );

			traverse_ready_queue = traverse_ready_queue->pNext;
			nItem++;
		}
		pDoc->isOpenDoc = false;
		cReadyQueue.ShowWindow(SW_SHOWDEFAULT);
		isLoaded = true;
	}
	//else
	{
		//MessageBox((LPCTSTR)(CString("New Test Data Sets not selected .... ")));
		//m_ListJOBQueue.ShowWindow(SW_SHOWDEFAULT);
	}

	
	
 }

}


/* DISPLAYS READY QUEUE WITH CPUBURST ORDER */
/*
void CProcessSchedulersView::OnBnClickedReadyqueue()
{
	// TODO: Add your control notification handler code here



		// TODO: Add your control notification handler code here
	//m_List.ShowWindow(SW_HIDE);
 //if(isLoaded==false)
 
 {
	cReadyQueue.DeleteAllItems();
	
	CProcessSchedulersDoc *pDoc = GetDocument();
	if( pREADYQueue->pNextCPUBurst != pREADYQueue )
	{
	
		if(cReadyQueue.IsWindowEnabled() == false)
	    {
			cReadyQueue.InsertColumn(0,(LPCTSTR)(CString("Arrival Time")),0,50,-1);
			cReadyQueue.InsertColumn(1,(LPCTSTR)(CString("Process ID")),0,50,-1);
			cReadyQueue.InsertColumn(2,(LPCTSTR)(CString("C CPUBurst")),0,50,-1);
			cReadyQueue.InsertColumn(3,(LPCTSTR)(CString("Priority")),0,50,-1);
			cReadyQueue.EnableWindow(true);
			
		}
		//else
		{
			//MessageBox((LPCTSTR)(CString("Already opened... Now Data may change as per newly opened document. ")));
		}
	
		int i;
		int nItem;
		CString str;
		READYQueue *traverse_ready_queue = pREADYQueue->pNextCPUBurst;

		cReadyQueue.DeleteAllItems();
		nItem = 0;
		while( traverse_ready_queue!= pREADYQueue )
		{
			str.Format(_T("%d"),traverse_ready_queue->ArrivalTime);
			nItem = cReadyQueue.InsertItem(nItem,(LPCTSTR)(str));
				
				

			str.Format(_T("%d"),traverse_ready_queue->Process_ID);
			cReadyQueue.SetItemText(nItem, 1, (LPCTSTR)(str) );


			str.Format(_T("%d"),traverse_ready_queue->current_CPU_Burst);
			cReadyQueue.SetItemText(nItem, 2, (LPCTSTR)(str));


			str.Format(_T("%d"),traverse_ready_queue->Priority);
			cReadyQueue.SetItemText(nItem, 3,(LPCTSTR)(str) );

			traverse_ready_queue = traverse_ready_queue->pNextCPUBurst;
			nItem++;
		}
		pDoc->isOpenDoc = false;
		cReadyQueue.ShowWindow(SW_SHOWDEFAULT);
		isLoaded = true;
	}
	//else
	{
		//MessageBox((LPCTSTR)(CString("New Test Data Sets not selected .... ")));
		//m_ListJOBQueue.ShowWindow(SW_SHOWDEFAULT);
	}

	
	
 }

}
*/


//dISPLAYS READY QUEUE WITH Priority order
/*void CProcessSchedulersView::OnBnClickedReadyqueue()
{
	// TODO: Add your control notification handler code here



		// TODO: Add your control notification handler code here
	//m_List.ShowWindow(SW_HIDE);
 //if(isLoaded==false)
 
 {
	cReadyQueue.DeleteAllItems();
	
	CProcessSchedulersDoc *pDoc = GetDocument();
	if( pREADYQueue->pNextPriority != pREADYQueue )
	{
	
		if(cReadyQueue.IsWindowEnabled() == false)
	    {
			cReadyQueue.InsertColumn(0,(LPCTSTR)(CString("Arrival Time")),0,50,-1);
			cReadyQueue.InsertColumn(1,(LPCTSTR)(CString("Process ID")),0,50,-1);
			cReadyQueue.InsertColumn(2,(LPCTSTR)(CString("C CPUBurst")),0,50,-1);
			cReadyQueue.InsertColumn(3,(LPCTSTR)(CString("Priority")),0,50,-1);
			cReadyQueue.EnableWindow(true);
			
		}
		//else
		{
			//MessageBox((LPCTSTR)(CString("Already opened... Now Data may change as per newly opened document. ")));
		}
	
		int i;
		int nItem;
		CString str;
		READYQueue *traverse_ready_queue = pREADYQueue->pNextPriority;

		cReadyQueue.DeleteAllItems();
		nItem = 0;
		while( traverse_ready_queue!= pREADYQueue )
		{
			str.Format(_T("%d"),traverse_ready_queue->ArrivalTime);
			nItem = cReadyQueue.InsertItem(nItem,(LPCTSTR)(str));
				
				

			str.Format(_T("%d"),traverse_ready_queue->Process_ID);
			cReadyQueue.SetItemText(nItem, 1, (LPCTSTR)(str) );


			str.Format(_T("%d"),traverse_ready_queue->current_CPU_Burst);
			cReadyQueue.SetItemText(nItem, 2, (LPCTSTR)(str));


			str.Format(_T("%d"),traverse_ready_queue->Priority);
			cReadyQueue.SetItemText(nItem, 3,(LPCTSTR)(str) );

			traverse_ready_queue = traverse_ready_queue->pNext;
			nItem++;
		}
		pDoc->isOpenDoc = false;
		cReadyQueue.ShowWindow(SW_SHOWDEFAULT);
		isLoaded = true;
	}
	//else
	{
		//MessageBox((LPCTSTR)(CString("New Test Data Sets not selected .... ")));
		//m_ListJOBQueue.ShowWindow(SW_SHOWDEFAULT);
	}

	
	
 }

}*/


void CProcessSchedulersView::OnBnClickedStartCpu()
{
	// TODO: Add your control notification handler code here
	//if(strcmp(vScheduleScheme.GetString(),"FCFS")==0)
	//{
	CEdit *pEB = (CEdit *)GetDlgItem(IDC_TIME_COUNT);
	CString strr;
	
	if( isJobSchedulerStarted == false)
	{
	 SetTimer(3,70,NULL);	
	 OnBnClickedButton2();//Run Job Scheduler...
	 cStopJobSchedulers.EnableWindow(true);
		cStartJobSchedulers.EnableWindow(false);
	
	}
	OnBnClickedCompletedJobStatistics();


	if(cScheduleScheme.GetCurSel()==0)
	{
		strr.Format(_T("FCFS Scheduler started..."));
		cRunningProcessStatus.SetWindowText(strr);
		

		SetTimer(2,70,NULL);	
		cStartCPU.EnableWindow(false);
		cStopCPU.EnableWindow(true);
		
	

	}
	else if(cScheduleScheme.GetCurSel()==1)
	{
		strr.Format(_T("SPN Scheduler started..."));
		pEB->SetWindowText(strr);

		SetTimer(5,70,NULL);	
		cStartCPU.EnableWindow(false);
		cStopCPU.EnableWindow(true);

	}
	else if(cScheduleScheme.GetCurSel()==2)
	{
		strr.Format(_T("SRT Scheduler started..."));
		pEB->SetWindowText(strr);

	} 
	else if(cScheduleScheme.GetCurSel()==3)
	{
		strr.Format(_T("HRRN Scheduler started..."));
		pEB->SetWindowText(strr);
	}
	else if(cScheduleScheme.GetCurSel()==4)
	{
		strr.Format(_T("RR Scheduler started..."));
		pEB->SetWindowText(strr);
	}
	else if(cScheduleScheme.GetCurSel()==5)
	{
		strr.Format(_T("Priority Scheduler started..."));
		pEB->SetWindowText(strr);
		SetTimer(6,70,NULL);	
		cStartCPU.EnableWindow(false);
		cStopCPU.EnableWindow(true);
	}
	else
 	{
		MessageBox((LPCTSTR)(CString("Select Scheduling technique first and then press Start CPU again... ")));
		return;
	}
	







	


	//}
}

void CProcessSchedulersView::OnBnClickedAutoRefresh()
{
	// TODO: Add your control notification handler code here
	SetTimer(4,35,NULL);
	cAutoRefresh.EnableWindow(false);
	
}


void CProcessSchedulersView::OnBnClickedStopCpu()
{
	// TODO: Add your control notification handler code here
	
	//KillTimer(1);
    KillTimer(2);
	//KillTimer(3);
	cStopCPU.EnableWindow(false);
	cStartCPU.EnableWindow(true);
}

void CProcessSchedulersView::OnLvnItemchangedListInputTable(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CProcessSchedulersView::OnBnClickedCompletedJobStatistics()
{
	// TODO: Add your control notification handler code here

{
	//cCompletedList.DeleteAllItems();
	
	CProcessSchedulersDoc *pDoc = GetDocument();
	//if( pREADYQueue->pNext != pREADYQueue )
	{
	
		if(cCompletedList.IsWindowEnabled() == false)
	    {
			
			cCompletedList.InsertColumn(0,(LPCTSTR)(CString("Process ID")),0,125,-1);
			cCompletedList.InsertColumn(1,(LPCTSTR)(CString("CPUBurst")),0,125,-1);
			cCompletedList.InsertColumn(2,(LPCTSTR)(CString("Priority")),0,125,-1);
			cCompletedList.InsertColumn(3,(LPCTSTR)(CString("ArrivalTime")),0,125,-1);
			cCompletedList.InsertColumn(4,(LPCTSTR)(CString("ResponseTime")),0,125,-1);
			cCompletedList.InsertColumn(5,(LPCTSTR)(CString("WaitingTime")),0,125,-1);
			cCompletedList.InsertColumn(6,(LPCTSTR)(CString("CompletionTime")),0,125,-1);
			cCompletedList.InsertColumn(7,(LPCTSTR)(CString("TurnAroundTime")),0,125,-1);
			cCompletedList.InsertColumn(8,(LPCTSTR)(CString("NoOfContextSwitch")),0,125,-1);

			cCompletedList.EnableWindow(true);
		}
		//else
		{
			//MessageBox((LPCTSTR)(CString("Already opened... Now Data may change as per newly opened document. ")));
		}
		

		cCompletedList.ShowWindow(SW_SHOWDEFAULT);
	}
	//else
	{
		//MessageBox((LPCTSTR)(CString("New Test Data Sets not selected .... ")));
		//m_ListJOBQueue.ShowWindow(SW_SHOWDEFAULT);
	}

	
	
 }

}

void CProcessSchedulersView::OnBnClickedStoreStatisticsToFile()
{
	// TODO: Add your control notification handler code here
	
	/*CFile dFile;
	if( dFile.Open((LPCTSTR)(CString("jigar.txt")),CFile::modeWrite) )
	{

		dFile.Write("hi",2);
		dFile.Close();
	}
	else
		MessageBox((LPCTSTR)(CString("New Test Data Sets not selected .... ")));
	*/


	CGetOPFileNameDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		HANDLE hFile = CreateFile(dlg.m_OPFileName,
         GENERIC_WRITE, FILE_SHARE_READ,
         NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile == INVALID_HANDLE_VALUE)
		  AfxMessageBox(_T("Couldn't create the file!"));
		else
		{
		// Attach a CFile object to the handle we have.
		  CFile myFile(hFile);
			
		    char max[500];
			const static char ch1[]="\n";
			const static char ch2[]=",";

			


			int totalitems = cCompletedList.GetItemCount();

			int j;	
			CString str ;

			char *buffer = new char[500];
				
			
			strcpy(buffer,"Process ID,");
			strcat(buffer,"CPUBurst,");
			strcat(buffer,"Priority,");
			strcat(buffer,"ArrivalTime,");
			strcat(buffer,"ResponseTime,");
			strcat(buffer,"WaitingTime,");
			strcat(buffer,"CompletionTime,");
			strcat(buffer,"TurnArroundTime,");
			strcat(buffer,"NoOfContextSwithes\n");
			myFile.Write(buffer,strlen(buffer));

			






			int l;
			for(int i=0;i<totalitems;i++)
			{
			
				for(j=0;j<8;j++)
				{
				  str = cCompletedList.GetItemText(i,j);
				  for (l = 0; l < str.GetLength(); l++)
					{
						buffer[l] = str.GetAt(l);
					}	

			
				  myFile.Write(buffer,str.GetLength());
				  
				  buffer[0]=',';
				  myFile.Write(buffer,1);
				}
				  
				str = cCompletedList.GetItemText(i,j);
				for (l = 0; l < str.GetLength(); l++)
				{
					buffer[l] = str.GetAt(l);
				}	

				myFile.Write(buffer,str.GetLength());
				  
				 buffer[0]='\n';
				 myFile.Write(buffer,1);

				//myFile.Write(ch1,1);
			}


			/*strcpy(buffer,"Total Processes Completed: ,");
			strcat(buffer,ltoa(total_processes_completed));
			strcat(buffer,",,,,,,\nTotal :");
			strcat(buffer,ltoa(avg_waiting_time));
			strcat(buffer,"ResponseTime,");
			strcat(buffer,"WaitingTime,");
			strcat(buffer,"CompletionTime,");
			strcat(buffer,"TurnArroundTime\n");

			myFile.Write(buffer,strlen(buffer));
            */

	        myFile.Close();
			MessageBox((LPCTSTR)(CString("Successfull Stored to file .... ")+dlg.m_OPFileName));

		}
	}
	else 
		MessageBox((LPCTSTR)(CString("Storing to file cancelled.... ")));
    
	
}
