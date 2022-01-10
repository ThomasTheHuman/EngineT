#pragma once
#include "Vector2D.h"
#include "GameController.h"

class CameraController
{
public:
	static Vector2D* cameraMovement;
	static SDL_Rect viewport;
	static int cameraSpeed;

	CameraController();

	CameraController(int camSpeed);
	static void setResolution(int w, int h);
	static void update();
};
