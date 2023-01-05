#include "TimeSystem.h"

double TimeSystem::deltaTime_ = 0;
float TimeSystem::frameRate_ = 0;

TimeSystem::TimeSystem()
	:frequency_(LARGE_INTEGER()),
	startTick_(LARGE_INTEGER()),
	endTick_(LARGE_INTEGER()),
	elipseTick_(0.0)
{

}

/// TimeSystem �ʱ�ȭ
/// 22.12.18 ������ ��
void TimeSystem::Initialize()
{
	QueryPerformanceFrequency(&frequency_);
	QueryPerformanceCounter(&startTick_);	// �ʱ� ���� ��
}

void TimeSystem::Finalize()
{

}

/// �� �����ӿ� �ɸ� �ð� ���� �� ��ŸŸ�� ���
/// 22.12.18 ������ ��
void TimeSystem::MeasureTime()
{
	QueryPerformanceCounter(&endTick_);

	elipseTick_ = (double)(endTick_.QuadPart - startTick_.QuadPart) /
		(double)(frequency_.QuadPart);
	deltaTime_ = elipseTick_;// *1000;	// 1000�� ���ϸ� ms ���� �Ȱ��ϸ� s����
	if (deltaTime_ != 0)
	{
		frameRate_ = 1 / deltaTime_;	// �ʴ� ������
	}

	QueryPerformanceCounter(&startTick_);
}

