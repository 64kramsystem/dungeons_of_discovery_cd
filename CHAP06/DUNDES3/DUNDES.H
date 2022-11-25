// dundes.h : main header file for the DUNDES application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

enum {Empty, Wall, Door, Key, Monster,
      Treasure, Sword, Armor, Potion };

const SQUARESIZE = 12;
const ROWSIZE = 32;
const COLSIZE = 32;
const OFFSET = 2;

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CDundesApp:
// See dundes.cpp for the implementation of this class
//

class CDundesApp : public CWinApp
{
public:
	CDundesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDundesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDundesApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
