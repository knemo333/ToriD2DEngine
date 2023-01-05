#include "Object.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "SceneSystem.h"
#include "Collider.h"
#include "Renderer.h"

/// <summary>
/// 생성자

/// 22.12.14 강석원 인재원
/// </summary>
Object::Object()
	: Object(0.0f, 0.0f)
{
}

Object::Object(float centerX, float centerY)
	: centerPosition_(Vector2D(centerX, centerY)), rotation_(0.0f), scale_(Vector2D(1, 1))
{
}

Object::~Object()
{
	//delete collider_;
}

/// <summary>
/// 이동
/// 덧셈
/// 
/// 22.12.14 강석원 집
/// </summary>
/// <param name="deltaVector"></param>
void Object::Translate(float dX, float dY)
{
	centerPosition_.x += dX;
	centerPosition_.y += dY;
}

/// <summary>
/// 회전(라디안)
/// 덧셈
/// (-2*π ~ 2*π) 범위 유지하도록 함
/// 
/// 22.12.14 강석원 집
/// </summary>
/// <param name="deltaRadian"></param>
void Object::Rotate(float deltaRadian)
{
	rotation_ += deltaRadian;

	while (rotation_ <= -(M_PI * 2) || M_PI * 2 <= rotation_)
	{
		if (rotation_ >= M_PI * 2)
		{
			rotation_ -= (float)(M_PI * 2);
		}
		else if (rotation_ <= -(M_PI * 2))
		{
			rotation_ += (float)(M_PI * 2);
		}
	}
}

/// <summary>
/// 확대 축소
/// 곱셈
/// 
/// 22.12.14 강석원 집
/// </summary>
/// <param name="deltaScale"></param>
void Object::Scale(float dX, float dY)
{
	scale_.x += dX;
	scale_.y += dY;
}

Vector2D Object::GetCenterPos() const
{
	return centerPosition_;
}

float Object::GetRotation() const
{
	return rotation_;
}

Vector2D Object::GetScale() const
{
	return scale_;
}

void Object::SetCenterPos(Vector2D newCenter)
{
	centerPosition_ = newCenter;
}

void Object::SetRotation(float newRotation)
{
	rotation_ = newRotation;
}

void Object::SetScale(Vector2D newScale)
{
	scale_ = newScale;
}
