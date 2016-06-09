#pragma once
#include "przedmiot.h"
class mikstury :
	public przedmiot
{
public:
	int zmianahp, zmianamany, zmianazrecz, zmianasily, zmianaint, zmianamaxhp, zmianamaxmana;
	mikstury(int zmianahp1, int zmianamany1,int zmianazrecz1,int zmianasily1, int zmianaint1, int zmianamaxhp1, int zmianamaxmana1);
	~mikstury();
};

