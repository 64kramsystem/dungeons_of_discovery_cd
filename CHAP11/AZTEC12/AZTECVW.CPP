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
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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
    //CopyDIBToWinG((BYTE*)m_pWinGDibBits, 0, 0,
    //    pDoc->m_pPartsADib, 0, 0, 240, 240);

    // Get a pointer to the panel bitmap's
    // BITMAPINFO structure.
    BITMAPINFO* pDibInfo =
        pDoc->m_pPanelDib->GetDibInfoPtr();

    // Blit the panel onto the window.
    StretchDIBits(pDC->m_hDC, 0, 0, 540, 420,
        0, 0, 540, 420, pDoc->m_pPanelBits, pDibInfo,
        DIB_RGB_COLORS, SRCCOPY);

    DisplayCompass(pDC);
    DisplayBody();
    DisplayKeys();
    DisplayPotions();
    DisplayStats();

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
    m_forwardButtonPressed = FALSE;
    m_backButtonPressed = FALSE;
    m_leftButtonPressed = FALSE;
    m_rightButtonPressed = FALSE;

    m_nextLevel[0] = 100;
    m_nextLevel[1] = 200;
    m_nextLevel[2] = 400;
    m_nextLevel[3] = 800;
    m_nextLevel[4] = 1500;
    m_nextLevel[5] = 3000;
    m_nextLevel[6] = 6000;
    m_nextLevel[7] = 12000;
    m_nextLevel[8] = 24000;
    m_nextLevel[9] = 50000;

    SetClassLong(m_hWnd, GCL_STYLE,
        CS_HREDRAW | CS_VREDRAW);
    
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

void CAztecView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Initialize the view's game variables.
    InitNewGame();

    // Reinitialize the WinG DC, bitmap,
    // and identity palette.
    DeleteWinGStuff();
    SetUpWinGStuff();

    // Set the pointer to the bitmap containing
    // the wall and door objects.
    m_pPartsDib = pDoc->m_pPartsADib;

	// Set up the identity palette.
	CClientDC clientDC(this);
    SelectPalette(clientDC.m_hDC, m_hPalette, FALSE);
    RealizePalette(clientDC.m_hDC);

    // Build the 3-D view and copy it to the WinG bitmap.
    CalcView(FALSE);
    DrawView();

    // Force the main window to redraw.
    Invalidate(FALSE);

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

void CAztecView::CalcView(BOOL toggleBMP)
{
    // Return immediately if the game is over.
    if (m_gameOver)
        return;

    int blockNums[13];

    // Get the numbers of the visible squares.
    switch (pDoc->m_faceDir)
    {
        case North: CalcNorthView(blockNums); break;
        case West: CalcWestView(blockNums); break;
        case South: CalcSouthView(blockNums); break;
        case East: CalcEastView(blockNums); break;
    }
    
    // Store the object types for the 13 visible
    // squares in the m_objects[] array.
    for (int i=0; i<13; ++i)
    {
        // If the square is off the grid, set it to empty.
        if ((blockNums[i] < 0) ||
            (blockNums[i] > DUNGEONSIZE-1))
            m_objects[i] = Empty;
        else
        {
            // Get a pointer to the item for the square.
            CItem* item =
                (CItem*) pDoc->m_Dungeon.GetAt(blockNums[i]);

            // Store the item's type in the object array.
            m_objects[i] = item->iType;

            // Store the item's number.
            m_objNums[i] = item->iNumber;
        }
    }

    // If requested, switch between dungeon images.
    if (toggleBMP)
    {
        if (m_pPartsDib == pDoc->m_pPartsADib)
            m_pPartsDib = pDoc->m_pPartsBDib;
        else
            m_pPartsDib = pDoc->m_pPartsADib;
    }
}

void CAztecView::CalcNorthView(int* blocks)
{
    // Calculate the visible blocks when the
    // player is facing north.
    blocks[0] = (pDoc->m_playerY-3) * ROWSIZE + pDoc->m_playerX - 2;
    blocks[1] = (pDoc->m_playerY-3) * ROWSIZE + pDoc->m_playerX + 2;
    blocks[2] = (pDoc->m_playerY-3) * ROWSIZE + pDoc->m_playerX - 1;
    blocks[3] = (pDoc->m_playerY-3) * ROWSIZE + pDoc->m_playerX + 1;
    blocks[4] = (pDoc->m_playerY-3) * ROWSIZE + pDoc->m_playerX;
    blocks[5] = (pDoc->m_playerY-2) * ROWSIZE + pDoc->m_playerX - 1;
    blocks[6] = (pDoc->m_playerY-2) * ROWSIZE + pDoc->m_playerX + 1;
    blocks[7] = (pDoc->m_playerY-2) * ROWSIZE + pDoc->m_playerX;
    blocks[8] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX - 1;
    blocks[9] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX + 1;
    blocks[10] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX;
    blocks[11] = pDoc->m_playerY * ROWSIZE + pDoc->m_playerX - 1;
    blocks[12] = pDoc->m_playerY * ROWSIZE + pDoc->m_playerX + 1;
}

