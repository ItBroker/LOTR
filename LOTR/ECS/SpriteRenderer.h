#pragma once
#include "SDL.h"
#include <string>
#include "Entity.h"
#include "Component.h"
#include "../AssetManager/AssetManager.h"
#include "Animation.h"
#include <map>
#include "../AssetManager/AssetManager.h"
class SpriteRenderer: public Component
{
public:
	
	int AnimIndex = 0;
	SpriteRenderer() = default;
	virtual ~SpriteRenderer() = default;
	SpriteRenderer(SDL_Renderer* target, string textureId): rTarget{ target }, textureID{ textureId }{}
	SpriteRenderer(SDL_Renderer* target, string textureId, Entity* spirite) : rTarget{ target }, textureID{ textureId }{
		entity = spirite;
	
	}
	SpriteRenderer(SDL_Renderer* target, string textureId, int w, int h, bool isAnimated) : rTarget{ target }, textureID{ textureId }
	{
		animated = isAnimated;
		width = w;
		height = h;
	}
	SpriteRenderer(SDL_Renderer* target, string textureId, int w, int h) : rTarget{ target }, textureID{ textureId }
	{
		width = w;
		height = h;
	}
	bool init() override final
	{
		
			
		
		transform = &entity->getComponent<Transform>();
		
		
		texture = AssetManager::get().getTexture(textureID);
		if (width == 0)
		{	
			if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) == 0)
				cout << SDL_GetError() << endl;
		}
		else
			cout << width << endl;
		
		dst.x = static_cast<int>(transform->position.x);
		dst.y = static_cast<int>(transform->position.y);
		dst.w = static_cast<int>(width);
		dst.h = static_cast<int>(height);

		src.x = 0;
		src.y = 0;
		src.w = static_cast<int>(width);
		src.h = static_cast<int>(height);
		if (textureID == "Frodo")
		{
			cout << src.x << endl << src.y << endl << src.w << endl << src.h << endl;
		}
		return true;
	}
	void draw()override final
	{
		SDL_RenderCopyEx(rTarget, texture, &src, &dst, NULL,NULL,flip);
	}
	void update() override final
	{
		if (animated)
		{
			src.x = src.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}
		dst.x = static_cast<int>(transform->position.x);
		dst.y = static_cast<int>(transform->position.y);
		dst.w = static_cast<int>(width);
		dst.h = static_cast<int>(height);
	}
	int getWidth()
	{
		return src.w;
	}
	int getHeight()
	{
		return src.h;
	}
	void Play(int a,int b)
	{
		switch (a)
		{
		case 1:
			animated = true;
			texture = AssetManager::get().getTexture( "FrodoAnim");
			width = 333;
			height = 256;
			

			break;
		case 0:
			animated = false;
			texture = AssetManager::get().getTexture("Frodo");
			break;
		default:
			break;
		}
	}
private:
	int width = 0;
	int height = 0;
	SDL_Rect src = {0,0,0,0}, dst = {0,0,0,0};
	Transform* transform = nullptr;
	string textureID = "";
	SDL_Texture* texture = nullptr;
	SDL_Renderer* rTarget = nullptr;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	bool animated = false;
	int frames = 3;
	int speed = 100;
};
