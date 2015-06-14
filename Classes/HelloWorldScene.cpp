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


		Vector<HeroModel*> heros = Vector<HeroModel*>();
		heros.pushBack(new HeroModel(1, "Mage1", "1"));
		heros.pushBack(new HeroModel(2, "Mage2", "2"));
		heros.pushBack(new HeroModel(3, "Mage3", "3"));
		heros.pushBack(new HeroModel(4, "Mage4", "4"));

		SelectHeroLayer* layer = SelectHeroLayer::createInstance();
		layer->m_closeAction =  (SEL_CallFuncN)(&HelloWorld::closeServerLayer);
		layer->setHeros(heros);
		addChild(layer);

	}
}

void HelloWorld::selectServerTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		Vector<ServerModel*> servers = Vector<ServerModel*>();
		servers.pushBack(new ServerModel(1, "1服—水", "2"));
		servers.pushBack(new ServerModel(2, "2服—生命", "2"));
		servers.pushBack(new ServerModel(3, "3服—盾", "3"));
		servers.pushBack(new ServerModel(4, "4服—雪", "4"));
		servers.pushBack(new ServerModel(5, "5服—电", "1"));
		servers.pushBack(new ServerModel(6, "6服—奥术", "3"));
		servers.pushBack(new ServerModel(7, "7服—石", "1"));
		servers.pushBack(new ServerModel(8, "8服—火", "1"));

		SelectServerLayer* layer = SelectServerLayer::createInstance();
		layer->m_closeAction =  (SEL_CallFuncN)(&HelloWorld::closeServerLayer);
		layer->setServers(servers);
		addChild(layer);
	}
}


void HelloWorld::closeServerLayer(Node* node)
{
	txtServerName->setString(RuntimeParam::getInstance()->m_currentServer->m_serverName);
	imgState->loadTexture(RuntimeParam::getInstance()->m_currentServer->getStateImage());
	closeLayer(node);
}

void HelloWorld::closeLayer(Node* node)
{
	node->removeFromParentAndCleanup(true);
	node=nullptr;
}
