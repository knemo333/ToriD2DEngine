#include "ToriD2D.h"

#define _USE_MATH_DEFINES
#include <math.h>

ToriD2D::ToriD2D()
	:hWnd_(NULL), D2DFactory_(nullptr), renderTarget_(nullptr), windowRect_(RECT()),
	DWriteFactory_(nullptr),textFormat_(nullptr),
	nowR_(-1), nowG_(-1), nowB_(-1), nowA_(-1)
{

}

ToriD2D::~ToriD2D()
{
}

/// <summary>
/// Direct2D ������ �ʱ�ȭ �Լ�
/// ClientRect ������ �ް�,
/// Factory �����,
/// RenderTarget �����Ѵ�.
/// 
/// 2022.12.12 ������ ��
/// </summary>
/// <param name="_hWnd"></param>
void ToriD2D::Initialize(HWND _hWnd)
{
	hWnd_ = _hWnd;
	HRESULT hr = S_OK;

	GetClientRect(hWnd_, &windowRect_);

	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &D2DFactory_);
	if (SUCCEEDED(hr))
	{
		hr = CreateDeviceResources();
	}
	
	if (SUCCEEDED(hr))
	{
		// ���ڿ� ����� ���� Factory ��ü�� �����Ѵ�.
		hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(DWriteFactory_),
		reinterpret_cast<IUnknown**>(&DWriteFactory_));
	}

	if (SUCCEEDED(hr))
	{
		// Create a DirectWrite text format object.
		hr = DWriteFactory_->CreateTextFormat(
			L"Verdana",
			NULL,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			25,
			L"", //locale
			&textFormat_
		);
	}

	//if (SUCCEEDED(hr))
	//{
	//	// Center the text horizontally and vertically.
	//	TextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);

	//	TextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	//}

	//���ڿ� �� ����
	renderTarget_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f), &textBrush_);
	renderTarget_->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Green), &greenBrush_);
	renderTarget_->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Yellow), &yellowBrush_);
	renderTarget_->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &redBrush_);
}

void ToriD2D::Finalize()
{
	SafeRelease<ID2D1HwndRenderTarget>(&renderTarget_);
	SafeRelease<ID2D1Factory>(&D2DFactory_);
	SafeRelease<ID2D1SolidColorBrush>(&greenBrush_);
	SafeRelease<ID2D1SolidColorBrush>(&yellowBrush_);
	SafeRelease<ID2D1SolidColorBrush>(&redBrush_);
}

void ToriD2D::BeginDraw()
{
	renderTarget_->BeginDraw();
	renderTarget_->Clear(D2D1::ColorF(D2D1::ColorF::Black));
}

void ToriD2D::EndDraw()
{
	HRESULT hr;
	hr = renderTarget_->EndDraw();
}

/// <summary>
/// �簢���� �׸��� �Լ�
/// �簢���� �� �������� ��ǥ�� �޾Ƽ� D2D SetTransform�� Ȱ���� �׸���
/// 
/// 22.12.14 ������ �����
/// </summary>
void ToriD2D::DrawRectST(float left, float top, float right, float bottom, POINTFLOAT center, float radian, POINTFLOAT p_scale)
{
	HRESULT hr = S_OK;

	D2D1_RECT_F rectangle = D2D1::Rect(left, top, right, bottom);


	renderTarget_->DrawRectangle(
		rectangle,
		greenBrush_
		);

	D2D1_SIZE_F scale;
	scale.height = p_scale.y;
	scale.width = p_scale.x;

	renderTarget_->SetTransform(
		D2D1::Matrix3x2F::Scale(
			scale,
			D2D1::Point2F(center.x,center.y)) * 
		D2D1::Matrix3x2F::Rotation(
		(float)(radian * 180.0f / M_PI), 
		D2D1::Point2F(center.x, center.y))
	);
	
	renderTarget_->DrawRectangle(rectangle, yellowBrush_);

	renderTarget_->SetTransform(D2D1::Matrix3x2F::Identity());
}

/// <summary>
/// ���� �׸��� �Լ�
/// ���� ������ �� ������ �޾Ƽ� D2D SetTransform�� Ȱ���� �׸���
/// 
/// 22.12.14 ������ �����
/// </summary>
void ToriD2D::DrawCircleST(float radius, POINTFLOAT center, float radian, POINTFLOAT p_scale)
{
	HRESULT hr = S_OK;

	D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(center.x, center.y), radius, radius);

	renderTarget_->DrawEllipse(ellipse, greenBrush_);

	D2D1_SIZE_F scale;
	scale.height = p_scale.y;
	scale.width = p_scale.x;

	renderTarget_->SetTransform(
		D2D1::Matrix3x2F::Scale(
			scale,
			D2D1::Point2F(center.x, center.y)) *
		D2D1::Matrix3x2F::Rotation(
			(float)(radian * 180.0f / M_PI),
			D2D1::Point2F(center.x, center.y))
	);

	renderTarget_->DrawEllipse(ellipse, yellowBrush_);

	renderTarget_->SetTransform(D2D1::Matrix3x2F::Identity());
}

