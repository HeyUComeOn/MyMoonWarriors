#include "PauseLayer.h"
#include "GamingLayer.h"
PauseLayer::PauseLayer()
{

}
PauseLayer::~PauseLayer()
{

}
bool PauseLayer::init()
{
	bool s=false;
	do 
	{
		CC_BREAK_IF(!LayerColor::initWithColor(Color4B(0,0,0,50)));
		SetView();
		s=true;
	} while (0);
	return s;
}

void PauseLayer::SetView()
{
	do 
	{
		auto resume_item=MenuItemImage::create("play.png","play.png",CC_CALLBACK_1(PauseLayer::Play_pressed,this));
		resume_item->setPosition(VisibleRect::center());
		auto menu=Menu::create(resume_item,NULL);
		menu->setPosition(VisibleRect::leftBottom());
		addChild(menu);
	} while (0);
	
}

void PauseLayer::Play_pressed(Ref*pSender)//搞清楚pSender的指向,resume_item
{
	//auto sk=(MenuItemImage*)pSender;
	//sk->setVisible(false);//第二次暂停后，play按钮不见了
	//1、隐藏暂停Layer
	this->setVisible(false);

	//2、获取父节点，然后设定父节点Menu的enable为true
	GamingLayer*fatherNode=(GamingLayer*)this->getParent();
	auto pPauseLayer=(PauseLayer*)fatherNode->getChildByTag(99);
	auto menu=(Menu*)fatherNode->getChildByTag(156);
	menu->setEnabled(true);

	//3、调用Director的resume
	Director::getInstance()->resume();

	//4、恢复背景音乐
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/mainMainMusic.mp3",true);
}


Scene* PauseLayer::scene()
{
	Scene*sc=NULL;
	do 
	{
		sc=Scene::create();
		CC_BREAK_IF(!sc);
		auto layer=PauseLayer::create();
		CC_BREAK_IF(!layer);
		sc->addChild(layer);
	} while (0);
	return sc;
}