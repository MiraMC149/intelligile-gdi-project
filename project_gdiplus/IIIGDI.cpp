#include "GWorld.h"
#include <windows.h>
#include <gdiplus.h>
#include <gdiplusheaders.h>

//(windowbased code)

void drawLine(void* DC, GWorld::GPoint* scaledPoint1, GWorld::GPoint* scaledPoint2, long n, GWorld::GColor pen, GWorld::GStyle style, GWorld::GThickness thickness, GWorld::GColor* themeColor) {
	HDC hdc = (HDC)DC;
	Gdiplus::ARGB color;
	Gdiplus::Graphics gf(hdc);
	if (pen != GWorld::NOCOLOR) {
		if (pen & GWorld::GINDEXEDCOLOR) {
			color = ((pen & GWorld::AlphaMask) << 1) | ((themeColor[pen & GWorld::COLORINDEXMASK]) & GWorld::RGBMASK);
		}
		else {
			color = ((pen & GWorld::AlphaMask) << 1) | (pen & GWorld::RGBMASK);
		}

		Gdiplus::Pen drawPen(Gdiplus::Color(color), thickness);
		gf.DrawLine(&drawPen, scaledPoint1->x, scaledPoint1->y, scaledPoint2->x, scaledPoint2->y );
	}
}

void drawRectangle(void* DC, GWorld::GPoint* scaledPoint, long n, GWorld::GColor fill, GWorld::GColor pen, GWorld::GStyle style, GWorld::GThickness thickness, GWorld::GColor* themeColor, int width, int height) {
	HDC hdc = (HDC)DC;
	Gdiplus::ARGB color;
	Gdiplus::Graphics gf(hdc);
	if (fill != GWorld::NOCOLOR) {
		if (fill & GWorld::GINDEXEDCOLOR) {
			color = ((fill & GWorld::AlphaMask) << 1) | ((themeColor[fill & GWorld::COLORINDEXMASK]) & GWorld::RGBMASK);
		}
		else {
			color = ((fill & GWorld::AlphaMask) << 1) | (fill & GWorld::RGBMASK);
		}

		Gdiplus::SolidBrush drawbrush(Gdiplus::Color(color)); //issue here
		Gdiplus::SolidBrush brush(Gdiplus::Color(255, 0, 255, 0));
		gf.FillRectangle(&brush, scaledPoint->x, scaledPoint->y, width, height);
		
	}
	if (pen != GWorld::NOCOLOR) {
		if (pen & GWorld::GINDEXEDCOLOR) {
			color = ((pen & GWorld::AlphaMask) << 1) | ((themeColor[pen & GWorld::COLORINDEXMASK]) & GWorld::RGBMASK);
		}
		else {
			color = ( (pen & GWorld::AlphaMask) << 1) | (pen & GWorld::RGBMASK) ;
		}

		Gdiplus::Pen drawPen(Gdiplus::Color(color), thickness);

		[in, ref] const Gdiplus::Rect rect(scaledPoint->x, scaledPoint->y, width, height);
		gf.DrawRectangle(&drawPen, rect);
	}
}

void drawEllipse(void* DC, GWorld::GPoint* scaledPoint, GWorld::GColor fill, GWorld::GColor pen, GWorld::GStyle style, GWorld::GThickness thickness, GWorld::GColor* themeColor, int width, int height) {
	HDC hdc = (HDC)DC;
	Gdiplus::ARGB color;
	Gdiplus::Graphics gf(hdc);
	if (fill != GWorld::NOCOLOR) {
		if (fill & GWorld::GINDEXEDCOLOR) {
			color = ((fill & GWorld::AlphaMask) << 1) | ((themeColor[fill & GWorld::COLORINDEXMASK]) & GWorld::RGBMASK);
		}
		else {
			color = ((fill & GWorld::AlphaMask) << 1) | (fill & GWorld::RGBMASK);
		}

		Gdiplus::SolidBrush drawbrush(Gdiplus::Color(color)); //issue here
		Gdiplus::SolidBrush brush(Gdiplus::Color(255, 0, 255, 0));
		[in, ref] const Gdiplus::Rect rect(scaledPoint->x, scaledPoint->y, width, height);
		gf.FillEllipse(&brush, scaledPoint->x, scaledPoint->y, width, height);

	}

	if (pen != GWorld::NOCOLOR) {
		if (pen & GWorld::GINDEXEDCOLOR) {
			color = ((pen & GWorld::AlphaMask) << 1) | ((themeColor[pen & GWorld::COLORINDEXMASK]) & GWorld::RGBMASK);
		}
		else {
			color = ((pen & GWorld::AlphaMask) << 1) | (pen & GWorld::RGBMASK);
		}

		Gdiplus::Pen drawPen(Gdiplus::Color(color), thickness);

		gf.DrawEllipse(&drawPen, scaledPoint->x, scaledPoint->y, width, height);
	}
	
};