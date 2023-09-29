
// MfcProjectDlg.h : ��� ����
//

#include "DlgImage.h"
#pragma once


// CMfcProjectDlg ��ȭ ����
class CMfcProjectDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMfcProjectDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CImage m_Image;
	CDlgImage *m_pDlgImage;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
