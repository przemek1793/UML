#pragma once
#include "Pola.h"
#include <array>
#include "postac.h"
#include <string>
#include "bohater.h"
#include "przeciwnik.h"
#include "skrzynia.h"
#include <exception>
#include "szkielet.h"
#include "SzkieletMag.h"
#include "skrzynia.h"

class Mapa
{
public:
	std::array<std::array<Pola*, 40>, 40> pola1;
	Mapa();
	~Mapa();
	bool PrzesunPostaczPola(postac* const postac1, std::string kierunek);
	void WybierzCel(postac* const celujacy, postac* const cel);
	void Mapa1 (bohater* gracz);
	void Mapa2 (bohater* gracz);
	void PokazMape(bohater* const gracz);
	void RuchWrogow(postac* const bohater);
};

            