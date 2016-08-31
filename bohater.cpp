#include "bohater.h"
#include "przedmiot.h"


bohater::bohater()
{
	nazwa = "gracz";
}

bohater::~bohater()
{
	delete zbroja1;
	delete bron1;
}

void bohater::ZdobadzXP(int xp)
{
	doswiadczenie += xp;
	while (doswiadczenie >= iledolvl)
	{
		doswiadczenie = doswiadczenie - iledolvl;
		LvlUp();
	}
}

void bohater::LvlUp()
{
	++poziom;
	std::cout << "awansowales na " <<poziom<< "poziom"<< std::endl;
	maxmana += manalvl;
	maxhp += hplvl;
	hp = maxhp;
	mana = maxmana;
	sila += silalvl;
	zrecznosc += zrecznosclvl;
	inteligencja += inteligencjalvl;
	iledolvl = iledolvl*1.5;
}

void bohater::RzucZaklecie(czar* const czar)
{
	if (cel->czyzyje == false)
	{
		std::cout << "cel nie zyje" << std::endl;
	}
	else
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
				mana = mana - czar->kosztmany;
				std::cout << "zuzyles " << czar->kosztmany << " many na zaklecie, pozostalo ci " << mana<< " punktow many" << std::endl;
				int obrazenia = czar->obrazeniabaza + inteligencja*czar->obrazenianaint;
				if (obrazenia < 0)
				{
					if ((cel->hp - obrazenia) > cel->maxhp)
					{
						std::cout << "uleczono do maksymalnej ilosci hp " << std::endl;
						cel->hp = cel->maxhp;
					}
					else
					{
						std::cout << "uleczyles " << -obrazenia << " punktow zycia zakleciem " << czar->nazwa << std::endl;
						cel->hp = cel->hp - obrazenia;
					}
				}
				else
				{		
					cel->hp = cel->hp - obrazenia;
					if (cel->hp <= 0)
					{
						cel->czyzyje = false;
						std::cout << "rzuciles na "<< cel->nazwa << " zaklecie "<< czar->nazwa<<" i go zabijasz" << std::endl;
						ZdobadzXP(cel->doswiadczenie);
					}
					else
					{
						std::cout << "rzuciles na " << cel->nazwa << " zaklecie " << czar->nazwa << " i zadajesz mu " << obrazenia << " punktow obrazen, pozostalo mu " <<cel->hp <<" punktow zycia"<< std::endl;
					}
				}
			}
		}
		else
		{
			std::cout << "nie znasz tego czaru" << std::endl;
		}
	}	
}

void bohater::UzyjZwoju(zwoje * const zwoj1, postac* const cel, int ktory)
{
	if (cel == NULL)
	{
		std::cout << "nie masz celu" << std::endl;
	}
	else if (cel->czyzyje == false)
	{
		std::cout << "cel nie zyje" << std::endl;
	}
	else
	{
		const czar zezwoju = zwoj1->czar1;
		int obrazenia = zezwoju.obrazeniabaza + (inteligencja+bron1->dodatkowainteligencja)*zezwoju.obrazenianaint;
		if (obrazenia < 0)
		{
			if ((cel->hp - obrazenia) > cel->maxhp)
			{
				std::cout << "uleczyles " << -obrazenia << " punktow zycia zakleciem ze zwoju" << std::endl;
				cel->hp = cel->maxhp;
			}
			else
			{
				std::cout << -obrazenia << " leczenie" << std::endl;
				cel->hp = cel->hp - obrazenia;
			}
		}
		else
		{
			std::cout << "rzuciles na " << cel->nazwa << " zaklecie " << zwoj1->czar1.nazwa << " i zadajesz mu " << obrazenia << " punktow obrazen" << std::endl;
			cel->hp = cel->hp - obrazenia;
			if (cel->hp <= 0)
			{
				cel->czyzyje = false;
				std::cout << "rzuciles na " << cel->nazwa << " zaklecie " << zwoj1->czar1.nazwa << " i go zabijasz" << std::endl;
				ZdobadzXP(cel->doswiadczenie);
			}
		}
		plecak.erase(plecak.begin() + ktory);
		delete zwoj1;
	}
}

