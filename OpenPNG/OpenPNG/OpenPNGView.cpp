
// OpenPNGView.cpp : COpenPNGView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "OpenPNG.h"
#endif

#include "OpenPNGDoc.h"
#include "OpenPNGView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenPNGView

IMPLEMENT_DYNCREATE(COpenPNGView, CView)

BEGIN_MESSAGE_MAP(COpenPNGView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COpenPNGView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// COpenPNGView ����/�Ҹ�

COpenPNGView::COpenPNGView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

COpenPNGView::~COpenPNGView()
{
}

BOOL COpenPNGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// COpenPNGView �׸���

void COpenPNGView::OnDraw(CDC* pDC)
{
	COpenPNGDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	// Gdiplus::Graphics ��ü ����
	Graphics graphics(pDC->m_hDC);

	// �̹��� �ε�
	Image* png = Image::FromFile(L"..\\image\\mario.png");

	// �̹��� �ε带 �����ϸ� nullptr�� ��ȯ
	if (png)
	{
		// 0, 0�� �̹����� �»���� ��ġ�Ͽ� ���
		graphics.DrawImage(png, 0, 0);
	}
}


// COpenPNGView �μ�


void COpenPNGView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL COpenPNGView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void COpenPNGView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void COpenPNGView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void COpenPNGView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COpenPNGView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COpenPNGView ����

#ifdef _DEBUG
void COpenPNGView::AssertValid() const
{
	CView::AssertValid();
}

void COpenPNGView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenPNGDoc* COpenPNGView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenPNGDoc)));
	return (COpenPNGDoc*)m_pDocument;
}
#endif //_DEBUG


// COpenPNGView �޽��� ó����
