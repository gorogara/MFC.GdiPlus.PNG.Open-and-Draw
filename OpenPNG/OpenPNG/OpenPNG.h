
// OpenPNG.h : OpenPNG ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// COpenPNGApp:
// �� Ŭ������ ������ ���ؼ��� OpenPNG.cpp�� �����Ͻʽÿ�.
//

class COpenPNGApp : public CWinAppEx
{
public:
	COpenPNGApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	ULONG gdiplusToken;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COpenPNGApp theApp;
