
// Practice8_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Practice8_1.h"
#include "Practice8_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

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


// CPractice8_1Dlg ��ȭ ����



CPractice8_1Dlg::CPractice8_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRACTICE8_1_DIALOG, pParent)
	, m_nRed(0)
	, m_nGreen(0)
	, m_nBlue(0)
	, m_nSize(0)
	, m_nSelObject(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPractice8_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SELECTION, m_tabSelection);
	DDX_Control(pDX, IDC_SLIDER_RED, m_sliderRed);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_sliderGreen);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_sliderBlue);
	DDX_Text(pDX, IDC_EDIT_RED, m_nRed);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_nGreen);
	DDX_Text(pDX, IDC_EDIT_BLUE, m_nBlue);
	DDX_Text(pDX, IDC_EDIT_SIZE, m_nSize);
	DDX_Control(pDX, IDC_SPIN_SIZE, m_spinSize);
}

BEGIN_MESSAGE_MAP(CPractice8_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SELECTION, &CPractice8_1Dlg::OnSelchangeTabSelection)
	ON_COMMAND(IDC_RADIO_RECTANGLE, &CPractice8_1Dlg::OnRadioRectangle)
	ON_COMMAND(IDC_RADIO_CIRCLE, &CPractice8_1Dlg::OnRadioCircle)
	ON_WM_HSCROLL()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SIZE, &CPractice8_1Dlg::OnDeltaposSpinSize)
END_MESSAGE_MAP()


// CPractice8_1Dlg �޽��� ó����

BOOL CPractice8_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	UpdateData(TRUE);
	m_nSize = 50;
	m_spinSize.SetRange(0, 100);
	UpdateData(FALSE);

	TC_ITEM tabItem;
	LPWSTR tabName[2] = { _T("���� ����"), _T("���� ����") };
	m_nSelObject = 1;
	m_colorObject = RGB(0, 0, 0);
	for (int i = 0; i < 2; i++)
	{
		tabItem.mask = TCIF_TEXT;
		tabItem.pszText = tabName[i];
		m_tabSelection.InsertItem(i, &tabItem);
	}

	GetDlgItem(IDC_RADIO_RECTANGLE)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO_CIRCLE)->ShowWindow(TRUE);

	GetDlgItem(IDC_STATIC_RED)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_GREEN)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_BLUE)->ShowWindow(FALSE);

	GetDlgItem(IDC_SLIDER_RED)->ShowWindow(FALSE);
	GetDlgItem(IDC_SLIDER_GREEN)->ShowWindow(FALSE);
	GetDlgItem(IDC_SLIDER_BLUE)->ShowWindow(FALSE);

	GetDlgItem(IDC_EDIT_RED)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_GREEN)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_BLUE)->ShowWindow(FALSE);

	m_sliderRed.SetRange(0, 255);
	m_sliderGreen.SetRange(0, 255);
	m_sliderBlue.SetRange(0, 255);

	((CButton *)GetDlgItem(IDC_RADIO_RECTANGLE))->SetCheck(TRUE);

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CPractice8_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPractice8_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	CRect rectView, rectFigure;
	GetDlgItem(IDC_STATIC_VIEW)->GetWindowRect(&rectView);
	CPoint ptCenter = rectView.CenterPoint();
	ScreenToClient(&ptCenter);

	rectFigure.left = ptCenter.x - (int)(rectView.Width() / 2.0f * (float)m_nSize / 100.0f);
	rectFigure.right = ptCenter.x + (int)(rectView.Width() / 2.0f * (float)m_nSize / 100.0f);
	rectFigure.top = ptCenter.y - (int)(rectView.Height() / 2.0f * (float)m_nSize / 100.0f);
	rectFigure.bottom = ptCenter.y + (int)(rectView.Height() / 2.0f * (float)m_nSize / 100.0f);

	CClientDC dc(this);
	CBrush NewBrush, *oldBrush;

	NewBrush.CreateSolidBrush(m_colorObject);
	oldBrush = dc.SelectObject(&NewBrush);

	switch (m_nSelObject)
	{
	case 1:
		dc.Rectangle(&rectFigure);
		break;
	case 2:
		dc.Ellipse(&rectFigure);
		break;

	}
	dc.SelectObject(oldBrush);
	NewBrush.DeleteObject();

}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CPractice8_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPractice8_1Dlg::OnSelchangeTabSelection(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nSelection = m_tabSelection.GetCurSel();

	switch (nSelection)
	{
	case 0 :
		GetDlgItem(IDC_RADIO_RECTANGLE)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO_CIRCLE)->ShowWindow(TRUE);

		GetDlgItem(IDC_STATIC_RED)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_GREEN)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_BLUE)->ShowWindow(FALSE);

		GetDlgItem(IDC_SLIDER_RED)->ShowWindow(FALSE);
		GetDlgItem(IDC_SLIDER_GREEN)->ShowWindow(FALSE);
		GetDlgItem(IDC_SLIDER_BLUE)->ShowWindow(FALSE);

		GetDlgItem(IDC_EDIT_RED)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_GREEN)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_BLUE)->ShowWindow(FALSE);
		break;

	case 1 : 
		GetDlgItem(IDC_RADIO_RECTANGLE)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO_CIRCLE)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_RED)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_GREEN)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_BLUE)->ShowWindow(TRUE);

		GetDlgItem(IDC_SLIDER_RED)->ShowWindow(TRUE);
		GetDlgItem(IDC_SLIDER_GREEN)->ShowWindow(TRUE);
		GetDlgItem(IDC_SLIDER_BLUE)->ShowWindow(TRUE);

		GetDlgItem(IDC_EDIT_RED)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_GREEN)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_BLUE)->ShowWindow(TRUE);
		break;
	}
	
	*pResult = 0;
}


void CPractice8_1Dlg::OnRadioRectangle()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSelObject = 1;
	Invalidate();
}


void CPractice8_1Dlg::OnRadioCircle()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSelObject = 2;
	Invalidate();
}


void CPractice8_1Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CRect rectView;
	GetDlgItem(IDC_STATIC_VIEW)->GetWindowRect(&rectView);
	ScreenToClient(&rectView);
	int nRed = m_sliderRed.GetPos();
	int nGreen = m_sliderGreen.GetPos();
	int nBlue = m_sliderBlue.GetPos();

	if (pScrollBar->GetSafeHwnd() == m_sliderRed.m_hWnd)
		m_nRed = nRed;
	else if (pScrollBar->GetSafeHwnd() == m_sliderGreen.m_hWnd)
		m_nGreen = nGreen;
	else if (pScrollBar->GetSafeHwnd() == m_sliderBlue.m_hWnd)
		m_nBlue = nBlue;
	else
		return;
	
	m_colorObject = RGB(nRed, nGreen, nBlue);
	UpdateData(FALSE);
	InvalidateRect(&rectView);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CPractice8_1Dlg::OnDeltaposSpinSize(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	Invalidate();

	*pResult = 0;
}
