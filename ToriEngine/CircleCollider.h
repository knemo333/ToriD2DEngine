#pragma once

#include "Collider.h"
#include "Component.h"

/// <summary>
/// ICollider �������̽��� ��ӹ޴� ���� �ݶ��̴�
/// �߽���ǥ�� �������� ���� �ִ�.
/// Circle Collision Detection�� �̿��ؼ� �浹�� üũ�Ѵ�.
/// Ÿ������ ���ؼ��� ���� ����°� ��������?
/// 
/// 22.12.19 ������ �����
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