void bohater::UzyjMikstury(mikstury * const mikstura1)
{
	zrecznosc += mikstura1->zmianazrecz;
	sila += mikstura1->zmianasily;
	inteligencja += mikstura1->zmianaint;
	maxhp += mikstura1->zmianamaxhp;
	hp += mikstura1->zmianamaxhp;
	maxmana += mikstura1->zmianamaxmana;
	mana += mikstura1->zmianamaxmana;
	if ((hp + mikstura1->zmianahp) > maxhp)
	{
		std::cout << "uleczono do maksymalnej ilosci hp " << std::endl;
		hp = maxhp;
	}
	else
	{
		std::cout << mikstura1->zmianahp << " leczenia" << std::endl;
		hp = hp + mikstura1->zmianahp;
	}
	if ((mana + mikstura1->zmianamany) > maxmana)
	{
		std::cout << "przywrocono maksymalna ilosc many" << std::endl;
		mana = maxmana;
	}
	else
	{
		std::cout << mikstura1->zmianamany << " przywroconej many" << std::endl;
		mana = mana + mikstura1->zmianamany;
	}
	delete mikstura1;
}


void bohater::Atakuj()
{
	if (cel->czyzyje == false)
	{
		std::cout << "cel nie zyje" << std::endl;
	}
	else
	{
		int obronacelu = cel->obrona + 1.5*cel->zrecznosc;
		int obrazenia = bron1->bazowy_atak + bron1->skalowanieint*(inteligencja + bron1->dodatkowainteligencja) + bron1->skalowaniezrecznosc*(zrecznosc + bron1->dodatkowazrecznosc) +bron1->skalowaniesila*(sila + bron1->dodatkowasila)-obronacelu;
		cel->hp = cel->hp - obrazenia;
		if (cel->hp <= 0)
		{
			cel->czyzyje = false;
			std::cout <<"Atakujesz " << cel->nazwa << " i go zabijasz" << std::endl;
			ZdobadzXP(cel->doswiadczenie);
		}
		else
		{
			std::cout << "Atakujesz " << cel->nazwa << " i ranisz go " << obrazenia << " punktow obrazen, zostawiajac mu " << cel->hp << " punktow zycia" << std::endl;
		}
	}
}

void bohater::PokazPlecak()
{
	if (plecak.empty())
	{
		std::cout << "nie masz zadnych przedmiotow" << std::endl;
	}
	else
	{
		for (auto it = begin(plecak); it != end(plecak); ++it)
		{
			przedmiot* obecny = *it;
			std::cout << obecny->nazwa << " w slocie " << std::distance(plecak.begin(), it) << std::endl;
		}
	}	
}

void bohater::PokazCzary()
{
	if (znaneczary.empty())
	{
		std::cout << "nie znasz zadnych czarow" << std::endl;
	}
	else
	{
		int a = 1;
		for (auto it = begin(znaneczary); it != end(znaneczary); ++it)
		{
			czar obecny = *it;
			std::cout <<a<< " "<< obecny.nazwa << std::endl;
			a++;
		}
	}
}

void bohater::UzyjPrzedmiotWSlocie(int ktory)
{
	if (ktory >= plecak.size())
	{
		std::cout << "pusty slot" << std::endl;
	}
	else
	{
		przedmiot* uzywany = plecak.at(ktory);
		if (uzywany->typ == "bron")
		{
			std::cout <<  "uzywam broni " << std::endl;
			bron * brona = dynamic_cast<bron*>(uzywany);
			plecak.erase(plecak.begin() + ktory);
			ZalozBron(brona);
		}
		else if (uzywany->typ == "zbroja")
		{
			std::cout << "uzywam zbroji " << std::endl;
			zbroja * zbroj = dynamic_cast<zbroja*>(uzywany);
			plecak.erase(plecak.begin() + ktory);
			ZalozZbroje(zbroj);
		}
		else if (uzywany->typ == "mikstura")
		{
			mikstury * uzywana = dynamic_cast <mikstury*>(uzywany);
			std::cout << "uzywam mikstury " << std::endl;
			plecak.erase(plecak.begin() + ktory);
			UzyjMikstury(uzywana);		
		}
		else if (uzywany->typ == "zwoj")
		{
			zwoje * zwoj = dynamic_cast <zwoje*>(uzywany);
			UzyjZwoju(zwoj, cel, ktory);
		}
	}	
}

void bohater::ZalozBron(bron * const bron2)
{
	plecak.push_back(bron1);
	bron1 = bron2;
}

