#ifndef GRID_ITEM_H___
#define GRID_ITEM_H___

#include "cocos2d.h"
#include "ui/CocosGUI.h"
class GridItem :public cocos2d::ui::Widget
{
public:
	GridItem();
	~GridItem();
	void setData(cocos2d::Color4F color, cocos2d::Size ss,bool isSame);
	int num;
private:
	cocos2d::DrawNode * _drawNode;
};
#endif