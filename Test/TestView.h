
// TestView.h : CTestView ��Ľӿ�
//

#pragma once
#include<vector>
#include<stack>

#include "CLine.h"
#include "CRectangle.h"


class CTestView : public CView
{
private:
protected: // �������л�����
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// ����
public:
	CTestDoc* GetDocument() const;

// ����
public:
	// ��ŵ���ݹ�ʵ��
	void Hanoilmpl(int n, char A, char B, char C);
	// �ƶ�
	void move(char A, char C);
	// ��ʼ��ͼ�ν���
	void init(CDC *pDC);
	// ������һ��
	void animFirst(std::stack<int> &target, CPoint toPoint, CPoint prePoint, int num);
	void recover(CRectangle &RoundRect);
	void animSecond(CPoint toPoint);
	void animThird(CPoint toPoint,int num);
	void setParams();
private:
	// �������ײ�������
	CPoint ta, tb, tc;
	// ����������������
	CPoint tta, ttb, ttc;
	// ͳ�����ϸ����θ���
	int totalA, totalB, totalC;
	// ���Ͼ��εĿ��
	std::stack<int> A,B,C;
	// Ŀ�����
	CRectangle *targetR;
	// ���ڽ��ж����ĵڼ���
	int animTime;
	// ����һ��������ÿ���ƶ��Ĳ���
	std::vector<std::pair<char, char>> route;
	std::vector<std::pair<char, char>>::iterator pointR;
	char st, ed;
	UINT_PTR mynIDEvent;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMyStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnd();
	afx_msg void OnOneStep();
};

#ifndef _DEBUG  // TestView.cpp �еĵ��԰汾
inline CTestDoc* CTestView::GetDocument() const
   { return reinterpret_cast<CTestDoc*>(m_pDocument); }
#endif

