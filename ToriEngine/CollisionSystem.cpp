#include "CollisionSystem.h"
#include "Collider.h"
#include "Object.h"
#include "CircleCollider.h"

#include "AABB.h"
#include "CC.h"

void CollisionSystem::Initialize()
{
	colliderList_.clear();
	prevStatus_.clear();
	statusBuffer_.clear();
}

/// <summary>
/// ���⼭ Collider delete ������� �� ������ ����.
/// ��� �Ҹ�Ǵ��� �����ؾ� �� �ʿ䰡 �ִ�.
/// 
/// 22.12.28 ������ ��
/// </summary>
void CollisionSystem::Finalize()
{
}

/// <summary>
/// ��ϵ� �ݶ��̴��鿡 ���� ���� �浹üũ�� �ؼ� ���¸� ����Ѵ�.
/// ��ϵ� �ݶ��̴� : ���� ���� ������Ʈ���� �����ִ� �ݶ��̴�
/// 
/// 22.12.22 ������ �����
/// 
/// 22.12.28 ������ ���浹��
/// </summary>
void CollisionSystem::CheckCollision()
{
	for (Collider* lhs : colliderList_)
	{
		for (Collider* rhs : colliderList_)
		{
			if (lhs == rhs)
			{
				continue;
			}

			if (CheckCC((CircleCollider*)lhs, (CircleCollider*)rhs))
			{
				statusBuffer_[lhs][rhs] = true;
				statusBuffer_[rhs][lhs] = true;

				if (prevStatus_.empty())
				{
					lhs->GetObj()->OnCollisionEnter();
					continue;
				}

				if (prevStatus_[lhs][rhs])
				{
					lhs->GetObj()->OnCollisionStay();
				}
				else
				{
					lhs->GetObj()->OnCollisionEnter();
				}
			}
			else
			{
				statusBuffer_[lhs][rhs] = false;
				statusBuffer_[rhs][lhs] = false;

				if (prevStatus_.empty())
				{
					lhs->GetObj()->OnCollisionExit();
					continue;
				}

				if (prevStatus_[lhs][rhs])
				{
					lhs->GetObj()->OnCollisionExit();
				}
			}
		}
	}

	prevStatus_ = statusBuffer_;
}

bool CollisionSystem::CheckCC(CircleCollider* const lhs, CircleCollider* const rhs)
{
	return DetectCircleCollision(lhs->GetCenterRelative(), lhs->GetRadius(), rhs->GetCenterRelative(), rhs->GetRadius());
}

void CollisionSystem::SetColliderList(const std::vector<Object>& objectList)
{
	colliderList_.clear();
	prevStatus_.clear();
	statusBuffer_.clear();

	for (auto object : objectList)
	{
		colliderList_.push_back(object.GetComponent<CircleCollider>());
	}
}

void CollisionSystem::AddList(Collider* const val)
{
	colliderList_.push_back(val);
}

CollisionSystem::CollisionSystem()
{

}
