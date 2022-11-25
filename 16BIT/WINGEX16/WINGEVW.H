// wingevw.h : interface of the CWingexView class
//
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

#include "c:\wing\include\wing.h"
#include "cdib.h"

typedef struct BmInfo
{
    BITMAPINFOHEADER Header;
    RGBQUAD aColors[256];
} BmInfo;

const WINGDIBWIDTH = 300;
const WINGDIBHEIGHT = 300;

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

class CWingexView : public CView
{
protected: // create from serialization only
	CWingexView();
	DECLARE_DYNCREATE(CWingexView)

// Attributes
public:
	CWingexDoc* GetDocument();

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    protected:
        HBITMAP m_hOldBitmap;
        HDC m_hWinGDC;
        BmInfo m_WinGBmInfo;
        void huge* m_pWinGDibBits;
        LONG m_orientation;
        HPALETTE m_hPalette;
        CDib* m_pSceneDib;
        CDib* m_pPropDib;
        UINT m_frameNum;
        
    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

// Operations
public:

// Implementation
public:
	virtual ~CWingexView();
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
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

    void CreateWinGDibPalette();
    //void CopyDIBToWinG(BYTE huge* m_pWinGBmBits, CDib* pDib);
    void CreateIdentityPalette(BmInfo* winGBmInfo,
        CDib* pDib);
    void CopyDIBToWinG(BYTE huge* m_pWinGBmBits,
        UINT dstX, UINT dstY, CDib* pDib,
        UINT frmX, UINT frmY, UINT frmW, UINT frmH);
    void CopyDIBToWinGTrns(BYTE huge* m_pWinGBmBits,
        UINT dstX, UINT dstY, CDib* pDib,
        UINT frmX, UINT frmY, UINT frmW, UINT frmH,
        UINT trnsColor);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

// Generated message map functions
protected:
	//{{AFX_MSG(CWingexView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in wingevw.cpp
inline CWingexDoc* CWingexView::GetDocument()
   { return (CWingexDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
