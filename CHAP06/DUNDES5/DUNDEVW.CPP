// dundevw.cpp : implementation of the CDundesView class
//

#include "stdafx.h"
#include "dundes.h"

#include "dundedoc.h"
#include "dundevw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

#include "itemdlg.h"

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CDundesView

IMPLEMENT_DYNCREATE(CDundesView, CView)

BEGIN_MESSAGE_MAP(CDundesView, CView)
	//{{AFX_MSG_MAP(CDundesView)
	ON_COMMAND(ID_ITEMS_ARMOR, OnItemsArmor)
	ON_UPDATE_COMMAND_UI(ID_ITEMS_ARMOR, OnUpdateItemsArmor)
	ON_COMMAND(ID_ITEMS_DOOR, OnItemsDoor)
	ON_UPDATE_COMMAND_UI(ID_ITEMS_DOOR, OnUpdateItemsDoor)
	ON_COMMAND(ID_ITEMS_KEY, OnItemsKey)
	ON_UPDATE_COMMAND_UI(ID_ITEMS_KEY, OnUpdateItemsKey)
	ON_COMMAND(ID_ITEMS_MONSTER, OnItemsMonster)
	ON_UPDATE_COMMAND_UI(ID_ITEMS_MONSTER, OnUpdateItemsMonster)
	ON_COMMAND(ID_ITEMS_POTION, OnItemsPotion)
	ON_UPDATE_COMMAND_UI(ID_ITEMS_POTION, OnUpdateItemsPotion)
	ON_COMMAND(ID_ITEMS_SWORD, OnItemsSword)
	ON_UPDATE_COMMAND_UI(ID_ITEMS_SWORD, OnUpdateItemsSword)
	ON_COMMAND(ID_ITEMS_TREASURE, OnItemsTreasure)
	ON_UPDATE_COMMAND_UI(ID_ITEMS_TREASURE, OnUpdateItemsTreasure)
	ON_COMMAND(ID_ITEMS_WALL, OnItemsWall)
	ON_UPDATE_COMMAND_UI(ID_ITEMS_WALL, OnUpdateItemsWall)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDundesView construction/destruction

