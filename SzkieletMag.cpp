#include "SzkieletMag.h"



SzkieletMag::SzkieletMag()
{
	maxhp = 250;
	hp = maxhp;
	maxmana = 300;
	mana = maxmana;
	doswiadczenie = 1200;
	nazwa = "szkielet mag";
	obrona = 0;
	sila = 5;
	inteligencja = 10;
	plecak.push_back(new zwoje(MniejszeLeczenie()));
	uzywany = kulaognia();
	znaneczary.push_back(uzywany);
	aggro = false;
	mag = true;
}

SzkieletMag::SzkieletMag(bohater * const gracz)
{
	maxhp = 250;
	hp = maxhp;
	maxmana = 300;
	mana = maxmana;
	doswiadczenie = 1200;
	nazwa = "szkielet mag";
	obrona = 3;
	sila = 5;
	inteligencja = 10;
	plecak.push_back(new zwoje(MniejszeLeczenie()));
	uzywany = kulaognia();
	znaneczary.push_back(uzywany);
	cel = gracz;
	aggro = false;
	mag = true;
}

SzkieletMag::~SzkieletMag()
{
}
