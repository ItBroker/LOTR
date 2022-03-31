#include "Collision.h"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
	
	return (recA.x + recA.w >= recB.x && recB.x + recB.w >= recA.x && 
		recA.y + recA.h >= recB.y && recB.y + recB.h >= recA.y);
}

bool Collision::AABB(const BoxCollider2D& colA, const BoxCollider2D& colB)
{
	if (AABB(colA.box, colB.box))
	{
		//cout << colA.collisionTag << " hit: " << colB.collisionTag << endl;
		return true;
	}
	else return false;
	
}
