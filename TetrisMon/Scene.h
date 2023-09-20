#pragma once

/// <summary>
/// All possible scenes
/// </summary>
enum SCENE_ID
{
	TITLE,
	TETRIS,
	GAME_OVER
};

/// <summary>
/// Abstract class to be inherited by the game scenes
/// </summary>
class Scene {
public:
	virtual SCENE_ID GetSceneID() const = 0;
	/// <summary>
	/// Function used by WndProc to update the scene data
	/// </summary>
	virtual void UpdateWindowData() = 0;
	/// <summary>
	/// Function used by the DrawingTimer to redraw the scene
	/// and inside WndProc when the event WM_PAINT triggers
	/// </summary>
	virtual void DrawScene() const = 0;

	virtual ~Scene() = 0;
};