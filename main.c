
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <OleAuto.h>
//#define GDIPVER 0x0110
#include "RawGdiplus.h"
#define _USE_MATH_DEFINES
#include <math.h>

// 使用时别忘了，仍然需要链接 Gdiplus.lib 库。
#pragma comment(lib, "Gdiplus")
#pragma comment(linker, "/ENTRY:mainCRTStartup")

// 声明镜像基址变量
EXTERN_C struct HINSTANCE__ __ImageBase;
// 主窗口消息函数
INT_PTR CALLBACK MainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// 定义主对话框模板
const struct MainDLGTEMPLATE
{
	DLGTEMPLATE dlg;
	WCHAR cls, menu, title;
} DT = { WS_OVERLAPPEDWINDOW, WS_EX_APPWINDOW, 0, MININT16, MININT16, 180, 240, };

int main()
{
	return DialogBoxIndirect(&__ImageBase, &DT.dlg, HWND_DESKTOP, MainProc);
}

INT_PTR CALLBACK MainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static ULONG_PTR token;
	static GpSolidFill *pSFB;
	static GpPen *pPen;
	static GpBitmap *pBmpMem;
	static GpImageAttributes *pImgAttr;
	static GpMatrix *pMat;
	static UINT uWidth, uHeight;

	GpStatus state;

	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		GpGraphics *pGrap;
		GpBitmap *pBmpFile;
#if (GDIPVER >= 0x0110)
		// 开始使用 Raw GDI+ 1.1
		GdiplusStartupInputEx gsi = { 2, };
		state = GdiplusStartup(&token, &gsi.StartupInput, NULL);
#else
		// 开始使用 Raw GDI+ 1.0
		GdiplusStartupInput gsi = { 1, };
		state = GdiplusStartup(&token, &gsi, NULL);
#endif //(GDIPVER >= 0x0110) 
		// 创建纯色填充画刷（初始为蓝色）
		state = GdipCreateSolidFill(GpColorBlue, &pSFB);
		// 创建纯色画笔（初始为红色，粗细为3像素）
		state = GdipCreatePen1(GpColorRed, 3, GpUnitPixel, &pPen);
		// 从文件创建位图
		state = GdipCreateBitmapFromFile(L"tree.png", &pBmpFile);
		// 获取图片宽度
		state = GdipGetImageWidth(pBmpFile, &uWidth);
		// 获取图片高度
		state = GdipGetImageHeight(pBmpFile, &uHeight);
		// 创建位图内存副本（并转换为32为预乘Alpha格式，提高绘图速度，同时也避免重复读取文件）
		state = GdipCreateBitmapFromScan0(uWidth, uHeight, 0, GpPixelFormat32bppPARGB, NULL, &pBmpMem);
		state = GdipGetImageGraphicsContext(pBmpMem, &pGrap);
		state = GdipSetCompositingMode(pGrap, GpCompositingModeSourceCopy);
		state = GdipDrawImageI(pGrap, pBmpFile, 0, 0);
		state = GdipDeleteGraphics(pGrap);
		// 释放位图文件
		state = GdipDisposeImage(pBmpFile);
		// 创建图形变换矩阵
		state = GdipCreateMatrix(&pMat);
		// 创建图像属性
		state = GdipCreateImageAttributes(&pImgAttr);
	}
		break;
	case WM_DESTROY:
		// 释放图像属性
		state = GdipDisposeImageAttributes(pImgAttr);
		// 删除图形变换矩阵
		state = GdipDeleteMatrix(pMat);
		// 释放位图图像
		state = GdipDisposeImage(pBmpMem);
		// 删除画笔
		state = GdipDeletePen(pPen);
		// 删除画刷
		state = GdipDeleteBrush(pSFB);
		// 停止使用 Raw GDI+
		GdiplusShutdown(token);
		break;
	case WM_CLOSE:
		// 结束对话框（并返回成功退出码）
		return EndDialog(hWnd, EXIT_SUCCESS);
	case WM_PAINT:
	{
		static const float angle = 48.381f * (float)M_PI / 180.f;
		static const int rcx = -90, rcy = -248;

		PAINTSTRUCT ps;
		GpGraphics *pGrap;
		// 颜色矩阵定义为红绿蓝三通道置0，透明度为40%，实现图像阴影模拟。
		const GpColorMatrix cMat = { {
			{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, },
			{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, },
			{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, },
			{ 0.0f, 0.0f, 0.0f, 0.4f, 0.0f, },
			{ 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, },
		} };
		// 开始绘制
		BeginPaint(hWnd, &ps);
		// 创建基于 HDC 的 Raw GDI+ 画布
		state = GdipCreateFromHDC(ps.hdc, &pGrap);
#if (GDIPVER >= 0x0110)
		// 设置抗锯齿模式（1.1 能支持8*8抗锯齿级别）
		state = GdipSetSmoothingMode(pGrap, GpSmoothingModeAntiAlias8x8);
#else
		// 设置抗锯齿模式（1.0 只支持8*4抗锯齿级别）
		state = GdipSetSmoothingMode(pGrap, GpSmoothingModeAntiAlias);
#endif //(GDIPVER >= 0x0110) 
		// 填充矩区域形到画布
		state = GdipFillRectangle(pGrap, pSFB, 30.5f, 40.5f, 200, 120);
		// 绘制椭圆边框到画布
		state = GdipDrawEllipse(pGrap, pPen, 20.5f, 180.5f, 220, 140);
		// 初始设置为单位矩阵
		state = GdipSetMatrixElements(pMat, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
		// 缩放变换矩阵
		state = GdipScaleMatrix(pMat, 1.0f, cosf(angle), GpMatrixOrderAppend);
		// 斜切变换矩阵
		state = GdipShearMatrix(pMat, -tanf(angle), 0, GpMatrixOrderAppend);
		// 平移变换矩阵
		state = GdipTranslateMatrix(pMat, 100, 280, GpMatrixOrderAppend);
		// 设置世界变换矩阵
		state = GdipSetWorldTransform(pGrap, pMat);
		// 设置颜色变换矩阵
		state = GdipSetImageAttributesColorMatrix(pImgAttr, GpColorAdjustTypeDefault, TRUE, &cMat, NULL, GpColorMatrixFlagsDefault);
		// 绘图阴影图
		state = GdipDrawImageRectRectI(pGrap, pBmpMem, rcx, rcy, uWidth, uHeight, 0, 0, uWidth, uHeight, GpUnitPixel, pImgAttr, NULL, NULL);
		// 重置世界变换矩阵
		state = GdipResetWorldTransform(pGrap);
		// 绘制原图
		state = GdipDrawImageI(pGrap, pBmpMem, 96 + rcx, 280 + rcy);
		// 删除画布
		state = GdipDeleteGraphics(pGrap);
		// 结束绘制
		EndPaint(hWnd, &ps);
	}
		break;
	default:
		return FALSE;
	}
	return TRUE;
}
