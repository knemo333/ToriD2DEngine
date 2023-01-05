#include "RenderSystem.h"
#include "Scene.h"
#include "Renderer.h"

void RenderSystem::Initialize()
{
	renderList_.clear();
}

void RenderSystem::Finalize()
{

}

void RenderSystem::Render(Scene* nowScene)
{
	for (auto render : renderList_[nowScene])
	{
		render->Render();
	}
}

void RenderSystem::AddList(Scene* nowScene, Renderer* const val)
{
	renderList_[nowScene].push_back(val);
}

RenderSystem::RenderSystem()
{

}
