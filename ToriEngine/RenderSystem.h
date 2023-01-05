#pragma once

#include <vector>
#include <map>

#include <windows.h>
#include <string>

class Renderer;
class Scene;

/// <summary>
/// Render클래스들을 실행시킬 System 클래스
///
/// 
/// 22.12.27 강석원 인재원
/// </summary>
class RenderSystem
{
public:
	~RenderSystem() {};

	static RenderSystem& Instance()
	{
		static RenderSystem* instance = new RenderSystem();
		return *instance;
	}

	void Initialize();
	void Finalize();

	void Render(Scene* nowScene);

	void AddList(Scene* nowScene, Renderer* const val);



	void PrintDebug(std::string _content)
	{
		std::wstring wsConverted = L"";
		wsConverted.assign(_content.begin(), _content.end());
		OutputDebugString(wsConverted.c_str());
	}

	void PrintDebug(double _content)
	{
		std::wstring tmpConverted = std::to_wstring(_content);
		OutputDebugString(tmpConverted.c_str());
	}

private:
	RenderSystem();
	std::map<Scene*, std::vector<Renderer*>> renderList_;
};

