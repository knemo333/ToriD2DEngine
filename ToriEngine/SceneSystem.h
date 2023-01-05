#pragma once
#include <list>
#include <string>

class Scene;

/// <summary>
/// 씬을 생성하고 생성자로 이름을 붙여 관리
/// 
/// 2022.12.13 강석원 집
/// </summary>
class SceneSystem
{
public:
	~SceneSystem();

	// 싱글턴
	static SceneSystem& Instance()
	{
		static SceneSystem* instance = new SceneSystem();
		return *instance;
	}

	void Initialize();							// SceneManager를 초기화
	void Finalize();

	Scene& CreateScene(std::string sceneName);	// 새로운 Scene을 생성하고 이름을 부여합니다.
	Scene* GetNowScene() const;						// 현재 Scene의 주소를 반환합니다.
	void SetNowScene(std::string sceneName);	// 현재 Scene을 인자로 넘어온 이름의 Scene으로 변경합니다.

private:
	SceneSystem();
	Scene* nowScene_;				// 현재 Scene

	std::list<Scene*> sceneList_;	// Scene List
};

