// mainfrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

// Attributes
public:

// Operations
public:

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
