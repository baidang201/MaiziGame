#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "SelectServerLayer.h"
#include "SelectHeroLayer.h"
#include "RuntimeParam.h"

USING_NS_CC;
using namespace cocostudio::timeline;
using namespace cocos2d::ui;


class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
	void closeLayer(Node* node);

	void closeServerLayer(Node* node);

	void startTouchEvent(Ref* sender, Widget::TouchEventType type );
	void selectServerTouchEvent(Ref* sender, Widget::TouchEventType type);

	Layout* root;
	Button* btnStart;

	ImageView* imgServerBack;
	Text* txtServerName;
	ImageView* imgState;

	TextField* txtUserName;
};

#endif // __HELLOWORLD_SCENE_H__
