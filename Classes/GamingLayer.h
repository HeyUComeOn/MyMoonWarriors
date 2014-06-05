#ifndef GamingLayer_h__
#define GamingLayer_h__
#include "BasicLayer.h"
#include "WarriorLayer.h"
#include "HeroBulletManager.h"
#include "EnemyManager.h"
class GamingLayer:public BasicLayer
{
public:
	GamingLayer();
	~GamingLayer();
	virtual bool init()override;
	void SetView();
	static Scene*scene();
	void Pause_down(Ref* sender);
	CREATE_FUNC(GamingLayer);
	void Background_scroll_logic(float );
	void warrior_add_new_bullet(float);
	WarriorLayer*m_warriorLayer;
	HeroBulletManager*m_heroBulletManager;
	EnemyManager*m_enemyManager;
};
#endif // GamingLayer_h__
