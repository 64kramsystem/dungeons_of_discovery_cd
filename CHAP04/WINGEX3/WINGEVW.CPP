// wingevw.cpp : implementation of the CWingexView class
//

#include "stdafx.h"
#include "wingex.h"

#include "wingedoc.h"
#include "wingevw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWingexView

IMPLEMENT_DYNCREATE(CWingexView, CView)

BEGIN_MESSAGE_MAP(CWingexView, CView)
	//{{AFX_MSG_MAP(CWingexView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWingexView construction/destruction

CWingexView::CWingexView()
{
	// TODO: add construction code here

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Load the SCENE.BMP file.
    m_pSceneDib = new CDib("scene.bmp");

    // Check what type of DIB we should use.
    WinGRecommendDIBFormat((BITMAPINFO*)&m_WinGBmInfo);

    // Save the recommended orientation.
    m_orientation = m_WinGBmInfo.Header.biHeight;

    // Fill in the BITMAPINFO structure with values
    // to create a 256-color 300x300 WinG bitmap.
    m_WinGBmInfo.Header.biBitCount = 8;
    m_WinGBmInfo.Header.biCompression = BI_RGB;
    m_WinGBmInfo.Header.biWidth = 300;
    m_WinGBmInfo.Header.biHeight = 300 * m_orientation;

    // Copy the screen colors into the WinG bitmap
    // and create a logical palette.
    //CreateWinGDibPalette();
    
    // Create an identity palette based on the
    // CDib object's 256-color palette.
    CreateIdentityPalette(&m_WinGBmInfo, m_pSceneDib);

    // Create a WinG device context.
    m_hWinGDC = WinGCreateDC();
    
    // Create a WinG bitmap compatible with the WinG DC.
    HBITMAP hBitmap = WinGCreateBitmap(m_hWinGDC,
        (BITMAPINFO*)&m_WinGBmInfo, &m_pWinGDibBits);

    // Select the WinG bitmap into the WinG DC.
    m_hOldBitmap =
        (HBITMAP)SelectObject(m_hWinGDC, hBitmap);

    // Clear the garbage from the WinG bitmap.
    PatBlt(m_hWinGDC, 0, 0, 300, 300, BLACKNESS);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

CWingexView::~CWingexView()
{
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Select the old bitmap back into the WinG DC.
    HBITMAP hBitmap =
        (HBITMAP)SelectObject(m_hWinGDC, m_hOldBitmap);

    // Delete the WinG bitmap that the program created.
    DeleteObject(hBitmap);

    // Delete the WinG DC.
    DeleteDC(m_hWinGDC);

    // Delete the logical palette.
    DeleteObject(m_hPalette);

    // Delete the CDib object holding SCENE.BMP.
    delete m_pSceneDib;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////
// CWingexView drawing

void CWingexView::OnDraw(CDC* pDC)
{
	CWingexDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Select the logical palette into the window's DC.
    SelectPalette(pDC->m_hDC, m_hPalette, FALSE);

    // Tell Windows to remap the system palette with
    // the program's logical palette.
    RealizePalette(pDC->m_hDC);

    // Draw a rectangle on the WinG bitmap.
    //Rectangle(m_hWinGDC, 20, 20, 100, 100);

    // Copy the scene to the WinG bitmap.
    CopyDIBToWinG((BYTE*)m_pWinGDibBits, m_pSceneDib);

    // Transfer the WinG bitmap to the window's display.
    WinGBitBlt(pDC->m_hDC, 20, 20, 300, 300, m_hWinGDC, 0, 0);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////
// CWingexView diagnostics

#ifdef _DEBUG
void CWingexView::AssertValid() const
{
	CView::AssertValid();
}

void CWingexView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWingexDoc* CWingexView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWingexDoc)));
	return (CWingexDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWingexView message handlers

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

void CWingexView::CreateWinGDibPalette()
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

void CWingexView::CopyDIBToWinG
    (BYTE* m_pWinGDibBits, CDib* pDib)
{
    // Get the bitmap's width and height.
    UINT srcWidth = pDib->GetDibWidth();
    UINT srcHeight = pDib->GetDibHeight();

     // Get a pointer to the image's data.
    BYTE* pDibBits = pDib->GetDibBitsPtr();

    // Copy data from the source bitmap to the WinG bitmap.
    for (UINT row=0; row<srcHeight; ++row)
        for (UINT col=0; col<srcWidth; ++col)
        {
            LONG index = row * srcWidth + col;   
            m_pWinGDibBits[index] = pDibBits[index];
        }
} 

void CWingexView::CreateIdentityPalette
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

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

