#include "CC.h"
#include "Vector2D.h"

bool DetectCircleCollision(Vector2D center1, float radius1, Vector2D center2, float radius2)
{
	float dx = center2.x - center1.x;
	float dy = center2.y - center1.y;
	float dr = radius1 + radius2;

	return dx * dx + dy * dy <= dr * dr;
}
