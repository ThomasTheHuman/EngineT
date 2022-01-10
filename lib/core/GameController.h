#pragma once
#include <memory>
#include "SDL.h"
#include "../components/Components.h"
#include "CameraController.h"
#include "ResourceManager.h"

class CameraController;
class ResourceManager;
class EntityManager;

class GameController
{
public:

	GameController(const char* title,
		int xpos,
		int ypos,
		int w,
		int h,
		bool fullScreen);
	~GameController();		

	void handleEvents();
	void update();
	void render();
	bool running() const;
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static ResourceManager* resourceManager;
	static CameraController cameraController;
	static EntityManager entityManager;
private:
	bool isRunning;
	std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
};
