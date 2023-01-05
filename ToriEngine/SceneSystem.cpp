#include "SceneSystem.h"
#include "Scene.h"

SceneSystem::SceneSystem()
	:nowScene_(nullptr)
{
	sceneList_.clear();
}

SceneSystem::~SceneSystem()
{
}

/// <summary>
/// SceneManager를 초기화
/// 멤버 변수를 전부 초기화
/// 
/// 2022.12.13 강석원 집
/// </summary>
void SceneSystem::Initialize()
{
	for (auto scene : sceneList_)
	{
		delete scene;
	}

	sceneList_.clear();

	Scene* defaultScene = new Scene("MainScene");
	nowScene_ = defaultScene;
	sceneList_.push_back(defaultScene);
}

void SceneSystem::Finalize()
{
	for (auto scene : sceneList_)
	{
		delete scene;
	}
}

/// <summary>
/// Scene을 생성
/// 
/// 2022.12.13 강석원 집
/// </summary>
Scene& SceneSystem::CreateScene(std::string sceneName)
{
	Scene* newScene = new Scene(sceneName);
	sceneList_.push_back(newScene);

	return *newScene;
}

/// <summary>
/// 현재 Scene의 주소를 반환
/// 
/// 2022.12.13 강석원 집
/// </summary>
Scene* SceneSystem::GetNowScene() const
{
	return nowScene_;
}

/// <summary>
/// 현재 Scene을 인자로 넘어온 이름의 Scene으로 변경
/// 
/// 2022.12.13 강석원 집
/// </summary>
void SceneSystem::SetNowScene(std::string sceneName)
{
	for (auto scene : sceneList_)
	{
		if (*scene == sceneName)
		{
			nowScene_ = scene;
			return;
		}
	}
}
