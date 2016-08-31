#include "Mapa.h"
#include <iostream>



Mapa::Mapa()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			Pola *temp=new Pola(i,j);
			pola1[i][j] = temp;
		}
	}
}


Mapa::~Mapa()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (pola1[i][j]->KtoJestNaPolu)
			{
				delete pola1[i][j]->KtoJestNaPolu;
			}
			delete pola1[i][j];
		}
	}
}

void Mapa::WybierzCel(postac* const celujacy, postac* const cel)
{
	celujacy->cel = cel;
}

bool Mapa::PrzesunPostaczPola(postac* const postac1, std::string kierunek)
{
	Pola* const polezpostacia = pola1[postac1->x][postac1->y];
	if (polezpostacia == NULL)
	{
		std::cout << "Nie znaleziono na mapie postaci" << std::endl;
		return false;
	}
	if (polezpostacia->KtoJestNaPolu != postac1)
	{
		std::cout << "Dana postac nie znajduje sie na tym polu" << std::endl;
	}
	else
	{
		int tempx, tempy;
		if (kierunek == "lewo")
		{
			if (polezpostacia->x == 0)
			{
				std::cout << "Nie mozesz wyjsc poza mape" << std::endl;
				return false;
			}
			else
			{
				if (pola1[polezpostacia->x - 1][polezpostacia->y]->KtoJestNaPolu != NULL)
				{
					std::cout << "Ktos juz jest na tym polu" << std::endl;
					return false;
				}
				else if (pola1[polezpostacia->x - 1][polezpostacia->y]->CzyZablokowane == true)
				{
					std::cout << "Nie da sie wejsc na to pole" << std::endl;
					return false;
				}
				else
				{
					pola1[polezpostacia->x - 1][polezpostacia->y]->KtoJestNaPolu = postac1;
					polezpostacia->KtoJestNaPolu = NULL;
					--postac1->x;
					return true;
				}
			}
		}
		else if (kierunek == "prawo")
		{
			if (polezpostacia->x == 39)
			{
				std::cout << "Nie mozesz wyjsc poza mape" << std::endl;
				return false;
			}
			else
			{
				if (pola1[polezpostacia->x + 1][polezpostacia->y]->KtoJestNaPolu != NULL)
				{
					std::cout << "Ktos juz jest na tym polu" << std::endl;
					return false;
				}
				else if (pola1[polezpostacia->x + 1][polezpostacia->y]->CzyZablokowane == true)
				{
					std::cout << "Nie da sie wejsc na to pole" << std::endl;
					return false;
				}
				else
				{
					pola1[polezpostacia->x + 1][polezpostacia->y]->KtoJestNaPolu = postac1;
					polezpostacia->KtoJestNaPolu = NULL;
					++postac1->x;
					return true;
				}
			}
		}
		else if (kierunek == "gora")
		{
			if (polezpostacia->y == 0)
			{
				std::cout << "Nie mozesz wyjsc poza mape" << std::endl;
				return false;
			}
			else
			{
				if (pola1[polezpostacia->x][polezpostacia->y - 1]->KtoJestNaPolu != NULL)
				{
					std::cout << "Ktos juz jest na tym polu" << std::endl;
					return false;
				}
				else if (pola1[polezpostacia->x][polezpostacia->y - 1]->CzyZablokowane == true)
				{
					std::cout << "Nie da sie wejsc na to pole" << std::endl;
					return false;
				}
				else
				{
					pola1[polezpostacia->x][polezpostacia->y - 1]->KtoJestNaPolu = postac1;
					polezpostacia->KtoJestNaPolu = NULL;
					--postac1->y;
					return true;
				}
			}
		}
		else if (kierunek == "dol")
		{
			if (polezpostacia->y == 39)
			{
				std::cout << "Nie mozesz wyjsc poza mape" << std::endl;
				return false;
			}
			else
			{
				if (pola1[polezpostacia->x][polezpostacia->y + 1]->KtoJestNaPolu != NULL)
				{
					std::cout << "Ktos juz jest na tym polu" << std::endl;
					return false;
				}
				else if (pola1[polezpostacia->x][polezpostacia->y + 1]->CzyZablokowane == true)
				{
					std::cout << "Nie da sie wejsc na to pole" << std::endl;
					return false;
				}
				else
				{
					pola1[polezpostacia->x][polezpostacia->y + 1]->KtoJestNaPolu = postac1;
					polezpostacia->KtoJestNaPolu = NULL;
					++postac1->y;
					return true;
				}
			}
		}
		else
		{
			std::cout << "niepoprawny kierunek" << std::endl;
			return false;
		}
	}
}

