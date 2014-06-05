#ifndef WarriorLayer_h__
#define WarriorLayer_h__

#include "BasicLayer.h"

class WarriorLayer:public BasicLayer
{
public:
	WarriorLayer();
	~WarriorLayer();
	virtual bool init()override;
	void SetView();
	static Scene*scene();
	CREATE_FUNC(WarriorLayer);
	Point getWarriorPosition();
	Size getWarriorSize();
private:
	Sprite*m_warrior;
};

#endif // WarriorLayer_h__
