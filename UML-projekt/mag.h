#pragma once
#include "bohater.h"


class mag :
	public bohater
{
	void UzyjZwoju(zwoje * zwoj1, postac* const cel, int ktory);
	int hplvl = 20;
	int silalvl = 1;
	int zrecznosclvl = 2;
	int inteligencjalvl = 5;
	int manalvl = 80;
	int hpbaza = 100;
	int silabaza = 5;
	int zrecznoscbaza = 10;
	int inteligencjabaza = 20;
	int manabaza = 200;
public:
	mag();
	~mag();
	void NaukaCzaru(czar czar1);
	void NaukaCzaru(zwoje * zwoj1, int ktory);
};

