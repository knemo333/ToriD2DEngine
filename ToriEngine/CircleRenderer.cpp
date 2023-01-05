#include "CircleRenderer.h"
#include "ToriD2D.h"
#include "Object.h"

CircleRenderer::CircleRenderer()
	: radius_(0.0f)
{

}

CircleRenderer::CircleRenderer(float radius)
	:radius_(radius)
{

}

void CircleRenderer::Render()
{
	ToriD2D::Instance().SetBrushColor(r_, g_, b_, a_);

	ToriD2D::Instance().DrawCircle(
		object_->GetCenterPos().x,
		object_->GetCenterPos().y,
		object_->GetRotation(),
		object_->GetScale().x,
		object_->GetScale().y,
		radius_);
}

