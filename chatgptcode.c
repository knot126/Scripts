/**
 * Compile with:
 * 
 * C:/Users/User/bin/llvm-mingw-20220323-ucrt-aarch64/llvm-mingw-20220323-ucrt-aarch64/bin/clang.exe -o wt.exe chatgptcode.c -luser32 -lgdi32
 */

#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // window class initialization
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.lpszClassName = TEXT("MyAppClass");
    if (!RegisterClass(&wc))
        return 1;

    // window creation
    HWND hwnd = CreateWindow(
        TEXT("MyAppClass"),
        TEXT("My Window"),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        640,
        480,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (!hwnd)
        return 1;

    // message loop
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        int width = 640;
        int height = 480;
        int bytesPerPixel = 3;

        unsigned char* pixelData = (unsigned char*)malloc(width * height * bytesPerPixel);
		
		for (int i = 0; i < width * height; i++) {
			pixelData[i * 3] = i;
		}
		
        if (pixelData == NULL)
        {
            // handle error
        }

        // populate pixelData array here

        BITMAPINFOHEADER psHeaderGlobal = {0};
        psHeaderGlobal.biSize = sizeof(BITMAPINFOHEADER);
        psHeaderGlobal.biWidth = width;
        psHeaderGlobal.biHeight = height;
        psHeaderGlobal.biPlanes = 1;
        psHeaderGlobal.biBitCount = bytesPerPixel * 8;

        BITMAPINFOHEADER* psHeader = &psHeaderGlobal;
        void* pPixels = (void*)pixelData;

        SetDIBitsToDevice(hdc, 0, 0, width, height, 0, 0, 0, height, pPixels, (BITMAPINFO*)psHeader, DIB_RGB_COLORS);

        EndPaint(hwnd, &ps);

        free(pixelData);

        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}
