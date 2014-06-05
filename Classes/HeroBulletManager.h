#ifndef HeroBulletManager_h__
#define HeroBulletManager_h__

#include "BasicLayer.h"

class HeroBulletManager:public BasicLayer
{
public:
	HeroBulletManager();
	~HeroBulletManager();
	virtual bool init()override;
	void SetView();
	static Scene*scene();
	void addNewBullet(const Point point,const Size WarriorSize);//用于外部使用的方法
	void moveAllBullets(float t);
	CREATE_FUNC(HeroBulletManager);
private:
	SpriteBatchNode*mBulletsBatchNode;
	Vector<Sprite*> HeroBulletVec;
};
#endif // HeroBulletManager_h__
