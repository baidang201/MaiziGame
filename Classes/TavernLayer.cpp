#include "TavernLayer.h"

TavernLayer::TavernLayer()
{
	m_closeAction = nullptr;
}

TavernLayer::~TavernLayer()
{
	m_closeAction = nullptr;
}

TavernLayer* TavernLayer::createInstance()
{
	return TavernLayer::create();
}

bool TavernLayer::init()
{
	if( !Layer::init())
	{
		return false;
	}

	initMain();

	return true;
}

void TavernLayer::initMain()
{
	Node* rootNode = CSLoader::createNode("TavernLayer.csb");
	addChild(rootNode);

	root = static_cast<Layout*> (rootNode->getChildByName("root"));

	//得到控件，注册事件
	btnClose = static_cast<Button*> ( Helper::seekWidgetByName(root, "btnClose") );
	btnClose->setTouchEnabled(true);
	btnClose->addTouchEventListener( CC_CALLBACK_2(TavernLayer::closeTouchEvent, this) );
}


void TavernLayer::closeTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		if(NULL != m_closeAction)
		{
			(this->getParent()->*m_closeAction)(this);
		}
	}
}


void TavernLayer::joinTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	//todo(liyh) 加入伙伴
}