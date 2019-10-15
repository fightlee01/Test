#include "stdafx.h"
#include "CShape.h"


CShape::CShape(void)
{
}


CShape::~CShape(void)
{
}
CPoint CShape::getPoint1() {
	return point1;
}

CPoint CShape::getPoint2() {
	return point2;
}

void CShape::onDraw(CDC *pDC) {}