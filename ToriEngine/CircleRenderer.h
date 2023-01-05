#pragma once
#include "Renderer.h"

class CircleRenderer : public Renderer
{
public:
	CircleRenderer();
	CircleRenderer(float radius);

	virtual void Render() override;

private:
	float radius_;		// 이거 오브젝트랑 어떻게 연결하지?
};

