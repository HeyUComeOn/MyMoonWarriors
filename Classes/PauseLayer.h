#ifndef PauseLayer_h__
#define PauseLayer_h__

#include "BasicLayer.h"
class PauseLayer:public LayerColor
{
public:
	PauseLayer();
	~PauseLayer();
	virtual bool init()override;
	void SetView();
	static Scene*scene();
	void Play_pressed(Ref*pSender);
	CREATE_FUNC(PauseLayer);

};
#endif // PauseLayer_h__
