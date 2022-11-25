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
