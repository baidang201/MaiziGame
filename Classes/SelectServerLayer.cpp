#include "SelectServerLayer.h"

SelectServerLayer::SelectServerLayer()
{
	m_closeAction = nullptr;
}

SelectServerLayer::~SelectServerLayer()
{
	m_closeAction = nullptr;
}

SelectServerLayer* SelectServerLayer::createInstance()
{
	return SelectServerLayer::create();
}

bool SelectServerLayer::init()
{
	if( !Layer::init())
	{
		return false;
	}

	initMain();

	return true;
}

void SelectServerLayer::initMain()
{
	Node* rootNode = CSLoader::createNode("SelectServerLayer.csb");
	addChild(rootNode);

	root = static_cast<Layout*> (rootNode->getChildByName("root"));

	//得到控件，注册事件
	btnOK = static_cast<Button*>( Helper::seekWidgetByName(root, "btnOK") );
	btnOK->setTouchEnabled(true);
	btnOK->addTouchEventListener( CC_CALLBACK_2(SelectServerLayer::okTouchEvent, this) );

	btnReturn = static_cast<Button*>( Helper::seekWidgetByName(root, "btnReturn") );
	btnReturn->setTouchEnabled(true);
	btnReturn->addTouchEventListener( CC_CALLBACK_2(SelectServerLayer::closeTouchEvent, this) );

	lstServer = static_cast<ListView* >(Helper::seekWidgetByName(root, "lstServer"));

}

void SelectServerLayer::okTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		RuntimeParam::getInstance() ->m_currentServer = _selectedServer;

		if(NULL != m_closeAction)
		{
			(this->getParent()->*m_closeAction)(this);
		}
	}
}

void SelectServerLayer::closeTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		if(NULL != m_closeAction)
		{
			(this->getParent()->*m_closeAction)(this);
		}
	}
}

void SelectServerLayer::selectTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if( type == Widget::TouchEventType::ENDED)
	{
		Layout* selectItem = static_cast<Layout*>(pSender);


		for(Widget* item : lstServer->getItems() )
		{
			ImageView* img = static_cast<ImageView*>(Helper::seekWidgetByName(item, "imgCheckBox"));
			img->loadTexture("Public/public_checkBox.png");
		}

		ImageView* imgCheckBox = static_cast<ImageView*>(Helper::seekWidgetByName(selectItem, "imgCheckBox"));
		imgCheckBox->loadTexture("Public/public_checkedBox.png");
		_selectedServer = static_cast<ServerModel*>(selectItem->getUserObject());
		

	}
}

void SelectServerLayer::setServers( Vector<ServerModel*> servers)
{
	lstServer->removeAllItems();

	Node* rootNode = CSLoader::createNode("SelectServerItem.csb");
	Layout* itemRoot = static_cast<Layout*> (rootNode->getChildByName("root"));

	itemRoot->setTouchEnabled(true);
	itemRoot->addTouchEventListener(CC_CALLBACK_2(SelectServerLayer::selectTouchEvent, this));

	for(ServerModel* server:servers)
	{
		Layout* item = (static_cast<Layout*>(itemRoot->clone()));
		lstServer->pushBackCustomItem(item);

		item->setUserObject(server);
		Text* txtServerName = static_cast<Text*>(Helper::seekWidgetByName(item, "txtServerName"));
		txtServerName->setString(server->m_serverName);

		ImageView* imgState = static_cast<ImageView*>(Helper::seekWidgetByName(item, "imgState"));
		imgState->loadTexture(server->getStateImage());

		ImageView* imgCheckBox = static_cast<ImageView*>(Helper::seekWidgetByName(item, "imgCheckBox"));
		imgCheckBox->loadTexture("public/public_checkBox.png");
	}
}