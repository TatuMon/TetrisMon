#include <memory>
#include "GameWindow.h"
#include "Scene.h"
#include "AllScenes.h"

namespace GameWindow {

    void InitGame() {
        Gdiplus::GdiplusStartupInput gdiplusStartupInput;

        GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

        wndClass.style = CS_HREDRAW | CS_VREDRAW;
        wndClass.lpfnWndProc = WndProc;
        wndClass.cbClsExtra = 0;
        wndClass.cbWndExtra = 0;
        wndClass.hInstance = hInstance;
        wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
        wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
        wndClass.lpszMenuName = NULL;
        wndClass.lpszClassName = TEXT("TetrisMon");

        RegisterClass(&wndClass);

        hWnd = CreateWindow(
            TEXT("TetrisMon"),   // window class name
            TEXT("TetrisMon"),  // window caption
            WS_OVERLAPPEDWINDOW,      // window style
            CW_USEDEFAULT,            // initial x position
            CW_USEDEFAULT,            // initial y position
            CW_USEDEFAULT,            // initial x size
            CW_USEDEFAULT,            // initial y size
            NULL,                     // parent window handle
            NULL,                     // window menu handle
            hInstance,                // program instance handle
            NULL);                    // creation parameters

        ShowWindow(hWnd, iCmdShow);
        UpdateWindow(hWnd);

        SetCurrentScene(TITLE);

        SetTimer(hWnd, timer_id, 16, DrawingTimerCallback);

        while (GetMessage(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void SetCurrentScene(SCENE_ID scene_id) {
        switch (scene_id)
        {
        case TITLE:
            current_scene = std::make_unique<TitleScene>();
            break;
        case TETRIS:
            current_scene = std::make_unique<TetrisScene>();
            break;
        case GAME_OVER:
            current_scene = std::make_unique<GameOverScene>();
            break;
        default:
            /// Return to title screen if a wrong scene id is provided
            current_scene = std::make_unique<TitleScene>();
            break;
        }
    }

    void Shutdown() {
        KillTimer(hWnd, timer_id);
        Gdiplus::GdiplusShutdown(gdiplusToken);
    }

    void UpdateWindowData() {

    }

    void DrawWindow() {

    }

    LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
        WPARAM wParam, LPARAM lParam)
    {
        HDC          hdc;
        PAINTSTRUCT  ps;

        switch (message)
        {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);

            current_scene->DrawScene();

            EndPaint(hWnd, &ps);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    } // WndProc

    VOID CALLBACK DrawingTimerCallback(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
    {
        current_scene->DrawScene();
    }
}