void CAztecView::CalcEastView(int* blocks)
{
    // Calculate the visible blocks when the
    // player is facing east.
    blocks[0] = (pDoc->m_playerY-2) * ROWSIZE + pDoc->m_playerX+3;
    blocks[1] = (pDoc->m_playerY+2) * ROWSIZE + pDoc->m_playerX+3;
    blocks[2] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX+3;
    blocks[3] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX+3;
    blocks[4] = (pDoc->m_playerY) * ROWSIZE + pDoc->m_playerX+3;
    blocks[5] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX+2;
    blocks[6] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX+2;
    blocks[7] = pDoc->m_playerY * ROWSIZE + pDoc->m_playerX+2;
    blocks[8] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX+1;
    blocks[9] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX+1;
    blocks[10] = pDoc->m_playerY * ROWSIZE + pDoc->m_playerX+1;
    blocks[11] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX;
    blocks[12] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX;
}

void CAztecView::CalcSouthView(int* blocks)
{
    // Calculate the visible blocks when the
    // player is facing south.
    blocks[0] = (pDoc->m_playerY+3) * ROWSIZE + pDoc->m_playerX + 2;
    blocks[1] = (pDoc->m_playerY+3) * ROWSIZE + pDoc->m_playerX - 2;
    blocks[2] = (pDoc->m_playerY+3) * ROWSIZE + pDoc->m_playerX + 1;
    blocks[3] = (pDoc->m_playerY+3) * ROWSIZE + pDoc->m_playerX - 1;
    blocks[4] = (pDoc->m_playerY+3) * ROWSIZE + pDoc->m_playerX;
    blocks[5] = (pDoc->m_playerY+2) * ROWSIZE + pDoc->m_playerX + 1;
    blocks[6] = (pDoc->m_playerY+2) * ROWSIZE + pDoc->m_playerX - 1;
    blocks[7] = (pDoc->m_playerY+2) * ROWSIZE + pDoc->m_playerX;
    blocks[8] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX + 1;
    blocks[9] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX - 1;
    blocks[10] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX;
    blocks[11] = pDoc->m_playerY * ROWSIZE + pDoc->m_playerX + 1;
    blocks[12] = pDoc->m_playerY * ROWSIZE + pDoc->m_playerX - 1;
}

void CAztecView::CalcWestView(int* blocks)
{            
    // Calculate the visible blocks when the
    // player is facing west.
    blocks[0] = (pDoc->m_playerY+2) * ROWSIZE + pDoc->m_playerX-3;
    blocks[1] = (pDoc->m_playerY-2) * ROWSIZE + pDoc->m_playerX-3;
    blocks[2] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX-3;
    blocks[3] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX-3;
    blocks[4] = (pDoc->m_playerY) * ROWSIZE + pDoc->m_playerX-3;
    blocks[5] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX-2;
    blocks[6] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX-2;
    blocks[7] = pDoc->m_playerY * ROWSIZE + pDoc->m_playerX-2;
    blocks[8] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX-1;
    blocks[9] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX-1;
    blocks[10] = pDoc->m_playerY * ROWSIZE + pDoc->m_playerX-1;
    blocks[11] = (pDoc->m_playerY+1) * ROWSIZE + pDoc->m_playerX;
    blocks[12] = (pDoc->m_playerY-1) * ROWSIZE + pDoc->m_playerX;
}

void CAztecView::DrawView()
{
    // Return immediately if the game is over.
    if (m_gameOver)
       return;

    // Define coordinates for each of the 13
    // possible wall objects.
    UINT wallcoords[13][6] =
    {
        0, 83, 242, 0, 31, 74,
        209, 83, 513, 0, 31, 74,
        9, 83, 274, 0, 81, 74,
        149, 83, 431, 0, 81, 74,
        83, 83, 356, 0, 74, 74,
        0, 68, 242, 87, 84, 104,
        156, 68, 432, 87, 84, 104,
        68, 68, 327, 87, 104, 104,
        0, 30, 0, 241, 69, 180,
        171, 30, 249, 241, 69, 180,
        30, 30, 70, 241, 178, 180,
        0, 0, 572, 146, 31, 240,
        209, 0, 604, 146, 31, 240
    };

    // Get a pointer to the source bitmap's
    // BITMAPINFO structure.
    LPBITMAPINFO pBmInfo =
        m_pPartsDib->GetDibInfoPtr();

    // Copy the background scene to the WinG bitmap.
    CopyDIBToWinG((BYTE*)m_pWinGDibBits, 0, 0,
        m_pPartsDib, 0, 0, 240, 240);

    // Check all 13 visible squares for objects.
    for (int i=0; i<13; ++i)
    {
        // If the current square is a wall...
        if (m_objects[i] == Wall)
        
            // Copy the wall's image from the source
            // bitmap to the WinG bitmap.
            CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                wallcoords[i][0], wallcoords[i][1],
                m_pPartsDib,
                wallcoords[i][2], wallcoords[i][3],
                wallcoords[i][4], wallcoords[i][5]);
        else if (m_objects[i] == Door) 
            ShowDoor(i);
        else if (m_objects[i] == Treasure)
            ShowTreasure(i);
        else if (m_objects[i] == Potion)
            ShowTreasure(i);
        else if (m_objects[i] == Sword)
            ShowTreasure(i);
        else if (m_objects[i] == Armor)
            ShowTreasure(i);
        else if (m_objects[i] == Key)
            ShowTreasure(i);
        else if (m_objects[i] == Monster)
            ShowMonster(i);
    }

    // If the player is on level 1, show the
    // appropriate horizon scene.
    if (pDoc->m_floorNum == 1)
        ShowScene();
}

