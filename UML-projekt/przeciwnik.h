#pragma once
#include "postac.h"
#include "bohater.h"

class przeciwnik :
	public postac
{
public:
	bool aggro;
	bool mag;
	czar uzywany;
	przeciwnik();
	przeciwnik(bohater * const gracz);
	~przeciwnik();
};

