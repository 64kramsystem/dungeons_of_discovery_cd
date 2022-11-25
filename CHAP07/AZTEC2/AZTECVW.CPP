// aztecvw.cpp : implementation of the CAztecView class
//

#include "stdafx.h"
#include "aztec.h"

#include "aztecdoc.h"
#include "aztecvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAztecView

IMPLEMENT_DYNCREATE(CAztecView, CView)

BEGIN_MESSAGE_MAP(CAztecView, CView)
	//{{AFX_MSG_MAP(CAztecView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAztecView construction/destruction

CAztecView::CAztecView()
{
	// TODO: add construction code here

}

CAztecView::~CAztecView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CAztecView drawing

void CAztecView::OnDraw(CDC* pDC)
{
	CAztecDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    SelectPalette(pDC->m_hDC, m_hPalette, FALSE);
    RealizePalette(pDC->m_hDC);
    WinGBitBlt(pDC->m_hDC, 51, 51,
        WINGDIBWIDTH, WINGDIBHEIGHT, m_hWinGDC, 0, 0);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////
// CAztecView diagnostics

#ifdef _DEBUG
void CAztecView::AssertValid() const
{
	CView::AssertValid();
}

void CAztecView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAztecDoc* CAztecView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAztecDoc)));
	return (CAztecDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAztecView message handlers

int CAztecView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    SetUpWinGStuff();
    
    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

	return 0;
}

void CAztecView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    if (m_hWinGDC)
        DeleteWinGStuff();

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

void CAztecView::SetUpWinGStuff()
{
    // Get recommended format for the WinG bitmap.
    WinGRecommendDIBFormat
        ((BITMAPINFO far *)&m_WinGBmInfo);

    // Save the suggested bitmap orientation.
    m_orientation = m_WinGBmInfo.Header.biHeight;
    
    // Set up the BITMAPINFO structure.
    m_WinGBmInfo.Header.biBitCount = 8;
    m_WinGBmInfo.Header.biCompression = BI_RGB;
    m_WinGBmInfo.Header.biWidth = WINGDIBWIDTH;
    m_WinGBmInfo.Header.biHeight =
        WINGDIBHEIGHT * m_orientation;

    // Create the identity palette.
    CreateIdentityPalette();
    
    // Create the WinG device context.
    m_hWinGDC = WinGCreateDC();
    
    // Create the WinG bitmap and select it into the WinG DC.
    m_hWinGDib = WinGCreateBitmap(m_hWinGDC,
        (BITMAPINFO far *)&m_WinGBmInfo, &m_pWinGDibBits);
    m_hOldBitmap =
        (HBITMAP)SelectObject(m_hWinGDC, m_hWinGDib);

    // Fill the WinG bitmap with blackness.
    PatBlt(m_hWinGDC, 0, 0,
        WINGDIBWIDTH, WINGDIBHEIGHT, BLACKNESS);
}

void CAztecView::DeleteWinGStuff()
{
    // Release the WinG bitmap by selecting the
    // old bitmap back into the WinG DC.
    HBITMAP hBitmap =
        (HBITMAP)SelectObject(m_hWinGDC, m_hOldBitmap);

    // Delete the WinG bitmap, DC, and palette.
    DeleteObject(hBitmap);
    DeleteDC(m_hWinGDC);
    DeleteObject(m_hPalette);
}
        
void CAztecView::CreateIdentityPalette()
{
    // Define a structure for the logical palette.
    struct
    {
        WORD Version;
        WORD NumberOfEntries;
        PALETTEENTRY aEntries[256];
    } logicalPalette = { 0x300, 256 };

    // Get a device context for the screen.
    HDC hScreenDC = ::GetDC(0);

    // Load the system palette into the
    // logical palette structure.
    GetSystemPaletteEntries
        (hScreenDC, 0, 256, logicalPalette.aEntries);

    // Get rid of the screen DC.
    ::ReleaseDC(0, hScreenDC);

    // Copy the system colors into the WinG bitmap's
    // color table and set the appropriate flags.
    for(int i = 0;i < 256;i++)
    {
        m_WinGBmInfo.aColors[i].rgbRed =
            logicalPalette.aEntries[i].peRed;
        m_WinGBmInfo.aColors[i].rgbGreen =
            logicalPalette.aEntries[i].peGreen;
        m_WinGBmInfo.aColors[i].rgbBlue =
            logicalPalette.aEntries[i].peBlue;
        m_WinGBmInfo.aColors[i].rgbReserved = 0;

        logicalPalette.aEntries[i].peFlags = 0;
    }

    // Create the program's logical palette.
    m_hPalette =
        CreatePalette((LOGPALETTE*)&logicalPalette);
}

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////
