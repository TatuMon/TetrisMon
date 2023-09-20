#pragma once
#include "Scene.h"

/// <summary>
/// See the Scene class to read the functions documentations
/// </summary>
class GameOverScene : public Scene {
public:
	SCENE_ID GetSceneID();
	void UpdateWindowData();
	void DrawScene();
private:
	const SCENE_ID scene_id = GAME_OVER;
};