/// <summary>
/// ���� �׸��� �Լ�
/// ���� ������ ���� ������ �޾Ƽ� D2D SetTransform�� Ȱ���� �׸���
/// 
/// 22.12.14 ������ �����
/// </summary>
void ToriD2D::DrawLineST(POINTFLOAT start, POINTFLOAT end, POINTFLOAT center, float radian, POINTFLOAT p_scale)
{
	HRESULT hr = S_OK;

	renderTarget_->DrawLine(
		D2D1::Point2F(start.x, start.y),
		D2D1::Point2F(end.x, end.y),
		greenBrush_
	);

	D2D1_SIZE_F scale;
	scale.height = p_scale.y;
	scale.width = p_scale.x;

	renderTarget_->SetTransform(
		D2D1::Matrix3x2F::Scale(
			scale,
			D2D1::Point2F(center.x, center.y)) *
		D2D1::Matrix3x2F::Rotation(
			(float)(radian * 180.0f / M_PI),
			D2D1::Point2F(center.x, center.y))
	);

	renderTarget_->DrawLine(
		D2D1::Point2F(start.x, start.y),
		D2D1::Point2F(end.x, end.y),
		yellowBrush_
	);

	renderTarget_->SetTransform(D2D1::Matrix3x2F::Identity());
}

void ToriD2D::DrawCircle(float centerX, float centerY, float rotation, float scaleX, float scaleY, float radius, int colorCode)
{
	HRESULT hr = S_OK;

	D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(centerX, centerY), radius, radius);

	switch (colorCode)
	{
		case D2D1::ColorF::Green :
		{
			renderTarget_->DrawEllipse(ellipse, greenBrush_);
		}
		break;

		case D2D1::ColorF::Red :
		{
			renderTarget_->DrawEllipse(ellipse, redBrush_);
		}
		break;

		default:
			break;
	}

	//D2D1_SIZE_F scale;
	//scale.width = scaleX;
	//scale.height = scaleY;

	//RenderTarget_->SetTransform(
	//	D2D1::Matrix3x2F::Scale(
	//		scale,
	//		D2D1::Point2F(centerX, centerY)) *
	//	D2D1::Matrix3x2F::Rotation(
	//		(float)(rotation * 180.0f / M_PI),
	//		D2D1::Point2F(centerX, centerY))
	//);

	//RenderTarget_->DrawEllipse(ellipse, YellowBrush);

	//RenderTarget_->SetTransform(D2D1::Matrix3x2F::Identity());
}

void ToriD2D::DrawCircle(float centerX, float centerY, float rotation, float scaleX, float scaleY, float radius)
{
	HRESULT hr = S_OK;

	D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(centerX, centerY), radius, radius);

	renderTarget_->DrawEllipse(ellipse, nowBrush_);
}

void ToriD2D::DrawText2D(const WCHAR* str, float left, float top)
{
	renderTarget_->DrawTextW(str, lstrlen(str), textFormat_,
		D2D1::RectF(left, top, renderTarget_->GetSize().width, renderTarget_->GetSize().height), textBrush_);
}

void ToriD2D::DrawText2D(const WCHAR* str, float left, float top, float right, float bottom)
{
	renderTarget_->DrawTextW(str, lstrlen(str), textFormat_,
		D2D1::RectF(left, top, right, bottom), textBrush_);
}

void ToriD2D::SetBrushColor(float r, float g, float b, float a)
{
	if (nowR_ == r && nowG_ == g && nowB_ == b && nowA_ == a)
	{
		return;
	}

	SafeRelease(&nowBrush_);

	renderTarget_->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF(r, g, b, a)), &nowBrush_);
}

/// <summary>
/// Direct2D RenderTarget�� �����ϴ� �Լ�
/// 
/// 2022.12.11 ������ ��
/// </summary>
HRESULT ToriD2D::CreateDeviceResources()
{
	HRESULT hr = S_OK;

	hr = D2DFactory_->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			hWnd_,
			D2D1::SizeU(
				windowRect_.right - windowRect_.left,
				windowRect_.bottom - windowRect_.top),
			D2D1_PRESENT_OPTIONS_IMMEDIATELY
		),
		&renderTarget_
	);
	return hr;
}
