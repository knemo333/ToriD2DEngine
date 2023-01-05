#pragma once

#include <vector>
#include <map>

class Collider;
class Object;
class CircleCollider;

/// <summary>
/// 충돌체크를 관리하는 클래스
/// ICollider를 포함하는 클래스를 관리하고 PhysicsUpdate를 수행해준다.
/// 
/// </summary>
class CollisionSystem
{
public:
	~CollisionSystem() {};

	static CollisionSystem& Instance()
	{
		static CollisionSystem* instance = new CollisionSystem();
		return *instance;
	}

	void Initialize();
	void Finalize();

	void CheckCollision();
	bool CheckCC(CircleCollider* const lhs, CircleCollider* const rhs);

	void SetColliderList(const std::vector<Object>& objectList);
	void AddList(Collider* const val);

private:
	CollisionSystem();
	std::vector<Collider*> colliderList_;
	std::map<Collider*, std::map<Collider*, bool>> prevStatus_;
	std::map<Collider*, std::map<Collider*, bool>> statusBuffer_;
};
