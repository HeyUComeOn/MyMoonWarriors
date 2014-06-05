#include "AboutLayer.h"
#include "WelcomeLayer.h"
AboutLayer::AboutLayer()
{

}
AboutLayer::~AboutLayer()
{

}
bool AboutLayer::init()
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

void AboutLayer::SetView()
{
	setBackgroundImage("loading.png");

	auto lb_abt=Sprite::create("menuTitle.png",Rect(0,34,134,39));
	lb_abt->setAnchorPoint(Point(0.5,1));
	lb_abt->setPosition(Point(getwinsize().width/2+5,getwinsize().height-40));
	addChild(lb_abt);

	auto lbf=Label::createWithBMFont("arial-14.fnt","Learn from Longlongxiu !");
	lbf->setPosition(VisibleRect::center());
	addChild(lbf);

	auto lb_back=Label::createWithBMFont("arial-14.fnt","go back");
	auto item_back=MenuItemLabel::create(lb_back,CC_CALLBACK_1(AboutLayer::keyBackClicked,this));
	item_back->setAnchorPoint(Point(1,0));
	item_back->setScale(1.3f);
	item_back->setPosition(Point(getwinsize().width,30));
	auto menu_back=Menu::create(item_back,NULL);
	menu_back->setPosition(Point(0,0));
	addChild(menu_back);
}

void AboutLayer::keyBackClicked(Ref* sender)
{
	Director::getInstance()->replaceScene(TransitionFade::create(0.5f,WelcomeLayer::scene()));
}
Scene* AboutLayer::scene()
{
	auto scene=Scene::create();
	auto layer=AboutLayer::create();
	scene->addChild(layer);
	return scene;
}