void Mapa::Mapa1(bohater* gracz)
{
	pola1[5][7]->KtoJestNaPolu = gracz;
	gracz->x = 5;
	gracz->y = 7;
	pola1[5][10]->CzyWyjscie = true;
	szkielet* sz1= new szkielet(gracz);
	pola1[9][8]->KtoJestNaPolu = sz1;
	sz1->x = 9;
	sz1->y = 8;
	pola1[3][5]->KtoJestNaPolu = new skrzynia(new ZwyklyMiecz());
	SzkieletMag* sz2= new SzkieletMag(gracz);
	pola1[4][6]->KtoJestNaPolu = sz2;
	sz2->x = 4;
	sz2->y = 6;
}

void Mapa::Mapa2(bohater* gracz)
{
	pola1[2][2]->KtoJestNaPolu = gracz;
	gracz->x = 2;
	gracz->y = 2;
	pola1[5][10]->CzyWyjscie = true;
	szkielet* sz1 = new szkielet(gracz);
	pola1[9][8]->KtoJestNaPolu = sz1;
	sz1->x = 9;
	sz1->y = 8;
	pola1[3][5]->KtoJestNaPolu = new skrzynia(new ZwyklyMiecz());
	SzkieletMag* sz2 = new SzkieletMag(gracz);
	pola1[4][6]->KtoJestNaPolu = sz2;
	sz2->x = 4;
	sz2->y = 6;
}

void Mapa::PokazMape(bohater* const gracz)
{
	Pola* const polezpostacia =pola1[gracz->x][gracz->y];
	std::cout <<  "  ";
	for (int i = polezpostacia->x - 4; i < polezpostacia->x + 5; i++)
	{
		if (!(i < 0 || i>39))
		{
			std::cout << i ;
		}
	}
	std::cout << std::endl;
	for (int j = polezpostacia->y - 4; j < polezpostacia->y + 5; j++)	
	{
		if (!(j < 0 || j>39))
		{
			if (j < 10)
			{
				std::cout << j << " ";
			}
			else
			{
				std::cout << j;
			}
		}
		for (int i = polezpostacia->x - 4; i < polezpostacia->x + 5; i++)
		{
			if (!(i < 0 || j < 0 || i>39 || j>39))
			{
				if (polezpostacia->x == i && polezpostacia->y == j)
				{
					std::cout << "G";
				}
				else if (dynamic_cast<skrzynia*>(pola1[i][j]->KtoJestNaPolu))
				{
					std::cout << "S";
				}
				else if (dynamic_cast<przeciwnik*>(pola1[i][j]->KtoJestNaPolu))
				{
					if (pola1[i][j]->KtoJestNaPolu->czyzyje)
					{
						std::cout << "P";
					}
					else
					{
						std::cout << "T";
					}
				}
				else
				{
					if (pola1[i][j]->CzyWyjscie)
					{
						std::cout << "W";
					}
					else if (pola1[i][j]->CzyZablokowane)
					{
						std::cout << "X";
					}
					else
					{
						std::cout << "*";
					}
				}
			}
		}
		if (!(j < 0 || j>39))
		{
			std::cout << std::endl;
		}
	}
}

void Mapa::RuchWrogow(postac* const bohater)
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (pola1[i][j]->KtoJestNaPolu)
			{
				if (i != bohater->x && j != bohater->y)
				{
					przeciwnik *wrog1= dynamic_cast <przeciwnik*>(pola1[i][j]->KtoJestNaPolu);
					if (wrog1->czyzyje)
					{
						int odleglosc = pow((bohater->x - wrog1->x), 2) + pow((bohater->y - wrog1->y), 2);
						if (!wrog1->aggro)
						{
							if (odleglosc < 9)
							{
								wrog1->aggro = true;
							}
						}
						if (wrog1->aggro)
						{
							if (wrog1->mag)
							{
								int koszmany = wrog1->uzywany.kosztmany;
								if (koszmany < wrog1->mana)
								{
									wrog1->RzucZaklecie(&wrog1->uzywany);
								}
							}
							else
							{
								if (odleglosc > 3)
								{
									if (wrog1->x > bohater->x)
									{
										PrzesunPostaczPola(wrog1, "lewo");
									}
									else if (wrog1->x < bohater->x)
									{
										PrzesunPostaczPola(wrog1, "prawo");
									}
									else if (wrog1->y > bohater->y)
									{
										PrzesunPostaczPola(wrog1, "gora");
									}
									else if (wrog1->y < bohater->y)
									{
										PrzesunPostaczPola(wrog1, "dol");
									}
								}
								else
								{
									wrog1->Atakuj();
								}
							}
						}
					}
				}
			}
		}
	}
}