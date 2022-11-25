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

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

protected:
    int m_mode;

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

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
	afx_msg void OnItemsArmor();
	afx_msg void OnUpdateItemsArmor(CCmdUI* pCmdUI);
	afx_msg void OnItemsDoor();
	afx_msg void OnUpdateItemsDoor(CCmdUI* pCmdUI);
	afx_msg void OnItemsKey();
	afx_msg void OnUpdateItemsKey(CCmdUI* pCmdUI);
	afx_msg void OnItemsMonster();
	afx_msg void OnUpdateItemsMonster(CCmdUI* pCmdUI);
	afx_msg void OnItemsPotion();
	afx_msg void OnUpdateItemsPotion(CCmdUI* pCmdUI);
	afx_msg void OnItemsSword();
	afx_msg void OnUpdateItemsSword(CCmdUI* pCmdUI);
	afx_msg void OnItemsTreasure();
	afx_msg void OnUpdateItemsTreasure(CCmdUI* pCmdUI);
	afx_msg void OnItemsWall();
	afx_msg void OnUpdateItemsWall(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in dundevw.cpp
inline CDundesDoc* CDundesView::GetDocument()
   { return (CDundesDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
