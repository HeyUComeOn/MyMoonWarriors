#include "Effects.h"

Effects* Effects::Instance=nullptr;//注意初始化的方式

Effects* Effects::getInstance()
{
	if(!Instance)
		Instance=new Effects;
	return Instance;
}

void Effects::preload()
{
	//png和plist在一个文件夹可以这样写
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("explosion.plist");
	char str[20]={};
	auto boomAnimation=Animation::create();
	boomAnimation->setDelayPerUnit(0.1f);
	boomAnimation->setLoops(1);
	for(int i=1;i!=36;i++)
	{
		sprintf(str,"explosion_%02d.png",i);
		auto boomSpfrm=SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		boomAnimation->addSpriteFrame(boomSpfrm);
	}

	//将这个动作加入到动画缓存中
	AnimationCache::getInstance()->addAnimation(boomAnimation,"boom");
}

void Effects::boom(Node*Target,Point point)
{
	auto sp=Sprite::createWithSpriteFrameName("explosion_01.png");
	Target->addChild(sp);
	sp->setPosition(point);

	auto animation=AnimationCache::getInstance()->getAnimation("boom");

	auto animate=Animate::create(animation);

	auto callaction=CallFunc::create(CC_CALLBACK_0(Effects::boom_back,this,sp));

	sp->runAction(Sequence::create(animate,callaction,NULL));
}

void Effects::boom_back(Node*node)
{
	node->removeFromParentAndCleanup(true);
}