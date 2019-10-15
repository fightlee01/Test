#include "stdafx.h"
#include "CLine.h"


CLine::CLine(void)
{
}


CLine::~CLine(void)
{
}

void CLine::onDraw(CDC *pDC) {
	pDC->MoveTo(this->point1.x, this->point1.y);
	pDC->LineTo(this->point2.x, this->point2.y);
}
