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
/// 씬에 object를 등록합니다
/// 
/// 22.12.13 강석원 집
/// </summary>
/// <param name="object">씬에 등록할 Object 주소</param>
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
/// 현재 씬에 등록된 Object들의 Upate를 실행
/// 
/// 2022.12.13 강석원 집
/// </summary>
void Scene::Update() const
{
	for (auto object : objectList_)
	{
		object->Update();
	}
}

/// <summary>
/// 현재 씬에 등록된 Renderable들의 Render를 실행
/// 
/// 2022.12.13 강석원 집
/// </summary>
void Scene::Render() const
{
	for (auto object : objectList_)
	{
		object->GetComponent<CircleRenderer>()->Render();	// 이거 Render로 받아서 하는건 안되나? 좀 맘에안드네..
	}
}