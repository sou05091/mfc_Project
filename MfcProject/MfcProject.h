
// MfcProject.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMfcProjectApp:
// �� Ŭ������ ������ ���ؼ��� MfcProject.cpp�� �����Ͻʽÿ�.
//

class CMfcProjectApp : public CWinApp
{
public:
	CMfcProjectApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMfcProjectApp theApp;