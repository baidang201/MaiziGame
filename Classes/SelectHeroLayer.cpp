#include "SelectHeroLayer.h"

SelectHeroLayer::SelectHeroLayer()
{
	m_closeAction = nullptr;
}

SelectHeroLayer::~SelectHeroLayer()
{
	m_closeAction = nullptr;
}

SelectHeroLayer* SelectHeroLayer::createInstance()
{
	return SelectHeroLayer::create();
}

bool SelectHeroLayer::init()
{
	if( !Layer::init())
	{
		return false;
	}

	initMain();

	return true;
}

void SelectHeroLayer::initMain()
{
	Node* rootNode = CSLoader::createNode("SelectHeroLayer.csb");
	addChild(rootNode);

	root = static_cast<Layout*> (rootNode->getChildByName("root"));

	//得到控件，注册事件
	btnOK = static_cast<Button*>( Helper::seekWidgetByName(root, "btnOK") );
	btnOK->setTouchEnabled(true);
	btnOK->addTouchEventListener( CC_CALLBACK_2(SelectHeroLayer::okTouchEvent, this) );

	btnReturn = static_cast<Button*>( Helper::seekWidgetByName(root, "btnReturn") );
	btnReturn->setTouchEnabled(true);
	btnReturn->addTouchEventListener( CC_CALLBACK_2(SelectHeroLayer::closeTouchEvent, this) );

	lstHero = static_cast<ListView* >(Helper::seekWidgetByName(root, "lstHero"));
	imgBack = static_cast<ImageView* >(Helper::seekWidgetByName(root, "imgBack"));
	
}

void SelectHeroLayer::okTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		RuntimeParam::getInstance() ->m_currentHero = _selectedHero;

		if(NULL != m_closeAction)
		{
			(this->getParent()->*m_closeAction)(this);
		}
	}
}

void SelectHeroLayer::closeTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		if(NULL != m_closeAction)
		{
			(this->getParent()->*m_closeAction)(this);
		}
	}
}

void SelectHeroLayer::selectTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if( type == Widget::TouchEventType::ENDED)
	{
		Layout* selectItem = static_cast<Layout*>(pSender);

		for(Widget* item : lstHero->getItems() )
		{
			ImageView* imgHero = static_cast<ImageView*>(Helper::seekWidgetByName(item, "imgHero"));
			imgHero->removeAllChildren();
		}

		ImageView* imgHero = static_cast<ImageView*>(Helper::seekWidgetByName(selectItem, "imgHero"));

		ParticleSystemQuad* particle = ParticleSystemQuad::create("particle_texture.plist");
		particle->setAutoRemoveOnFinish(true);
		imgHero->addChild(particle);
		particle->setPosition( Vec2(50 , 50)  );


		_selectedHero = static_cast<HeroModel*>(selectItem->getUserObject());
	}
}

void SelectHeroLayer::setHeros( Vector<HeroModel*> heros)
{
	lstHero->removeAllItems();

	Node* rootNode = CSLoader::createNode("SelectHeroItem.csb");
	Layout* itemRoot = static_cast<Layout*> (rootNode->getChildByName("root"));

	itemRoot->setTouchEnabled(true);
	itemRoot->addTouchEventListener(CC_CALLBACK_2(SelectHeroLayer::selectTouchEvent, this));

	for(HeroModel* hero:heros)
	{
		Layout* item = (static_cast<Layout*>(itemRoot->clone()));
		lstHero->pushBackCustomItem(item);

		item->setUserObject(hero);
		Text* txtServerName = static_cast<Text*>(Helper::seekWidgetByName(item, "txtHeroName"));
		txtServerName->setString(hero->m_heroName);

		ImageView* imgState = static_cast<ImageView*>(Helper::seekWidgetByName(item, "imgHero"));
		imgState->loadTexture(hero->getHeroImage());


	}
}