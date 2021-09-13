#pragma once
#include "Vector2D.h"
#include "GameController.h"

/// class that implements functionality of virtual camera by changing positions of entities on screen
class CameraController
{
public:
	/// pointer to vector representing virtual movement of camera
	static Vector2D* cameraMovement;
	/// rectangle representing screen
	static SDL_Rect viewport;
	/// speed of camera movement if triggered
	static int cameraSpeed;

	CameraController();

	CameraController(int camSpeed);
	/// sets resolution of camera
	static void setResolution(int w, int h);
	/// updates logic
	static void update();
};
