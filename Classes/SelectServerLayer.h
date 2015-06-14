#ifndef __SELECTSERVERLAYER_H__
#define __SELECTSERVERLAYER_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui/CocosGUI.h"

#include "ServerModel.h"
#include "RuntimeParam.h"

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

class SelectServerLayer : public Layer
{
public:
	static SelectServerLayer* createInstance();
	virtual bool init();
	CREATE_FUNC(SelectServerLayer);
	void initMain();

	SEL_CallFuncN  m_closeAction;

	void setServers(Vector<ServerModel*> servers);

private:
	SelectServerLayer();
	~SelectServerLayer();

	void okTouchEvent(Ref* sender, Widget::TouchEventType type);
	void closeTouchEvent(Ref* sender, Widget::TouchEventType type);
	void selectTouchEvent(Ref* sender, Widget::TouchEventType type);

	Layout* root;
	ListView* lstServer;
	Button* btnOK;
	Button* btnReturn;

	ServerModel* _selectedServer;
};

#endif