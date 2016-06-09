#pragma once
#include "bohater.h"
#include "postac.h"
class wojownik :
	public bohater
{
	int hplvl =50;
	int silalvl = 5;
	int zrecznosclvl = 3;
	int inteligencjalvl = 0;
	int manalvl = 0;
	int hpbaza = 200;
	int silabaza = 20;
	int zrecznoscbaza = 15;
	int inteligencjabaza = 0;
	int manabaza = 0;
public:
	wojownik();
	~wojownik();
};

