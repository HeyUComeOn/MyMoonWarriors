#ifndef EnemyManager_h__
#define EnemyManager_h__


#include "BasicLayer.h"
#include "Header.h"
#include "EnemyModel.h"
class EnemyManager : public BasicLayer {

public:
	//  �л��Ĺ��������
	Vector<EnemyModel*> enemyVec;
public:
	EnemyManager();
	~EnemyManager();
	virtual bool init();
	void setupViews();
	CREATE_FUNC( EnemyManager );

	void addEnemy( float t );
	Vector<EnemyModel*>& getEnemyVec(  );
};
#endif // EnemyManager_h__
