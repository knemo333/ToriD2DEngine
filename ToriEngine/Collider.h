#pragma once
#include "Vector2D.h"
#include "Component.h"

class Object;

/// <summary>
/// �浹 ó���� ���� ��ӹ��� �ݶ��̴� �������̽�
/// �� �������̽��� ��ӹ޾Ƽ� ���� collider�� ���� �� (�ڽ�,��,�� ���)
/// 
/// 2022.12.13 ������ ��
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

