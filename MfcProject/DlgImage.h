#pragma once


// CDlgImage 대화 상자입니다.
#define MAX_POINT	100

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgImage();
	CImage m_Image;
	int m_nDataCount = 0;
	CPoint m_ptData[MAX_POINT];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	void InitImage();
	afx_msg void OnPaint();
	void drawData(CDC* pDC);
};
