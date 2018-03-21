
// Practice 4_1Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CPractice4_1Dlg ��ȭ ����
class CPractice4_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPractice4_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE4_1_DIALOG };
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
	CString m_strEdit;
	CListBox m_listBox;
	CComboBox m_cbListItem;
	void UpdateComboBox();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	bool m_bChecked[3];
	afx_msg void OnClickedCheck1();
	afx_msg void OnClickedCheck2();
//	afx_msg void OnClickedCheck3();
	afx_msg void OnClickedCheck3();
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonComboInsert();
	afx_msg void OnClickedButtonComboDelete();
	afx_msg void OnClickedButtonListInsert();
	afx_msg void OnClickedButtonListDelete();
};
