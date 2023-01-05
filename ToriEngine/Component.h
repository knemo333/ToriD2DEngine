#pragma once

class Object;

/// <summary>
/// ������Ʈ ���̽� Ŭ����
/// �����Ҷ� ������ componentID_�� ComponentID enum ���� �ʱ�ȭ ������Ѵ�.
/// 
/// 22.12.21 ������ �����
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



