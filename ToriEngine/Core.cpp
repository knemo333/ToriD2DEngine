#include "Core.h"

#include "ToriD2D.h"
#include "SceneSystem.h"
#include "Scene.h"
#include "TimeSystem.h"
#include "InputSystem.h"
#include "CollisionSystem.h"
#include "RenderSystem.h"

Core::Core()
	: toriD2D_(ToriD2D::Instance()), 
	sceneSystem_(SceneSystem::Instance()),
	timeSystem_(TimeSystem::Instance()),
	inputSystem_(InputSystem::Instance()),
	collisionSystem_(CollisionSystem::Instance()),
	renderSystem_(RenderSystem::Instance())
{
}

Core::~Core()
{
}

void Core::Initialize(HWND hWnd)
{
	toriD2D_.Initialize(hWnd);
	sceneSystem_.Initialize();
	timeSystem_.Initialize();
	inputSystem_.Initialize();
	collisionSystem_.Initialize();
	renderSystem_.Initialize();
}

void Core::Finalize()
{
	toriD2D_.Finalize();
	sceneSystem_.Finalize();
	timeSystem_.Finalize();
	inputSystem_.Finalize();
	collisionSystem_.Finalize();
	renderSystem_.Finalize();

	delete &toriD2D_;
	delete &sceneSystem_;
	delete &timeSystem_;
	delete &inputSystem_;
	delete &collisionSystem_;
	delete &renderSystem_;
}

void Core::CycleOnce()
{
	timeSystem_.MeasureTime();

	PhysicsUpdate();
	Input();
	Update();
	Render();
}

void Core::PhysicsUpdate()
{
	collisionSystem_.CheckCollision();
}

void Core::Input()
{
	inputSystem_.AgingStatus();
	inputSystem_.CheckInput();
}

void Core::Update()
{
	sceneSystem_.GetNowScene()->Update();
}

void Core::Render()
{
	toriD2D_.BeginDraw();
	renderSystem_.Render(sceneSystem_.GetNowScene());
	toriD2D_.EndDraw();
}
