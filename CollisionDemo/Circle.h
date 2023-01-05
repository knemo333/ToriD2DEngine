#pragma once
#include "Object.h"

class Circle : public Object
{
public:
	Circle(float centerX, float centerY, float radius);
	virtual ~Circle() {};

	virtual void Update() override;

	virtual void OnCollisionEnter() override;
	virtual void OnCollisionStay() override;
	virtual void OnCollisionExit() override;

	void SetRadius(float p_radius);
	float GetRadius();

	bool IsPlayer() const { return isPlayer_; }
	void SetPlayer(bool isPlayer);

private:
	float radius_;
	bool isPlayer_;
};

