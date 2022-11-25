// dundevw.h : interface of the CDundesView class
//
/////////////////////////////////////////////////////////////////////////////

class CDundesView : public CView
{
protected: // create from serialization only
	CDundesView();
	DECLARE_DYNCREATE(CDundesView)

// Attributes
public:
	CDundesDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDundesView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDundesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDundesView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in dundevw.cpp
inline CDundesDoc* CDundesView::GetDocument()
   { return (CDundesDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
