#include <Windows.h>
#include <gdiplus.h>

#include "Scene.h"

#pragma once

using WND_UPDATE_CALLBACK = void (*)();

const HWND                hWnd;
const MSG                 msg;
const WNDCLASS            wndClass;
const Gdiplus::GdiplusStartupInput gdiplusStartupInput;
const ULONG_PTR           gdiplusToken;
const UINT_PTR TIMER_ID = 1;

Scene* currentScene;

/// <summary>
/// Initialize the main window and all the necessary
/// resources to load the game
/// </summary>
void initGame();

/// <summary>
/// Calls the current scene's update function
/// </summary>
void updateWindowData();

/// <summary>
/// Calls the current scene's draw function
/// </summary>
void drawWindow();