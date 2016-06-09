#pragma once
#include "przedmiot.h"
#include <string>

class ekwipunek :
	public przedmiot
{
public:
	std::string wymagana_klasa ;
	int dodatkowasila, dodatkowazrecznosc, dodatkowainteligencja;
	ekwipunek();
	~ekwipunek();
};

