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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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
