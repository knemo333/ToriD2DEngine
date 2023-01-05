#include "CollisionDemoScene.h"

#include "Circle.h"
#include "SceneSystem.h"
#include "Scene.h"
#include "CircleCollider.h"
#include "CircleRenderer.h"

#define SCENENAME "CollisionDemoScene"

/// <summary>
/// 말은 초기화지만 여기서 오브젝트 생성
/// 엔진의 오브젝트나 만들어진 것들 상속받아서 생성해도 됨
/// 
/// 22.12.14 강석원 인재원
/// </summary>
void CollisionDemoScene::Initialize()
{
	SceneSystem& sceneManager = SceneSystem::Instance();
	Scene* nowScene = sceneManager.GetNowScene();

	nowScene->SetSceneName(SCENENAME);

	Circle* circle = new Circle(250, 250, 50);
	nowScene->RegisterObject(circle);
	circle->AddComponent(new CircleCollider(50));
	circle->AddComponent(new CircleRenderer(50));
	circle->GetComponent<CircleRenderer>()->SetRGBA(0, 255, 0, 255);

	Circle* playerCircle = new Circle(420, 420, 50);
	nowScene->RegisterObject(playerCircle);
	playerCircle->AddComponent(new CircleCollider(50));
	playerCircle->AddComponent(new CircleRenderer(50));
	circle->GetComponent<CircleRenderer>()->SetRGBA(0, 255, 0, 255);
	playerCircle->SetPlayer(true);
}

