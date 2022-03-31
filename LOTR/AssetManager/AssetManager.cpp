  #include "AssetManager.h"
#include <iostream>
#include "../Engine/Engine.h"

AssetManager* AssetManager::s_instance = nullptr;

AssetManager::AssetManager()
{
	if (IMG_Init(IMG_INIT_PNG) != 0)
	{
		cerr << SDL_GetError()<<endl;
	}
}

void AssetManager::clean()
{
	for (auto it = textures.begin(); it != textures.end(); it++)
	{
		SDL_DestroyTexture(it->second);
		
	}
	textures.clear();
	cout << "Assets cleared !" << endl;
}

SDL_Texture* AssetManager::getTexture(string id)
{

	return (textures.count(id)>0)? textures[id] : nullptr;
}

void AssetManager::loadTexture(string id, string path)
{
	if (textures.count(id) <= 0)
	{
		SDL_Texture* texture = IMG_LoadTexture(Engine::get().getRenderer(), path.c_str());
		if (texture)
		{
			textures[id] = texture;
			cout << "texture[ " << path << " ] loaded" << endl;
			
		}
		else
			cerr << IMG_GetError() << endl;
	}
}
