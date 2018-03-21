
// Practice8_1Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CPractice8_1Dlg ��ȭ ����
class CPractice8_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPractice8_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE8_1_DIALOG };
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
	CTabCtrl m_tabSelection;
	CSliderCtrl m_sliderRed;
	CSliderCtrl m_sliderGreen;
	CSliderCtrl m_sliderBlue;
	int m_nRed;
	int m_nGreen;
	int m_nBlue;
	int m_nSize;
	CSpinButtonCtrl m_spinSize;
	int m_nSelObject;
	COLORREF m_colorObject;
	afx_msg void OnSelchangeTabSelection(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnRadioRectangle();
	afx_msg void OnRadioCircle();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDeltaposSpinSize(NMHDR *pNMHDR, LRESULT *pResult);
};
