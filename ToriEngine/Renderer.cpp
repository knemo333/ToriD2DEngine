#include "Renderer.h"
#include "RenderSystem.h"
#include "SceneSystem.h"

Renderer::Renderer()
	:r_(0.0f), g_(0.0f), b_(0.0f), a_(0.0f)
{
	RenderSystem::Instance().AddList(SceneSystem::Instance().GetNowScene(), this);
}

void Renderer::SetRGBA(float r, float g, float b, float a)
{
	r_ = r;
	g_ = g;
	b_ = b;
	a_ = a;
}