void CAztecView::ShowScene()
{
    UINT x, y;

    // Get the appropriate scene's coordinates
    // in the source bitmap.
    switch (pDoc->m_faceDir)
    {
        case North: x = 454; y = 192; break;
        case East:  x = 454; y = 276; break;
        case South: x = 454; y = 360; break;
        case West:  x = 341; y = 360; break;
    }
    
    // Copy the horizon scene to the WinG bitmap.
    CopyDIBToWinG((BYTE*)m_pWinGDibBits,
        64, 0, m_pPartsDib, x, y, 112, 83);
}

void CAztecView::InitNewGame()
{
    // Initialize the game-over flag.
    m_gameOver = FALSE;
}

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

void CAztecView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // If the game is over, return immediately.
    if (m_gameOver)
        return;

    // Initialize the Boolean flag.
    BOOL moveOK = TRUE;

    // Perform the appropriate move based on the
    // key pressed. This function responds only to
    // the arrow keys.
    switch(nChar)
    {
        case VK_LEFT: TurnLeft(); break;
        case VK_RIGHT: TurnRight(); break;
        case VK_UP: moveOK = MoveForward(); break;
        case VK_DOWN: moveOK = MoveBack(); break;
        default: moveOK = FALSE;
    }

    // If the requested move checks out okay, do it.
    if (moveOK)
        DoMove();

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

void CAztecView::TurnLeft()
{
    // Update the player's facing direction.
    switch(pDoc->m_faceDir)
    {
        case North: pDoc->m_faceDir = West; break;
        case East : pDoc->m_faceDir = North; break;
        case South: pDoc->m_faceDir = East; break;
        case West : pDoc->m_faceDir = South; break;
    }
}

void CAztecView::TurnRight()
{
    // Update the player's facing direction.
    switch(pDoc->m_faceDir)
    {
        case North: pDoc->m_faceDir = East; break;
        case East : pDoc->m_faceDir = South; break;
        case South: pDoc->m_faceDir = West; break;
        case West : pDoc->m_faceDir = North; break;
    }
}

/*
BOOL CAztecView::MoveForward()
{
    // Save the player's current position.
    UINT oldX = pDoc->m_playerX;
    UINT oldY = pDoc->m_playerY;
    
    // Update the player's position based on
    // which direction he's facing.
    switch(pDoc->m_faceDir)
    {
        case North: --pDoc->m_playerY; break;
        case East : ++pDoc->m_playerX; break;
        case South: ++pDoc->m_playerY; break;
        case West : --pDoc->m_playerX; break;
    }
    
    // Calculate the number of the square that
    // the player is about to move onto.
    UINT square = pDoc->m_playerY * ROWSIZE + pDoc->m_playerX;

    // Get the item stored in that square.
    CItem* item = (CItem*)pDoc->m_Dungeon.GetAt(square);

    // If the item is a wall, the player can't move there.
    if (item->iType == Wall)
    {
        // Restore old player position.
        pDoc->m_playerX = oldX;
        pDoc->m_playerY = oldY;

        // Indicate that the move failed.
        return FALSE;
    }
    
    // Indicate that the move is okay.
    return TRUE;
}
*/

BOOL CAztecView::MoveForward()
{
    // Initialize temporary variables for the
    // player's new position.
    UINT newX = pDoc->m_playerX;
    UINT newY = pDoc->m_playerY;
    
    // Update the player's position based on
    // which direction he's facing.
    switch(pDoc->m_faceDir)
    {
        case North: newY = pDoc->m_playerY - 1; break;
        case East : newX = pDoc->m_playerX + 1; break;
        case South: newY = pDoc->m_playerY + 1; break;
        case West : newX = pDoc->m_playerX - 1; break;
    }
    
    // Calculate the number of the square that
    // the player is about to move onto.
    UINT square = newY * ROWSIZE + newX;

    // Get the item stored in that square.
    CItem* pItem = (CItem*)pDoc->m_Dungeon.GetAt(square);

    // If the item is a wall, the player can't move there.
    if (pItem->iType == Wall)
        return FALSE;
    else if (pItem->iType == Key)
    {
        pItem->iType = Empty;
        GetKey(pItem->iNumber);
        return FALSE;
    }
    else if (pItem->iType == Potion)
    {
        pItem->iType = Empty;
        GetPotion(pItem->iValue);
        return FALSE;
    }
    else if (pItem->iType == Sword)
    {
        pItem->iType = Empty;
        GetSword(pItem->iValue);
        return FALSE;
    }
    else if (pItem->iType == Armor)
    {
        pItem->iType = Empty;
        GetArmor(pItem->iValue);
        return FALSE;
    }
    else if (pItem->iType == Treasure)
    {
        pItem->iType = Empty;
        GetTreasure(pItem->iValue);
        return FALSE;
    }
    else if (pItem->iType == Door)
    {
        if (pDoc->m_keys[pItem->iNumber])
        {
            pItem->iType = Empty;
            OpenDoor();
         }
        return FALSE;
    }

    // Set the player's new position in the dungeon.
    pDoc->m_playerX = newX;
    pDoc->m_playerY = newY;
    
    // Indicate that the move is okay.
    return TRUE;
};

