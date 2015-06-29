#include "MapLayer.h"

MapLayer::MapLayer()
{
}

MapLayer::~MapLayer()
{
}

MapLayer* MapLayer::createInstance()
{
	return MapLayer::create();
}

bool MapLayer::init()
{
	if( !Layer::init())
	{
		return false;
	}

	initMain();

	return true;
}

void MapLayer::initMain()
{
	Node* rootNode = CSLoader::createNode("MapLayer.csb");
	addChild(rootNode);

	root = static_cast<Layout*> (rootNode->getChildByName("root"));

	//得到控件，注册事件
	btnTavern = static_cast<Button*> ( Helper::seekWidgetByName(root, "btnTavern") );
	btnTavern->setTouchEnabled(true);
	btnTavern->addTouchEventListener( CC_CALLBACK_2( MapLayer::selectTavernTouchEvent, this) );


}


void MapLayer::selectTavernTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if( type == Widget::TouchEventType::ENDED)
	{
		//弹出酒馆界面
		TavernLayer* layer = TavernLayer::createInstance();
		layer->m_closeAction =  (SEL_CallFuncN)(&MapLayer::closeTavernLayer);
		layer->setPartners(RuntimeParam::getInstance()->m_partners);
		addChild(layer);
	}
}


void MapLayer::closeTavernLayer(Node* node)
{
	closeLayer(node);
}


void MapLayer::closeLayer(Node* node)
{
	node->removeFromParentAndCleanup(true);
	node=nullptr;
}

