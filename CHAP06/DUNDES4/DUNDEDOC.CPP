// dundedoc.cpp : implementation of the CDundesDoc class
//

#include "stdafx.h"
#include "dundes.h"

#include "dundedoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDundesDoc

IMPLEMENT_DYNCREATE(CDundesDoc, CDocument)

BEGIN_MESSAGE_MAP(CDundesDoc, CDocument)
	//{{AFX_MSG_MAP(CDundesDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDundesDoc construction/destruction

CDundesDoc::CDundesDoc()
{
	// TODO: add one-time construction code here

}

CDundesDoc::~CDundesDoc()
{
}

BOOL CDundesDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Iterate through each square in the dungeon.
    for (UINT i=0; i<DUNGEONSIZE; ++i)
    {
        // Construct a new item for the current square.
        CItem* pItem = new CItem;
    
        // If the square must contain a wall...
        if (InStartingWalls(i))
        {
            pItem->iType = Wall;
            pItem->iNumber = 0;
            pItem->iValue = 0;
        }

        // If the square must contain the level's exit...
        else if (i == 61)
        {
            pItem->iType = Door;
            pItem->iNumber = 5;
            pItem->iValue = 0;
        }

        // If the square must contain
        // the level's boss monster...
        else if ( i == 62)
        {
            pItem->iType = Monster;
            pItem->iNumber = 2;
            pItem->iValue = 50;
        }

        // Otherwise, the square is empty...
        else
        {
            pItem->iType = Empty;
            pItem->iNumber = 0;
            pItem->iValue = 0;
        }

        // Add the new item to the array.
        m_Dungeon.Add(pItem);
    }

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDundesDoc serialization

void CDundesDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here

	    ///////////////////////////////////////
        ///////////////////////////////////////
        // START CUSTOM CODE
        ///////////////////////////////////////
        ///////////////////////////////////////

        // Iterate through each dungeon square, sending
        // its contents to the output stream.
        for (UINT i=0; i<DUNGEONSIZE; ++i)
        {
            CItem* pItem = (CItem*) m_Dungeon.GetAt(i);
            ar << pItem->iType;
            ar << pItem->iNumber;
            ar << pItem->iValue;
        }

        ///////////////////////////////////////
        ///////////////////////////////////////
        // END CUSTOM CODE
        ///////////////////////////////////////
        ///////////////////////////////////////
}
	else
	{
		// TODO: add loading code here

        ///////////////////////////////////////
        ///////////////////////////////////////
        // START CUSTOM CODE
        ///////////////////////////////////////
        ///////////////////////////////////////

        // Iterate through each dungeon square,
        // loading its contents from the input stream.
        for (UINT i=0; i<DUNGEONSIZE; ++i)
        {
            CItem* pItem = new CItem;
            ar >> pItem->iType;
            ar >> pItem->iNumber;
            ar >> pItem->iValue;
            m_Dungeon.Add(pItem);
        }

        // Tell the view to update its display.
        UpdateAllViews(NULL);

        ///////////////////////////////////////
        ///////////////////////////////////////
        // END CUSTOM CODE
        ///////////////////////////////////////
        ///////////////////////////////////////
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDundesDoc diagnostics

#ifdef _DEBUG
void CDundesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDundesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDundesDoc commands

void CDundesDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Get the size of the array.
    UINT size = m_Dungeon.GetSize();

    // If the array contains pointers, delete the
    // pointers and empty the array.
    if (size > 0)
    {
        for (UINT i=0; i<DUNGEONSIZE; ++i)
            delete m_Dungeon.GetAt(i);
        m_Dungeon.RemoveAll();
    }

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

	CDocument::DeleteContents();
}

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

BOOL CDundesDoc::InStartingWalls(int squareNum)
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

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

