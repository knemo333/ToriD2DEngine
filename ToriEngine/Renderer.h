#pragma once
#include "Component.h"

class Object;

/// <summary>
/// �������� ������ ����
/// D2D���� �׷��޶�� ��û�Ѵ�
/// 
/// 22.12.28 ������ �����
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

