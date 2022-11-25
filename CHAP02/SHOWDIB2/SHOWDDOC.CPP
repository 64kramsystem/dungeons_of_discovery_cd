// showddoc.cpp : implementation of the CShowdibDoc class
//

#include "stdafx.h"
#include "showdib.h"

#include "showddoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowdibDoc

IMPLEMENT_DYNCREATE(CShowdibDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowdibDoc, CDocument)
	//{{AFX_MSG_MAP(CShowdibDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowdibDoc construction/destruction

CShowdibDoc::CShowdibDoc()
{
	// TODO: add one-time construction code here

}

CShowdibDoc::~CShowdibDoc()
{
}

BOOL CShowdibDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CShowdibDoc serialization

void CShowdibDoc::Serialize(CArchive& ar)
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
// CShowdibDoc diagnostics

#ifdef _DEBUG
void CShowdibDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowdibDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowdibDoc commands
