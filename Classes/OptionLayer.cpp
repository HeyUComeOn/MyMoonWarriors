#include "OptionLayer.h"
#include "WelcomeLayer.h"
OptionLayer::OptionLayer()
{

}
OptionLayer::~OptionLayer()
{

}
bool OptionLayer::init()
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

void OptionLayer::SetView()
{
	setBackgroundImage("loading.png");

	auto lb_opt=Sprite::create("menuTitle.png",Rect(0,0,134,35));
	lb_opt->setAnchorPoint(Point(0.5,1));
	lb_opt->setPosition(Point(getwinsize().width/2+5,getwinsize().height-40));
	addChild(lb_opt);

	auto itemToggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(OptionLayer::MusicCallback, this),
		MenuItemFont::create( "Music On" ),
		MenuItemFont::create( "Music Off" ),
		NULL );

	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		itemToggle->setSelectedIndex(1);
	} 
	else
	{
		itemToggle->setSelectedIndex(0);
	}
	itemToggle->setPosition(VisibleRect::center());

	auto lb_back=Label::createWithBMFont("arial-14.fnt","go back");
	auto item_back=MenuItemLabel::create(lb_back,CC_CALLBACK_1(OptionLayer::keyBackClicked,this));
	item_back->setAnchorPoint(Point(1,0));
	item_back->setScale(1.3f);
	item_back->setPosition(Point(getwinsize().width,30));
	auto menu=Menu::create(itemToggle,item_back,NULL);
	menu->setPosition(VisibleRect::leftBottom());

	addChild(menu);
}

void OptionLayer::MusicCallback(Ref*pSender)
{
	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		
		log("stopmusic");
		UserDefault::getInstance()->setBoolForKey("music_not_playing",true);
		UserDefault::getInstance()->flush();

	} 
	else
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/mainMainMusic.mp3",true);//win32xiaresumeºÍpause²»Áé»î
		log("playmusic");
		UserDefault::getInstance()->setBoolForKey("music_not_playing",false);
		UserDefault::getInstance()->flush();
	}
}

void OptionLayer::keyBackClicked(Ref* sender)
{
	Director::getInstance()->replaceScene(TransitionFade::create(0.5f,WelcomeLayer::scene()));
}

Scene* OptionLayer::scene()
{
	Scene*sc=NULL;
	do 
	{
		sc=Scene::create();
		CC_BREAK_IF(!sc);
		auto layer=OptionLayer::create();
		CC_BREAK_IF(!layer);
		sc->addChild(layer);
	} while (0);
	return sc;
}