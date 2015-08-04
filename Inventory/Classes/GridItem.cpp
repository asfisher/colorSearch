#include "GridItem.h"
using namespace cocos2d;
GridItem::GridItem()
{
	_drawNode = DrawNode::create();
	addChild(_drawNode);
	num=1;
}

GridItem::~GridItem()
{

}


void GridItem::setData(Color4F color,Size ss, bool isSame)
{
	_drawNode->clear();
	Vec2 vec[] = { Vec2(0, 0), Vec2(0, ss.height), Vec2(ss.width, ss.height), Vec2(ss.width, 0) };
	_drawNode->drawPolygon(vec, 4, color, 0, color);
	this->setSize(ss);
	if (isSame)
	{
		this->setBright(true);
		this->setHighlighted(true);
		log(111111);
	}
}