#include "GamingLayer.h"
#include "ScoreLayer.h"
#include "TimeLayer.h"
#include "PauseLayer.h"

GamingLayer::GamingLayer()
{

}
GamingLayer::~GamingLayer()
{

}
bool GamingLayer::init()
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

void GamingLayer::SetView()
{
	auto sp0=Sprite::create("bg01.jpg");
	auto sp1=Sprite::create("bg01.jpg");
	sp0->setAnchorPoint(Point(0,0));
	sp1->setAnchorPoint(Point(0,0));
	sp0->setPosition(Point(0,0));
	sp1->setPosition(Point(0,576));

	this->addChild(sp0,0,10);
	this->addChild(sp1,0,11);

	//����������schedule����
	this->schedule(schedule_selector(GamingLayer::Background_scroll_logic),0.01f);

	//�����������
	auto score_layer=ScoreLayer::create();
	score_layer->setAnchorPoint(Point(0,1));
	score_layer->setPosition(Point(10,getwinsize().height-20));
	addChild(score_layer);

	//����ʱ�䲼��
	auto time_layer=TimeLayer::create();
	time_layer->setAnchorPoint(Point(0,1));
	time_layer->setPosition(Point(getwinsize().width-time_layer->getContentSize().width/4-10,getwinsize().height-20));
	addChild(time_layer);

	//������ͣ��ť
	auto pause_item=MenuItemImage::create("pause.png","pause.png",CC_CALLBACK_1(GamingLayer::Pause_down,this));
	pause_item->setAnchorPoint(Point(1,0));
	pause_item->setPosition(VisibleRect::rightBottom());
	auto menu=Menu::create(pause_item,NULL);
	menu->setPosition(VisibleRect::leftBottom());
	addChild(menu,1,156);

	//����PauseLayer���������ó����ص�
	auto pPause=PauseLayer::create();
	pPause->setVisible(false);
	this->addChild(pPause,10,99);
	
	//����ɻ�
	m_warriorLayer=WarriorLayer::create();
	addChild(m_warriorLayer);

	////�����ӵ�
	m_heroBulletManager=HeroBulletManager::create();
	addChild(m_heroBulletManager,1);

	//�ƶ�Ӣ���ӵ���schedule
	this->schedule(schedule_selector(GamingLayer::warrior_add_new_bullet),0.15f);

	//����л�
	//�޷���ʾ������һ�ֿ��ܣ�����λ��δ����Ļ��
	m_enemyManager=EnemyManager::create();
	this->addChild(m_enemyManager);
	
	//

}

void GamingLayer::Pause_down(Ref* sender)
{
	//1����ʾ���PauseLayer
	this->getChildByTag(99)->setVisible(true);

	//2������Director��pause����
	Director::getInstance()->pause();
	
	//3���趨Menu��EnabledΪfalse
	auto menu=(Menu*)this->getChildByTag(156);
	menu->setEnabled(false);

	//4���������ֵĿ���
	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}
}

void GamingLayer::Background_scroll_logic(float t)
{
	auto sp0=(Sprite*)this->getChildByTag(10);
	auto sp1=(Sprite*)this->getChildByTag(11);
	sp0->setPositionY(sp0->getPositionY()-5);
	sp1->setPositionY(sp0->getPositionY()+576);
	if(sp1->getPositionY()<=0)
		sp0->setPositionY(0);
}

Scene* GamingLayer::scene()
{
	Scene*sc=NULL;
	do 
	{
		sc=Scene::create();
		CC_BREAK_IF(!sc);
		auto layer=GamingLayer::create();
		CC_BREAK_IF(!layer);
		sc->addChild(layer);
	} while (0);
	return sc;
}

void GamingLayer::warrior_add_new_bullet(float t)
{
	m_heroBulletManager->addNewBullet(m_warriorLayer->getWarriorPosition(),m_warriorLayer->getWarriorSize());
}