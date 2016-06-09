#include <iostream>
#include "postac.h"
#include "wojownik.h"
#include "szkielet.h"
#include "czar.h"
#include "kulaognia.h"
#include "mag.h"
#include "zwoje.h"
#include "leczenie.h"
#include "mikstury.h"
#include "ZwyklyMiecz.h"
#include "Topor.h"
#include "Mapa.h"
#include "bohater.h"
#include <cstdlib >


bohater* WyborKlasy(std::string nazwaklasy)
{
	bohater* gracz{};
	if (nazwaklasy == "wojownik")
	{
		gracz =new wojownik();
	}
	else if (nazwaklasy == "mag")
	{
		gracz = new mag();
	}
	else
	{
		std::cout << "Podales niepoprawna nazwe klasy" << std::endl;
		return NULL;
	}
	return gracz;
}

int main()
{
	szkielet andrzej{};
	Mapa map{};
	bool koniec = false;
	std::cout << "Wybierz klase postaci" << std::endl;
	std::cout << "Dostepne klasy to: mag i wojownik" << std::endl;
	std::string wybor;
	std::getline(std::cin, wybor);
	bohater *gracz=WyborKlasy(wybor);
	while (!gracz)
	{
		std::cout << "Wybierz klase postaci" << std::endl;
		std::cout << "Dostepne klasy to: mag i wojownik" << std::endl;
		std::getline(std::cin, wybor);
		gracz = WyborKlasy(wybor);
	}
	map.Mapa1(gracz);
	while (!koniec&& gracz->czyzyje)
	{
		Pola* PoleZGraczem = map.pola1[gracz->x][gracz->y];
		if (PoleZGraczem->CzyWyjscie == true)
		{
			std::cout << "Gratulacje, doszedles do wyjscia" << std::endl;
			koniec = true;
		}
		else
		{
			std::cout << "G-gracz, P-przeciwnik, T-pokonany przeciwnik, S-skrzynia, W-wyjscie, X-pole na ktore nie da sie wejsc" << std::endl;
			std::cout << "Aby wygrac dojdz do wyjscia" << std::endl;
			std::cout << "Obecnie znajdujesz sie na polu " << PoleZGraczem->x << " " << PoleZGraczem->y << std::endl;
			if (gracz->cel != NULL)
			{
				std::cout << "Twoj obecny cel atakow to " << gracz->cel->nazwa << " znajdujacy sie na polu " << gracz->cel->x << " " << gracz->cel->y << std::endl;
			}
			else
			{
				std::cout << "obecnie nie masz zadnego celu atakow" << std::endl;
			}
			map.PokazMape(gracz);
			std::cout << "Dostepne ruchy to: rusz sie, wybierz cel, atakuj cel, przejrzyj ekwipunek, uzyj przedmiotu, zobacz znane czary,"  << std::endl;
			std::cout << "rzuc czar, statystyki postaci, statystyki celu, przeszukaj cel, informacje o zakleciu,"  << std::endl;
				std::cout << "informacje o przedmiocie, wyjdz z gry" << std::endl;
			std::getline(std::cin, wybor);
			if (wybor == "rusz sie")
			{
				std::cout << "gdzie chcesz isc (lewo, prawo, gora, dol)" << std::endl;
				std::getline(std::cin, wybor);
				if (map.PrzesunPostaczPola(gracz, wybor))
				{
					map.RuchWrogow(gracz);
				}
			}
			else if (wybor == "wybierz cel")
			{
				int tempx, tempy;
				std::cout << "Podaj wspolrzedna x postaci ktora chcesz wybrac" << std::endl;
				std::getline(std::cin, wybor);
				tempx = atoi(wybor.c_str());
				std::cout << "Podaj wspolrzedna y postaci ktora chcesz wybrac" << std::endl;
				std::getline(std::cin, wybor);
				tempy = atoi(wybor.c_str());
				postac* tempcel;
				tempcel = map.pola1[tempx][tempy]->KtoJestNaPolu;
				if (!tempcel)
				{
					std::cout << "Na danym polu nie ma postaci" << std::endl;
				}
				else
				{
					gracz->cel = tempcel;
					std::cout << "Wybrano " <<gracz->cel->nazwa<< " "<< " znajdujacy sie na polu o wspolrzednych "<< tempx<<" "<<tempy<<" na cel"<< std::endl;
				}
			}
			else if (wybor == "atakuj cel")
			{
				if (gracz->cel != NULL)
				{
					if (gracz->cel->nazwa == "skrzynia")
					{
						std::cout << "cel to skrzynia, nie mozesz zaatakowac skrzyni" << std::endl;
					}
					else if (gracz->cel->czyzyje)
					{
						int odleglosc = pow((gracz->x - gracz->cel->x), 2)+ pow((gracz->y - gracz->cel->y), 2);
						if (odleglosc > 3)
						{
							std::cout << "cel jest za daleko aby go zaatakowac" << std::endl;
						}
						else
						{
							gracz->Atakuj();
							map.RuchWrogow(gracz);
						}
					}
					else
					{
						std::cout << "Twoj cel juz nie zyje" << std::endl;
					}
				}
				else
				{
					std::cout << "Nie masz celu ataku" << std::endl;
				}
			}
			else if (wybor == "przejrzyj ekwipunek")
			{
				gracz->PokazPlecak();
				std::cout << "aktualnie ubrana bron to " << gracz->bron1->nazwa << std::endl;
				std::cout << "aktualnie wybrana zbroja to " << gracz->zbroja1->nazwa << std::endl;
			}
			else if (wybor == "uzyj przedmiotu")
			{
				if (gracz->plecak.empty())
				{
					std::cout << "nie masz zadnych przedmiotow" << std::endl;
				}
				else
				{
					gracz->PokazPlecak();
					std::cout << "Podaj numer slotu w ktorym znajduje sie przedmiot ktory chcesz uzyc" << std::endl;
					std::getline(std::cin, wybor);
					int slot = atoi(wybor.c_str());
					gracz->UzyjPrzedmiotWSlocie(slot);
				}	
			}
			else if (wybor == "zobacz znane czary")
			{
				gracz->PokazCzary();
			}
			else if (wybor == "rzuc czar")
			{
				if (gracz->cel != NULL)
				{
					if (gracz->cel->nazwa == "skrzynia")
					{
						std::cout << "cel to skrzynia, nie mozesz atakowac skrzyn" << std::endl;
					}
					else if (gracz->cel->czyzyje)
					{
						if (gracz->znaneczary.empty())
						{
							std::cout << "nie znasz zadnych czarow" << std::endl;
						}
						else
						{
							gracz->PokazCzary();
							std::cout << "podaj numer zaklecia ktore chcesz uzyc" << std::endl;
							std::getline(std::cin, wybor);
							int numer = atoi(wybor.c_str())-1;
							gracz->RzucZaklecie(&gracz->znaneczary.at(numer));
							map.RuchWrogow(gracz);
						}		
					}
					else
					{
						std::cout << "Twoj cel juz nie zyje" << std::endl;
					}
				}
				else
				{
					std::cout << "Nie masz celu ataku" << std::endl;
				}
			}
			else if (wybor == "statystyki postaci")
			{
				std::cout << "aktualny poziom to  " << gracz->poziom << " potrzebujesz " << gracz->iledolvl<< " doswiadczenia aby awansowac na kolejny poziom" << std::endl;
				std::cout << "hp " << gracz->hp << std::endl; 
				std::cout << "maksymalne mozliwe hp " << gracz->maxhp << std::endl;
				std::cout << "mana " << gracz->mana << std::endl;
				std::cout << "maksymalna mozliwa mana " << gracz->maxmana << std::endl;
				std::cout << "sila " << gracz->sila+gracz->zbroja1->dodatkowasila+gracz->bron1->dodatkowasila << std::endl;
				std::cout << "zrecznosc " << gracz->zrecznosc + gracz->zbroja1->dodatkowazrecznosc + gracz->bron1->dodatkowazrecznosc << std::endl;
				std::cout << "inteligencja " << gracz->inteligencja + gracz->zbroja1->dodatkowainteligencja + gracz->bron1->dodatkowainteligencja << std::endl;
				std::cout << "aktualnie ubrana bron to " << gracz->bron1->nazwa << std::endl;
				std::cout << "aktualnie wybrana zbroja to " << gracz->zbroja1->nazwa << std::endl;
				std::cout << "obrona " << gracz->obrona << std::endl;
			}
			else if (wybor == "statystyki celu")
			{
				if (gracz->cel->nazwa == "skrzynia")
				{
					std::cout << "cel to skrzynia, skrzynie nie maja statystyk" << std::endl;
				}
				else
				{
					std::cout << gracz->cel->nazwa << std::endl;
					std::cout << "hp " << gracz->cel->hp << std::endl;
					std::cout << "maksymalne mozliwe hp " << gracz->cel->maxhp << std::endl;
					std::cout << "mana " << gracz->cel->mana << std::endl;
					std::cout << "maksymalna mozliwa mana " << gracz->cel->maxmana << std::endl;
					std::cout << "sila " << gracz->cel->sila << std::endl;
					std::cout << "zrecznosc " << gracz->cel->zrecznosc << std::endl;
					std::cout << "inteligencja " << gracz->cel->inteligencja << std::endl;
					std::cout << "obrona " << gracz->cel->obrona << std::endl;
				}
			}
			else if (wybor == "przeszukaj cel")
			{
				if (gracz->cel == NULL)
				{
					std::cout << "nie masz celu" << std::endl;
				}
				else
				{
					if (gracz->cel->czyzyje == false || gracz->cel->nazwa == "skrzynia")
					{
						wybor = "tak";
						while (wybor == "tak")
						{

							std::vector <przedmiot*>* przeszukane= gracz->Przeszukaj();		
							if (!przeszukane->empty())
							{
								std::cout << "Wpisz numer slotu z przedmiotem ktory chcesz wziac" << std::endl;
								std::getline(std::cin, wybor);
								int numer = atoi(wybor.c_str());
								gracz->zabierz(numer, przeszukane);
								std::cout << "Jesli chcesz cos jeszcze zabrac wpisz \"tak\"" << std::endl;
								std::getline(std::cin, wybor);
							}
							else
							{
								wybor = "nie";
							}
						}
					}
					else
					{
						std::cout << "cel jeszcze zyje" << std::endl;
					}
				}		
			}
			else if (wybor == "informacje o zakleciu")
			{
				if (gracz->znaneczary.empty())
				{
					std::cout << "nie znasz zadnych czarow" << std::endl;
				}
				else
				{
					gracz->PokazCzary();
					std::cout << "podaj numer zaklecia" << std::endl;
					std::getline(std::cin, wybor);
					int numer = atoi(wybor.c_str()) - 1;
					gracz->InformacjeOCzarze(&gracz->znaneczary.at(numer));
				}
			}
			else if (wybor == "informacje o przedmiocie")
			{
				std::cout << "aktualnie ubrana bron to " << gracz->bron1->nazwa << std::endl;
				std::cout << "aktualnie wybrana zbroja to " << gracz->zbroja1->nazwa << std::endl;
				gracz->PokazPlecak();
				std::cout << "Wpisz numer slotu z przedmiotem ktorego statystyki chcesz zobaczyc, lub wpisz zbroja/bron aby zobaczyc statystyki uzywanej zbroji/broni" << std::endl;
				std::getline(std::cin, wybor);
				if (wybor == "bron")
				{
					gracz->InformacjeOPrzedmiocie(gracz->bron1);
				}
				else if (wybor == "zbroja")
				{
					gracz->InformacjeOPrzedmiocie(gracz->zbroja1);
				}
				else
				{
					int numer = atoi(wybor.c_str());
					gracz->InformacjeOPrzedmiocie(gracz->plecak.at(numer));
				}
			}
			else if (wybor == "wyjdz z gry")
			{
				koniec = true;
			}
			else
			{
				std::cout << "niepoprawny ruch" << std::endl;
			}
		}
		std::cout << std::endl;
	}	
	if (!gracz->czyzyje)
	{
		std::cout << "Twoja postac umarla" << std::endl;
	}
	std::cout << "koniec gry" << std::endl;
	system("PAUSE");
	return 0;
}