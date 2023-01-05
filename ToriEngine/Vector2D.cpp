#include "Vector2D.h"

#include <cmath>

Vector2D::Vector2D()
	:x(0), y(0)
{

}

Vector2D::Vector2D(float x, float y)
	:x(x), y(y)
{

}

Vector2D::~Vector2D()
{

}

void Vector2D::Normalize()
{
	float magnitude = this->Magnitude();

	if (magnitude <= 0)
	{
		return;
	}

	x /= magnitude;
	y /= magnitude;
}

float Vector2D::Magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

float Vector2D::DotProduct(const Vector2D& rhs) const
{
	return (x * rhs.x) + (y * rhs.y);
}

/// <summary>
/// 2차원 벡터의 외적
///	결과가 Vector3D지만 2차원의 외적은 (0, 0, x1y2 - y1x2) 이므로
/// 마지막 결과만 float으로 반환하도록 했음
/// 
/// 22.12.19 강석원 인재원
/// </summary>
/// <param name="rhs"></param>
/// <returns></returns>
float Vector2D::CrossProduct(const Vector2D& rhs) const
{
	return (x * rhs.y) - (y * rhs.x);
}
