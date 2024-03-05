#include "ResourceManager.h"

ResourceManager* ResourceManager::pInstance = NULL;

ResourceManager::~ResourceManager()
{
}

void ResourceManager::removeGraphic(const char* file)
{
	updateFirstFreeSlotGraphic();
}

Sint32 ResourceManager::loadAndGetGraphicID(const char* file)
{
	//creo un iterador (robot que busqui)
	std::map<std::string, Sint32>::iterator it;
	//creo un index per comprovar si ha fallat
	Sint32 index;
	//li ordeno que busqui el fitxer
	it = mIDMap.find(file);
	//si no ha arribat al final del sac
	if (it != mIDMap.end())
	{
		//retornes el id
		return it->second;
	}
	else//si ha arribat al final hi no l'ha trobat
	{
		//afageix el grafic
		index = addGraphic(file);
		if (index < 0)
		{
			printf("Error al carregar grafic: %s", SDL_GetError());
		}
		return index;
	}
}

std::string ResourceManager::getGraphicPathByID(Sint32 ID)
{
	return std::string();
}

void ResourceManager::getGraphicSize(Sint32 img, int& width, int& height)
{

	SDL_Surface* superficie = getGraphicByID(img);
	if (superficie != NULL)
	{
		width = superficie->w;
		height = superficie->h;
	}
	else
	{
		width = 0;
		height = 0;
	}
}

Uint16 ResourceManager::getGraphicWidth(Sint32 img)
{
	//creo variables de amplada i altura
	int width;
	int height;
	//crido la funcio de saber el tamany del grafic
	getGraphicSize(img, width, height);
	//retorno l'amplada del grafic
	return width;
}

Uint16 ResourceManager::getGraphicHeight(Sint32 img)
{
	//creo variables de amplada i altura
	int width;
	int height;
	//crido la funcio de saber el tamany del grafic
	getGraphicSize(img, width, height);
	//retorno l'altura del grafic
	return height;
}

SDL_Surface* ResourceManager::getGraphicByID(Sint32 ID)
{
	if (ID < 0)
	{
		return NULL;
	}

	if (ID < mGraphicsVector.size())
	{
		return mGraphicsVector[ID];
	}
	else
	{
		return NULL;
	}
}

void ResourceManager::setAlphaGraphic(Sint32 ID, Uint8 alpha_value)
{
}

void ResourceManager::printLoadedGraphics()
{
}

Sint32 ResourceManager::createGraphic(const char* name, Uint16 width, Uint16 height)
{
	return Sint32();
}

ResourceManager* ResourceManager::getInstance()
{
	//si no hi ha resource manager creal
	if (!pInstance)
	{
		pInstance = new ResourceManager;
	}
	return pInstance;
}

ResourceManager::ResourceManager()
{
	mFirstFreeSlot = 0;
}

Sint32 ResourceManager::addGraphic(const char* file)
{
	SDL_Surface* grafic = NULL;
	//cargar grafico
	grafic = IMG_Load(file);
	//verificar si se ha cargado
	if (grafic == NULL)
	{
		printf("Error al afegir el grafic: %s", SDL_GetError());
	}
	else
	{
		//a�adir grafico al vector
		mGraphicsVector.push_back(grafic);
		//a�adir grafico al map
		mIDMap.insert(std::pair<std::string, Sint32>(file, mGraphicsVector.size() - 1));
		//devolver en que posicion del vector se ha quedado
		return mGraphicsVector.size() - 1;
	}
	return -1;
}

Uint32 ResourceManager::updateFirstFreeSlotGraphic()
{
	int freeSlot = mGraphicsVector.size();
	for (int i = 0; i < mGraphicsVector.size(); i++)
	{
		if (mGraphicsVector[i] == NULL)
		{
			freeSlot = i;
			break;
		}
	}
	return freeSlot - 1;
}
