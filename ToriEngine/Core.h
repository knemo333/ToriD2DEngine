#pragma once

#include <windows.h>

class ToriD2D;
class SceneSystem;
class TimeSystem;
class InputSystem;
class CollisionSystem;
class RenderSystem;

/// <summary>
/// ������ �ھ��.
/// Core������ ���� ���� ��� �����(Input,Renderer,Time)�� ���ս��� �����Ѵ�.
/// ���� ������Ʈ���� ������ ���� ������Ʈ�� ����� �� �ֵ��� �Ѵ�.
/// 
/// 2022.12.13 ������ ��
/// </summary>
class Core
{
public:
	Core();
	~Core();

	void Initialize(HWND hWnd);			// ���� �ʱ�ȭ
	void Finalize();
	void CycleOnce();			// ���ǵ� ������� ������ 1ȸ ����Ŭ ��Ŵ

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
