#include <windows.h>
#include <string>

#include "Circle.h"
#include "InputSystem.h"
#include "TimeSystem.h"

#include "CircleRenderer.h"

#include "d2d1.h"

#define SPEED 100

Circle::Circle(float centerX, float centerY, float radius)
	: Object(centerX, centerY), radius_(radius), isPlayer_(false)
{
}

void Circle::Update()
{
	if (isPlayer_)
	{
		float dX = 0;
		float dY = 0;

		if (InputSystem::GetKeyHold(VK_LEFT))
		{
			dX = -SPEED * (float)TimeSystem::GetDeltaTime();
		}

		if (InputSystem::GetKeyHold(VK_RIGHT))
		{
			dX = SPEED * (float)TimeSystem::GetDeltaTime();
		}

		if (InputSystem::GetKeyHold(VK_UP))
		{
			dY = -SPEED * (float)TimeSystem::GetDeltaTime();
		}

		if (InputSystem::GetKeyHold(VK_DOWN))
		{
			dY = SPEED * (float)TimeSystem::GetDeltaTime();
		}

		Translate(dX, dY);
	}
}

//void Circle::Render()
//{
//	ToriD2D::Instance().DrawCircle(
//		centerPosition_.x,
//		centerPosition_.y,
//		rotation_,
//		scale_.x,
//		scale_.y,
//		radius_,
//		color_);
//
//	WCHAR dt[128];
//	WCHAR fr[128];
//
//	swprintf_s(dt, L"%f", (float)TimeSystem::GetDeltaTime());
//	swprintf_s(fr, L"%f", (float)TimeSystem::GetFrameRate());
//
//	ToriD2D::Instance().DrawText2D(dt, 0, 0);
//	ToriD2D::Instance().DrawText2D(fr, 0, 50);
//}

void Circle::OnCollisionEnter()
{
	GetComponent<CircleRenderer>()->SetRGBA(255, 0, 0, 255);
}

void Circle::OnCollisionStay()
{
	GetComponent<CircleRenderer>()->SetRGBA(255, 0, 0, 255);
}

void Circle::OnCollisionExit()
{
	GetComponent<CircleRenderer>()->SetRGBA(0, 255, 0, 255);
}

void Circle::SetRadius(float p_radius)
{
	radius_ = p_radius;
}

float Circle::GetRadius()
{
	return radius_;
}

void Circle::SetPlayer(bool isPlayer)
{
	isPlayer_ = isPlayer;
}

