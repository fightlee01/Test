#pragma once
#include "cshape.h"
class CLine :
	public CShape
{
public:
	CLine(int x1, int y1, int x2, int y2):CShape(x1, y1, x2, y2){}
	CLine(void);
	~CLine(void);
	void onDraw(CDC *pDC);
};

