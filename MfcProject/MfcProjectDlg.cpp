
// MfcProjectDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MfcProject.h"
#include "MfcProjectDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include "MfcProjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTSartup /subsystem:console")

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.
using namespace std;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMfcProjectDlg ��ȭ ����



CMfcProjectDlg::CMfcProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMfcProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MAKE_CIRCLE, &CMfcProjectDlg::OnBnClickedMakeCircle)
	ON_EN_CHANGE(IDC_CIRCLE_SIZE, &CMfcProjectDlg::OnEnChangeCircleSize)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CMfcProjectDlg �޽��� ó����

BOOL CMfcProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//InitImage();
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0, 0, 640, 480);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMfcProjectDlg::InitImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_Image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_Image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_Image.GetPitch();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();

	memset(fm, 0xff, nWidth*nHeight);
}

void CMfcProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMfcProjectDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
	if (m_Image) {
		m_Image.Draw(dc, 0, 0);
	}

	//drawData(&dc);
	//drawCircle(&dc, 320, 240, 50);
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMfcProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMfcProjectDlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_pDlgImage->m_Image.Draw(dc, 0, 0);
}

void CMfcProjectDlg::OnBnClickedMakeCircle()
{
	//�̹��� ũ��
	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();

	// �̹��� �ʱ�ȭ
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
	memset(fm, 0xff, nWidth * nHeight);
	UpdateDisplay();

	// ���� ������
	int radius = GetDlgItemInt(IDC_CIRCLE_SIZE);

	// ���ڸ�� ũ��
	int size = 10;

	// �Է°��� ������ �⺻���� 20�� ���
	if (radius <= 0) {
		radius = 20;
	}
	cout << "���� ũ�� : " << radius << endl;

	// ��ư�� Ŭ������ �� ���� �׸��� �ڵ�
	CClientDC dc(m_pDlgImage);

	// ���� �߽� ��ǥ�� �������� ����
	int centerX = rand() % 640; // ���� �߾�
	int centerY = rand() % 480; // ���� �߾�

	drawHollowCircle(&dc, centerX, centerY, radius * 2);
	drawCircle(&dc, centerX, centerY, radius);
	drawCross(&dc, centerX, centerY, size);
	

	cout << "��ǥ : " << centerX << "," << centerY << endl;
}

void CMfcProjectDlg::drawCircle(CDC* pDC, int x, int y, int radius)
{
	CBrush brush(RGB(0, 0, 0));
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	pDC->Ellipse(x - radius, y - radius, x + radius, y + radius);
	pDC->SelectObject(pOldBrush);
}


void CMfcProjectDlg::OnEnChangeCircleSize()
{

}


void CMfcProjectDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	if (m_pDlgImage) delete m_pDlgImage;
}


void CMfcProjectDlg::drawCross(CDC* pDC, int x, int y, int size)
{
	// ���� ��� �׸� �� ����� �� ����
	CPen pen(PS_SOLID, 2, RGB(0xff, 0xff, 0xff)); // 2�ȼ� ����

	// ���� ���� �����ϰ� �� ������ ����
	CPen* pOldPen = pDC->SelectObject(&pen);

	// ���μ� �׸���
	pDC->MoveTo(x - size, y);
	pDC->LineTo(x + size, y);

	// ���μ� �׸���
	pDC->MoveTo(x, y - size);
	pDC->LineTo(x, y + size);

	// ���� ������ ����
	pDC->SelectObject(pOldPen);
}

void CMfcProjectDlg::drawHollowCircle(CDC* pDC, int centerX, int centerY, int radius)
{
	CPen pen(PS_SOLID, 2, RGB(255, 255, 0)); // �����, �β� 2
	CPen* pOldPen = pDC->SelectObject(&pen);

	int left = centerX - radius;
	int top = centerY - radius;
	int right = centerX + radius;
	int bottom = centerY + radius;

	pDC->Ellipse(left, top, right, bottom);

	pDC->SelectObject(pOldPen);
}

