#pragma once
#include "postac.h"
#include "zwoje.h"
#include "mikstury.h"
#include "ekwipunek.h"
#include "bron.h"
#include "zbroja.h"
#include "Topor.h"
#include "ZwyklyMiecz.h"
#include "Szata.h";
#include "SkorzanaZbroja.h"

class bohater :
	public postac
{
	virtual void UzyjZwoju(zwoje * zwoj1, postac* const cel, int ktory);
	void UzyjMikstury(mikstury * mikstura1);
	int hplvl, manalvl, silalvl, zrecznosclvl, inteligencjalvl = 0;
	void LvlUp();
public:
	void ZalozBron(bron * const bron2);
	void ZalozZbroje(zbroja* zbroja2);
	zbroja* zbroja1;
	bron* bron1;	
	int iledolvl = 500;
	void ZdobadzXP(int xp);
	void RzucZaklecie(czar* const czar);
	void PokazPlecak();
	void InformacjeOCzarze(czar* const czar);
	void InformacjeOPrzedmiocie(przedmiot* const przedmiot);
	void UzyjPrzedmiotWSlocie(int ktory);
	std::vector <przedmiot*>* Przeszukaj();
	void zabierz(int ktory, std::vector<przedmiot*>* lupy);
	void PokazCzary();
	virtual void Atakuj();
	bohater();
	~bohater();
};

