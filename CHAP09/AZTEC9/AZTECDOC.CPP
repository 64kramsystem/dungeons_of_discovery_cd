// aztecdoc.cpp : implementation of the CAztecDoc class
//

#include "stdafx.h"
#include "aztec.h"

#include "aztecdoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAztecDoc

IMPLEMENT_DYNCREATE(CAztecDoc, CDocument)

BEGIN_MESSAGE_MAP(CAztecDoc, CDocument)
	//{{AFX_MSG_MAP(CAztecDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAztecDoc construction/destruction

CAztecDoc::CAztecDoc()
{
	// TODO: add one-time construction code here

    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    m_pPartsADib = new CDib("LEVEL01A.BMP");
    m_pPartsBDib = new CDib("LEVEL01B.BMP");
    m_pLevelFileName = new CString("LEVEL01.DUN");
    m_gameOver = FALSE;
    m_pPanelDib = new CDib("panel.bmp");
    m_pSundryDib = new CDib("sundry.bmp");
    m_pMessageDib = new CDib("message.bmp");
    m_pPanelBits = m_pPanelDib->GetDibBitsPtr();
    m_pSundryBits = m_pSundryDib->GetDibBitsPtr();

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

CAztecDoc::~CAztecDoc()
{
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    delete m_pPartsADib;
    delete m_pPartsBDib;
    delete m_pLevelFileName;
    delete m_pPanelDib;
    delete m_pSundryDib;
    delete m_pMessageDib;

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////
}

BOOL CAztecDoc::OnNewDocument()
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

    // Initialize game variables for a new game.
    m_floorNum = 1;
    m_playerX = 1;
    m_playerY = 1;
    m_faceDir = East;

    m_potionCount = 0;
    m_curSword = 0;
    m_curArmor = 0;
    m_hasSword = FALSE;
    m_hasArmor = FALSE;

    for (UINT i=0; i<6; ++i)
    {
        m_keys[i] = FALSE;
        m_potionValues[i] = 0;
    }

    // Load data for the current floor.
    LoadLevel();

    // Notify the view of a change in the document.
    UpdateAllViews(NULL);

    ///////////////////////////////////////
    ///////////////////////////////////////
    // END CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAztecDoc serialization

void CAztecDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAztecDoc diagnostics

#ifdef _DEBUG
void CAztecDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAztecDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAztecDoc commands

///////////////////////////////////////
///////////////////////////////////////
// START CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

void CAztecDoc::LoadLevel()
{
    CFile file;
    char far* pFileName;

    // Get a pointer to the current file name.
    pFileName = m_pLevelFileName->GetBuffer(12);

    // Open the dungeon data file for the current floor.
    BOOL opened = file.Open(pFileName, CFile::modeRead);

    // If the file opened okay...
    if (opened)
    {
        // Construct an archive object from the file.
        CArchive ar(&file, CArchive::load);
   
           // Read all dungeon items and add them
           // to the item array.
        for (int i=0; i<DUNGEONSIZE; ++i)
        {
            CItem* pItem = new CItem;
            ar >> pItem->iType;
            ar >> pItem->iNumber;
            ar >> pItem->iValue;
            m_Dungeon.Add(pItem);
        }
        
        // Close the archive object and the file.
        ar.Close();
        file.Close();
    }

    // If there's an error loading the data,
    // end the game.
    else
        m_gameOver = TRUE;
}

///////////////////////////////////////
///////////////////////////////////////
// END CUSTOM CODE
///////////////////////////////////////
///////////////////////////////////////

void CAztecDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	
    ///////////////////////////////////////
    ///////////////////////////////////////
    // START CUSTOM CODE
    ///////////////////////////////////////
    ///////////////////////////////////////

    // Get the number of elements in the m_Dungeon array.
    UINT size = m_Dungeon.GetSize();

    // If the array isn't empty, delete its contents.
    if (size > 0)
    {
        for (int i=0; i<DUNGEONSIZE; ++i)
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
