#include "skrzynia.h"



skrzynia::skrzynia()
{
	nazwa = "skrzynia";
}

skrzynia::skrzynia(przedmiot* cos)
{
	nazwa = "skrzynia";
	plecak.push_back(cos);
}

skrzynia::~skrzynia()
{
}
