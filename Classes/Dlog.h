#ifndef Dlog_h__
#define Dlog_h__

#include "cocos2d.h"
USING_NS_CC;
//  Log π§æﬂ¿‡
class Dlog
{
public:
	Dlog();
	~Dlog();
	const static bool flag=true;
	static void d(const char*content);
};
#endif // Dlog_h__
