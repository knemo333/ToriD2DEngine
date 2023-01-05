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
/// 여기서 Collider delete 해줬더니 힙 오류가 난다.
/// 어디서 소멸되는지 추적해야 할 필요가 있다.
/// 
/// 22.12.28 강석원 집
/// </summary>
void CollisionSystem::Finalize()
{
}

/// <summary>
/// 등록된 콜라이더들에 대해 전부 충돌체크를 해서 상태를 기록한다.
/// 등록된 콜라이더 : 현재 씬의 오브젝트들이 갖고있는 콜라이더
/// 
/// 22.12.22 강석원 인재원
/// 
/// 22.12.28 지금은 원충돌만
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