BOOL CAztecView::MoveBack()
{
    // Save the player's current position.
    UINT oldX = pDoc->m_playerX;
    UINT oldY = pDoc->m_playerY;
    
    // Update the player's position based on
    // which direction he's facing.
    switch(pDoc->m_faceDir)
    {
        case North: ++pDoc->m_playerY; break;
        case East : --pDoc->m_playerX; break;
        case South: --pDoc->m_playerY; break;
        case West : ++pDoc->m_playerX; break;
    }
    
    // Calculate the number of the square that
    // the player is about to move onto.
    UINT square = pDoc->m_playerY * ROWSIZE + pDoc->m_playerX;

    // Get the item stored in that square.
    CItem* item = (CItem*)pDoc->m_Dungeon.GetAt(square);

    // If the square isn't empty,
    // the player can't move there.
    if (item->iType != Empty)
    {
        // Restore the player's old position.
        pDoc->m_playerX = oldX;
        pDoc->m_playerY = oldY;

        // Tell the calling function that the move failed.
        return FALSE;
    }
    
    // Tell the calling function that the move is okay.
    return TRUE;
}

void CAztecView::DoMove()
{
    // Get a DC for the window.
    CClientDC clientDC(this);

    // Get a pointer to the source
    // bitmap's BITMAPINFO structure.
    LPBITMAPINFO pBmInfo =
        m_pPartsDib->GetDibInfoPtr();

    // Calculate the new view and draw the
    // view on the WinG bitmap.
    CalcView(TRUE);
    DrawView();

    // Select and realize the palette.
    SelectPalette(clientDC.m_hDC, m_hPalette, FALSE);
    RealizePalette(clientDC.m_hDC);

    // Blit the WinG bitmap to the window.
    WinGBitBlt(clientDC.m_hDC, 51, 51, 240, 240,
        m_hWinGDC, 0, 0);

    // Update the compass face.
    DisplayCompass(&clientDC);
}

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

void CAztecView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // If the game is over, return immediately.
    if (m_gameOver)
        return;

    // Get a DC for the window.
    CClientDC clientDC(this);

    // Select and realize the palette.
    SelectPalette(clientDC.m_hDC, m_hPalette, FALSE);
    RealizePalette(clientDC.m_hDC);

    // Get a pointer to the source bitmap's
    // BITMAPINFO structure.
    BITMAPINFO* pBmInfo =
        pDoc->m_pSundryDib->GetDibInfoPtr();

    // Clicked on forward button?
    if ((point.x > 184) && (point.x < 234) &&
             (point.y > 296) && (point.y < 330))
        HandleForwardButton(clientDC, pBmInfo);

    // Clicked on backward button?
    else if ((point.x > 184) && (point.x < 234) &&
             (point.y > 336) && (point.y < 368))
        HandleBackButton(clientDC, pBmInfo);

    // Clicked on left button?
    else if ((point.x > 128) && (point.x < 178) &&
             (point.y > 296) && (point.y < 368))
        HandleLeftButton(clientDC, pBmInfo);

    // Clicked on right button?
    else if ((point.x > 240) && (point.x < 290) &&
             (point.y > 298) && (point.y < 368))
        HandleRightButton(clientDC, pBmInfo);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

	CView::OnLButtonDown(nFlags, point);
}

void CAztecView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Get a DC for the window.
    CClientDC clientDC(this);

    // Select and realize the palette.
    SelectPalette(clientDC.m_hDC, m_hPalette, FALSE);
    RealizePalette(clientDC.m_hDC);

    // Get a pointer to the source
    // bitmap's BITMAPINFO structure.
    BITMAPINFO* pBmInfo =
        pDoc->m_pSundryDib->GetDibInfoPtr();

    // If the forward button is depressed...
    if (m_forwardButtonPressed)
        DoForwardButton(clientDC, pBmInfo);

    // ...else if the backward button is depressed...
    else if (m_backButtonPressed)
        DoBackwardButton(clientDC, pBmInfo);

    // ...else if the left button is depressed...
    else if (m_leftButtonPressed)
        DoLeftButton(clientDC, pBmInfo);

    // ...else if the right button is depressed.
    else if (m_rightButtonPressed)
        DoRightButton(clientDC, pBmInfo);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

	CView::OnLButtonUp(nFlags, point);
}

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

