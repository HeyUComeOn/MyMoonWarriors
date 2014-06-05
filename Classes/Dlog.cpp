#include "Dlog.h"
Dlog::Dlog(){};
Dlog::~Dlog(){};
void Dlog:: d(const char*content)
{
	if(flag)
	{
		log("log==>s%", content);
	}
};

