#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include<string>

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

HelloWorld::HelloWorld()
{
	dd = DrawNode::create();
	addChild(dd);
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	cc = 0;
	  auto rootNode = CSLoader::createNode("MainScene.csb");
	  Size ss = Director::getInstance()->getVisibleSize();
	  rootNode->setPosition((ss.width-rootNode->getContentSize().width)/2, (ss.height-rootNode->getContentSize().height)/2);
	  addChild(rootNode);
	  auto btn0 = rootNode->getChildByName("btn_0");
	  static_cast<ui::Button*>(btn0)->addClickEventListener(CC_CALLBACK_1(HelloWorld::clickBtn1, this));
	Director::getInstance()->getTextureCache()->addImageAsync("image/atlas.png", CC_CALLBACK_1(HelloWorld::callBack, this));
    return true;
}

void HelloWorld::clickBtn1(Object *sender)
{
	cc++;
	auto size=Director::getInstance()->getVisibleSize();
	EventDispatcher * disp;
	EventListenerMouse* listener = EventListenerMouse::create();
	listener->onMouseDown = CC_CALLBACK_1(HelloWorld::onTouchBegan, this);
	listener->onMouseMove = CC_CALLBACK_1(HelloWorld::onTouchMoved, this);
	listener->onMouseUp = CC_CALLBACK_1(HelloWorld::onTouchEnded, this);
	int noSame = random(0, 15);
	for (int i = 0; i < 16; i++)
	{
		gridList.push_back(new GridItem());
		gridList[i]->setData(Color4F(1, 0, 1, 1), Size(100, 100), noSame == i);
		gridList[i]->setPosition(Vec2((100 + 5)*(i % 4)+(size.width-400)/2, size.height-200-(100 + 5)*(i / 4)));
		addChild(gridList[i]);
		gridList[i]->num = i;
		gridList[i]->setEnabled(true);
		gridList[i]->setTouchEnabled(true);
		gridList[i]->addClickEventListener(CC_CALLBACK_1(HelloWorld::clickGrid, this));
		disp = gridList[i]->getEventDispatcher();
		gridList[i]->setSwallowTouches(true);
		//disp->addEventListenerWithSceneGraphPriority(listener->clone(), gridList[i]);
	}
}

void HelloWorld::clickGrid(Ref *d)
{
	log("1111");
}


void HelloWorld::onTouchBegan(Event* pEvent)
{
}
// 移动 ParallaxNode 节点
void HelloWorld::onTouchMoved( Event* pEvent)
{
	auto target=pEvent->getCurrentTarget();
	//log("%d", static_cast<GridItem*>(target)->num);
}
// 触摸结束后，输出每个节点的位置信息
void HelloWorld::onTouchEnded(Event* pEvent)
{
	CCLOG("---------------------------------------");
}

void HelloWorld::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(HelloWorld::onDraw, this, transform, flags);
	renderer->addCommand(&_customCommand);
}

void HelloWorld::onDraw(const cocos2d::Mat4 &transform, bool transformUpdated)
{
	Size s = Director::getInstance()->getVisibleSize();
	Vec2 filledVertices[] = { Vec2(100, 100), Vec2(100, 200), Vec2(200, 200), Vec2(200, 100) };
	DrawPrimitives::drawSolidPoly(filledVertices, 4, Color4F(0.5f, 0.5f, 1, 1));//参数依次为定
}


void HelloWorld::callBack(Texture2D *texture)
{
	AlterLoader::getInstance()->loadAtlas("image/atlas.txt", texture);
	auto frame = AlterLoader::getInstance()->getSpriteFrameByName("bg_day");
	Sprite *png = Sprite::createWithSpriteFrame(frame);
	Size ss = Director::getInstance()->getVisibleSize();
	auto scene=Director::getInstance()->getRunningScene();
	png->setAnchorPoint(ccp(0, 0));
	png->setPosition((ss.width - png->getContentSize().width) / 2, (ss.height - png->getContentSize().height) / 2);
	Label *labe = Label::create();
	wstring wss = L"中文啊";
	string ss1 = this->unicodeToUtf8(wss);
	labe->setString(ss1);
	labe->setColor(ccc3(200, 200, 200));
	labe->setSystemFontSize(20);
	labe->setPositionX(100);
	labe->setPositionY(100);
	addChild(labe);
	log(ss1.c_str());
	log("%f %f %f %f %f %f", ss.width, png->getContentSize().width, ss.height, png->getContentSize().height, (ss.width - png->getContentSize().width) / 2, (ss.height - png->getContentSize().height) / 2);
	//this->addChild(png);
}

string HelloWorld::unicodeToUtf8(const wstring text)
{
	wstring tes;
	int asciSize = WideCharToMultiByte(CP_UTF8, 0, text.c_str(), text.size(), NULL, 0, NULL, NULL);
	if (asciSize == ERROR_NO_UNICODE_TRANSLATION || asciSize == 0)
	{
		return string();
	}

	char *resultString = new char[asciSize];
	int conveResult = WideCharToMultiByte(CP_UTF8, 0, text.c_str(), text.size(), resultString, asciSize, NULL, NULL);
	if (conveResult != asciSize)
	{
		return string();
	}
	string buffer = "";
	buffer.append(resultString, asciSize);

	//CCLog("CCLog: buffer: %s",buffer.c_str());LOGNEWLINE;
	//buffer = strcpy();
	//printf("resultString1: %s",resultString);LOGNEWLINE;
	//CCLog("resultString2: %s",resultString);LOGNEWLINE;

	delete[] resultString; //释放内存
	return buffer;
}