CDundesView::CDundesView()
{
	// TODO: add construction code here

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    m_mode = Wall;
    m_Colors[Empty] = RGB(255,255,255);
    m_Colors[Wall] = RGB(128,128,128);
    m_Colors[Door] = RGB(0,0,255);
    m_Colors[Key] = RGB(255,255,0);
    m_Colors[Monster] = RGB(255,0,0);
    m_Colors[Treasure] = RGB(0,128,0);
    m_Colors[Sword] = RGB(255,0,255);
    m_Colors[Armor] = RGB(0,255,255);
    m_Colors[Potion] = RGB(0,255,0);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

CDundesView::~CDundesView()
{
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    delete m_pBitmap;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////
// CDundesView drawing

void CDundesView::OnDraw(CDC* pDC)
{
	CDundesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Create a memory DC that's compatible
    // with the paint DC.
    CDC memDC;
    memDC.CreateCompatibleDC(pDC);

    // Select the bitmap into the memory DC.
    memDC.SelectObject(m_pBitmap);

    // Blit the bitmap onto the screen.
    pDC->BitBlt(0, 0, 640, 480, &memDC, 0, 0, SRCCOPY);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

}

/////////////////////////////////////////////////////////////////////////////
// CDundesView printing

BOOL CDundesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDundesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDundesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDundesView diagnostics

#ifdef _DEBUG
void CDundesView::AssertValid() const
{
	CView::AssertValid();
}

void CDundesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDundesDoc* CDundesView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDundesDoc)));
	return (CDundesDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDundesView message handlers

void CDundesView::OnItemsArmor() 
{
	// TODO: Add your command handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    m_mode = Armor;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnUpdateItemsArmor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    if (m_mode == Armor)
        pCmdUI->SetCheck(TRUE);
    else
        pCmdUI->SetCheck(FALSE);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnItemsDoor() 
{
	// TODO: Add your command handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    m_mode = Door;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnUpdateItemsDoor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    if (m_mode == Door)
        pCmdUI->SetCheck(TRUE);
    else
        pCmdUI->SetCheck(FALSE);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnItemsKey() 
{
	// TODO: Add your command handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    m_mode = Key;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnUpdateItemsKey(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    if (m_mode == Key)
        pCmdUI->SetCheck(TRUE);
    else
        pCmdUI->SetCheck(FALSE);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnItemsMonster() 
{
	// TODO: Add your command handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    m_mode = Monster;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnUpdateItemsMonster(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    if (m_mode == Monster)
        pCmdUI->SetCheck(TRUE);
    else
        pCmdUI->SetCheck(FALSE);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnItemsPotion() 
{
	// TODO: Add your command handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    m_mode = Potion;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnUpdateItemsPotion(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    if (m_mode == Potion)
        pCmdUI->SetCheck(TRUE);
    else
        pCmdUI->SetCheck(FALSE);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnItemsSword() 
{
	// TODO: Add your command handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    m_mode = Sword;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnUpdateItemsSword(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    if (m_mode == Sword)
        pCmdUI->SetCheck(TRUE);
    else
        pCmdUI->SetCheck(FALSE);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnItemsTreasure() 
{
	// TODO: Add your command handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    m_mode = Treasure;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnUpdateItemsTreasure(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    if (m_mode == Treasure)
        pCmdUI->SetCheck(TRUE);
    else
        pCmdUI->SetCheck(FALSE);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnItemsWall() 
{
	// TODO: Add your command handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    m_mode = Wall;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnUpdateItemsWall(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    if (m_mode == Wall)
        pCmdUI->SetCheck(TRUE);
    else
        pCmdUI->SetCheck(FALSE);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

int CDundesView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Get a device context for the window.	
    CClientDC clientDC(this);

    // Create a bitmap compatible with the window DC.
    m_pBitmap = new CBitmap;
    m_pBitmap->CreateCompatibleBitmap(&clientDC, 640, 480);

    // Create a memory DC compatible with the window DC.
    CDC memDC;
    memDC.CreateCompatibleDC(&clientDC);

    // Select the bitmap into the memory DC.
    memDC.SelectObject(m_pBitmap);

    // Clear the memory DC to white.
    CBrush* brush = new CBrush(RGB(255,255,255));
    memDC.FillRect(CRect(0, 0, 639, 479), brush);
    delete brush;

    // Draw the dungeon grid on the memory bitmap.
    DrawGrid(&memDC);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

	return 0;
}

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

void CDundesView::DrawGrid(CDC* dc)
{
    // Draw the grid's vertical lines.
    for (int x=0; x<=COLSIZE; ++x)
    {
        dc->MoveTo(SQUARESIZE*x+OFFSET, OFFSET);
        dc->LineTo(SQUARESIZE*x+OFFSET,
            SQUARESIZE*COLSIZE+OFFSET);
    }
    
    // Draw the grid's horizontal lines.
    for (int y=0; y<=ROWSIZE; ++y)
    {
        dc->MoveTo(OFFSET, SQUARESIZE*y+OFFSET);
        dc->LineTo(SQUARESIZE*ROWSIZE+OFFSET,
           SQUARESIZE*y+OFFSET);
    }
}

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////


void CDundesView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Get a pointer to the document object.
    CDundesDoc* pDoc = (CDundesDoc*) GetDocument();

    // Create a DC for the window.
    CClientDC clientDC(this);

    // Create a memory DC that's
    // compatible with the window DC.
    CDC memDC;
    memDC.CreateCompatibleDC(&clientDC);

    // Select the dungeon-grid bitmap into the memory DC.
    memDC.SelectObject(m_pBitmap);

    // Iterate through each square in the dungeon grid.
    for (int i=0; i<DUNGEONSIZE; ++i)
    {
        // Get the currently indexed item.
        CItem* pItem = (CItem*) pDoc->m_Dungeon.GetAt(i);

        // Create and select a brush for the item.
        CBrush* brush = new CBrush(m_Colors[pItem->iType]);
        CBrush* oldBrush = memDC.SelectObject(brush);

        // Calculate the pixel position to draw the square.
        UINT row = i / ROWSIZE;
        UINT col = i - (row * ROWSIZE);
        UINT x = col * SQUARESIZE + OFFSET;
        UINT y = row * SQUARESIZE + OFFSET;

        // Draw the square on the bitmap.
        memDC.Rectangle(x, y,
            x+SQUARESIZE+1, y+SQUARESIZE+1);

        // Restore the DC and delete the brush.
        memDC.SelectObject(oldBrush);
        delete brush;
    }

    // Force the window to redraw.
    Invalidate();

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

void CDundesView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // If the user clicked in the dungeon grid...
    if (ClickInsideGrid(point))
    {
        // Calculate the square's column and row.
        UINT col = ((point.x - OFFSET) / SQUARESIZE) *
            SQUARESIZE + OFFSET;
        UINT row = ((point.y - OFFSET) / SQUARESIZE) *
            SQUARESIZE + OFFSET;

        // Calculate the square's number.
        UINT squareNum = (col / SQUARESIZE) +
            (row / SQUARESIZE) * ROWSIZE;
 
        // If the square is not unchangeable...
        if (!InStartingWalls(squareNum))
            HandleLeftClick(squareNum, col, row);
    }

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

	CView::OnLButtonDown(nFlags, point);
}

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

BOOL CDundesView::ClickInsideGrid(CPoint point)
{
    // Calculate width and height of grid in pixels.
    int gridSize = SQUARESIZE * ROWSIZE;

    // If the user clicked within the grid, return TRUE.
    if ((point.x < gridSize + OFFSET) && (point.x > OFFSET) &&
        (point.y < gridSize + OFFSET) && (point.y > OFFSET))
        return TRUE;

    // Otherwise, return FALSE.
    return FALSE;
}
BOOL CDundesView::InStartingWalls(int squareNum)
{
    // Determine whether the square is one of
    // the default wall squares.
    if ((squareNum > -1) && (squareNum < ROWSIZE))
        return TRUE;
    if ((squareNum > (COLSIZE-1)*ROWSIZE) &&
        (squareNum < COLSIZE*ROWSIZE))
        return TRUE;
    if ((squareNum % ROWSIZE == 0) ||
        (squareNum % ROWSIZE == ROWSIZE-1))
        return TRUE;
    if ((squareNum == 93) || (squareNum == 94))
         return TRUE;
    return FALSE;
}
void CDundesView::HandleLeftClick(UINT squareNum,
    UINT col, UINT row)
{
    // Get a pointer to the document object.
    CDundesDoc* pDoc = GetDocument();

    // Get the item at the selected square.
    CItem* pItem =
        (CItem*) pDoc->m_Dungeon.GetAt(squareNum);

    // If the square already holds something...
    if (pItem->iType != Empty)
    {
        // ...empty the square in memory...
        pItem->iType = Empty;

        // ...and redraw the square.
        CBrush* brush = new CBrush(RGB(255,255,255));
        DrawSquare(col, row, brush);
    }
    
    // Otherwise, place the appropriate
    // type of item in the square.
    else if (m_mode == Wall)
        PlaceWall(pItem, col, row);
    else
        PlaceItem(pItem, col, row, m_mode);
 
    // Tell the document object
    // that it's been modified.
    pDoc->SetModifiedFlag();
}
void CDundesView::PlaceWall(CItem* pItem, UINT x, UINT y)
{
    // Initialize the new wall item.
    pItem->iType = Wall;
    pItem->iNumber = 0;
    pItem->iValue = 0;

    // Create a brush for the wall from the color array.
    CBrush* brush = new CBrush(m_Colors[Wall]);

    // Draw the new wall square on the screen.
    DrawSquare(x, y, brush);
}

void CDundesView::PlaceItem(CItem* pItem,
    UINT x, UINT y, UINT itemType)
{
    // Display the Item dialog box.
    CItemDlg dlg;
    dlg.m_number = 0;
    dlg.m_value = 0;
    UINT result = dlg.DoModal();
    
    // If the user exits the dialog box with the OK button...
    if (result == IDOK)
    {
        // Get the requested item number.
        UINT itemNumber = dlg.m_number;

        // See whether the item already exists.
        WORD itemValue;
        BOOL found =
            FindItem(itemType, itemNumber, itemValue);
        result = IDNO;
        
        // No such item yet, so ask if user wants
        // to create a new item of the requested type.
        if (!found)
            result = MessageBox("Create new item?",
                "Item", MB_ICONQUESTION | MB_YESNO);

        // If it's okay to create the item...
        if ((result == IDYES) || (found))
        {
            // Change the item object from empty
            // to the new item.
            pItem->iType = itemType;
            pItem->iNumber = itemNumber;
            if (found)
                pItem->iValue = itemValue;
            else
                pItem->iValue = dlg.m_value;

            // Make sure the item number is within
            // proper bounds for the item type.
            if (NotValidItem(pItem))
            {
                MessageBox("Item Number Not Valid",
                    "Invalid Item",
                    MB_ICONEXCLAMATION | MB_OK);
                pItem->iType = Empty;
                itemType = Empty;
                pItem->iNumber = 0;
                pItem->iValue = 0;
            }
            // Draw the new item on the screen.
            CBrush* brush = new CBrush(m_Colors[itemType]);
            DrawSquare(x, y, brush);
        }
    }
}
BOOL CDundesView::NotValidItem(CItem* pItem)
{
    BOOL notValid = FALSE;

    // Check each item type for valid item numbers.
    switch(pItem->iType)
    {
        case Door:
        case Key:
            if (pItem->iNumber > 5)
                notValid = TRUE;
            break;
        case Monster:
            if (pItem->iNumber > 2)
                notValid = TRUE;
            break;
        case Sword:
        case Armor:
            if (pItem->iNumber > 0)
                notValid = TRUE;
    }

    return notValid;
}
BOOL CDundesView::FindItem(WORD itemType,
    WORD itemNum, WORD& itemValue)
{
    // Get a pointer to the document object.
    CDundesDoc* pDoc = GetDocument();

    BOOL found = FALSE;
    int i = 0;
    
    // Search through the item array until the item
    // is found or until the loop reaches the end
    // of the array.
    while ((!found) && (i<DUNGEONSIZE))
    {
        // Get the currently indexed item.
        CItem* pItem = (CItem*) pDoc->m_Dungeon.GetAt(i);

        // Check whether the items match.
        if ((pItem->iType == itemType) &&
            (pItem->iNumber == itemNum))
        {
            itemValue = pItem->iValue;
            found = TRUE;
        }

        // Increment index variable.
        ++i;
    }
    
    return found;
}
void CDundesView::DrawSquare(UINT x, UINT y, CBrush* brush)
{
    // Create a DC for the window and a memory
    // DC compatible with the window DC.
    CClientDC clientDC(this);
    CDC memDC;
    memDC.CreateCompatibleDC(&clientDC);

    // Select the dungeon-grid bitmap into the memory DC.
    memDC.SelectObject(m_pBitmap);

    // Select the brush into both DCs.
    CBrush* oldBrush1 = memDC.SelectObject(brush);
    CBrush* oldBrush2 = clientDC.SelectObject(brush);

    // Draw the square in both DCs.
    memDC.Rectangle(x, y,
        x + SQUARESIZE + 1, y + SQUARESIZE + 1);
    clientDC.Rectangle(x, y,
        x + SQUARESIZE + 1, y + SQUARESIZE + 1);

    // Restore DCs and delete the brush.
    memDC.SelectObject(oldBrush1);
    clientDC.SelectObject(oldBrush2);
    delete brush;
}

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

