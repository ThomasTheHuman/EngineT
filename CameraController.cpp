﻿#include "CameraController.h"

Vector2D* CameraController::cameraMovement(nullptr);
SDL_Rect CameraController::viewport;
int CameraController::cameraSpeed(1);

CameraController::CameraController()
{
	cameraSpeed = 1;
	
	cameraMovement = new Vector2D;
	viewport.x = viewport.y = 0;
}

CameraController::CameraController(const int camSpeed)
{
	cameraSpeed = camSpeed;
	
	cameraMovement = new Vector2D;
	viewport.x = viewport.y = 0;
}

void CameraController::setResolution(int w, int h)
{
	viewport.w = w/2;
	viewport.h = h/2;
}

void CameraController::update()
{
	const auto playerPosition = GameController::entityManager.getGroup(5)[0]->getComponent<TransformComponent>().position;

	if(playerPosition.x < viewport.w/4)
	{
		cameraMovement->x = cameraSpeed;
	} else if(playerPosition.x > 3*viewport.w/4)
	{
		cameraMovement->x = -cameraSpeed;
	} else if((int)playerPosition.x == (int)viewport.w/2)
	{
		cameraMovement->x = 0;
	}

	if (playerPosition.y < viewport.h / 4)
	{
		cameraMovement->y = cameraSpeed;
	}
	else if (playerPosition.y > 3 * viewport.h / 4)
	{
		cameraMovement->y = -cameraSpeed;
	}
	else if ((int)playerPosition.y == (int)viewport.h / 2)
	{
		cameraMovement->y = 0;
	}
	
	viewport.x -= cameraMovement->x;
	viewport.y -= cameraMovement->y;
}
