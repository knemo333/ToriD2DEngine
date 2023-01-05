#pragma once
#include <windows.h>
#include <map>

/// �Է� ���¸� ��Ÿ���� enum class
enum class InputStatus
{
	JUSTUP,
	JUSTDOWN,
	HOLD,
	UP
};

/// �Է��� �����ϴ� ����
/// keyID�� ���������� �����ְ�
/// �������� ������¸� �����Ѵ�.
/// 
/// 22.12.18 ������ ��
struct InputUnit
{
	int keyID = -1;
	bool prevStatus = false;	// bit�������� �ٲٰ�ʹ�
	bool nowStatus = false;
};

/// �Է��� ���¸� �ٷ� �� �� �ֵ��� ����� �迭
/// ù��° �ε����� ���� ����
/// �ι�° �ε����� ���� ���¸� ������
/// �ش� ���°� � �������� �˷��ش�.
/// 
/// 22.12.18 ������ ��
static const int inputStatus[2][2] = {
	(const int)InputStatus::UP,
	(const int)InputStatus::JUSTDOWN,
	(const int)InputStatus::JUSTUP,
	(const int)InputStatus::HOLD,
};

/// �Է��� �����ϴ� Ŭ����
/// �Է��� InputUnit�̶�� ������ map �ڷᱸ���� ����
/// 
/// 22.12.18 ������ ��
class InputSystem
{
public:
	~InputSystem();

	static InputSystem& Instance()
	{
		static InputSystem* instance = new InputSystem();
		return *instance;
	}

	void Initialize();
	void Finalize();
	void AgingStatus();
	void CheckInput();

#pragma region ����ڰ� ���� Ű ��������
	static bool GetKeyUp(int keyCode);
	static bool GetKeyJustDown(int keyCode);
	static bool GetKeyJustUp(int keyCode);
	static bool GetKeyHold(int keyCode);
#pragma endregion ����ڰ� ���� Ű ����

private:
	InputSystem();

	static std::map<int, InputUnit*> inputMap_;

};

