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

    // Copy the background image to the WinG bitmap.
    CopyDIBToWinG((BYTE*)m_pWinGDibBits, 0, 0,
        pDoc->m_pPartsADib, 0, 0, 240, 240);

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

    pDoc = GetDocument();
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
    //CreateIdentityPalette();
    CreateIdentityPalette(&m_WinGBmInfo, pDoc->m_pPartsADib);
        
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

void CAztecView::CreateIdentityPalette
    (BmInfo* winGBmInfo, CDib* pDib)
{
    struct
    {
        WORD Version;
        WORD NumberOfEntries;
        PALETTEENTRY aEntries[256];
    } logicalPalette = {0x300, 256};

    // Get the screen DC.
    HDC Screen = ::GetDC(0);

    // Copy Windows' 20 standard system colors
    // into the new logical palette.
    GetSystemPaletteEntries
        (Screen, 0, 10, logicalPalette.aEntries);
    GetSystemPaletteEntries
        (Screen, 246, 10, logicalPalette.aEntries + 246);

    // Get rid of the screen DC.
    ::ReleaseDC(0,Screen);

    // Copy the standard 20 system colors into
    // the WinG bitmap's color table.
    for(int i = 0; i < 10; i++)
    {
        winGBmInfo->aColors[i].rgbRed =
            logicalPalette.aEntries[i].peRed;
        winGBmInfo->aColors[i].rgbGreen =
            logicalPalette.aEntries[i].peGreen;
        winGBmInfo->aColors[i].rgbBlue =
            logicalPalette.aEntries[i].peBlue;
        winGBmInfo->aColors[i].rgbReserved = 0;

        logicalPalette.aEntries[i].peFlags = 0;

        winGBmInfo->aColors[i + 246].rgbRed =
            logicalPalette.aEntries[i + 246].peRed;
        winGBmInfo->aColors[i + 246].rgbGreen =
            logicalPalette.aEntries[i + 246].peGreen;
        winGBmInfo->aColors[i + 246].rgbBlue =
            logicalPalette.aEntries[i + 246].peBlue;
        winGBmInfo->aColors[i + 246].rgbReserved = 0;

        logicalPalette.aEntries[i + 246].peFlags = 0;
    }

    // Get a pointer to the source bitmap's color table.
    LPRGBQUAD pColorTable = pDib->GetDibRGBTablePtr();

    // Copy the source bitmap's color table into both
    // the WinG bitmap color table and
    // into the new logical palette.
    for(i = 10; i < 246; i++)
    {
        winGBmInfo->aColors[i].rgbRed =
            logicalPalette.aEntries[i].peRed =
            pColorTable[i].rgbRed;
        winGBmInfo->aColors[i].rgbGreen =
            logicalPalette.aEntries[i].peGreen =
            pColorTable[i].rgbGreen;
        winGBmInfo->aColors[i].rgbBlue =
            logicalPalette.aEntries[i].peBlue =
            pColorTable[i].rgbBlue;
        winGBmInfo->aColors[i].rgbReserved = 0;

        logicalPalette.aEntries[i].peFlags =
            PC_NOCOLLAPSE;
    }

    // Create the logical palette.
    m_hPalette =
        CreatePalette((LOGPALETTE*)&logicalPalette);
}

void CAztecView::CopyDIBToWinG
    (BYTE* m_pWinGDibBits, UINT dstX, UINT dstY,
     CDib* pDib, UINT frmX, UINT frmY, UINT frmW, UINT frmH)
{
    // Get the bitmap's width and height.
    DWORD srcWidth = pDib->GetDibWidth();
    DWORD srcHeight = pDib->GetDibHeight();

     // Get a pointer to the image's data.
    BYTE* pDibBits = pDib->GetDibBitsPtr();

    // Copy data from the source bitmap to the WinG bitmap.
    for (UINT row=0; row<frmH; ++row)
        for (UINT col=0; col<frmW; ++col)
        {
            DWORD newSrcY = srcHeight - frmH - frmY + row;
            if (m_orientation == -1)
                newSrcY = srcHeight - row - frmY - 1;
            DWORD srcIndex =
                newSrcY * srcWidth + col + frmX;
            DWORD newDstY =
                WINGDIBHEIGHT - frmH - dstY + row;
            if (m_orientation == -1)
                newDstY = row + dstY;
            DWORD dstIndex =
                newDstY * WINGDIBWIDTH + col + dstX;
            m_pWinGDibBits[dstIndex] = pDibBits[srcIndex];
        }
}

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////
