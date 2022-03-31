#pragma once
#include "../ECS/BoxCollider2D.h"
class Collision
{
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
	static bool AABB(const BoxCollider2D& colA, const BoxCollider2D& colB);
};