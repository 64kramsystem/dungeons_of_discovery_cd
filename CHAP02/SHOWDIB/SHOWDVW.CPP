// showdvw.cpp : implementation of the CShowdibView class
//

#include "stdafx.h"
#include "showdib.h"

#include "showddoc.h"
#include "showdvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowdibView

IMPLEMENT_DYNCREATE(CShowdibView, CView)

BEGIN_MESSAGE_MAP(CShowdibView, CView)
	//{{AFX_MSG_MAP(CShowdibView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowdibView construction/destruction

CShowdibView::CShowdibView()
{
	// TODO: add construction code here

}

CShowdibView::~CShowdibView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CShowdibView drawing

void CShowdibView::OnDraw(CDC* pDC)
{
	CShowdibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Get a pointer to the current CDib object.
    CDib* pDib = pDoc->m_pDib;

    // If the CDib object is valid, display it.
    if (pDib)
    {
        // Create the DIB's palette;
        HPALETTE hPalette = CreateDibPalette(pDib);

        // Select the DIB's palette into the DC.
        HPALETTE hOldPalette =
            SelectPalette(pDC->m_hDC, hPalette, FALSE);

        // Map the DIB's palette to the system palette.
        RealizePalette(pDC->m_hDC);

        // Get a pointer to the DIB's image data.
        BYTE* pBmBits = pDib->GetDibBitsPtr();
    
        // Get a pointer to the DIB's info structure.
        LPBITMAPINFO pBmInfo = pDib->GetDibInfoPtr();
    
        // Get the DIB's width and height.
        UINT bmWidth = pDib->GetDibWidth();
        UINT bmHeight = pDib->GetDibHeight();

        // Display the DIB.
        StretchDIBits(pDC->m_hDC,
            10, 10, bmWidth, bmHeight,
            0, 0, bmWidth, bmHeight,
            pBmBits, pBmInfo, DIB_RGB_COLORS, SRCCOPY);

        // Deselect the logical palette from the DC.
        SelectPalette(pDC->m_hDC, hOldPalette, FALSE);

        // Delete the logical palette.
        DeleteObject(hPalette);
    }

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////
// CShowdibView diagnostics

#ifdef _DEBUG
void CShowdibView::AssertValid() const
{
	CView::AssertValid();
}

void CShowdibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShowdibDoc* CShowdibView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowdibDoc)));
	return (CShowdibDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowdibView message handlers

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

HPALETTE CShowdibView::CreateDibPalette(CDib* pDib)
{
    // Get a pointer to the DIB's color table.
    LPRGBQUAD pColorTable = pDib->GetDibRGBTablePtr();
    
    // Get the number of colors in the DIB.
    UINT numColors = pDib->GetDibNumColors();

    struct
    {
        WORD Version;
        WORD NumberOfEntries;
        PALETTEENTRY aEntries[256];
    } logicalPalette = { 0x300, 256 };
    
    // Fill the palette structure with the DIB's colors.
    for(UINT i=0; i<numColors; ++i)
    {
        logicalPalette.aEntries[i].peRed =
            pColorTable[i].rgbRed;
        logicalPalette.aEntries[i].peGreen =
            pColorTable[i].rgbGreen;
        logicalPalette.aEntries[i].peBlue =
            pColorTable[i].rgbBlue;
        logicalPalette.aEntries[i].peFlags = 0;
    }

    // Create the palette object.
    HPALETTE hPalette =
        CreatePalette((LPLOGPALETTE)&logicalPalette);

    return hPalette;
}

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////
