#include "InputSystem.h"

std::map<int, InputUnit*> InputSystem::inputMap_;

InputSystem::InputSystem()
{
	inputMap_.clear();
}

InputSystem::~InputSystem()
{

}

/// InputSystem에서 관리할 입력 키값을 map에 미리 등록한다.
/// 22.12.18 강석원 집
void InputSystem::Initialize()
{
	InputUnit* left = new InputUnit;
	left->keyID = VK_LEFT;
	inputMap_.insert(std::make_pair(VK_LEFT, left));

	InputUnit* up = new InputUnit;
	up->keyID = VK_UP;
	inputMap_.insert(std::make_pair(VK_UP, up));

	InputUnit* right = new InputUnit;
	right->keyID = VK_RIGHT;
	inputMap_.insert(std::make_pair(VK_RIGHT, right));

	InputUnit* down = new InputUnit;
	down->keyID = VK_DOWN;
	inputMap_.insert(std::make_pair(VK_DOWN, down));
}

void InputSystem::Finalize()
{
	for (std::pair<int, InputUnit*> unit : inputMap_)
	{
		delete unit.second;
	}
}

/// 이전 프레임의 상태를 이전 상태로 옮긴다.
/// 22.12.18 강석원 집
void InputSystem::AgingStatus()
{
	for (std::pair<int, InputUnit*> inputUnit : inputMap_)
	{
		inputUnit.second->prevStatus = inputUnit.second->nowStatus;
		inputUnit.second->nowStatus = false;
	}
}

/// Input을 입력받아서 상태를 저장한다.
/// 22.12.18 강석원 집
void InputSystem::CheckInput()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		inputMap_[VK_LEFT]->nowStatus = true;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		inputMap_[VK_UP]->nowStatus = true;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{
		inputMap_[VK_RIGHT]->nowStatus = true;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		inputMap_[VK_DOWN]->nowStatus = true;
	}
}

bool InputSystem::GetKeyUp(int keyCode)
{
	return (const int)InputStatus::UP == inputStatus[inputMap_[keyCode]->prevStatus][inputMap_[keyCode]->nowStatus];
}

bool InputSystem::GetKeyJustDown(int keyCode)
{
	return (const int)InputStatus::JUSTDOWN == inputStatus[inputMap_[keyCode]->prevStatus][inputMap_[keyCode]->nowStatus];
}

bool InputSystem::GetKeyJustUp(int keyCode)
{
	return (const int)InputStatus::JUSTUP == inputStatus[inputMap_[keyCode]->prevStatus][inputMap_[keyCode]->nowStatus];
}

bool InputSystem::GetKeyHold(int keyCode)
{
	return (const int)InputStatus::HOLD == inputStatus[inputMap_[keyCode]->prevStatus][inputMap_[keyCode]->nowStatus];
}

