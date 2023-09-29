#pragma once


// CDlgImage ��ȭ �����Դϴ�.
#define MAX_POINT	100

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgImage();
	CImage m_Image;
	int m_nDataCount = 0;
	CPoint m_ptData[MAX_POINT];

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	void InitImage();
	afx_msg void OnPaint();
	void drawData(CDC* pDC);
};
