
// TestView.cpp : CTestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Test.h"
#endif

#include "TestDoc.h"
#include "TestView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_32771, &CTestView::OnMyStart)
	ON_WM_TIMER()
	ON_COMMAND(ID_32772, &CTestView::OnEnd)
	ON_COMMAND(ID_32774, &CTestView::OnOneStep)
END_MESSAGE_MAP()

// CTestView ����/����

CTestView::CTestView()
{
	// TODO: �ڴ˴���ӹ������
	setParams();
}

CTestView::~CTestView()
{
}

// ��ʼ������
void CTestView::setParams() {
	this->totalA = 4;
	this->totalB = 0;
	this->totalC = 0;
	this->animTime = 3;
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTestView ����

void CTestView::OnDraw(CDC* /*pDC*/)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	Hanoilmpl(4, 'A', 'B', 'C');
	pointR = route.begin();
	CDC *pDC = GetDC();
	init(pDC);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}



// CTestView ���

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestView ��Ϣ�������

// ʵ�ֺ�ŵ��
void CTestView::Hanoilmpl(int n, char A, char B, char C) {
	if(n==1) move(A, C);
	else {
		Hanoilmpl(n-1, A, C, B);
		move(A, C);
		Hanoilmpl(n-1, B, A, C);
	}
}
// ʵ��ģ���ƶ�
void CTestView::move(char A, char C) {
	static int j = 0;
	j++;
	// ���ƶ�·����������
	route.push_back(std::pair<char, char>(A, C));
}
// �����ʼ��
void CTestView::init(CDC *pDC) {
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(217, 217, 217));
	// ���û���
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);
	// ����������
	CLine lineOne(300, 100, 300, 400);
	CLine lineTwo(500, 100, 500, 400);
	CLine lineThree(700, 100, 700, 400);
	CLine land(200, 400, 800, 400);
	lineOne.onDraw(pDC);
	lineTwo.onDraw(pDC);
	lineThree.onDraw(pDC);
	land.onDraw(pDC);
	pDC->SelectObject(oldPen);
	// ��ʼ���������ײ�������
	this->ta = lineOne.getPoint2();
	this->tb = lineTwo.getPoint2();
	this->tc = lineThree.getPoint2();
	// ��ʼ����������λ��
	this->tta = lineOne.getPoint1();
	this->ttb = lineTwo.getPoint1();
	this->ttc = lineThree.getPoint1();
	// ������
	CBrush brush(RGB(255, 0, 0));// ��ʼ����ˢ
	CBrush *oldBrush = pDC->SelectObject(&brush);
	CRectangle roundRect1(50);
	roundRect1.setNum(4);
	roundRect1.setHeight(25);
	CRectangle roundRect2(100);
	roundRect2.setNum(3);
	roundRect2.setHeight(25);
	CRectangle roundRect3(150);
	roundRect3.setNum(2);
	roundRect3.setHeight(25);
	CRectangle roundRect4(200);
	roundRect4.setNum(1);
	roundRect4.setHeight(25);
	A.push(200);
	A.push(150);
	A.push(100);
	A.push(50);
	roundRect1.prepare(ta, pDC);
	roundRect2.prepare(ta, pDC);
	roundRect3.prepare(ta, pDC);
	roundRect4.prepare(ta, pDC);
	pDC->SelectObject(oldBrush);
	ReleaseDC(pDC);
}
// ������һ��
void CTestView::animFirst(std::stack<int> &target, CPoint toPoint, CPoint prePoint, int num) {
	// ȥ����һ������
	CDC *pDC = GetDC();
	// ���û���
	CPen cTowerPen;
	cTowerPen.CreatePen(PS_SOLID, 0, RGB(217, 217, 217));
	CPen *oldPen = pDC->SelectObject(&cTowerPen);
	// ���û�ˢ
	CBrush brush(RGB(217, 217, 217));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	// ��ȡĿ����ο�Ȳ����ƾ���
	int rwid = target.top();
	CRectangle RoundRect(rwid);
	RoundRect.setNum(num);
	RoundRect.setHeight(25);
	RoundRect.prepare(prePoint, pDC);
	
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);

	recover(RoundRect);
	RoundRect.setNum(1);
	CBrush brush1(RGB(255, 0, 0));
	CBrush *oldBrush1 = pDC->SelectObject(&brush1);
	RoundRect.prepare(toPoint, pDC);
	ReleaseDC(pDC);
	this->targetR = new CRectangle(RoundRect);
}

