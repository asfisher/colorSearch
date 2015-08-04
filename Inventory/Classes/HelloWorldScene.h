#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "AlterLoader.h"
#include "GridItem.h"
#include <vector>

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

	HelloWorld();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void callBack(Texture2D *texture);
	string unicodeToUtf8(const wstring txt);

	virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags) override;
	int cc;
	void clickBtn1(Object *sender);
protected:
	void onDraw(const cocos2d::Mat4 &transform, bool transformUpdated);
	cocos2d::CustomCommand _customCommand;
	DrawNode * dd;
	vector<GridItem *> gridList;
	void clickGrid(Ref *d);
	void HelloWorld::onTouchBegan(Event* pEvent);
	void HelloWorld::onTouchMoved(Event* pEvent);
	void HelloWorld::onTouchEnded(Event* pEvent);
};

#endif // __HELLOWORLD_SCENE_H__
