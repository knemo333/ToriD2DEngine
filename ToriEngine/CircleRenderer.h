#pragma once
#include "Renderer.h"

class CircleRenderer : public Renderer
{
public:
	CircleRenderer();
	CircleRenderer(float radius);

	virtual void Render() override;

private:
	float radius_;		// �̰� ������Ʈ�� ��� ��������?
};