void CTestView::recover(CRectangle &rectangle) {
	CPoint top, bottom;
	top.x = rectangle.getPoint1().x + rectangle.getWidth();
	top.y = rectangle.getPoint1().y;
	bottom.x = rectangle.getPoint2().x - rectangle.getWidth();
	bottom.y = rectangle.getPoint2().y;
	CDC *pDC = GetDC();
	CPen cTowerPen;
	cTowerPen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&cTowerPen);
	pDC->MoveTo(top.x, top.y);
	pDC->LineTo(bottom.x, bottom.y);
	ReleaseDC(pDC);
}

void CTestView::animSecond(CPoint toPoint)
{
	// ������һ������
	CDC *pDC = GetDC();
	CPen cTowerPen;
	cTowerPen.CreatePen(PS_SOLID, 0, RGB(217, 217, 217));
	CPen* oldPen = pDC->SelectObject(&cTowerPen);
	CBrush brush(RGB(217, 217, 217));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	this->targetR->onDraw(pDC);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	// ������һ��λ�þ���
	CBrush brush1(RGB(255, 0, 0));
	CBrush *oldBrush1 = pDC->SelectObject(&brush1);
	this->targetR->prepare(toPoint, pDC);
	ReleaseDC(pDC);
}

void CTestView::animThird(CPoint toPoint,int num)
{
	// ������һ������
	CDC *pDC = GetDC();
	CPen cTowerPen;
	cTowerPen.CreatePen(PS_SOLID, 0, RGB(217, 217, 217));
	CPen* oldPen = pDC->SelectObject(&cTowerPen);
	CBrush brush(RGB(217, 217, 217));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	this->targetR->onDraw(pDC);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	// ������һ������
	this->targetR->setNum(num);
	this->targetR->setHeight(25);
	CBrush brush1(RGB(255, 0, 0));
	CBrush *oldBrush1 = pDC->SelectObject(&brush1);
	this->targetR->prepare(toPoint, pDC);
	ReleaseDC(pDC);
}

void CTestView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	mynIDEvent = nIDEvent;
	if (animTime == 0) {
		if (totalC==4) {
			KillTimer(nIDEvent);
			return;
		}
		this->pointR++;
		animTime = 3;
	}
	// ������һ��
	if (animTime == 3) {
		animTime--;
		this->st = pointR->first;
		this->ed = pointR->second;
		// ��A��ʼ��һ��
		if (st == 'A') {
			animFirst(A, tta, ta, totalA);
			if (ed == 'B') {
				int wid = A.top();
				A.pop();
				B.push(wid);
				totalA -= 1;
				totalB += 1;
			}
			else {
				int wid = A.top();
				A.pop();
				C.push(wid);
				totalA -= 1;
				totalC += 1;
			}
		}
		else if (st == 'B') {
			animFirst(B, ttb, tb, totalB);
			if (ed == 'A') {
				int wid = B.top();
				B.pop();
				A.push(wid);
				totalB -= 1;
				totalA += 1;
			}
			else {
				int wid = B.top();
				B.pop();
				C.push(wid);
				totalB -= 1;
				totalC += 1;
			}
		}
		else if(st=='C')
		{
			animFirst(C, ttc, tc, totalC);
			if (ed == 'A') {
				int wid = C.top();
				C.pop();
				A.push(wid);
				totalC -= 1;
				totalA += 1;
			}
			else {
				int wid = C.top();
				C.pop();
				B.push(wid);
				totalC -= 1;
				totalB += 1;
			}
		}
	}
	// �����ڶ���
	else if (animTime == 2) {
		animTime--;
		if (ed == 'A') {
			animSecond(tta);
		}
		else if(ed == 'B')
		{
			animSecond(ttb);
		}
		else
		{
			animSecond(ttc);
		}
	}
	else {
		animTime--;
		if (ed == 'A') {
			animThird(ta, totalA);
		}
		else if (ed == 'B') {
			animThird(tb, totalB);
		}
		else {
			animThird(tc, totalC);
		}
	}
	CView::OnTimer(nIDEvent);
}

void CTestView::OnMyStart()
{
	// TODO: �ڴ���������������
	SetTimer(1, 1000, NULL);
}


void CTestView::OnEnd()
{
	// TODO: �ڴ���������������
	KillTimer(mynIDEvent);
	CDC *pDC = GetDC();
	init(pDC);
}


void CTestView::OnOneStep()
{
	// TODO: �ڴ���������������
	SetTimer(1, 1000, NULL);
	KillTimer(mynIDEvent);
}
