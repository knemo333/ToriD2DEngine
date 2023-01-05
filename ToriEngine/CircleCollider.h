#pragma once

#include "Collider.h"
#include "Component.h"

/// <summary>
/// ICollider 인터페이스를 상속받는 원형 콜라이더
/// 중심좌표와 반지름을 갖고 있다.
/// Circle Collision Detection을 이용해서 충돌을 체크한다.
/// 타원형에 대해서는 따로 만드는게 나으려나?
/// 
/// 22.12.19 강석원 인재원
/// </summary>
class CircleCollider : public Collider
{
public:
	CircleCollider(float radius);
	virtual ~CircleCollider() {};
	
	float GetRadius() const;
	void SetRadius(float radius);

private:
	float radius_;
};

