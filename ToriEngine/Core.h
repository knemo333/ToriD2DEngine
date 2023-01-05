#pragma once

#include <windows.h>

class ToriD2D;
class SceneSystem;
class TimeSystem;
class InputSystem;
class CollisionSystem;
class RenderSystem;

/// <summary>
/// 엔진의 코어다.
/// Core에서는 엔진 내의 모든 담당자(Input,Renderer,Time)를 집합시켜 조립한다.
/// 데모 프로젝트에서 엔진에 여러 오브젝트를 등록할 수 있도록 한다.
/// 
/// 2022.12.13 강석원 집
/// </summary>
class Core
{
public:
	Core();
	~Core();

	void Initialize(HWND hWnd);			// 엔진 초기화
	void Finalize();
	void CycleOnce();			// 정의된 순서대로 엔진을 1회 싸이클 시킴

private:
	ToriD2D& toriD2D_;
	SceneSystem& sceneSystem_;
	TimeSystem& timeSystem_;
	InputSystem& inputSystem_;
	CollisionSystem& collisionSystem_;
	RenderSystem& renderSystem_;
	
	void PhysicsUpdate();
	void Input();
	void Update();
	void Render();
};
