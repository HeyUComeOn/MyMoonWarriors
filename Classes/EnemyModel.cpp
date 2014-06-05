#include "EnemyModel.h"
#include "VisibleRect.h"
EnemyModel::EnemyModel(Monster monster,Point targetPoint):BulletVec()
{
	//��WelcomeLayer�м���Monster.plist�ļ�
	
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
	//���뵽��Node�еľ���,λ��������Node��(0,0)��
	m_Sprite->setPosition(Point(0,0));
	addChild(m_Sprite);
	log("m_Action�����ô���%d",m_Action->getReferenceCount());
	this->runAction(m_Action);//�����1��ԭ��Switchѡ���Monster1δ�༭��copy����Ĵ���
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

void EnemyModel::moveBullet(float t)//�����⣡����
{
	Vector<Sprite*> ::iterator iter;
	for (iter=BulletVec.begin();iter!=BulletVec.end();)
	{
		
		log("(*iter)->getPositionY()A:%f",(-100.0+(*iter)->getPositionY()));//Ϊʲô���������һ��(ԭ�����ҿ�ʼ�õ�%d,Ӧ����f%)
		(*iter)->setPositionY((*iter)->getPositionY()-10);//û����Ӧ�е����ã��ӵ�λ��δ�ı�,(���������������ˣ�����ԭ��ԭ������ѭ��)
		log("(*iter)->getPositionY()B:%f",(*iter)->getPositionY());
		if((*iter)->getPositionY()<=-480)//��Ϊ�ӵ���������EnemyModel��
		{
			removeChild(*iter,true);
			iter=BulletVec.erase(iter);//����д�������ƻ�������
		}
		else
			iter++;//��ʼ��������ˣ������ѭ����
		log("the size of BulletVec:%d",BulletVec.size());
	}
}