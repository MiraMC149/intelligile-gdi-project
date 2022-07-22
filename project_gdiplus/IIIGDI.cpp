#include "GWorld.h"
#include <windows.h>
#include <gdiplus.h>
#include <gdiplusheaders.h>

inline void drawLine(void* DC, GWorld::GPoint scaledPoints[2], GWorld::GColor pen, GWorld::GThickness thickness, GWorld::GColor* themeColor) {
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
		gf.DrawLine(&drawPen, scaledPoints[0].x, scaledPoints[0].y, scaledPoints[1].x, scaledPoints[1].y);
	}
}

inline void drawRectangle(void* DC, GWorld::GPoint scaledPoints[1], GWorld::GColor fill, GWorld::GColor pen, GWorld::GThickness thickness, GWorld::GColor* themeColor, int width, int height) {
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
		gf.FillRectangle(&brush, scaledPoints[0].x, scaledPoints[0].y, width, height);
		
	}
	if (pen != GWorld::NOCOLOR) {
		if (pen & GWorld::GINDEXEDCOLOR) {
			color = ((pen & GWorld::AlphaMask) << 1) | ((themeColor[pen & GWorld::COLORINDEXMASK]) & GWorld::RGBMASK);
		}
		else {
			color = ( (pen & GWorld::AlphaMask) << 1) | (pen & GWorld::RGBMASK) ;
		}

		Gdiplus::Pen drawPen(Gdiplus::Color(color), thickness);

		const Gdiplus::Rect rect(scaledPoints[0].x, scaledPoints[0].y, width, height);
		gf.DrawRectangle(&drawPen, rect);
	}
}

inline void drawEllipse(void* DC, GWorld::GPoint scaledPoints[1], GWorld::GColor fill, GWorld::GColor pen, GWorld::GStyle style, GWorld::GThickness thickness, GWorld::GColor* themeColor, int width, int height) {
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
		const Gdiplus::Rect rect(scaledPoints[0].x, scaledPoints[0].y, width, height);
		gf.FillEllipse(&brush, scaledPoints[0].x, scaledPoints[0].y, width, height);

	}

	if (pen != GWorld::NOCOLOR) {
		if (pen & GWorld::GINDEXEDCOLOR) {
			color = ((pen & GWorld::AlphaMask) << 1) | ((themeColor[pen & GWorld::COLORINDEXMASK]) & GWorld::RGBMASK);
		}
		else {
			color = ((pen & GWorld::AlphaMask) << 1) | (pen & GWorld::RGBMASK);
		}

		Gdiplus::Pen drawPen(Gdiplus::Color(color), thickness);

		gf.DrawEllipse(&drawPen, scaledPoints[0].x, scaledPoints[0].y, width, height);
	}
	
};