void bohater::ZalozZbroje(zbroja* zbroja2)
{
	plecak.push_back(zbroja1);
	zbroja1 = zbroja2;
	obrona = zbroja2->obrona;
}

std::vector <przedmiot*>* bohater::Przeszukaj()
{
	std::vector <przedmiot*>* ostatnioprzeszukane = &cel->plecak;
	if (ostatnioprzeszukane->empty())
	{
		std::cout << "cel nie ma zadnych przedmiotow" << std::endl;
	}
	else
	{
		for (auto it = begin(cel->plecak); it != end(cel->plecak); ++it)
		{
			przedmiot* obecny = *it;
			std::cout << obecny->nazwa << " w slocie " << std::distance(cel->plecak.begin(), it) << std::endl;
		}
	}
	return ostatnioprzeszukane;
}

void bohater::zabierz(int ktory, std::vector<przedmiot*>* lupy)
{
	if (ktory >= lupy->size())
	{
		std::cout << "pusty slot" << std::endl;
	}
	else
	{
		przedmiot* brany = lupy->at(ktory);
		lupy->erase(lupy->begin() + ktory);
		plecak.push_back(brany);
	}
}

void bohater::InformacjeOCzarze(czar* const czar)
{
	std::cout << czar->nazwa << std::endl;
	std::cout << "wymagany poziom to " << czar->wymaganypoziom << std::endl;
	std::cout << "kosztmany to " << czar->kosztmany << std::endl;
	if (czar->obrazeniabaza > 0)
	{
		std::cout << "obrazenia bazowe to " << czar->obrazeniabaza << std::endl;
	}
	else
	{
		std::cout << "leczenie bazowe to " << -czar->obrazeniabaza << std::endl;
	}
	std::cout << "mnoznik od inteligencji " << czar->obrazenianaint << std::endl;
}

void bohater::InformacjeOPrzedmiocie(przedmiot* const przedmiot1)
{
	if (przedmiot1->typ == "bron")
	{
		bron * brona = dynamic_cast<bron*>(przedmiot1);
		std::cout << brona->nazwa << std::endl;
		std::cout << "bazowy atak: " << brona->bazowy_atak <<std::endl;
		std::cout << "skalowanie ataku do sily: " << brona->skalowaniesila << std::endl;
		std::cout << "skalowanie ataku do zrecznosci: " << brona->skalowaniezrecznosc << std::endl;
		std::cout << "skalowanie ataku do inteligencji: " << brona->skalowanieint << std::endl;
	}
	else if (przedmiot1->typ == "zbroja")
	{
		zbroja * zbroj1 = dynamic_cast<zbroja*>(przedmiot1);
		std::cout << zbroj1->nazwa << std::endl;
		std::cout << "obrona: " << zbroj1->obrona << std::endl;
	}
	else if (przedmiot1->typ == "zwoj")
	{
		zwoje * zwoj = dynamic_cast<zwoje*>(przedmiot1);
		std::cout << zwoj->nazwa << std::endl;
		if (zwoj->czar1.obrazeniabaza > 0)
		{
			std::cout << "obrazenia bazowe to " << zwoj->czar1.obrazeniabaza << std::endl;
		}
		else
		{
			std::cout << "leczenie bazowe to " << -zwoj->czar1.obrazeniabaza << std::endl;
		}
		std::cout << "mnoznik od inteligencji " << zwoj->czar1.obrazenianaint << std::endl;
	}
	else if (przedmiot1->typ == "mikstura")
	{
		mikstury * mikstura = dynamic_cast<mikstury*>(przedmiot1);
		std::cout << "zmiana hp: " << mikstura->zmianahp << std::endl;
		std::cout << "zmiana many: " << mikstura->zmianamany << std::endl;
		std::cout << "zmiana inteligencji: " << mikstura->zmianaint << std::endl;
		std::cout << "zmiana sily: " << mikstura->zmianasily << std::endl;
		std::cout << "zmiana zrecznosci: " << mikstura->zmianazrecz << std::endl;
		std::cout << "zmiana maksymalnego hp: " << mikstura->zmianamaxhp << std::endl;
		std::cout << "zmiana maksymalnej many: " << mikstura->zmianamaxmana << std::endl;
	}
	else
	{
		std::cout << "Niepoprawny typ przedmiotu" << std::endl;
	}
}