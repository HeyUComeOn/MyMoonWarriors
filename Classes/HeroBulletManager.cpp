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
	//1、将子弹的plist文件加入到SpriteFrameCache中
	//转到WelcomeLayer.cpp中了

	//2、读取其中英雄的子弹加入到SpriteBatchNode中
	mBulletsBatchNode=SpriteBatchNode::create("bullet.png");

	//3、为SpriteBatchNode加入光晕效果
	BlendFunc cd={GL_SRC_ALPHA,GL_ONE};
	mBulletsBatchNode->setBlendFunc(cd);//通过SpriteBatchNode一并渲染

	addChild(mBulletsBatchNode);

//	this->schedule(schedule_selector(HeroBulletManager::addNewBullet),0.5f);//产生慢，消失快，导致子弹有间隔
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

void HeroBulletManager::moveAllBullets(float t)//“移”------“动”  子弹，不只是删除
{
	Vector<Sprite*>::iterator iter; 
	for (iter=HeroBulletVec.begin();iter!=HeroBulletVec.end();)
	{
		(*iter)->setPositionY((*iter)->getPositionY()+10);
		if((*iter)->getPositionY()>=(VisibleRect::top()).y)
		{
			mBulletsBatchNode->removeChild((*iter),true);//注意这两条语句顺序千万不能错
			iter=HeroBulletVec.erase(iter);

		}
		else
		{
			auto father=(GamingLayer*)this->getParent();
			auto EnemyVec=father->m_enemyManager->enemyVec;
			Vector<EnemyModel*>::iterator iter2;//感觉decltype反而不好用了
			for (iter2=EnemyVec.begin();iter2!=EnemyVec.end();)
			{
				if((*iter)->getBoundingBox().containsPoint((*iter2)->getPosition()))
					log("碰上了");
				iter2++;
			}
			iter++;
			
		}
	}

}

