#include "EnemyModel.h"
#include "VisibleRect.h"
EnemyModel::EnemyModel(Monster monster,Point targetPoint):BulletVec()
{
	//在WelcomeLayer中加入Monster.plist文件
	
	switch (monster)
	{
	case monster0:
		m_Sprite=Sprite::createWithSpriteFrameName("Monster1.png");
		m_Action=MoveTo::create(3.0f,targetPoint);
		break;
	case monster1:
		m_Sprite=Sprite::createWithSpriteFrameName("Monster2.png");
		break;
	case monster2:
		m_Sprite=Sprite::createWithSpriteFrameName("Monster3.png");
		break;
	case monster3:
		m_Sprite=Sprite::createWithSpriteFrameName("Monster4.png");
		break;
	case monster4:
		m_Sprite=Sprite::createWithSpriteFrameName("Monster5.png");
		break;
	case monster5:
		m_Sprite=Sprite::createWithSpriteFrameName("Monster6.png");
		break;
	default:
		break;
	}
}

EnemyModel::~EnemyModel()
{

}

bool EnemyModel::init()
{	
	this->setContentSize(m_Sprite->getContentSize());
	this->setAnchorPoint(Point(0,0));
	//加入到此Node中的精灵,位置设置在Node的(0,0)点
	m_Sprite->setPosition(Point(0,0));
	addChild(m_Sprite);
	log("m_Action的引用次数%d",m_Action->getReferenceCount());
	this->runAction(m_Action);//报错点1，原因Switch选择的Monster1未编辑，copy代码的代价
	this->schedule(schedule_selector(EnemyModel::addBullet),0.15f);
	this->schedule(schedule_selector(EnemyModel::moveBullet),0.01f);

	return true;
}

EnemyModel*EnemyModel::getEnemy(Monster monster,Point targetPoint){


	EnemyModel* model = new EnemyModel( monster,targetPoint );

	if( model && model->init()){

		model->autorelease();

		return  model;
	}

	CC_SAFE_DELETE( model );
	return NULL;
}

void EnemyModel::addBullet(float t)
{
	auto bulletsp=Sprite::createWithSpriteFrameName("W1.png");
	bulletsp->setPosition(m_Sprite->getPosition());
	log("the size of BulletVec:%d",m_Sprite->getPositionX());
	BlendFunc cd={GL_SRC_ALPHA,GL_ONE};
	bulletsp->setBlendFunc(cd);
	addChild(bulletsp);
	BulletVec.pushBack(bulletsp);
	log("the size of BulletVec:%d",BulletVec.size());
}

void EnemyModel::moveBullet(float t)//有问题！！！
{
	Vector<Sprite*> ::iterator iter;
	for (iter=BulletVec.begin();iter!=BulletVec.end();)
	{
		
		log("(*iter)->getPositionY()A:%f",(-100.0+(*iter)->getPositionY()));//为什么输出和下面一样(原因，是我开始用的%d,应该用f%)
		(*iter)->setPositionY((*iter)->getPositionY()-10);//没有起到应有的作用，子弹位置未改变,(后来发现起作用了，错误原因原来是死循环)
		log("(*iter)->getPositionY()B:%f",(*iter)->getPositionY());
		if((*iter)->getPositionY()<=-480)//因为子弹的坐标在EnemyModel上
		{
			removeChild(*iter,true);
			iter=BulletVec.erase(iter);//这种写法不会破坏迭代器
		}
		else
			iter++;//开始忘记添加了，结果死循环了
		log("the size of BulletVec:%d",BulletVec.size());
	}
}