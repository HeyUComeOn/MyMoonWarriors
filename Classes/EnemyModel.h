#ifndef EnemyModel_h__
#define EnemyModel_h__
#include "Header.h"
#include "cocos2d.h"
USING_NS_CC;
class EnemyModel : public Node//EnemyModel�ڵ��С��ͼƬ��ͬ
{
public:
	EnemyModel(Monster monster,Point targetPoint);
	~EnemyModel();

	bool init();
	//��ȡ�л�ָ��
	static EnemyModel*getEnemy(Monster monster,Point targetPoint);

	void addBullet(float);

	void moveBullet(float);

	Vector<Sprite*> BulletVec;//�л��ӵ�������
private:
	Action*m_Action;
	Sprite*m_Sprite;

};
#endif // EnemyModel_h__
