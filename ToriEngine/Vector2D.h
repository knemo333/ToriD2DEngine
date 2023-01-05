#pragma once

/// <summary>
/// ������ 2���� ���� Ŭ����
/// x,y �� ���� float���� ����� ũ�⸦ ��Ÿ����.
/// 
/// 22.12.19 ������ �����
/// </summary>
class Vector2D
{
public:
	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);
	~Vector2D();
	
	void Normalize();
	float Magnitude() const;
	float DotProduct(const Vector2D& rhs) const;
	float CrossProduct(const Vector2D& rhs) const;	// ����� Vector3D���� 2������ ������ (0, 0, x1y2 - y1x2) �̹Ƿ�
														// ������ ����� ��ȯ�ϵ��� �ߴ�.

	Vector2D operator+(const Vector2D& rhs) const
	{
		return Vector2D(x + rhs.x, y + rhs.y);
	}

	Vector2D operator-(const Vector2D& rhs) const
	{
		return Vector2D(x - rhs.x, y - rhs.y);
	}

	Vector2D operator*(const Vector2D& rhs) const
	{
		return Vector2D(x * rhs.x, y * rhs.y);
	}

	Vector2D& operator+=(const Vector2D& rhs)
	{
		(*this) = (*this) + rhs;
		return (*this);
	}
	
	Vector2D& operator-=(const Vector2D& rhs)
	{
		(*this) = (*this) - rhs;
		return (*this);
	}

	bool operator==(const Vector2D& rhs) const
	{
		return (x == rhs.x) && (y == rhs.y);
	}
};
