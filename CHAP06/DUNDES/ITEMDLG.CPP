// itemdlg.cpp : implementation file
//

#include "stdafx.h"
#include "dundes.h"
#include "itemdlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CItemDlg dialog


CItemDlg::CItemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CItemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CItemDlg)
	m_number = 0;
	m_value = 0;
	//}}AFX_DATA_INIT
}


void CItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CItemDlg)
	DDX_Text(pDX, IDC_NUMBER, m_number);
	DDX_Text(pDX, IDC_VALUE, m_value);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CItemDlg, CDialog)
	//{{AFX_MSG_MAP(CItemDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CItemDlg message handlers
