#pragma once

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
	virtual SCENE_ID getSceneID() const = 0;
	virtual void updateWindowData() = 0;
	virtual void drawWindowData() const = 0;

	virtual ~Scene() = 0;
};