#pragma once
#include "postac.h"

class Pola
{
public:
	int x, y;
	postac* KtoJestNaPolu;
	bool CzyZablokowane = false;
	bool CzyWyjscie;
	Pola(int x1, int y1);
	~Pola();
};

