#pragma once
#include "przedmiot.h"
#include "czar.h"
class zwoje :
	public przedmiot
{
public:
	czar czar1;
	zwoje(czar czar2);
	~zwoje();
};

