#include "WarriorLayer.h"
#include "WelcomeLayer.h"

WarriorLayer::WarriorLayer()
{

}
WarriorLayer::~WarriorLayer()
{
	m_warrior=NULL;
}
bool WarriorLayer::init()
{
	bool s=false;
	do 
	{
		CC_BREAK_IF(!BasicLayer::init());
		SetView();
		s=true;
	} while (0);
	return s;
}

void WarriorLayer::SetView()
{
	//1、添加一个精灵，即主角
	m_warrior=Sprite::create("ship01.png",Rect(60,0,60,43));
	m_warrior->setPosition(VisibleRect::center());
	addChild(m_warrior,1,110);

	//2、为精灵添加动作
	auto animation=Animation::create();
	auto spfrm1=SpriteFrame::create("ship01.png",Rect(60,0,60,43));
	auto spfrm2=SpriteFrame::create("ship01.png",Rect(0,0,60,43));
	animation->addSpriteFrame(spfrm1);
	animation->addSpriteFrame(spfrm2);
	animation->setDelayPerUnit(0.2f);
	auto animate=Animate::create(animation);
	m_warrior->runAction(RepeatForever::create(animate));

	//3、创建触摸
	auto listener=EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	
	listener->onTouchBegan=[&](Touch *touch, Event *unused_event)//第二个参数指代的是什么
	{
		auto movto=MoveTo::create(0.3f,touch->getLocation());
		m_warrior->runAction(movto);
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,m_warrior);
}

Scene* WarriorLayer::scene()
{
	Scene*sc=NULL;
	do 
	{
		sc=Scene::create();
		CC_BREAK_IF(!sc);
		auto layer=WarriorLayer::create();
		CC_BREAK_IF(!layer);
		sc->addChild(layer);
	} while (0);
	return sc;
}

Point WarriorLayer::getWarriorPosition()
{
	return m_warrior->getPosition();
}

Size WarriorLayer::getWarriorSize()
{
	return m_warrior->getContentSize();
}