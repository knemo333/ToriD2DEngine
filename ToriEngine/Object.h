#pragma once
//#include <map>
#include <vector>
#include <typeinfo>

#include "Vector2D.h"

class Component;
class Renderer;

/// <summary>
/// ��� ������Ʈ�� �⺻������ ��ӹ޴� base object Ŭ����
/// ���߿��� �ʿ��� ������Ʈ���� �������ִ� ���丮�� ���� ���޹޾� �� �� �ְ� �� ����
/// 
/// 2022.12.14 ������ ��
/// </summary>
class Object
{
public:
	/// ������, �Ҹ���
	Object();	
	Object(float centerX, float centerY);
	~Object();

	/// ��� ������Ʈ�� Update�� �����Ѵ�.
	/// Update�� Core���� �ϰ������� ȣ��ȴ�.
	virtual void Update() {}

#pragma region Collision
	/// Collider���� �浹������ �Ǹ� CollisionSystem���� ȣ���Ű�� �ݹ� �Լ���
	virtual void OnCollisionEnter() {};
	virtual void OnCollisionStay() {};
	virtual void OnCollisionExit() {};
#pragma endregion Collision

#pragma region TransformMethods
	void Translate(float dX, float dY);		// deltaVector ��ŭ ���� (�̵�)
	void Rotate(float deltaRadian);				// deltaRadian ��ŭ ���� (ȸ��)
	void Scale(float dX, float dY);			// deltaScale ��ŭ ���� (Ȯ��,���)

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
	Vector2D centerPosition_;		// ������Ʈ�� �߾� ��
	float rotation_;				// ������Ʈ�� ���� �� (-2*�� ~ 2*��)
	Vector2D scale_;				// ������Ʈ�� scale ��

//	Renderer* renderer_;

#pragma region Component
/// ������Ʈ ����
public:

	// ������Ʈ�� �߰� �Ǵ� ȹ��
	template <typename T>
	T AddComponent(T addComponent);

	/// <summary>
	/// �Ϲ� ����
	/// </summary>
	template <typename T>
	T* GetComponent();

	/// <summary>
	/// ������ ���� (T�� �����ͷ� �־�� ��)
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

		// *T�� ����� �� ����.
		if (typeid(*temp).name() == typeid(T).name())
		{
			// return dynamic_cast<T*>(co);	// Component�� ���� �����̿��� ��. Component�� virtual�� �־����.
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

		// ���̳��� ĳ��Ʈ�� ��� �߻� ���ɼ��� ����.
		// (������ �ϳ��� ��ƼƼ�� ������Ʈ�� �� ���� ������)
		T _co = dynamic_cast<T>(co);
		if (NULL != _co)
		{
			return _co;
		}
	}

	return nullptr;
}

