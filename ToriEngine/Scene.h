#pragma once

#include <list>
#include <string>

class Object;

/// <summary>
/// ���Դϴ�.
/// ���� Object�� Renderable�� ����Ͽ� ���
/// 
/// 2022.12.13 ������ ��
/// 
/// ����ڰ� ������ ���� ��ӹ��� BaseClass
/// ���⼭ ����� ������Ʈ�� ������ ������Ʈ�� ���� �ڵ�����
/// ObjectSystem, ColliderSystem, RenderSystem�� ��ϵȴ�.
/// 
/// 2022.12.28 ������ �����
/// </summary>
class Scene
{
public:
	Scene(std::string sceneName);
	~Scene();

	bool RegisterObject(Object* object);		// Scene�� Object�� ��Ͻ�Ŵ(Update ����)

	void SetSceneName(const std::string& sceneName);

	void Update() const;		// Scene�� ��ϵ� ������Ʈ�鿡 ���� Update�� ����(Core���� ȣ����)
	void Render() const;		// Scene�� ��ϵ� Renderable�� ���� Render�� ����(Core���� ȣ����)

	bool operator==(const Scene& rhs)
	{
		return this->sceneName_ == rhs.sceneName_;
	}

	bool operator==(const std::string sceneName)
	{
		return this->sceneName_ == sceneName;
	}

private:
	std::string sceneName_;
	std::list<Object*> objectList_;
};
