#pragma once
#include <string>
#include "czar.h"
#include <vector>
#include <iostream>
#include "przedmiot.h"
#include "kulaognia.h"
#include "MniejszeLeczenie.h"

class postac
{
public:
	int x, y;
	std::vector <przedmiot*> plecak;
	std::vector <czar > znaneczary;
	bool czyzyje = true;
	std::string nazwa;
	int maxhp, maxmana, sila, zrecznosc, inteligencja, poziom, doswiadczenie, hp,mana, obrona=0;
	postac* cel;
	postac();
	~postac();
	virtual void Atakuj();
	virtual void RzucZaklecie(czar* const czar);
};

