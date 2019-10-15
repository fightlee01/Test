
// TestView.h : CTestView 类的接口
//

#pragma once
#include<vector>
#include<stack>

#include "CLine.h"
#include "CRectangle.h"


class CTestView : public CView
{
private:
protected: // 仅从序列化创建
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// 特性
public:
	CTestDoc* GetDocument() const;

// 操作
public:
	// 汉诺塔递归实现
	void Hanoilmpl(int n, char A, char B, char C);
	// 移动
	void move(char A, char C);
	// 初始化图形界面
	void init(CDC *pDC);
	// 动画第一步
	void animFirst(std::stack<int> &target, CPoint toPoint, CPoint prePoint, int num);
	void recover(CRectangle &RoundRect);
	void animSecond(CPoint toPoint);
	void animThird(CPoint toPoint,int num);
	void setParams();
private:
	// 三个塔底部的坐标
	CPoint ta, tb, tc;
	// 三个塔顶部的坐标
	CPoint tta, ttb, ttc;
	// 统计塔上个矩形个数
	int totalA, totalB, totalC;
	// 塔上矩形的宽度
	std::stack<int> A,B,C;
	// 目标矩形
	CRectangle *targetR;
	// 正在进行动画的第几步
	int animTime;
	// 设置一个数组存放每次移动的步骤
	std::vector<std::pair<char, char>> route;
	std::vector<std::pair<char, char>>::iterator pointR;
	char st, ed;
	UINT_PTR mynIDEvent;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMyStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnd();
	afx_msg void OnOneStep();
};

#ifndef _DEBUG  // TestView.cpp 中的调试版本
inline CTestDoc* CTestView::GetDocument() const
   { return reinterpret_cast<CTestDoc*>(m_pDocument); }
#endif

