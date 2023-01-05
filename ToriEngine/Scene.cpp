#include "Scene.h"
#include "Object.h"
#include "CircleRenderer.h"

Scene::Scene(std::string sceneName)
	:sceneName_(sceneName)
{
}

Scene::~Scene()
{
	for (auto object : objectList_)
	{
		delete object;
	}
}

/// <summary>
/// ���� object�� ����մϴ�
/// 
/// 22.12.13 ������ ��
/// </summary>
/// <param name="object">���� ����� Object �ּ�</param>
/// <returns></returns>
bool Scene::RegisterObject(Object* object)
{
	if (object == nullptr)
	{
		return false;
	}

	objectList_.push_back(object);

	return true;
}


void Scene::SetSceneName(const std::string& sceneName)
{
	sceneName_ = sceneName;
}

/// <summary>
/// ���� ���� ��ϵ� Object���� Upate�� ����
/// 
/// 2022.12.13 ������ ��
/// </summary>
void Scene::Update() const
{
	for (auto object : objectList_)
	{
		object->Update();
	}
}

/// <summary>
/// ���� ���� ��ϵ� Renderable���� Render�� ����
/// 
/// 2022.12.13 ������ ��
/// </summary>
void Scene::Render() const
{
	for (auto object : objectList_)
	{
		object->GetComponent<CircleRenderer>()->Render();	// �̰� Render�� �޾Ƽ� �ϴ°� �ȵǳ�? �� �����ȵ��..
	}
}