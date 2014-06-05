#ifndef Effects_h__
#define Effects_h__
#include "cocos2d.h"
USING_NS_CC;
class Effects
{
public:
	static Effects* getInstance();
	void preload();
	void boom(Node*Target,Point point);
	void boom_back(Node*node);
private:
	static Effects* Instance;
};
#endif // Effects_h__
