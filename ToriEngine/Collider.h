#pragma once
#include "Vector2D.h"
#include "Component.h"

class Object;

/// <summary>
/// 충돌 처리를 위해 상속받을 콜라이더 인터페이스
/// 이 인터페이스를 상속받아서 여러 collider를 만들 것 (박스,원,선 등등)
/// 
/// 2022.12.13 강석원 집
/// </summary>
class Collider : public Component
{
public:
	static enum class ColliderType
	{
		CIRCLE,
		RECTANGLE
	};

	Collider();
	Collider(unsigned int type);
	
	int GetColliderType();
	Vector2D GetCenterRelative() const;

protected:
	int colliderType_;

	Vector2D centerPos_;
	float rotation_;		// radian
	Vector2D scale_;
};

