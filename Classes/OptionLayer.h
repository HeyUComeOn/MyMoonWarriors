#ifndef  OptionLayer_h__
#define OptionLayer_h__
#include "BasicLayer.h"
class OptionLayer:public BasicLayer
{
public:
	OptionLayer();
	~OptionLayer();
	virtual bool init()override;
	void SetView();
	static Scene*scene();
	void keyBackClicked(Ref* sender);
	CREATE_FUNC(OptionLayer);
	void MusicCallback(Ref*pSender);
};
#endif // OptionLayer_h__
