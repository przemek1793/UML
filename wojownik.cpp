#include "wojownik.h"



wojownik::wojownik()
{
	maxhp = hpbaza+hplvl;
	maxmana = manabaza+manalvl;
	sila = silabaza+silalvl;
	zrecznosc = zrecznoscbaza+zrecznosclvl;
	inteligencja = inteligencjabaza+inteligencjalvl;
	poziom = 1;
	mana = maxmana;
	hp = maxhp;
	czyzyje = true;
	bron1 = new Topor{};
	zbroja1 = new SkorzanaZbroja{};
	obrona = zbroja1->obrona;
	nazwa = "wojownik";
}

wojownik::~wojownik()
{
}