void CAztecView::DoForwardButton
    (CClientDC& clientDC, BITMAPINFO* pBmInfo)
{
    // Draw the button in its unselected form.
    StretchDIBits(clientDC.m_hDC,
        183, 297, 52, 34,
        108, 182, 52, 34,
        pDoc->m_pSundryBits,
        pBmInfo, DIB_RGB_COLORS, SRCCOPY);

        // Turn off the button's flag.
        m_forwardButtonPressed = FALSE;

        // Release the mouse capture.
        ReleaseCapture();

        // Check whether it's okay to move forward.
        BOOL moveOK = MoveForward();

        // If it is okay, do it.
        if (moveOK)
            DoMove();
}

void CAztecView::DoBackwardButton
    (CClientDC& clientDC, BITMAPINFO* pBmInfo)
{
    StretchDIBits(clientDC.m_hDC,
        183, 335, 52, 34,
        0, 182, 52, 34,
        pDoc->m_pSundryBits,
        pBmInfo, DIB_RGB_COLORS, SRCCOPY);
    m_backButtonPressed = FALSE;
    ReleaseCapture();
    BOOL moveOK = MoveBack();
    if (moveOK)
        DoMove();
}

void CAztecView::DoLeftButton
    (CClientDC& clientDC, BITMAPINFO* pBmInfo)
{
    StretchDIBits(clientDC.m_hDC,
        127, 297, 52, 72,
        0, 108, 52, 72,
        pDoc->m_pSundryBits,
        pBmInfo, DIB_RGB_COLORS, SRCCOPY);
    m_leftButtonPressed = FALSE;
    ReleaseCapture();
    TurnLeft();
    DoMove();
}

void CAztecView::DoRightButton
    (CClientDC& clientDC, BITMAPINFO* pBmInfo)
{
    StretchDIBits(clientDC.m_hDC,
        239, 297, 52, 72,
        108, 108, 52, 72,
        pDoc->m_pSundryBits,
        pBmInfo, DIB_RGB_COLORS, SRCCOPY);
    m_rightButtonPressed = FALSE;
    ReleaseCapture();
    TurnRight();
    DoMove();
}

void CAztecView::HandleForwardButton
    (CClientDC& clientDC, BITMAPINFO* pBmInfo)
{
    // Blit the depressed button image to the window.
    StretchDIBits(clientDC.m_hDC,
        183, 297, 52, 34,
        162, 182, 52, 34,
        pDoc->m_pSundryBits,
        pBmInfo, DIB_RGB_COLORS, SRCCOPY);

    // Set the button flag.
    m_forwardButtonPressed = TRUE;

    // Capture the mouse.
    SetCapture();
}

void CAztecView::HandleBackButton
    (CClientDC& clientDC, BITMAPINFO* pBmInfo)
{
    StretchDIBits(clientDC.m_hDC,
        183, 335, 52, 34,
        54, 182, 52, 34,
        pDoc->m_pSundryBits,
        pBmInfo, DIB_RGB_COLORS, SRCCOPY);
    m_backButtonPressed = TRUE;
    SetCapture();
}

void CAztecView::HandleLeftButton
    (CClientDC& clientDC, BITMAPINFO* pBmInfo)
{
    StretchDIBits(clientDC.m_hDC,
        127, 297, 52, 72,
        54, 108, 52, 72,
        pDoc->m_pSundryBits,
        pBmInfo, DIB_RGB_COLORS, SRCCOPY);
    m_leftButtonPressed = TRUE;
    SetCapture();
}

void CAztecView::HandleRightButton
    (CClientDC& clientDC, BITMAPINFO* pBmInfo)
{
    StretchDIBits(clientDC.m_hDC,
        239, 297, 52, 72,
        162, 108, 52, 72,
        pDoc->m_pSundryBits,
        pBmInfo, DIB_RGB_COLORS, SRCCOPY);
    m_rightButtonPressed = TRUE;
    SetCapture();
}

void CAztecView::DisplayCompass(CDC* pDC)
{
    // Get a pointer to the source
    // bitmap's BITMAPINFO structure.
    BITMAPINFO* pDibInfo =
        pDoc->m_pSundryDib->GetDibInfoPtr();

    UINT x;
    
    // Get the coordinates of the appropriate compass
    // face based on the player's facing direction.
    switch (pDoc->m_faceDir)
    {
        case North: x = 0; break;
        case West : x = 60; break;
        case South: x = 120; break;
        case East : x = 180; 
    }

    // Select and realize the palette.
    SelectPalette(pDC->m_hDC, m_hPalette, FALSE);
    RealizePalette(pDC->m_hDC);

    // Blit the compass face onto the window.
    StretchDIBits(pDC->m_hDC, 58, 309, 58, 58,
        x, 218, 58, 58, pDoc->m_pSundryBits, pDibInfo,
        DIB_RGB_COLORS, SRCCOPY);
}

