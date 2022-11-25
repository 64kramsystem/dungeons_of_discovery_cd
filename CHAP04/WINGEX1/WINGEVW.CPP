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

}

CWingexView::~CWingexView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CWingexView drawing

void CWingexView::OnDraw(CDC* pDC)
{
	CWingexDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
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
