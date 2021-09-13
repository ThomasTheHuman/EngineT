#pragma once
#include <memory>
#include "SDL.h"
#include "Components.h"
#include "CameraController.h"
#include "ResourceManager.h"

class CameraController;
class ResourceManager;
class EntityManager;

/// base class controlling screen rendering and logic
class GameController
{
public:
	/// constructor
	/// @param title title of window
	/// @param xpos horizontal position of window
	/// @param ypos vertical position of window
	/// @param w width of window
	/// @param h height of window
	/// @param fullScreen if true, game is full screen
	GameController(const char* title,
		int xpos,
		int ypos,
		int w,
		int h,
		bool fullScreen);
	~GameController();		

	/// handles user input
	void handleEvents();
	/// updates logic
	void update();
	/// renders to screen
	void render();
	/// true if game is running @return {@link isRunning}
	bool running() const;
	/// pointer to SDL renderer
	static SDL_Renderer* renderer;
	/// current event from event queue
	static SDL_Event event;
	/// pointer to resource manager @link ResourceManager
	static ResourceManager* resourceManager;
	/// camera controller @link CameraController
	static CameraController cameraController;
	/// entity manager @link EntityManager
	static EntityManager entityManager;
private:
	/// changes to false when user clicks X on window bar
	bool isRunning;
	/// smart pointer to window to which game is rendered
	std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
};
