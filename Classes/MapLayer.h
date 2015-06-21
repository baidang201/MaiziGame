#ifndef __MAPRLAYER_H__
#define __MAPRLAYER_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui/CocosGUI.h"
#include "TavernLayer.h"

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

class MapLayer : public Layer
{
public:
	static MapLayer* createInstance();
	virtual bool init();
	CREATE_FUNC(MapLayer);
	void initMain();

private:
	MapLayer();
	~MapLayer();

	void selectTavernTouchEvent(Ref* sender, Widget::TouchEventType type);
	void closeTavernLayer(Node* node);
	void closeLayer(Node* node);

	Layout* root;
	Button* btnTavern;
};

#endif