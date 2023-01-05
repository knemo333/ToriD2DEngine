#pragma once

#include <windows.h>

/// <summary>
/// ������ ������ ���� ������ Ŭ����
/// 
/// 22.12.18 ������ ��
/// </summary>
class TimeSystem 
{
public:
	~TimeSystem() {};

	// �̱���
	static TimeSystem& Instance()
	{
		static TimeSystem* instance = new TimeSystem();
		return *instance;
	}

	void Initialize();
	void Finalize();
	void MeasureTime();

	static double GetDeltaTime() { return deltaTime_; }
	static float GetFrameRate() { return frameRate_; }

private:
	TimeSystem();

	LARGE_INTEGER frequency_;
	LARGE_INTEGER startTick_;
	LARGE_INTEGER endTick_;

	double elipseTick_;
	static double deltaTime_;
	static float frameRate_;
};

