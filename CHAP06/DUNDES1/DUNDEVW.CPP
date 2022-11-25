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

/////////////////////////////////////////////////////////////////////////////
// CDundesView

IMPLEMENT_DYNCREATE(CDundesView, CView)

BEGIN_MESSAGE_MAP(CDundesView, CView)
	//{{AFX_MSG_MAP(CDundesView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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

}

CDundesView::~CDundesView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CDundesView drawing

void CDundesView::OnDraw(CDC* pDC)
{
	CDundesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
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