void CAztecView::ShowDoor(UINT objectNum)
{
    switch (objectNum)
    {
        case 0:
            if (m_objects[2] == Wall)
                CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                    0, 88, m_pPartsDib,
                    610, 388, 10, 63);
            break;
        case 1:
            if (m_objects[3] == Wall)
                CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                    230, 88, m_pPartsDib,
                    596, 388, 10, 63);
                break;
        case 2:
            if (m_objects[4] == Wall)
                CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                    19, 88, m_pPartsDib,
                    574, 388, 66, 63);
                break;
        case 3:
            if (m_objects[4] == Wall)
                CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                    155, 88, m_pPartsDib,
                    574, 388, 66, 63);
                break;
        case 4:
            CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                87, 88, m_pPartsDib,
                574, 388, 66, 63);
            break;
        case 5:
            if (m_objects[7] == Wall)
                CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                    0, 78, m_pPartsDib,
                    555, 0, 77, 86);
                break;
        case 6:
            if (m_objects[7] == Wall)
                CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                    162, 78, m_pPartsDib,
                    545, 0, 77, 86);
                break;
        case 7:
            CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                77, 78, m_pPartsDib,
                545, 0, 86, 86);
            break;
        case 8:
            if (m_objects[10] == Wall)
                CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                    0, 52, m_pPartsDib,
                    396, 192, 50, 136);
            break;
        case 9:
            if (m_objects[10] == Wall)
                CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                    189, 52, m_pPartsDib,
                    319, 192, 51, 136);
            break;
        case 10:
            CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                52, 52, m_pPartsDib,
                319, 192, 134, 136);
    }
}

void CAztecView::ShowTreasure(UINT objectNum)
{
    int coords[13][6] =
    {
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        21, 140, 78, 446, 30, 12,
        185, 140, 78, 446, 30, 12,
        102, 140, 78, 446, 30, 12,
        0, 160, 92, 423, 35, 21,
        204, 160, 78, 423, 35, 21,
        90, 160, 78, 423, 49, 21,
        0, 180, 56, 423, 20, 43,
        220, 180, 0, 423, 20, 43,
        82, 180, 0, 423, 76, 43,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0
    };
    
    CopyDIBToWinGTrns((BYTE*)m_pWinGDibBits,
        coords[objectNum][0],
        coords[objectNum][1],
        m_pPartsDib,
        coords[objectNum][2],
        coords[objectNum][3],
        coords[objectNum][4],
        coords[objectNum][5], 253);
}

void CAztecView::CopyDIBToWinGTrns
    (BYTE* m_pWinGDibBits, UINT dstX, UINT dstY,
     CDib* pDib, UINT frmX, UINT frmY, UINT frmW, UINT frmH,
     UINT trnsColor)
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
            if (pDibBits[srcIndex] != trnsColor)
                m_pWinGDibBits[dstIndex] = pDibBits[srcIndex];
        }
}

void CAztecView::GetKey(UINT number)
{
    // Tell the player he found a key.
    ShowMessage(Key);

    // Record the key in the key array.
    pDoc->m_keys[number] = TRUE;

    // Update the key display.
    DisplayKeys();

    // Add to player's experience.
    UpdateExper(2);

    // Show new statistics.
    DisplayStats();
}

void CAztecView::GetPotion(UINT value)
{
    // Tell the player what he found.
    ShowMessage(Potion);

    // If there's room for another potion....
    if (pDoc->m_potionCount < 6)
    {
        // Increment the potion count.
        ++pDoc->m_potionCount;

        // Record the potion's value.
        pDoc->m_potionValues[pDoc->m_potionCount-1] = value;
    }

    // Update the potion display.
    DisplayPotions();

    // Add to player's experience.
    UpdateExper(2);

    // Show new statistics.
    DisplayStats();
}

void CAztecView::GetSword(UINT value)
{
    // Tell player what he found.
    ShowMessage(Sword);

    // Set the sword flag.
    pDoc->m_hasSword = TRUE;

    // Update the player's attack statistic.
    pDoc->m_playerAttack = value;

    // Record the player's new weapon type.
    pDoc->m_curSword = pDoc->m_floorNum - 1;

    // Add to player's experience.
    UpdateExper(2);

    // Display new statistics.
    DisplayStats();

    // Show new body with sword.
    DisplayBody();
}

void CAztecView::GetArmor(UINT value)
{
    // Tell the player what he found.
    ShowMessage(Armor);

    // Set the shield flag.
    pDoc->m_hasArmor = TRUE;

    // Update the player's defense statistic.
    pDoc->m_playerDefense = value;

    // Record the player's new armor type.
    pDoc->m_curArmor = pDoc->m_floorNum - 1;

    // Add to player's experience.
    UpdateExper(2);

    // Display new statistics.
    DisplayStats();

    // Show new body with shield.
    DisplayBody();
}

void CAztecView::GetTreasure(UINT value)
{
    // Tell the player that he found some treasure.
    ShowMessage(Treasure);

    // Increase the player's gold.
    pDoc->m_playerGold += value;

    // Add to player's experience.
    UpdateExper(2);

    // Display new statistics.
    DisplayStats();
}

