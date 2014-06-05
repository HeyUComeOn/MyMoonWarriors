#ifndef __BASIC_LAYER_H__
#define __BASIC_LAYER_H__

#include "cocos2d.h"
#include "VisibleRect.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
class BasicLayer : public Layer
{
public:
	BasicLayer(){};
	~BasicLayer(){};
	virtual bool init();
	CREATE_FUNC(BasicLayer);
	Size getwinsize();
	void setBackgroundImage(const std::string Background_file_name);
};
#endif