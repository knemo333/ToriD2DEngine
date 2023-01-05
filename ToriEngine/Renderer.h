#pragma once
#include "Component.h"

class Object;

/// <summary>
/// 렌더링을 수행할 단위
/// D2D에게 그려달라고 요청한다
/// 
/// 22.12.28 강석원 인재원
/// </summary>
class Renderer : public Component
{
public:
	Renderer();
	virtual void Render() abstract;
	void SetRGBA(float r, float g, float b, float a);

protected:
	float r_;
	float g_;
	float b_;
	float a_;
};

