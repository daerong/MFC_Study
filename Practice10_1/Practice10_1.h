
// Practice10_1.h : Practice10_1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CPractice10_1App:
// �� Ŭ������ ������ ���ؼ��� Practice10_1.cpp�� �����Ͻʽÿ�.
//

class CPractice10_1App : public CWinApp
{
public:
	CPractice10_1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPractice10_1App theApp;
