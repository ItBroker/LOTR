#pragma once
#include <string>
#include <map>
#include "SDL.h"
#include"SDL_image.h"
using namespace std;
class AssetManager
{
public:
	AssetManager();
	~AssetManager() = default;
	void clean();
	SDL_Texture* getTexture(string id);
	void loadTexture(string id, string path);
	inline static AssetManager& get()
	{
		if (s_instance == nullptr)
		{
			s_instance = new AssetManager();
		}
		return *s_instance;
	}
private:
	static AssetManager* s_instance;
	std::map<string, SDL_Texture*> textures;
};