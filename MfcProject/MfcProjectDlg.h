
// MfcProjectDlg.h : 헤더 파일
//

#include "DlgImage.h"
#pragma once


// CMfcProjectDlg 대화 상자
class CMfcProjectDlg : public CDialogEx
{
// 생성입니다.
public:
	CMfcProjectDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	CImage m_Image;
	CDlgImage *m_pDlgImage;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMakeCircle();
	void InitImage();
	void UpdateDisplay();
	void drawCircle(CDC* pDC, int x, int y, int radius);
	afx_msg void OnEnChangeCircleSize();
	afx_msg void OnDestroy();
	void drawCross(CDC* pDC, int x, int y, int size);
	void drawHollowCircle(CDC* pDC, int centerX, int centerY, int radius);
};
