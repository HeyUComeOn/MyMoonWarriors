#ifndef ScoreLayer_h__
#define ScoreLayer_h__

#include "BasicLayer.h"
class ScoreLayer:public BasicLayer
{
public:
	ScoreLayer();
	~ScoreLayer();
	virtual bool init()override;
	void SetView();
	static Scene*scene();

	CREATE_FUNC(ScoreLayer);
	
};
#endif // ScoreLayer_h__
