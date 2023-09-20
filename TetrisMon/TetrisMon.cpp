#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <string>
#include "GameWindow.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
    GameWindow::InitGame();

    if (GameWindow::should_shutdown)
}