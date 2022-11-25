// wingex.h : main header file for the WINGEX application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWingexApp:
// See wingex.cpp for the implementation of this class
//

class CWingexApp : public CWinApp
{
public:
	CWingexApp();

// Overrides
	virtual BOOL InitInstance();

// Implementation

	//{{AFX_MSG(CWingexApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
