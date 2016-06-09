#include "zwoje.h"



zwoje::zwoje(czar czar2)
{
	czar1 = czar2;
	nazwa = "zwoj z zakleciem " + czar1.nazwa;
	typ = "zwoj";
}


zwoje::~zwoje()
{
}
