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

}

CAztecDoc::~CAztecDoc()
{
}

BOOL CAztecDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

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
