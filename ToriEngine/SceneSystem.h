#pragma once
#include <list>
#include <string>

class Scene;

/// <summary>
/// ���� �����ϰ� �����ڷ� �̸��� �ٿ� ����
/// 
/// 2022.12.13 ������ ��
/// </summary>
class SceneSystem
{
public:
	~SceneSystem();

	// �̱���
	static SceneSystem& Instance()
	{
		static SceneSystem* instance = new SceneSystem();
		return *instance;
	}

	void Initialize();							// SceneManager�� �ʱ�ȭ
	void Finalize();

	Scene& CreateScene(std::string sceneName);	// ���ο� Scene�� �����ϰ� �̸��� �ο��մϴ�.
	Scene* GetNowScene() const;						// ���� Scene�� �ּҸ� ��ȯ�մϴ�.
	void SetNowScene(std::string sceneName);	// ���� Scene�� ���ڷ� �Ѿ�� �̸��� Scene���� �����մϴ�.

private:
	SceneSystem();
	Scene* nowScene_;				// ���� Scene

	std::list<Scene*> sceneList_;	// Scene List
};

