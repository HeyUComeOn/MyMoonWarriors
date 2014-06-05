#include "WelcomeLayer.h"
#include "Resource.h"
#include "AboutLayer.h"
#include "OptionLayer.h"
#include "GamingLayer.h"

WelcomeLayer::WelcomeLayer()
{

}
WelcomeLayer::~WelcomeLayer()
{

}
bool WelcomeLayer::init()
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

void WelcomeLayer::SetView()
{
	//提前加入plist文件，避免在使用时无法调用
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Monster.plist","Monster.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bullet.plist","bullet.png");
	setBackgroundImage("loading.png");
	auto newgame0=Sprite::create(s_pathMenu,Rect(0,0,126,33));
	auto newgame1=Sprite::create(s_pathMenu,Rect(0,33,126,33));
	auto newgame2=Sprite::create(s_pathMenu,Rect(0,66,126,33));
	auto newgame =MenuItemSprite::create(newgame0,newgame1,newgame2,CC_CALLBACK_1(WelcomeLayer::Touch_new,this));

	auto option0=Sprite::create(s_pathMenu,Rect(126,0,126,33));
	auto option1=Sprite::create(s_pathMenu,Rect(126,33,126,33));
	auto option2=Sprite::create(s_pathMenu,Rect(126,66,126,33));
	auto option =MenuItemSprite::create(option0,option1,option2,CC_CALLBACK_1(WelcomeLayer::Touch_option,this));

	auto about0=Sprite::create(s_pathMenu,Rect(252,0,126,33));
	auto about1=Sprite::create(s_pathMenu,Rect(252,33,126,33));
	auto about2=Sprite::create(s_pathMenu,Rect(252,66,126,33));
	auto about =MenuItemSprite::create(about0,about1,about2,CC_CALLBACK_1(WelcomeLayer::Touch_about,this));

	auto menu=Menu::create(newgame,option,about,NULL);
	menu->alignItemsVerticallyWithPadding(10);//10为间隔
	this->addChild(menu);
	menu->setPosition(Point(getwinsize().width/2, getwinsize().height/2-30));

	auto log_sp=Sprite::create("logo.png");
	log_sp->setAnchorPoint(Point(0.5,1));
	log_sp->setPosition(VisibleRect::top());
	addChild(log_sp);
}

void WelcomeLayer::Touch_new(Ref*sender)
{
	Director::getInstance()->replaceScene(TransitionFade::create(0.5f,GamingLayer::scene()));
}

void WelcomeLayer::Touch_option(Ref*sender)
{
	Director::getInstance()->replaceScene(TransitionFade::create(0.5f,OptionLayer::scene()));
}

void WelcomeLayer::Touch_about(Ref*sender)
{
	Director::getInstance()->replaceScene(TransitionFade::create(0.5f,AboutLayer::scene()));
}
Scene* WelcomeLayer::scene()
{
	auto scene=Scene::create();
	auto layer=WelcomeLayer::create();
	scene->addChild(layer);
	return scene;
}

void WelcomeLayer::onEnter()
{
	Layer::onEnter();//1111111111111111111111111111111
	log("onEnter");
	bool pl=UserDefault::getInstance()->getBoolForKey("music_not_playing");
	UserDefault::getInstance()->flush();
	if(!pl)
	{
		if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())//
		{
			SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/mainMainMusic.mp3",true);
		}
	}
	else
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}