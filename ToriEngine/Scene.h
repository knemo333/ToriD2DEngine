#pragma once

#include <list>
#include <string>

class Object;

/// <summary>
/// 씬입니다.
/// 씬에 Object와 Renderable을 등록하여 사용
/// 
/// 2022.12.13 강석원 집
/// 
/// 사용자가 생성할 씬이 상속받을 BaseClass
/// 여기서 등록한 오브젝트는 부착된 컴포넌트에 따라 자동으로
/// ObjectSystem, ColliderSystem, RenderSystem에 등록된다.
/// 
/// 2022.12.28 강석원 인재원
/// </summary>
class Scene
{
public:
	Scene(std::string sceneName);
	~Scene();

	bool RegisterObject(Object* object);		// Scene에 Object를 등록시킴(Update 관리)

	void SetSceneName(const std::string& sceneName);

	void Update() const;		// Scene에 등록된 오브젝트들에 대해 Update를 수행(Core에서 호출함)
	void Render() const;		// Scene에 등록된 Renderable에 대해 Render를 수행(Core에서 호출함)

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
