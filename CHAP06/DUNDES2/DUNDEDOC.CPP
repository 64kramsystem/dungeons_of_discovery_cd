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

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDundesDoc serialization

void CDundesDoc::Serialize(CArchive& ar)
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
