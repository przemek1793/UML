#include "szkielet.h"



szkielet::szkielet()
{
	maxhp = 200;
	hp = maxhp;
	doswiadczenie = 700;
	nazwa = "szkielet";
	obrona = 5;
	sila = 30;
	plecak.push_back(new mikstury(50, 20, 0, 0, 0, 0, 0));
	plecak.push_back(new mikstury(0, 0, 3, 2, 5, 0, 0));
	aggro = false;
	mag = false;
}

szkielet::~szkielet()
{

}

szkielet::szkielet(bohater * const gracz)
{
	maxhp = 200;
	hp = maxhp;
	doswiadczenie = 700;
	nazwa = "szkielet";
	obrona = 5;
	sila = 30;
	plecak.push_back(new mikstury(50, 20, 0, 0, 0, 0, 0));
	plecak.push_back(new mikstury(0, 0, 3, 2, 5, 0, 0));
	cel = gracz;
	aggro = false;
	mag = false;
}
