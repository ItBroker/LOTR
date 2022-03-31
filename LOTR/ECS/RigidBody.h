#pragma once
#include "Entity.h"
#include "../Vector2D.h"
#include "Component.h"
constexpr float GRAVITY = 10.0f;
class RigidBody: public Component
{
public:
	RigidBody() = default;
	virtual ~RigidBody() = default;

	RigidBody(float gravity_scale): gravityScale{gravity_scale}
	{

	}
	RigidBody( float gravity_scale,float a, float b) : gravityScale{ gravity_scale }
	{
		force.x = a;
		force.y = b;
	}
	bool init() override final
	{
		transform = &entity->getComponent<Transform>();
		return true;
	}
	void update() override final
	{
		velocity.x = force.x - drag.x;
		velocity.y = force.y + drag.y + gravityScale*GRAVITY;
		transform->translate(velocity);

	}
	void SetForce(const Vector2D vec)
	{
		force = vec;
	}
private:
	float mass;
	float gravityScale = 1.0f; 
	Vector2D drag = Vector2D();
	Vector2D force = Vector2D();

	Vector2D velocity = Vector2D();
	Transform* transform = nullptr;
};
