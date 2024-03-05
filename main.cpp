#include "ResourceManager.h"
#include "Video.h"
#include <iostream>

int main(int argc, char* args[]) {

    Video::getInstance();

    Sint32 img = ResourceManager::getInstance()->loadAndGetGraphicID("img.jpg");

    Video::getInstance()->renderGraphic(img, 0, 0, ResourceManager::getInstance()->getGraphicWidth(img),
        ResourceManager::getInstance()->getGraphicHeight(img));


    Sint32 img2 = ResourceManager::getInstance()->loadAndGetGraphicID("img2.jpg");

    Video::getInstance()->renderGraphic(img2, 700, 0, ResourceManager::getInstance()->getGraphicWidth(img2),
        ResourceManager::getInstance()->getGraphicHeight(img2));


    Sint32 img3 = ResourceManager::getInstance()->loadAndGetGraphicID("img3.jpg");

    Video::getInstance()->renderGraphic(img3, 0, 500, ResourceManager::getInstance()->getGraphicWidth(img3),
        ResourceManager::getInstance()->getGraphicHeight(img3));

    Video::getInstance()->updateScreen();

    Video::getInstance()->waitTime(5000);

    return 0;

}