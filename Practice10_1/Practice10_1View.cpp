
// Practice10_1View.cpp : CPractice10_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CPractice10_1View 생성/소멸

CPractice10_1View::CPractice10_1View()
	: CFormView(IDD_PRACTICE10_1_FORM)
	, m_strText(_T(""))
	, m_nRed(0)
	, m_nGreen(0)
	, m_nBlue(0)
	, m_nX(0)
	, m_nY(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CPractice10_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CPractice10_1View 진단

#ifdef _DEBUG
void CPractice10_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CPractice10_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPractice10_1Doc* CPractice10_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice10_1Doc)));
	return (CPractice10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice10_1View 메시지 처리기


void CPractice10_1View::OnClickedButtonOutput()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);

	if (m_nRed > 255 || m_nRed < 0 || m_nGreen > 255 || m_nGreen < 0 || m_nBlue > 255 || m_nBlue < 0)
	{
		AfxMessageBox(_T("잘못된 색상입니다."));
	}
	else
	{
		Invalidate();
	}
}


void CPractice10_1View::OnClickedButtonColor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_nY > 230)
		m_nY -= 5;
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnClickedButtonDown()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_nY < 400)
		m_nY += 5;
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnClickedButtonLeft()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_nX > 30)
		m_nX -= 5;
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnClickedButtonRight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_nX < 350)
		m_nX += 5;
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditRed()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument() -> SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditGreen()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditBlue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditText()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnDraw(CDC* pDC)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	pDC->SetTextColor(m_colorText);
	pDC->TextOut(m_nX, m_nY, m_strText);
}
