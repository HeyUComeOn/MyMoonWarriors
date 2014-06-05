#ifndef EnemyModel_h__
#define EnemyModel_h__
#include "Header.h"
#include "cocos2d.h"
USING_NS_CC;
class EnemyModel : public Node//EnemyModel节点大小与图片相同
{
public:
	EnemyModel(Monster monster,Point targetPoint);
	~EnemyModel();

	bool init();
	//获取敌机指针
	static EnemyModel*getEnemy(Monster monster,Point targetPoint);

	void addBullet(float);

	void moveBullet(float);

	Vector<Sprite*> BulletVec;//敌机子弹的数组
private:
	Action*m_Action;
	Sprite*m_Sprite;

};
#endif // EnemyModel_h__
