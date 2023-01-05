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
/// 2���� ������ ����
///	����� Vector3D���� 2������ ������ (0, 0, x1y2 - y1x2) �̹Ƿ�
/// ������ ����� float���� ��ȯ�ϵ��� ����
/// 
/// 22.12.19 ������ �����
/// </summary>
/// <param name="rhs"></param>
/// <returns></returns>
float Vector2D::CrossProduct(const Vector2D& rhs) const
{
	return (x * rhs.y) - (y * rhs.x);
}
