// wingedoc.cpp : implementation of the CWingexDoc class
//

#include "stdafx.h"
#include "wingex.h"

#include "wingedoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWingexDoc

IMPLEMENT_DYNCREATE(CWingexDoc, CDocument)

BEGIN_MESSAGE_MAP(CWingexDoc, CDocument)
	//{{AFX_MSG_MAP(CWingexDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWingexDoc construction/destruction

CWingexDoc::CWingexDoc()
{
	// TODO: add one-time construction code here
}

CWingexDoc::~CWingexDoc()
{
}

BOOL CWingexDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CWingexDoc serialization

void CWingexDoc::Serialize(CArchive& ar)
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
// CWingexDoc diagnostics

#ifdef _DEBUG
void CWingexDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWingexDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWingexDoc commands
