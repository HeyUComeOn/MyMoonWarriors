#include "HeroBulletManager.h"
#include "WelcomeLayer.h"
#include "GamingLayer.h"
HeroBulletManager::HeroBulletManager():HeroBulletVec()
{

}
HeroBulletManager::~HeroBulletManager()
{
	
}
bool HeroBulletManager::init()
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

void HeroBulletManager::SetView()
{
	//1�����ӵ���plist�ļ����뵽SpriteFrameCache��
	//ת��WelcomeLayer.cpp����

	//2����ȡ����Ӣ�۵��ӵ����뵽SpriteBatchNode��
	mBulletsBatchNode=SpriteBatchNode::create("bullet.png");

	//3��ΪSpriteBatchNode�������Ч��
	BlendFunc cd={GL_SRC_ALPHA,GL_ONE};
	mBulletsBatchNode->setBlendFunc(cd);//ͨ��SpriteBatchNodeһ����Ⱦ

	addChild(mBulletsBatchNode);

//	this->schedule(schedule_selector(HeroBulletManager::addNewBullet),0.5f);//����������ʧ�죬�����ӵ��м��
	this->schedule(schedule_selector(HeroBulletManager::moveAllBullets),0.015f);
}

Scene* HeroBulletManager::scene()
{
	Scene*sc=NULL;
	do 
	{
		sc=Scene::create();
		CC_BREAK_IF(!sc);
		auto layer=HeroBulletManager::create();
		CC_BREAK_IF(!layer);
		sc->addChild(layer);
	} while (0);
	return sc;
}

void HeroBulletManager::addNewBullet(const Point point,const Size WarriorSize)
{
	//left bullet
	auto bulletSprite1=Sprite::createWithSpriteFrameName("W1.png");
	bulletSprite1->setPosition(Point(point.x-WarriorSize.width/4+2,point.y+WarriorSize.height/2));
	
	//right bullet
	auto bulletSprite2=Sprite::createWithSpriteFrameName("W1.png");
	bulletSprite2->setPosition(Point(point.x+WarriorSize.width/4-2,point.y+WarriorSize.height/2));
	mBulletsBatchNode->addChild(bulletSprite1);
	mBulletsBatchNode->addChild(bulletSprite2);
	HeroBulletVec.pushBack(bulletSprite1);
	HeroBulletVec.pushBack(bulletSprite2);

}

void HeroBulletManager::moveAllBullets(float t)//���ơ�------������  �ӵ�����ֻ��ɾ��
{
	Vector<Sprite*>::iterator iter; 
	for (iter=HeroBulletVec.begin();iter!=HeroBulletVec.end();)
	{
		(*iter)->setPositionY((*iter)->getPositionY()+10);
		if((*iter)->getPositionY()>=(VisibleRect::top()).y)
		{
			mBulletsBatchNode->removeChild((*iter),true);//ע�����������˳��ǧ���ܴ�
			iter=HeroBulletVec.erase(iter);

		}
		else
		{
			auto father=(GamingLayer*)this->getParent();
			auto EnemyVec=father->m_enemyManager->enemyVec;
			Vector<EnemyModel*>::iterator iter2;//�о�decltype������������
			for (iter2=EnemyVec.begin();iter2!=EnemyVec.end();)
			{
				if((*iter)->getBoundingBox().containsPoint((*iter2)->getPosition()))
					log("������");
				iter2++;
			}
			iter++;
			
		}
	}

}

