#ifndef __TAVERNLAYER_H__
#define __TAVERNLAYER_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui/CocosGUI.h"
#include "HeroModel.h"

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

class TavernLayer : public Layer
{
public:
	static TavernLayer* createInstance();
	virtual bool init();
	CREATE_FUNC(TavernLayer);
	void initMain();

	void setPartners(Vector<HeroModel*> parts );
	void selectTouchEvent(Ref* pSender, Widget::TouchEventType type);
	void selectMyPartnerTouchEvent(Ref* pSender, Widget::TouchEventType type);
	SEL_CallFuncN  m_closeAction;

	void showPartnerInfo(HeroModel* info);
	void refreshMyPartner();

private:
	TavernLayer();
	~TavernLayer();
	void closeTouchEvent(Ref* pSender, Widget::TouchEventType type);
	void joinTouchEvent(Ref* pSender, Widget::TouchEventType type);

	Layout* root;
	Button* btnClose;
	Button* btnJoin;

	ListView* lstFreePartner;
	ListView* lstMyPartner;
	Text* txtPartnerInfo;

	HeroModel* _selectedPartner;
};

#endif