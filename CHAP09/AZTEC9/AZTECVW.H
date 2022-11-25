// aztecvw.h : interface of the CAztecView class
//
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

#include "c:\wing\include\wing.h"

const WINGDIBWIDTH = 240;
const WINGDIBHEIGHT = 240;

typedef struct BmInfo
{
    BITMAPINFOHEADER Header;
    RGBQUAD aColors[256];
} BmInfo;

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

class CAztecView : public CView
{
protected: // create from serialization only
	CAztecView();
	DECLARE_DYNCREATE(CAztecView)

// Attributes
public:
	CAztecDoc* GetDocument();

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

protected:
    HBITMAP m_hWinGDib;
    HBITMAP m_hOldBitmap;
    BmInfo m_WinGBmInfo;
    long m_orientation;
    void* m_pWinGDibBits;
    HDC m_hWinGDC;
    HPALETTE m_hPalette;
    CAztecDoc* pDoc;
    CDib* m_pPartsDib;
    UINT m_objects[13];
    BOOL m_gameOver;
    BOOL m_forwardButtonPressed;
    BOOL m_backButtonPressed;
    BOOL m_leftButtonPressed;
    BOOL m_rightButtonPressed;

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAztecView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAztecView();
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

    void SetUpWinGStuff();
    void DeleteWinGStuff();
    void CreateIdentityPalette();
    void CreateIdentityPalette
        (BmInfo* winGBmInfo, CDib* pDib);
    void CopyDIBToWinG (BYTE* m_pWinGDibBits,
        UINT dstX, UINT dstY, CDib* pDib,
        UINT frmX, UINT frmY, UINT frmW, UINT frmH);
    void CalcView(BOOL toggleBMP);
    void DrawView();
    void CalcNorthView(int* blocks);
    void CalcEastView(int* blocks);
    void CalcSouthView(int* blocks);
    void CalcWestView(int* blocks);
    void InitNewGame();
    void ShowScene();
    void TurnRight();
    void TurnLeft();
    BOOL MoveForward();
    BOOL MoveBack();
    void DoMove();
    void DisplayCompass(CDC* pDC);
    void HandleForwardButton(CClientDC& clientDC,
        BITMAPINFO* pBmInfo);
    void HandleBackButton(CClientDC& clientDC,
        BITMAPINFO* pBmInfo);
    void HandleLeftButton(CClientDC& clientDC,
        BITMAPINFO* pBmInfo);
    void HandleRightButton(CClientDC& clientDC,
        BITMAPINFO* pBmInfo);
    void DoForwardButton(CClientDC& clientDC,
        BITMAPINFO* pBmInfo);
    void DoBackwardButton(CClientDC& clientDC,
        BITMAPINFO* pBmInfo);
    void DoLeftButton(CClientDC& clientDC,
        BITMAPINFO* pBmInfo);
    void DoRightButton(CClientDC& clientDC,
        BITMAPINFO* pBmInfo);
    void CopyDIBToWinGTrns(BYTE* m_pWinGDibBits,
        UINT dstX, UINT dstY, CDib* pDib, UINT frmX,
        UINT frmY, UINT frmW, UINT frmH, UINT trnsColor);
    void ShowDoor(UINT objectNum);
    void ShowTreasure(UINT objectNum);
    void GetKey(UINT number);
    void GetPotion(UINT value);
    void GetSword(UINT value);
    void GetArmor(UINT value);
    void GetTreasure(UINT value);
    void ShowMessage(UINT type);
    void DisplayKeys();
    void DisplayPotions();
    void DisplayBody();
    void DisplaySword(CClientDC* pClientDC);
    void DisplayArmor(CClientDC* pClientDC);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

// Generated message map functions
protected:
	//{{AFX_MSG(CAztecView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in aztecvw.cpp
inline CAztecDoc* CAztecView::GetDocument()
   { return (CAztecDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
