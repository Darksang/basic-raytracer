#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	// Register Window Class
	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = L"RAYTRACER";

	RegisterClass(&wc);

	// Create Window
	HWND window = CreateWindowEx(
		0,
		L"RAYTRACER",
		L"Basic Raytracer",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		0,
		0,
		hInstance,
		0);

	if (window == 0)
		return -1;

	// Make window visible
	ShowWindow(window, nCmdShow);

	MSG msg = {};
	HDC hdc = {};
	COLORREF test_color = RGB(255, 0, 0);

	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		hdc = GetDC(window);

		SetPixel(hdc, 400, 300, test_color);
		SetPixel(hdc, 401, 300, test_color);
		SetPixel(hdc, 402, 300, test_color);
		SetPixel(hdc, 403, 300, test_color);
		SetPixel(hdc, 404, 300, test_color);

		SetPixel(hdc, 400, 301, test_color);
		SetPixel(hdc, 400, 302, test_color);
		SetPixel(hdc, 400, 303, test_color);
		SetPixel(hdc, 400, 304, test_color);

		ReleaseDC(window, hdc);
	}

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hwnd, &ps);

				FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

				EndPaint(hwnd, &ps);
			}

			return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}