#include <windows.h>
#include <gdiplus.h>
#include <gdiplusheaders.h>

// repair a view.  shoould be in view.cpp
void draw(HDC hdc) {
	Gdiplus::Graphics gf(hdc);
	Gdiplus::Pen pen(Gdiplus::Color(255, 255, 0, 0));               // For lines, rectangles and curves
	Gdiplus::SolidBrush brush(Gdiplus::Color(255, 0, 255, 0));      // For filled shapes

	gf.DrawLine(&pen, 0, 0, 500, 500);
	gf.FillRectangle(&brush, 320, 200, 100, 100);
	gf.DrawRectangle(&pen, 600, 400, 100, 150);

	Gdiplus::Bitmap bmp(L"water_small.png");
	gf.DrawImage(&bmp, 430, 10);

	gf.FillEllipse(&brush, 50, 400, 200, 100);
}