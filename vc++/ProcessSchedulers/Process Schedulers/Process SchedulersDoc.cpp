// Process SchedulersDoc.cpp : implementation of the CProcessSchedulersDoc class
//

#include "stdafx.h"
#include "Process Schedulers.h"

#include "Process SchedulersDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProcessSchedulersDoc

IMPLEMENT_DYNCREATE(CProcessSchedulersDoc, CDocument)

BEGIN_MESSAGE_MAP(CProcessSchedulersDoc, CDocument)
END_MESSAGE_MAP()


// CProcessSchedulersDoc construction/destruction

CProcessSchedulersDoc::CProcessSchedulersDoc()
{
	// TODO: add one-time construction code here
	isOpenDoc = false;
	pPCBWithTiming = NULL;
	m_TotalProcesses = 0;
	current_cpu_clock_time = -5;
}

CProcessSchedulersDoc::~CProcessSchedulersDoc()
{
}

BOOL CProcessSchedulersDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	isOpenDoc=false;
	return TRUE;
}




// CProcessSchedulersDoc serialization

void CProcessSchedulersDoc::Serialize(CArchive& ar)
{
	ULONGLONG l;
	char *buffer;
	short buffer_index;
	short process_entry_in_file;
	short current_word_index;
	char cword[50];
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		CDocument::Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
		isOpenDoc = true;
		pFile = ar.GetFile();
		l=pFile->GetLength();
		buffer = new char[l+1];
		char current_word[50];
		pFile->Read((void *)buffer,l);
		
		m_TotalProcesses = atoi(buffer);
		pPCBWithTiming = new PCBWithTiming[m_TotalProcesses];

		buffer_index = 0;
		//skip first line
		while(buffer[buffer_index]!='\r')
		{
			buffer_index++;
		}

		buffer_index++;	//move to next line

		for(process_entry_in_file=0;process_entry_in_file < (m_TotalProcesses-1);process_entry_in_file++)
		{
			//Extract Process id
			for(current_word_index=0;buffer[buffer_index]!=',';current_word_index++, buffer_index++)
			{
				current_word[current_word_index] = buffer[buffer_index];
			}
			current_word[current_word_index]='\0';
			pPCBWithTiming[process_entry_in_file].Process_ID = atoi(current_word);
			buffer_index++; //skip comma for next word
		
			//extract cpuburst
			for(current_word_index=0;buffer[buffer_index]!=',';current_word_index++, buffer_index++)
			{
				current_word[current_word_index] = buffer[buffer_index];
			}
			current_word[current_word_index]='\0';
			pPCBWithTiming[process_entry_in_file].CPU_Burst = atoi(current_word);
			buffer_index++; //skip comma for next word

			//extract arrivaltime
			for(current_word_index=0;buffer[buffer_index]!=',';current_word_index++, buffer_index++)
			{
				current_word[current_word_index] = buffer[buffer_index];
			}
			current_word[current_word_index]='\0';
			pPCBWithTiming[process_entry_in_file].ArrivalTime = atoi(current_word);
			buffer_index++; //skip comma for next word


			//extract Priority
			for(current_word_index=0;buffer[buffer_index]!='\r';current_word_index++,buffer_index++)
			{
				current_word[current_word_index] = buffer[buffer_index];
			}
			current_word[current_word_index]='\0';
			pPCBWithTiming[process_entry_in_file].Priority = atoi(current_word);
			buffer_index++; //skip newline for next word
		}
			//last record of file is to be read different way...
			for(current_word_index=0;buffer[buffer_index]!=',';current_word_index++, buffer_index++)
			{
				current_word[current_word_index] = buffer[buffer_index];
			}
			current_word[current_word_index]='\0';
			pPCBWithTiming[process_entry_in_file].Process_ID = atoi(current_word);
			buffer_index++; //skip comma for next word
		
			//extract cpuburst
			for(current_word_index=0;buffer[buffer_index]!=',';current_word_index++, buffer_index++)
			{
				current_word[current_word_index] = buffer[buffer_index];
			}
			current_word[current_word_index]='\0';
			pPCBWithTiming[process_entry_in_file].CPU_Burst = atoi(current_word);
			buffer_index++; //skip comma for next word

			//extract arrivaltime
			for(current_word_index=0;buffer[buffer_index]!=',';current_word_index++, buffer_index++)
			{
				current_word[current_word_index] = buffer[buffer_index];
			}
			current_word[current_word_index]='\0';
			pPCBWithTiming[process_entry_in_file].ArrivalTime = atoi(current_word);
			buffer_index++; //skip comma for next word


			//extract Priority
			for(current_word_index=0;buffer[buffer_index]!='\0';current_word_index++,buffer_index++)
			{
				current_word[current_word_index] = buffer[buffer_index];
			}
			current_word[current_word_index]='\0';
			pPCBWithTiming[process_entry_in_file].Priority = atoi(current_word);
			buffer_index++; //skip newline for next word

			
	}
	
}


// CProcessSchedulersDoc diagnostics

#ifdef _DEBUG
void CProcessSchedulersDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProcessSchedulersDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CProcessSchedulersDoc commands
