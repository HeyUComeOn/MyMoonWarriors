#include "EnemyManager.h"
#include "EnemyModel.h"

EnemyManager::EnemyManager():enemyVec()
{

}
EnemyManager::~EnemyManager()
{

}

bool EnemyManager::init()
{

	if( !BasicLayer::init() )
	{
		return false;
	}

	setupViews();

	return true;

}

void EnemyManager::setupViews()
{
	//  ��ʼ��һ���л�
	Monster monster = { monster0 };

	EnemyModel* enemyModel = EnemyModel::getEnemy( monster, Point( 0 , -getwinsize().height *.25) );

	enemyVec.pushBack( enemyModel );

	this->addChild(enemyModel,1);
	enemyModel->setPosition( VisibleRect::top() );//Ŀ��λ�ý�����enemyModelΪ׼���

}

void EnemyManager::addEnemy( float t )
{

}

Vector<EnemyModel*>& EnemyManager::getEnemyVec()
{

	return enemyVec;
}