#ifndef __TAVERNLAYER_H__
#define __TAVERNLAYER_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

class TavernLayer : public Layer
{
public:
	static TavernLayer* createInstance();
	virtual bool init();
	CREATE_FUNC(TavernLayer);
	void initMain();

	SEL_CallFuncN  m_closeAction;

private:
	TavernLayer();
	~TavernLayer();
	void closeTouchEvent(Ref* pSender, Widget::TouchEventType type);
	void joinTouchEvent(Ref* pSender, Widget::TouchEventType type);

	Layout* root;
	Button* btnClose;
	Button* btnJoin;
};

#endif