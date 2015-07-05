#include "TavernLayer.h"
#include "RuntimeParam.h"

TavernLayer::TavernLayer()
{
	m_closeAction = nullptr;
	_selectedPartner = nullptr;
}

TavernLayer::~TavernLayer()
{
	m_closeAction = nullptr;
	_selectedPartner = nullptr;
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

	btnJoin = static_cast<Button*> (Helper::seekWidgetByName(root, "btnJoin"));
	btnJoin->setTouchEnabled(true);
	btnJoin->addTouchEventListener( CC_CALLBACK_2(TavernLayer::joinTouchEvent, this) );

	lstFreePartner = static_cast<ListView*> (Helper::seekWidgetByName(root, "lstFreePartner") );
	lstMyPartner = static_cast<ListView*> (Helper::seekWidgetByName(root, "lstMyPartner") );
	txtPartnerInfo = static_cast<Text*> (Helper::seekWidgetByName(root, "txtPartnerInfo") );
}


void TavernLayer::closeTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		if(nullptr != m_closeAction)
		{
			(this->getParent()->*m_closeAction)(this);
		}
	}
}


void TavernLayer::joinTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	//todo(liyh) 加入伙伴
	if( nullptr != _selectedPartner)
	{
		bool fFind = false;
		for(HeroModel* hero : RuntimeParam::getInstance()->m_MyPartners)
		{
			if(hero->m_heroID == _selectedPartner->m_heroID)
			{
				fFind = true;
				break;
			}
		}

		if (!fFind)
		{
			RuntimeParam::getInstance()->m_MyPartners.pushBack(_selectedPartner);
		}

		refreshMyPartner();
	}
}

void TavernLayer::setPartners( Vector<HeroModel*> partners)
{
	lstFreePartner->removeAllItems();
											
	Node* rootNode = CSLoader::createNode("SelectPartnerItem.csb");
	Layout* itemRoot = static_cast<Layout*> (rootNode->getChildByName("root"));

	itemRoot->setTouchEnabled(true);
	itemRoot->addTouchEventListener( CC_CALLBACK_2( TavernLayer::selectTouchEvent, this ) );

	for(HeroModel* partner:partners)
	{
		Layout* item = (static_cast<Layout*>(itemRoot->clone()));
		lstFreePartner->pushBackCustomItem(item);

		item->setUserObject(partner);

		ImageView* imgParnter = static_cast<ImageView*>(Helper::seekWidgetByName(item, "imgPartner"));
		imgParnter->loadTexture(partner->getPartnerImage());
	}
}

void TavernLayer::selectTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if( type == Widget::TouchEventType::ENDED)
	{
		Layout* selectItem = static_cast<Layout*>(pSender);
		
		//删除上次的粒子效果
		for(Widget* item : lstFreePartner->getItems() )
		{
			ImageView* imgPartner = static_cast<ImageView*>(Helper::seekWidgetByName(item, "imgPartner"));
			imgPartner->removeAllChildren();
		}

		ImageView* imgPartner = static_cast<ImageView*>(Helper::seekWidgetByName(selectItem, "imgPartner"));

		ParticleSystemQuad* particle = ParticleSystemQuad::create("particle_texture.plist");
		particle->setAutoRemoveOnFinish(true);
		imgPartner->addChild(particle);
		particle->setPosition( Vec2(50 , 50)  );


		_selectedPartner = static_cast<HeroModel*>(selectItem->getUserObject());
		showPartnerInfo(_selectedPartner);
	}
}

void TavernLayer::selectMyPartnerTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if( type == Widget::TouchEventType::ENDED)
	{
		Layout* selectItem = static_cast<Layout*>(pSender);
		
		//删除上次的粒子效果
		for(Widget* item : lstMyPartner->getItems() )
		{
			ImageView* imgPartner = static_cast<ImageView*>(Helper::seekWidgetByName(item, "imgPartner"));
			imgPartner->removeAllChildren();
		}

		ImageView* imgPartner = static_cast<ImageView*>(Helper::seekWidgetByName(selectItem, "imgPartner"));

		ParticleSystemQuad* particle = ParticleSystemQuad::create("particle_texture.plist");
		particle->setAutoRemoveOnFinish(true);
		imgPartner->addChild(particle);
		particle->setPosition( Vec2(50 , 50)  );


		_selectedPartner = static_cast<HeroModel*>(selectItem->getUserObject());
		showPartnerInfo(_selectedPartner);
	}
}

void TavernLayer::showPartnerInfo(HeroModel* hero)
{
	txtPartnerInfo->setString(hero->m_heroName);
}

void TavernLayer::refreshMyPartner()
{
	lstMyPartner->removeAllItems();

	Node* rootNode = CSLoader::createNode("SelectPartnerItem.csb");
	Layout* itemRoot = static_cast<Layout*> (rootNode->getChildByName("root"));

	itemRoot->setTouchEnabled(true);
	itemRoot->addTouchEventListener( CC_CALLBACK_2( TavernLayer::selectMyPartnerTouchEvent, this ) );

	for(HeroModel* partner:RuntimeParam::getInstance()->m_MyPartners)
	{
		Layout* item = (static_cast<Layout*>(itemRoot->clone()));
		lstMyPartner->pushBackCustomItem(item);

		item->setUserObject(partner);

		ImageView* imgParnter = static_cast<ImageView*>(Helper::seekWidgetByName(item, "imgPartner"));
		imgParnter->loadTexture(partner->getPartnerImage());
	}
}