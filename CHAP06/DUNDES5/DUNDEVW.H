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
    CBitmap* m_pBitmap;
    COLORREF m_Colors[9];

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
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDundesView();
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

    void DrawGrid(CDC* dc);
    BOOL ClickInsideGrid(CPoint point);
    BOOL InStartingWalls(int squareNum);
    void HandleLeftClick(UINT squareNum, UINT col, UINT row);
    void PlaceWall(CItem* pItem, UINT x, UINT y);
    void PlaceItem(CItem* pItem, UINT x, UINT y, UINT mode);
    BOOL NotValidItem(CItem* pItem);
    BOOL FindItem(WORD itemType, WORD itemNum, WORD& itemValue);
    void DrawSquare(UINT x, UINT y, CBrush* brush);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in dundevw.cpp
inline CDundesDoc* CDundesView::GetDocument()
   { return (CDundesDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
