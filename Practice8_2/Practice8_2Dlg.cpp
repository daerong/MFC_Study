
// Practice8_2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Practice8_2.h"
#include "Practice8_2Dlg.h"
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


// CPractice8_2Dlg ��ȭ ����



CPractice8_2Dlg::CPractice8_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRACTICE8_2_DIALOG, pParent)
	, m_nTransmitRate(0)
	, m_nData(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPractice8_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS_SENDER, m_addrSenderIP);
	DDX_Control(pDX, IDC_IPADDRESS_RECEIVER, m_addrReceiverIP);
	DDX_Control(pDX, IDC_PROGRESS_TRANSMIT, m_prgsTransmit);
	//  DDX_Control(pDX, IDC_DATETIMEPICKER_DATE, m_lineTransmit);
	DDX_Text(pDX, IDC_EDIT_DATA, m_nData);
	DDX_Control(pDX, IDC_EDIT_SUMMARY, m_edSummary);
	DDX_Control(pDX, IDC_SPIN_DATA, m_spinData);
	DDX_Control(pDX, IDC_DATETIMEPICKER_DATE, m_timeTransmit);
}

BEGIN_MESSAGE_MAP(CPractice8_2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TRANSMIT, &CPractice8_2Dlg::OnClickedButtonTransmit)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CPractice8_2Dlg �޽��� ó����

BOOL CPractice8_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

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

	m_prgsTransmit.SetRange(0, 100);
	m_prgsTransmit.SetPos(0);
	m_spinData.SetRange(-100, 100);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CPractice8_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPractice8_2Dlg::OnPaint()
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
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CPractice8_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPractice8_2Dlg::OnClickedButtonTransmit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	// ���� ������ ���۷��� 0�ۼ�Ʈ�� �����Ѵ�.
	m_nTransmitRate = 0;
	// Ÿ�̸Ӹ� �����Ѵ�. Ÿ�̸� ID = 1, ���� = 30;
	SetTimer(1, 30, NULL);

	// ������ ������ ���۵Ǹ� ��ư�� ��Ȱ��ȭ ��Ų��.
	GetDlgItem(IDC_BUTTON_TRANSMIT)->EnableWindow(FALSE);
}


void CPractice8_2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CString strSummary;

	if (m_nTransmitRate != 100)
	{
		m_nTransmitRate++;
		m_prgsTransmit.SetPos(m_nTransmitRate);
		strSummary.Format(_T("������ ���� ���Դϴ� - %d%%\r\n\r\n ��� ��ٷ��ּ���......"), m_nTransmitRate);
		
		m_edSummary.SetWindowText(strSummary);
	}
	else
	{
		KillTimer(1);
		GetDlgItem(IDC_BUTTON_TRANSMIT)->EnableWindow(TRUE);
		UpdateData(TRUE);

		CString strTrans, strDataDesc;
		m_prgsTransmit.SetPos(m_nTransmitRate);
		strTrans.Format(_T("������ ������ �Ϸ��߽��ϴ�. - %d%%\r\n\r\n"), m_nTransmitRate);

		BYTE first, second, third, forth;
		CString strSender, strReceiver;
		m_addrSenderIP.GetAddress(first, second, third, forth);
		strSender.Format(_T("�۽��� �ּ� : %d.%d.%d.%d\t\t\t\t"), first, second, third, forth);

		m_addrReceiverIP.GetAddress(first, second, third, forth);
		strReceiver.Format(_T("������ �ּ� : %d.%d.%d.%d\r\n\r\n"), first, second, third, forth);

		CTime timeTime;
		DWORD dwResult = m_timeTransmit.GetTime(timeTime);

		CString strDate;
		strDate.Format(_T("���۳�¥ : %s \r\n\r\n"), timeTime.Format(" %A, %B, %d, %Y "));

		CString strData;
		strData.Format(_T("���� ������ ���� : %d"), m_nData);

		strSummary = strTrans + strSender + strReceiver + strDate + strData;
		m_edSummary.SetWindowText(strSummary);
	}

	CDialogEx::OnTimer(nIDEvent);
}