void CAztecView::ShowMessage(UINT type)
{
    // Get DC for the window.
    CClientDC clientDC(this);

    // Select and realize the identity palette..
    SelectPalette(clientDC.m_hDC, m_hPalette, FALSE);
    RealizePalette(clientDC.m_hDC);

    UINT x, y;

    switch(type)
    {
       case Treasure: x = 0;   y = 0; break;
       case Armor:    x = 164; y = 0; break;
       case Key:      x = 0;   y = 94; break;
       case Potion:   x = 164; y = 94; break;
       case Sword:    x = 0;   y = 188; break;
    }

    // Copy the message to the WinG bitmap.
    CopyDIBToWinG((BYTE*)m_pWinGDibBits,
        10, 10, pDoc->m_pMessageDib,
        x, y, 165, 94);

    // Display the scene.
    WinGBitBlt(clientDC.m_hDC, 51, 51, 240, 240,
        m_hWinGDC, 0, 0);
}

void CAztecView::DisplayKeys()
{
    // Get a DC for the window.
    CClientDC clientDC(this);

    // Select and realize the palette.
    SelectPalette(clientDC.m_hDC, m_hPalette, FALSE);
    RealizePalette(clientDC.m_hDC);

    // Get a pointer to the source bitmap's
    // BITMAPINFO structure.
    BITMAPINFO* pBmInfo =
        pDoc->m_pSundryDib->GetDibInfoPtr();

    // Display up to six keys.
    for (UINT i=0; i<6; ++i)
    {
        // If the player has this key, show it.
        if (pDoc->m_keys[i])
            StretchDIBits(clientDC.m_hDC,
                311 + i * 32, 297, 32, 32,
                0, 448 - i * 34, 32, 32,
                pDoc->m_pSundryBits,
                pBmInfo, DIB_RGB_COLORS, SRCCOPY);
    }    
}

void CAztecView::DisplayPotions()
{
    // Get a DC for the window.
    CClientDC clientDC(this);

    // Select and realize the palette.
    SelectPalette(clientDC.m_hDC, m_hPalette, FALSE);
    RealizePalette(clientDC.m_hDC);

    // Erase the current potion display.
    clientDC.SelectStockObject(BLACK_BRUSH);
    clientDC.Rectangle(312, 351, 502, 384);

    // Get a pointer to the source bitmap's
    // BITMAPINFO structure.
    BITMAPINFO* pBmInfo =
        pDoc->m_pSundryDib->GetDibInfoPtr();

    // Display the player's potions.
    for (UINT i=0; i<pDoc->m_potionCount; ++i)
        StretchDIBits(clientDC.m_hDC,
            311 + i * 32, 351, 32, 32,
            102, 380, 32, 32,
            pDoc->m_pSundryBits,
            pBmInfo, DIB_RGB_COLORS, SRCCOPY);    
}

void CAztecView::DisplayBody()
{
    // Get a DC for the window.
    CClientDC clientDC(this);

    // Select and realize the palette.
    SelectPalette(clientDC.m_hDC, m_hPalette, FALSE);
    RealizePalette(clientDC.m_hDC);

    // Get a pointer to the source bitmap's
    // BITMAPINFO structure.
    BITMAPINFO* pBmInfo =
        pDoc->m_pSundryDib->GetDibInfoPtr();

    // If the user has no sword or shield,
    // display the normal body.
    if ((!pDoc->m_hasSword) && (!pDoc->m_hasArmor))
        StretchDIBits(clientDC.m_hDC,
            392, 52, 48, 87,
            152, 291, 48, 87,
            pDoc->m_pSundryBits,
            pBmInfo, DIB_RGB_COLORS, SRCCOPY);

    // Otherwise, display the battle-ready body.
    else
        StretchDIBits(clientDC.m_hDC,
            392, 52, 48, 87,
            102, 291, 48, 87,
            pDoc->m_pSundryBits,
            pBmInfo, DIB_RGB_COLORS, SRCCOPY);

    // Display the player's sword and shield.
    DisplaySword(&clientDC);
    DisplayArmor(&clientDC);
}

void CAztecView::DisplaySword(CClientDC* pClientDC)
{
    // Get a pointer to the source bitmap's
    // BITMAPINFO structure.
    BITMAPINFO* pBmInfo =
        pDoc->m_pSundryDib->GetDibInfoPtr();

    // If the player has a sword, show it.
    if (pDoc->m_hasSword)
        StretchDIBits(pClientDC->m_hDC,
            381, 46, 27, 93,
            202+(pDoc->m_curSword)*29, 285, 27, 93,
            pDoc->m_pSundryBits,
            pBmInfo, DIB_RGB_COLORS, SRCCOPY);    
}

void CAztecView::DisplayArmor(CClientDC* pClientDC)
{
    // Get a pointer to the source bitmap's
    // BITMAPINFO structure.
    BITMAPINFO* pBmInfo =
        pDoc->m_pSundryDib->GetDibInfoPtr();

    // If the player has a shield, show it.
    if (pDoc->m_hasArmor)
        StretchDIBits(pClientDC->m_hDC,
            421, 68, 32, 32,
            136+(pDoc->m_curArmor)*34, 448, 32, 32,
            pDoc->m_pSundryBits,
            pBmInfo, DIB_RGB_COLORS, SRCCOPY);    
}

