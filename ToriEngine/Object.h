#pragma once
//#include <map>
#include <vector>
#include <typeinfo>

#include "Vector2D.h"

class Component;
class Renderer;

/// <summary>
/// 모든 오브젝트가 기본적으로 상속받는 base object 클래스
/// 나중에는 필요한 오브젝트들을 생성해주는 팩토리를 만들어서 전달받아 쓸 수 있게 할 예정
/// 
/// 2022.12.14 강석원 집
/// </summary>
class Object
{
public:
	/// 생성자, 소멸자
	Object();	
	Object(float centerX, float centerY);
	~Object();

	/// 모든 오브젝트는 Update를 수행한다.
	/// Update는 Core에서 일괄적으로 호출된다.
	virtual void Update() {}

#pragma region Collision
	/// Collider에서 충돌감지가 되면 CollisionSystem에서 호출시키는 콜백 함수들
	virtual void OnCollisionEnter() {};
	virtual void OnCollisionStay() {};
	virtual void OnCollisionExit() {};
#pragma endregion Collision

#pragma region TransformMethods
	void Translate(float dX, float dY);		// deltaVector 만큼 덧셈 (이동)
	void Rotate(float deltaRadian);				// deltaRadian 만큼 덧셈 (회전)
	void Scale(float dX, float dY);			// deltaScale 만큼 곱셈 (확대,축소)

	Vector2D GetCenterPos() const;
	float GetRotation() const;
	Vector2D GetScale() const;

	void SetCenterPos(Vector2D newCenter);
	void SetRotation(float newRotation);
	void SetScale(Vector2D newScale);
#pragma endregion TransformMethods

	//Renderer* GetRenderer() const { return renderer_; }
	//void SetRenderer(Renderer* const val);

protected:
	Vector2D centerPosition_;		// 오브젝트의 중앙 값
	float rotation_;				// 오브젝트의 라디안 값 (-2*π ~ 2*π)
	Vector2D scale_;				// 오브젝트의 scale 값

//	Renderer* renderer_;

#pragma region Component
/// 컴포넌트 관련
public:

	// 컴포넌트를 추가 또는 획득
	template <typename T>
	T AddComponent(T addComponent);

	/// <summary>
	/// 일반 버전
	/// </summary>
	template <typename T>
	T* GetComponent();

	/// <summary>
	/// 포인터 버전 (T를 포인터로 넣어야 함)
	/// </summary>
	template <typename T>
	T GetComponent2();

private:
	std::vector<Component*> components_;
#pragma endregion Component
};

template <typename T>
T Object::AddComponent(T addComponent)
{
	Component* tempComponent = dynamic_cast<Component*>(addComponent);
	if (!tempComponent)
	{
		return NULL;
	}
	tempComponent->SetObject(this); 

	components_.push_back(tempComponent);

	return addComponent;
}

template <typename T>
T* Object::GetComponent()
{
	for (Component* co : components_)
	{
		auto temp = dynamic_cast<T*>(co);
		if (!temp)
		{
			continue;
		}
		//const type_info& _info = typeid(*co);
		//const type_info& _infoT = typeid(T);

		// *T를 사용할 수 없음.
		if (typeid(*temp).name() == typeid(T).name())
		{
			// return dynamic_cast<T*>(co);	// Component가 다형 형식이여야 함. Component에 virtual이 있어야함.
			return (T*)co;
		}
	}

	return nullptr;
}

template <typename T>
T Object::GetComponent2()
{
	for (Component* co : components_)
	{
		//const type_info& _info = typeid(*co);
		//const type_info& _infoT = typeid(T);

		// 다이내믹 캐스트는 비용 발생 가능성이 있음.
		// (하지만 하나의 엔티티에 컴포넌트가 몇 개나 있을까)
		T _co = dynamic_cast<T>(co);
		if (NULL != _co)
		{
			return _co;
		}
	}

	return nullptr;
}

