// wingedoc.h : interface of the CWingexDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CWingexDoc : public CDocument
{
protected: // create from serialization only
	CWingexDoc();
	DECLARE_DYNCREATE(CWingexDoc)

// Attributes
public:
// Operations
public:

// Implementation
public:
	virtual ~CWingexDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual BOOL OnNewDocument();

// Generated message map functions
protected:
	//{{AFX_MSG(CWingexDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
