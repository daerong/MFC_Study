
// Practice8_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPractice8_1App:
// �� Ŭ������ ������ ���ؼ��� Practice8_1.cpp�� �����Ͻʽÿ�.
//

class CPractice8_1App : public CWinApp
{
public:
	CPractice8_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPractice8_1App theApp;
