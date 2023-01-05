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
/// SceneManager�� �ʱ�ȭ
/// ��� ������ ���� �ʱ�ȭ
/// 
/// 2022.12.13 ������ ��
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
/// Scene�� ����
/// 
/// 2022.12.13 ������ ��
/// </summary>
Scene& SceneSystem::CreateScene(std::string sceneName)
{
	Scene* newScene = new Scene(sceneName);
	sceneList_.push_back(newScene);

	return *newScene;
}

/// <summary>
/// ���� Scene�� �ּҸ� ��ȯ
/// 
/// 2022.12.13 ������ ��
/// </summary>
Scene* SceneSystem::GetNowScene() const
{
	return nowScene_;
}

/// <summary>
/// ���� Scene�� ���ڷ� �Ѿ�� �̸��� Scene���� ����
/// 
/// 2022.12.13 ������ ��
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
