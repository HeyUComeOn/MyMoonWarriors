#include "BasicLayer.h"
bool BasicLayer::init()
{
	bool s=false;
	do 
	{
		CC_BREAK_IF(!Layer::init());
		s=true;
	} while (0);
	return s;
};

Size BasicLayer::getwinsize()
{
	return Director::getInstance()->getWinSize();
};

void BasicLayer::setBackgroundImage(const std::string Background_file_name )
{
	Sprite* sprite=Sprite::create(Background_file_name);
	sprite->setPosition(getwinsize().width/2,getwinsize().height/2);
	this->addChild(sprite);
}