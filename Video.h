#pragma once
#include "sdl.h"
#include "ResourceManager.h"
class Video
{
public:
	~Video();
	void renderGraphic(int img, int posX, int posY, int width, int height);
	void clearScreen(unsigned int color_key);
	void updateScreen();
	void waitTime(int ms);
	void close();
	static Video* getInstance();
	SDL_Surface* getScreen();
	SDL_Window* gWindow;
	SDL_Surface* gScreenSurface;
private:
	static Video* pInstance;
protected:
	Video();
};