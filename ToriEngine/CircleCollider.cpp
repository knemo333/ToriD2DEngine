#include "Vector2D.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius)
	: Collider((unsigned int)ColliderType::CIRCLE), radius_(radius)
{
	//componentID_ = (unsigned int)ComponentID::CIRCLE_COLLIDER;
}

float CircleCollider::GetRadius() const
{
	return radius_;
}

void CircleCollider::SetRadius(float radius)
{
	radius_ = radius;
}
