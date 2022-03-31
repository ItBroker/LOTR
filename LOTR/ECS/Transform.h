#pragma once
#include "Component.h"
#include "..\Vector2D.h"
class Transform : public Component
{
public:
	Transform() = default;
	
	Transform(float x,float y)
	{
		position.x = x;
		position.y = y;
	}
	Transform(float x, float y, float sx, float sy)
	{
		position.x = x;
		position.y = y;
		scale.x = sx;
		scale.y = sy;

	}
	Transform(float x, float y, float sx, float sy,float rot)
	{
		position.x = x;
		position.y = y;
		scale.x = sx;
		scale.y = sy;
		rotation = rot;
	}
	virtual ~Transform() {}
	void update() override final
	{
		
		position.x += velosity.x * speed;
		
		position.y += velosity.y * speed;
	}
	bool init() override final
	{
		velosity.x = 0;
		velosity.y = 0;
		return true;
	}
	
	void translate(const Vector2D vec)
	{
		position += vec;
	}
	Vector2D velosity;
	int speed = 3;
	Vector2D position = Vector2D(); 
	Vector2D scale = Vector2D(1,1);
	float rotation = 0.0f;


};