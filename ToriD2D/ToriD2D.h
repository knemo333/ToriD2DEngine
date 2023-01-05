#pragma once
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "Dwrite")

#include "d2d1.h"
#include "dwrite.h"
#include <string>

/// <summary>
/// D2D ������ Ŭ����
/// 
/// 2022.12.13 ������ ��
/// </summary>
class ToriD2D
{
public:
	~ToriD2D();

	static ToriD2D& Instance()
	{
		static ToriD2D* instance = new ToriD2D();
		return *instance;
	}

	void Initialize(HWND _hWnd);	// hWnd�� ���޹޾� D2D�� �ʱ�ȭ
	void Finalize();

	void BeginDraw();				// �������� �����ϱ����� ȣ���Ͽ� BeginDraw()�� Clear()�� ȣ��
	void EndDraw();					// �������� ������ ȣ���Ͽ� EndDraw()�� ȣ��

	static void babo() {}

#pragma region PrimitiveDrawWithSetTransformInD2D
	void DrawRectST(float left, float top, float right, float bottom, POINTFLOAT center, float radian, POINTFLOAT p_scale);
	void DrawCircleST(float radius, POINTFLOAT center, float radian, POINTFLOAT p_scale);
	void DrawLineST(POINTFLOAT start, POINTFLOAT end, POINTFLOAT center, float radian, POINTFLOAT p_scale);
#pragma endregion PrimitiveDrawWithSetTransformInD2D

#pragma region PrimitiveDraw
	void DrawCircle(float centerX, float centerY, float rotation, float scaleX, float scaleY, float radius, int colorCode);
	void DrawCircle(float centerX, float centerY, float rotation, float scaleX, float scaleY, float radius);
	void DrawText2D(const WCHAR* str,  float left, float top);
	void DrawText2D(const WCHAR* str, float left, float top, float right, float bottom);
#pragma endregion PrimitiveDraw

#pragma region NowBrush
	void SetBrushColor(float r, float g, float b, float a);
#pragma endregion NowBrush

private:
	ToriD2D();

	HWND hWnd_;
	ID2D1Factory* D2DFactory_;
	ID2D1HwndRenderTarget* renderTarget_;
	IDWriteFactory* DWriteFactory_;
	IDWriteTextFormat* textFormat_;

	ID2D1SolidColorBrush* nowBrush_ = nullptr;
	ID2D1SolidColorBrush* textBrush_ = nullptr;
	ID2D1SolidColorBrush* greenBrush_ = nullptr;
	ID2D1SolidColorBrush* yellowBrush_ = nullptr;
	ID2D1SolidColorBrush* redBrush_ = nullptr;

	float nowR_;
	float nowG_;
	float nowB_;
	float nowA_;

	RECT windowRect_;

	HRESULT CreateDeviceResources();

	template <class T> void SafeRelease(T** ppT);
};

template<class T>
inline void ToriD2D::SafeRelease(T** ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}
