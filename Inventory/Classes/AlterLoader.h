#ifndef  _ALTER_LOADER_H_
#define  _APP_DELEGATE_H_
#include <string>
#include "cocos2d.h"
#include<iostream>
using namespace std;
using namespace cocos2d;
typedef struct _atlas{
	char name[255];
	int width;
	int height;
	Point start;
	Point end;
} Atlas;

class AlterLoader
{
public:
	AlterLoader();
	~AlterLoader();

	static AlterLoader* getInstance();

	/**
	*  Destroys the instance of AtlasLoader.
	*/
	static void destroyInstance();

	/**
	* Load the atlas of file
	* This function load the image, so it will be delay the main thread
	* exp. AtlasLoader::getInstance()->loadAtlas("atlas.txt");
	*/
	void loadAtlas(string filename);

	/**
	* Load the atlas of file
	* you can load the texture in asyc method then use this function
	*/
	void loadAtlas(string filename, Texture2D *texture);

	/**
	* Get the sprite by name.
	* Warm: you should use this function after add atlas.png to getTextureCache,
	* or this function will take you a long time to load texture.
	* exp. SpriteFrame *bg_day = AtlasLoader::getInstance()->getSpriteFrameByName("bg_day");
	*/
	SpriteFrame* getSpriteFrameByName(string name);

protected:
	static AlterLoader* sharedAtlasLoader;

	Map<std::string, SpriteFrame*> _spriteFrames;
};
#endif

