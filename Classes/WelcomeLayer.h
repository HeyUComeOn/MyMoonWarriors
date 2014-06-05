#ifndef WelcomeLayer_h__
#define WelcomeLayer_h__
#include "BasicLayer.h"
class WelcomeLayer:public BasicLayer
{
public:
	WelcomeLayer();
	~WelcomeLayer();

	virtual bool init();
	void SetView();
	static Scene*scene();
	void Touch_new(Ref*sender);
	void Touch_option(Ref*sender);
	void Touch_about(Ref*sender);
	CREATE_FUNC(WelcomeLayer);
	virtual void onEnter()override;
};


#endif // WelcomeLayer_h__
