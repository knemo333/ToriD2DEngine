#pragma once
#include <windows.h>
#include <map>

/// 입력 상태를 나타내는 enum class
enum class InputStatus
{
	JUSTUP,
	JUSTDOWN,
	HOLD,
	UP
};

/// 입력을 저장하는 단위
/// keyID를 정수형으로 갖고있고
/// 이전상태 현재상태를 저장한다.
/// 
/// 22.12.18 강석원 집
struct InputUnit
{
	int keyID = -1;
	bool prevStatus = false;	// bit연산으로 바꾸고싶다
	bool nowStatus = false;
};

/// 입력의 상태를 바로 알 수 있도록 고안한 배열
/// 첫번째 인덱스로 이전 상태
/// 두번째 인덱스로 현재 상태를 넣으면
/// 해당 상태가 어떤 상태인지 알려준다.
/// 
/// 22.12.18 강석원 집
static const int inputStatus[2][2] = {
	(const int)InputStatus::UP,
	(const int)InputStatus::JUSTDOWN,
	(const int)InputStatus::JUSTUP,
	(const int)InputStatus::HOLD,
};

/// 입력을 관리하는 클래스
/// 입력을 InputUnit이라는 단위로 map 자료구조로 관리
/// 
/// 22.12.18 강석원 집
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

#pragma region 사용자가 받을 키 상태정보
	static bool GetKeyUp(int keyCode);
	static bool GetKeyJustDown(int keyCode);
	static bool GetKeyJustUp(int keyCode);
	static bool GetKeyHold(int keyCode);
#pragma endregion 사용자가 받을 키 상태

private:
	InputSystem();

	static std::map<int, InputUnit*> inputMap_;

};

