#include <windows.h>
#include <gdiplus.h>
#include <gdiplusheaders.h>

LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam);
void draw(HDC hdc);

int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE previousInstance, PSTR cmdLine, INT cmdCount) {
	// Initialize GDI+
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

	// Register the window class
	const char* CLASS_NAME = "myWin32WindowClass";
	WNDCLASS wc{};
	wc.hInstance = currentInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProcessMessages;
	RegisterClass(&wc);

	// Create the window
	CreateWindow(CLASS_NAME, "Win32 Drawing with GDI+ Tutorial",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,            // Window style
		CW_USEDEFAULT, CW_USEDEFAULT,                // Window initial position
		800, 600,                                    // Window size
		nullptr, nullptr, nullptr, nullptr);

	// Window loop
	MSG msg{};
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	Gdiplus::GdiplusShutdown(gdiplusToken);
	return 0;
}

LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam) {
	HDC hdc;
	PAINTSTRUCT ps;

	switch (msg) {
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		draw(hdc);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, param, lparam);
	}
}








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

	/*FontFamily  fontFamily(L"Times New Roman");
	Font        font(&fontFamily, 24, FontStyleRegular, UnitPixel);
	PointF      pointF(30.0f, 10.0f);
	SolidBrush  solidBrush(Color(255, 0, 0, 255));

	graphics.DrawString(L"Hello", -1, &font, pointF, &solidBrush);*/
}

//IIIGDI.cpp (windowbased code)

void drawLine(void* DC, GWorld::GPoint* scaledPoints, long n, GWorld::GColor pen, GWorld::GStyle style, GWorld::GThickness thickness) {
	HDC hdc = (HDC)DC;
	ARGB color;
	Gdiplus::Graphics gf(hdc);
	if (pen != GWorld::NOCOLOR) {
		if (pen & GWorld::GINDEXEDCOLOR) {
			color = ((pen & GWorld::AlphaMask) << 1) | ((themeColor[pen & GWorld::COLORINDEXMASK]) & GWorld::RGBMASK);
		}
		else {
			color = ((pen & GWorld::AlphaMask) << 1) | (pen & GWorld::RGBMASK)
		}

		Gdiplus::Pen drawPen(Gdiplus::Color(color));
		gf.DrawLine(&drawpen, );
	}
}


void drawRectangle() {
	HDC hdc = (HDC)DC;
	ARGB color;
	Gdiplus::Graphics gf(hdc); 
	if (fill != GWorld::NOCOLOR) {
		if (fill & GWorld::GINDEXEDCOLOR) {
			color = ((fill & GWorld::AlphaMask) << 1) | ((themeColor[fill & GWorld::COLORINDEXMASK]) & GWorld::RGBMASK);
		}
		else {
			color = ((fill & GWorld::AlphaMask) << 1) | (fill & GWorld::RGBMASK)
		}

		Gdiplus::SolidBrush brush(Gdiplus::Color(color));
		gf.DrawRectangle();
	}
	if (pen != GWorld::NOCOLOR) {
		if (pen & GWorld::GINDEXEDCOLOR) {
			color = ((pen & GWorld::AlphaMask) << 1) | ((themeColor[pen & GWorld::COLORINDEXMASK]) & GWorld::RGBMASK);
		}
		else {
			color = ((pen & GWorld::AlphaMask) << 1) | (pen & GWorld::RGBMASK)
		}

		Gdiplus::Pen drawPen(Gdiplus::Color(color));
		gf.DrawRectangle(&drawpen, );
	}
}

void drawEllipse();