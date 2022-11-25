// showdvw.h : interface of the CShowdibView class
//
/////////////////////////////////////////////////////////////////////////////

class CShowdibView : public CView
{
protected: // create from serialization only
	CShowdibView();
	DECLARE_DYNCREATE(CShowdibView)

// Attributes
public:
	CShowdibDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowdibView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowdibView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    HPALETTE CreateDibPalette(CDib* pDib);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

// Generated message map functions
protected:
	//{{AFX_MSG(CShowdibView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in showdvw.cpp
inline CShowdibDoc* CShowdibView::GetDocument()
   { return (CShowdibDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
