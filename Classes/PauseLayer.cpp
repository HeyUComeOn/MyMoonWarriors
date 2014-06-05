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

void PauseLayer::Play_pressed(Ref*pSender)//�����pSender��ָ��,resume_item
{
	//auto sk=(MenuItemImage*)pSender;
	//sk->setVisible(false);//�ڶ�����ͣ��play��ť������
	//1��������ͣLayer
	this->setVisible(false);

	//2����ȡ���ڵ㣬Ȼ���趨���ڵ�Menu��enableΪtrue
	GamingLayer*fatherNode=(GamingLayer*)this->getParent();
	auto pPauseLayer=(PauseLayer*)fatherNode->getChildByTag(99);
	auto menu=(Menu*)fatherNode->getChildByTag(156);
	menu->setEnabled(true);

	//3������Director��resume
	Director::getInstance()->resume();

	//4���ָ���������
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