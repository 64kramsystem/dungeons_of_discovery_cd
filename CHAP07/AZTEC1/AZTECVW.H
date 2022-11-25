// aztecvw.h : interface of the CAztecView class
//
/////////////////////////////////////////////////////////////////////////////

class CAztecView : public CView
{
protected: // create from serialization only
	CAztecView();
	DECLARE_DYNCREATE(CAztecView)

// Attributes
public:
	CAztecDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAztecView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAztecView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAztecView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in aztecvw.cpp
inline CAztecDoc* CAztecView::GetDocument()
   { return (CAztecDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
