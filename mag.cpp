#include "mag.h"



mag::mag()
{	
	maxhp = hplvl + hpbaza;
	maxmana = manalvl + manabaza;
	sila = silabaza + silalvl;
	zrecznosc = zrecznoscbaza + zrecznosclvl;
	inteligencja = inteligencjabaza + inteligencjalvl;
	poziom = 1;
	hp = maxhp;
	mana = maxmana;
	kulaognia a{};
	NaukaCzaru(a);
	czyzyje = true;
	bron1 =new ZwyklyMiecz{};
	zbroja1 = new Szata{};
	obrona = zbroja1->obrona;
	nazwa = "mag";
}

mag::~mag()
{
}

void mag::NaukaCzaru(czar czar1)
{
	if (czar1.wymaganypoziom <= poziom)
	{
		znaneczary.push_back(czar1);
	}
	else
	{
		std::cout << "masz za niski poziom aby nauczyc sie tego czaru" << std::endl;
	}
}

void mag::NaukaCzaru(zwoje *zwoj1, int ktory)
{
	czar zezwoju = zwoj1->czar1;
	if (zezwoju.wymaganypoziom <= poziom)
	{
		NaukaCzaru(zezwoju);
		plecak.erase(plecak.begin() + ktory);
		delete zwoj1;
	}
	else
	{
		std::cout << "masz za niski poziom aby nauczyc sie tego czaru" << std::endl;
	}
}

void mag::UzyjZwoju(zwoje * const zwoj1, postac* const cel, int ktory)
{
	std::cout << "czy chcesz sie nauczyc czaru ze zwoju (\"tak\"aby sie uczyc, w innych przypadkach zostanie rzucone zaklecie ze zwoju)" << std::endl;
	std::string wybor;
	std::getline(std::cin, wybor);
	if (wybor == "tak")
	{
		NaukaCzaru(zwoj1, ktory);
	}
	else if (cel == NULL)
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
		int obrazenia = zezwoju.obrazeniabaza + (inteligencja + bron1->dodatkowainteligencja)*zezwoju.obrazenianaint;
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