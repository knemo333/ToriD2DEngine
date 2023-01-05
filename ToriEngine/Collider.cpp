#include "Collider.h"
#include "Object.h"
#include "CollisionSystem.h"

Collider::Collider()
	:Collider(-1)
{

}

Collider::Collider(unsigned int type)
	:colliderType_(type), centerPos_(Vector2D(0,0)), rotation_(0), scale_(Vector2D(0,0))
{
	CollisionSystem::Instance().AddList(this);
}

int Collider::GetColliderType()
{
	return colliderType_;
}

/// <summary>
/// Object�� ��ġ�� Collider�� ������ ���ؼ� ��ȯ
/// 
/// 22.12.28 ������ ��
/// </summary>
/// <returns></returns>
Vector2D Collider::GetCenterRelative() const
{
	Vector2D temp;
	temp += object_->GetCenterPos();
	return temp;
}