void CAztecView::OpenDoor()
{
    // Get a DC for the window.
    CClientDC clientDC(this);

    // Select and realize the identity palette.
    SelectPalette(clientDC.m_hDC, m_hPalette, FALSE);
    RealizePalette(clientDC.m_hDC);

    // Set standard door coordinates.
    UINT dstY = 52;
    UINT dibY = 193;
    UINT dibH = 135;

    // Set special door coordinates for floor 1.
    if (pDoc->m_floorNum == 1)
    {
        dstY = 99;
        dibY = 239;
        dibH = 89;
    }

    // Perform four frames of animation.
    for (int i=0; i<4; ++i)
    {
        // Calculate and redraw the 3-D view.
        CalcView(FALSE);
        DrawView();

        // Display door parts every frame except the last.
        if (i < 3)
        {
            // Show the left side of the opening door.
            CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                52, dstY, m_pPartsDib,
                334+i*15, dibY, 52-i*15, dibH);

            // Show the right side of the opening door.
            CopyDIBToWinG((BYTE*)m_pWinGDibBits,
                134+i*15, dstY, m_pPartsDib,
                386, dibY, 52-i*15, dibH);
        }

        // Display the new 3-D scene.
        WinGBitBlt(clientDC.m_hDC, 51, 51, 240, 240,
            m_hWinGDC, 0, 0);
    }
}

void CAztecView::DisplayStats()
{
    // Get a DC for the window.
    CClientDC clientDC(this);

    // Select a black brush.
    clientDC.SelectStockObject(BLACK_BRUSH);

    // Erase the old stats
    for (UINT i=0; i<6; ++i)
        clientDC.Rectangle(470, 159+i*20, 502, 175+i*20);

    // Create and display the statistics text strings.
    char s[10];
    clientDC.SetTextColor(RGB(255,0,0));
    clientDC.SetBkColor(RGB(0,0,0));
    wsprintf(s, "%d", pDoc->m_playerLevel);
    clientDC.TextOut(470, 159, s, strlen(s));
    wsprintf(s, "%d", pDoc->m_playerExper);
    clientDC.TextOut(470, 179, s, strlen(s));
    wsprintf(s, "%d", pDoc->m_playerHP);
    clientDC.TextOut(470, 199, s, strlen(s));
    wsprintf(s, "%d", pDoc->m_playerGold);
    clientDC.TextOut(470, 219, s, strlen(s));
    wsprintf(s, "%d", pDoc->m_playerAttack);
    clientDC.TextOut(470, 239, s, strlen(s));
    wsprintf(s, "%d", pDoc->m_playerDefense);
    clientDC.TextOut(470, 259, s, strlen(s));
}

void CAztecView::UpdateExper(int exp)
{
    pDoc->m_playerExper += pDoc->m_floorNum * exp;
    CheckLevel();
}

void CAztecView::CheckLevel()
{
    // Get the player's current experience.
    UINT experience = pDoc->m_playerExper;

    // Get the experience needed to attain the next level.
    UINT experNeeded = m_nextLevel[pDoc->m_playerLevel-1];

    // If the player has enough experience, advance
    // him to the next level.
    if (experience >= experNeeded)
    {
        MessageBox("Your level is increased", "Level", MB_OK);
        pDoc->m_playerLevel += 1;
        DisplayStats();
    }
}

void CAztecView::ShowMonster(UINT squareNum)
{
    // Coordinates for placing monsters in the WinG bitmap.
    int monstercoords[13][6] =
    {
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        19, 88, 208, 360, 74, 74,
        155, 88, 208, 360, 74, 74,
        80, 88, 208, 360, 74, 74,
        0, 78, 34, 360, 70, 104,
        169, 78, 0, 360, 70, 104,
        67, 78, 0, 360, 104, 104,
        0, 52, 120, 0, 60, 180,
        179, 52, 0, 0, 60, 180,
        36, 52, 0, 0, 180, 180,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0
    };

    // Get a pointer to the appropriate monster images.
    CDib* pMonsterDib = GetMonsterDib(m_objNums[squareNum]);
    
    // Get a pointer to the monster bitmap's
    // BITMAPINFO structure.
    LPBITMAPINFO pBmInfo =
        pMonsterDib->GetDibInfoPtr();
    
    // Blit the monster image to the WinG bitmap.
    CopyDIBToWinGTrns((BYTE*)m_pWinGDibBits,
        monstercoords[squareNum][0],
        monstercoords[squareNum][1],
        pMonsterDib,
        monstercoords[squareNum][2],
        monstercoords[squareNum][3],
        monstercoords[squareNum][4],
        monstercoords[squareNum][5], 253);
}

CDib* CAztecView::GetMonsterDib(UINT monsterNum)
{
    CDib* pMonsterDib;

    // Choose a monster bitmap based on
    // the monster's item number.
    switch(monsterNum)
    {
        case 0: pMonsterDib = pDoc->m_pMonsterADib; break;
        case 1: pMonsterDib = pDoc->m_pMonsterBDib; break;
        case 2: pMonsterDib = pDoc->m_pMonsterCDib;
    }

    return pMonsterDib;
}

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

