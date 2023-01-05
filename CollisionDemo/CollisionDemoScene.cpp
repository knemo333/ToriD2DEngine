#include "CollisionDemoScene.h"

#include "Circle.h"
#include "SceneSystem.h"
#include "Scene.h"
#include "CircleCollider.h"
#include "CircleRenderer.h"

#define SCENENAME "CollisionDemoScene"

/// <summary>
/// ���� �ʱ�ȭ���� ���⼭ ������Ʈ ����
/// ������ ������Ʈ�� ������� �͵� ��ӹ޾Ƽ� �����ص� ��
/// 
/// 22.12.14 ������ �����
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

