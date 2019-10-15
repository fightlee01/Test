#pragma once
#include "cshape.h"
class CRectangle :
	public CShape
{
public:
	CRectangle(void);
	CRectangle(int width) :width(width/2) {
		//Ĭ��Բ��Ϊ10
		radius.x = 10;
		radius.y = 10;
	}
	CRectangle(int x1, int y1, int x2, int y2, int width) : CShape(x1, y1, x2, y2),width(width) {
		//Ĭ��Բ��Ϊ10
		radius.x = 10;
		radius.y = 10;
	};
	~CRectangle(void);
	void onDraw(CDC *pDC);
	void prepare(const CPoint location,int height,CDC *pDC);
	void setNum(int num);
	void prepare(const CPoint location, CDC * pDC);
	int getWidth();
	void setHeight(int height);
private:
	CPoint radius, top, bottom;
	// ���ο��
	int width;
	// ���θ߶�
	int height;
	// ����ײ��ж��ٸ����θ߶�
	int num;
};

