#pragma once

class Object;

/// <summary>
/// 컴포넌트 베이스 클래스
/// 생성할때 무조건 componentID_를 ComponentID enum 으로 초기화 해줘야한다.
/// 
/// 22.12.21 강석원 인재원
/// </summary>
class Component
{
public:

	virtual void foo() {};

	void Enable()
	{
		isEnable = true;
	}

	void Disable()
	{
		isEnable = false;
	}

	void SetObject(Object* object);
	Object* GetObj() const;

protected:
	Object* object_;
	bool isEnable;
};



