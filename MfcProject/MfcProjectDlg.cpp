
// MfcProjectDlg.cpp : 구현 파일
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

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
using namespace std;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMfcProjectDlg 대화 상자



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


// CMfcProjectDlg 메시지 처리기

BOOL CMfcProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	//InitImage();
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0, 0, 640, 480);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMfcProjectDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (m_Image) {
		m_Image.Draw(dc, 0, 0);
	}

	//drawData(&dc);
	//drawCircle(&dc, 320, 240, 50);
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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
	//이미지 크기
	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();

	// 이미지 초기화
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
	memset(fm, 0xff, nWidth * nHeight);
	UpdateDisplay();

	// 원의 반지름
	int radius = GetDlgItemInt(IDC_CIRCLE_SIZE);

	// 십자모양 크기
	int size = 10;

	// 입력값이 없으면 기본값인 20을 사용
	if (radius <= 0) {
		radius = 20;
	}
	cout << "원의 크기 : " << radius << endl;

	// 버튼을 클릭했을 때 원을 그리는 코드
	CClientDC dc(m_pDlgImage);

	// 원의 중심 좌표와 반지름을 설정
	int centerX = rand() % 640; // 가로 중앙
	int centerY = rand() % 480; // 세로 중앙

	drawHollowCircle(&dc, centerX, centerY, radius * 2);
	drawCircle(&dc, centerX, centerY, radius);
	drawCross(&dc, centerX, centerY, size);
	

	cout << "좌표 : " << centerX << "," << centerY << endl;
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
	// 십자 모양 그릴 때 사용할 펜 생성
	CPen pen(PS_SOLID, 2, RGB(0xff, 0xff, 0xff)); // 2픽셀 굵기

	// 현재 펜을 저장하고 새 펜으로 설정
	CPen* pOldPen = pDC->SelectObject(&pen);

	// 가로선 그리기
	pDC->MoveTo(x - size, y);
	pDC->LineTo(x + size, y);

	// 세로선 그리기
	pDC->MoveTo(x, y - size);
	pDC->LineTo(x, y + size);

	// 이전 펜으로 복원
	pDC->SelectObject(pOldPen);
}

void CMfcProjectDlg::drawHollowCircle(CDC* pDC, int centerX, int centerY, int radius)
{
	CPen pen(PS_SOLID, 2, RGB(255, 255, 0)); // 노란색, 두께 2
	CPen* pOldPen = pDC->SelectObject(&pen);

	int left = centerX - radius;
	int top = centerY - radius;
	int right = centerX + radius;
	int bottom = centerY + radius;

	pDC->Ellipse(left, top, right, bottom);

	pDC->SelectObject(pOldPen);
}

