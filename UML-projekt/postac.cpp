#include "postac.h"
#include "przeciwnik.h"


postac::postac()
{
	czyzyje = true;
}

postac::~postac()
{
	while (!plecak.empty())
	{
		przedmiot* obecny = plecak.back();
		plecak.pop_back();
		delete obecny;
	}
}

void postac::RzucZaklecie(czar* const czar)
{
	bool czyznaleziono = false;
	for (auto it = begin(znaneczary); it != end(znaneczary); ++it)
	{
		if (it->nazwa == czar->nazwa)
		{
			czyznaleziono = true;
		}
	}
	if (czyznaleziono == true)
	{
		if (mana < czar->kosztmany)
		{
			std::cout << "nie dosc many" << std::endl;
		}
		else
		{
			int obrazenia = czar->obrazeniabaza + inteligencja*czar->obrazenianaint;
			if (obrazenia < 0)
			{
				if ((cel->hp - obrazenia) > cel->maxhp)
				{
					cel->hp = cel->maxhp;
				}
				else
				{
					cel->hp = cel->hp - obrazenia;
				}
			}
			else
			{
				cel->hp = cel->hp - obrazenia;
				if (cel->hp <= 0)
				{
					cel->czyzyje = false;
				}
				else
				{
					std::cout <<nazwa<<  " rzucil na ciebie zaklecie " << czar->nazwa << " i zadaje ci " << obrazenia << " punktow obrazen, pozostalo ci " << cel->hp << " punktow zycia" << std::endl;
				}
			}
		}
	}
	else
	{
		std::cout << "nie znasz tego czaru" << std::endl;
	}
}

void postac::Atakuj()
{
	int obronacelu = cel->obrona + 1.5*cel->zrecznosc;
	int obrazenia = sila * 2 - obronacelu;
	if (obrazenia < 0)
	{
		obrazenia = 0;
	}
	cel->hp = cel->hp - obrazenia;
	if (cel->hp <= 0)
	{
		cel->czyzyje = false;
		std::cout << nazwa << " atakuje " << cel->nazwa << " i go zabija" << std::endl;
	}
	else
	{
		std::cout << nazwa << " atakuje " << cel->nazwa << " i rani go " << obrazenia << " punktow obrazen, zostawiajac mu " << cel->hp << " punktow zycia" << std::endl;
	}
}
