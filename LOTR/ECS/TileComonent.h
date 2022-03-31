#pragma once
#include "Entity.h"
#include "Component.h"
#include "SDL.h"
#include "SpriteRenderer.h"
#include "../Engine/Engine.h"
#include <string>
class TileComponent : public Component
{
public:
	Transform* transform;
	SpriteRenderer* sprite;
	SDL_Rect tileRect;
	int tileID;
	string path;
	TileComponent() = default;
	TileComponent(int x, int y, int id)
	{
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = 0;
		tileRect.h = 0;
		tileID = id;
		switch (tileID)
		{
		case 0:
			path = "water";

			break;
		case 1:

			path = "dirt";
			break;
		case 2:
			path = "grass";
			break;
		default:
			break;
		}
	}
	TileComponent(int x, int y, int w, int h, int id)
	{
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;
		switch (tileID)
		{
		case 0:
			path = "water";
			cout << "water" << endl;
			break;
		case 1:
			path = "dirt";
			cout << "dirt" << endl;
			break;
		case 2:
			path = "grass";
			cout << "grass" << endl;
			break;
		default:
			break;
		}
	} 

	bool init()override final
	{
		entity->addComponent<Transform>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->getComponent<Transform>();
		entity->addComponent<SpriteRenderer>(Engine::renderer, path, entity);
		sprite = &entity->getComponent<SpriteRenderer>();
		entity->addComponent<BoxCollider2D>(Engine::renderer,sprite->getWidth(), sprite->getHeight(), path);
		return true;
	}
};