#ifndef AboutLayer_h__
#define AboutLayer_h__

#include "BasicLayer.h"
class AboutLayer: public BasicLayer
{
public:
	AboutLayer();
	~AboutLayer();
	virtual bool init()override;
	void SetView();
	static Scene*scene();
	void keyBackClicked(Ref* sender);
	CREATE_FUNC(AboutLayer);
};
#endif // AboutLayer_h__
