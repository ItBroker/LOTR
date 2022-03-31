#pragma once
#include <string>
#include "SDL.h"
#include "Component.h"
#include "Entity.h"
#include "../Engine/Engine.h"

class BoxCollider2D: public Component
{
public:
	BoxCollider2D(SDL_Renderer* target, int width, int height) : rTarget{ target }
	{
		box.w = width;
		box.h = height;
	}
	BoxCollider2D(SDL_Renderer* target, int width, int height, string tag) : rTarget{ target }, collisionTag{tag}
	{
		box.w = width;
		box.h = height;
	}
	~BoxCollider2D() = default;
	bool init() override final
	{
		transform = &entity->getComponent<Transform>();
		Engine::colliders.push_back(this);
		return true;
	}

	void draw() override final
	{
		SDL_SetRenderDrawColor(rTarget, 255, 214, 98, 255);
		SDL_RenderDrawRect(rTarget, &box);
	}
	void update() override final
	{
		box.x = static_cast<int>(transform->position.x);
		box.y = static_cast<int>(transform->position.y);
	}
	string getCollisionTag() const
	{
		return collisionTag;
	}
private:
	friend class Collision;
	SDL_Rect box = {0,0,0,0};
	string collisionTag = "";
	Transform* transform = nullptr;
	SDL_Renderer* rTarget = nullptr;
};
