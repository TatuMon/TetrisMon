#include <Windows.h>
#include <gdiplus.h>

#include "Scene.h"

#pragma once

namespace GameWindow {
	bool should_shutdown;
	bool is_paused;

	/// <summary>
	/// Holds the current event of the game loop
	/// </summary>
	MSG msg;

	/// <summary>
	/// Handler of the main window process
	/// </summary>
	HWND hWnd;

	/// <summary>
	/// Class of the main window process
	/// </summary>
	WNDCLASS wndClass;

	/// <summary>
	/// Pointer that holds the token of the game's GDI+ process.
	/// It's later used to shutdown GDI+
	/// </summary>
	ULONG_PTR gdiplusToken;

	/// <summary>
	/// ID of the game's timer
	/// </summary>
	const UINT_PTR timer_id = 1;

	/// <summary>
	/// Pointer of the current assigned scene
	/// </summary>
	std::unique_ptr<Scene> current_scene;

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	VOID DrawingTimerCallback(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

	/// <summary>
	/// Initialize the main window and all the necessary
	/// resources to load the game
	/// </summary>
	void InitGame();

	void SetCurrentScene(SCENE_ID scene_id);

	/// <summary>
	/// Kills the timer and shutsdown GDI+
	/// </summary>
	void Shutdown();

	/// <summary>
	/// Calls the current scene's update function
	/// </summary>
	void UpdateWindowData();

	/// <summary>
	/// Calls the current scene's draw function
	/// </summary>
	void DrawWindow();
}