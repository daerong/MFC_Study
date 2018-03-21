
// Practice10_1View.cpp : CPractice10_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice10_1.h"
#endif

#include "Practice10_1Doc.h"
#include "Practice10_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice10_1View

IMPLEMENT_DYNCREATE(CPractice10_1View, CFormView)

BEGIN_MESSAGE_MAP(CPractice10_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_OUTPUT, &CPractice10_1View::OnClickedButtonOutput)
	ON_BN_CLICKED(IDC_BUTTON_COLOR, &CPractice10_1View::OnClickedButtonColor)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CPractice10_1View::OnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_UP, &CPractice10_1View::OnClickedButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, &CPractice10_1View::OnClickedButtonDown)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CPractice10_1View::OnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CPractice10_1View::OnClickedButtonRight)
	ON_EN_CHANGE(IDC_EDIT_RED, &CPractice10_1View::OnChangeEditRed)
	ON_EN_CHANGE(IDC_EDIT_GREEN, &CPractice10_1View::OnChangeEditGreen)
	ON_EN_CHANGE(IDC_EDIT_BLUE, &CPractice10_1View::OnChangeEditBlue)
	ON_EN_CHANGE(IDC_EDIT_TEXT, &CPractice10_1View::OnChangeEditText)
END_MESSAGE_MAP()

// CPractice10_1View ����/�Ҹ�

CPractice10_1View::CPractice10_1View()
	: CFormView(IDD_PRACTICE10_1_FORM)
	, m_strText(_T(""))
	, m_nRed(0)
	, m_nGreen(0)
	, m_nBlue(0)
	, m_nX(0)
	, m_nY(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_colorText = RGB(0, 0, 0);
	m_nX = 30;
	m_nY = 230;
}

CPractice10_1View::~CPractice10_1View()
{
}

void CPractice10_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
	DDX_Text(pDX, IDC_EDIT_RED, m_nRed);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_nGreen);
	DDX_Text(pDX, IDC_EDIT_BLUE, m_nBlue);
	DDV_MinMaxInt(pDX, m_nBlue, 0, 255);
	DDV_MinMaxInt(pDX, m_nGreen, 0, 255);
	DDV_MinMaxInt(pDX, m_nRed, 0, 255);
}

BOOL CPractice10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CPractice10_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CPractice10_1View ����

#ifdef _DEBUG
void CPractice10_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CPractice10_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPractice10_1Doc* CPractice10_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice10_1Doc)));
	return (CPractice10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice10_1View �޽��� ó����


void CPractice10_1View::OnClickedButtonOutput()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);

	if (m_nRed > 255 || m_nRed < 0 || m_nGreen > 255 || m_nGreen < 0 || m_nBlue > 255 || m_nBlue < 0)
	{
		AfxMessageBox(_T("�߸��� �����Դϴ�."));
	}
	else
	{
		Invalidate();
	}
}


void CPractice10_1View::OnClickedButtonColor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	CColorDialog colorDlg;
	if (colorDlg.DoModal() == IDOK)
	{
		m_colorText = colorDlg.GetColor();
	}

	m_nRed = GetRValue(m_colorText);
	m_nGreen = GetGValue(m_colorText);
	m_nBlue = GetBValue(m_colorText);

	UpdateData(FALSE);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnClickedButtonReset()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_strText.Empty();
	m_nRed = 0;
	m_nGreen = 0;
	m_nBlue = 0;
	m_nX = 30;
	m_nY = 230;
	UpdateData(FALSE);
	Invalidate();
	GetDocument()->OnNewDocument();
}


void CPractice10_1View::OnClickedButtonUp()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_nY > 230)
		m_nY -= 5;
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnClickedButtonDown()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_nY < 400)
		m_nY += 5;
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnClickedButtonLeft()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_nX > 30)
		m_nX -= 5;
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnClickedButtonRight()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_nX < 350)
		m_nX += 5;
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditRed()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument() -> SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditGreen()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditBlue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditText()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnDraw(CDC* pDC)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	pDC->SetTextColor(m_colorText);
	pDC->TextOut(m_nX, m_nY, m_strText);
}
