#include "TimeLayer.h"

TimeLayer::TimeLayer()
{
	counter=0;
}
TimeLayer::~TimeLayer()
{

}
bool TimeLayer::init()
{
	bool s=false;
	do 
	{
		CC_BREAK_IF(!BasicLayer::init());
		SetView();
		s=true;
	} while (0);
	return s;
}

void TimeLayer::SetView()
{
	auto scoreFont=LabelBMFont::create("Time:0","arial-14.fnt");
	scoreFont->setAnchorPoint(Point(0,0));
	scoreFont->setPosition(Point(0,0));
	scoreFont->setScale(1.5f);
	addChild(scoreFont,0,15);//tag作用：便于在time_counting_down调用
	this->schedule(schedule_selector(TimeLayer::time_counting_down),1.0f);
}

void TimeLayer::time_counting_down(float t)
{
	auto time_font=(LabelBMFont*)this->getChildByTag(15);
	char str[20]={};
	counter++;
	sprintf_s(str,"Time:%d",counter);
	time_font->setString(str);
}

Scene* TimeLayer::scene()
{
	Scene*sc=NULL;
	do 
	{
		sc=Scene::create();
		CC_BREAK_IF(!sc);
		auto layer=TimeLayer::create();
		CC_BREAK_IF(!layer);
		sc->addChild(layer);
	} while (0);
	return sc;
}