#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	root = static_cast<Layout*>(rootNode->getChildByName("root"));

	btnStart = static_cast<Button*> (Helper::seekWidgetByName(root, "btnStart"));
	btnStart->setTouchEnabled(true);
	btnStart->addTouchEventListener(CC_CALLBACK_2(HelloWorld::startTouchEvent, this));

	imgServerBack = static_cast<ImageView*> (Helper::seekWidgetByName(root, "imgServerBack"));
	imgServerBack->setTouchEnabled(true);
	imgServerBack->addTouchEventListener(CC_CALLBACK_2(HelloWorld::selectServerTouchEvent, this));

	txtServerName = static_cast<Text*> (Helper::seekWidgetByName(root, "txtServerName"));
	imgState = static_cast<ImageView*> (Helper::seekWidgetByName(root, "imgState"));
	txtUserName = static_cast<TextField*> (Helper::seekWidgetByName(root, "txtUserName"));
		
    return true;
}


void HelloWorld::startTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		string userName = txtUserName->getString();	
		SelectHeroLayer* layer = SelectHeroLayer::createInstance();
		layer->m_closeAction =  (SEL_CallFuncN)(&HelloWorld::closeHeroLayer);
		layer->setHeros(RuntimeParam::getInstance()->m_heros);
		addChild(layer);

	}
}

void HelloWorld::selectServerTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		SelectServerLayer* layer = SelectServerLayer::createInstance();
		layer->m_closeAction =  (SEL_CallFuncN)(&HelloWorld::closeServerLayer);
		layer->setServers(RuntimeParam::getInstance()->m_servers);
		addChild(layer);
	}
}


void HelloWorld::closeServerLayer(Node* node)
{
	txtServerName->setString(RuntimeParam::getInstance()->m_currentServer->m_serverName);
	imgState->loadTexture(RuntimeParam::getInstance()->m_currentServer->getStateImage());
	closeLayer(node);
}

void HelloWorld::closeHeroLayer(Node* node)
{
	//Ìí¼ÓµØÍ¼Ñ¡Ôñ
	MapLayer* layer = MapLayer::createInstance();
	addChild(layer);

	closeLayer(node);
}


void HelloWorld::closeLayer(Node* node)
{
	node->removeFromParentAndCleanup(true);
	node=nullptr;
}

