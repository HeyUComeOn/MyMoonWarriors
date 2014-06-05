#include "ScoreLayer.h"

ScoreLayer::ScoreLayer()
{

}
ScoreLayer::~ScoreLayer()
{

}
bool ScoreLayer::init()
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

void ScoreLayer::SetView()
{
	auto scoreFont=LabelBMFont::create("Score:20","arial-14.fnt");
	scoreFont->setAnchorPoint(Point(0,0));
	scoreFont->setPosition(Point(0,0));
	scoreFont->setScale(1.5f);
	addChild(scoreFont);
}



Scene* ScoreLayer::scene()
{
	Scene*sc=NULL;
	do 
	{
		sc=Scene::create();
		CC_BREAK_IF(!sc);
		auto layer=ScoreLayer::create();
		CC_BREAK_IF(!layer);
		sc->addChild(layer);
	} while (0);
	return sc;
}