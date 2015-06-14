#ifndef __SELECTHEROLAYER_H__
#define __SELECTHEROLAYER_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui/CocosGUI.h"

#include "HeroModel.h"
#include "RuntimeParam.h"

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

class SelectHeroLayer : public Layer
{
public:
	static SelectHeroLayer* createInstance();
	virtual bool init();
	CREATE_FUNC(SelectHeroLayer);
	void initMain();

	SEL_CallFuncN  m_closeAction;

	void setHeros(Vector<HeroModel*> heros);

private:
	SelectHeroLayer();
	~SelectHeroLayer();

	void okTouchEvent(Ref* sender, Widget::TouchEventType type);
	void closeTouchEvent(Ref* sender, Widget::TouchEventType type);
	void selectTouchEvent(Ref* sender, Widget::TouchEventType type);

	Layout* root;
	ListView* lstHero;
	Button* btnOK;
	Button* btnReturn;
	ImageView* imgBack;

	HeroModel* _selectedHero;	
};

#endif