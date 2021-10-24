#include "GameController.h"
#include <memory>

SDL_Event GameController::event;

SDL_Renderer* GameController::renderer(nullptr);

ResourceManager* GameController::resourceManager(new ResourceManager);

CameraController GameController::cameraController(2);

EntityManager GameController::entityManager;

GameController::GameController(const char* title, int xpos, int ypos, int w, int h, bool fullScreen)
	: window(nullptr, SDL_DestroyWindow)
{
	CameraController::setResolution(w, h);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
	SDL_SetHint(SDL_HINT_RENDER_DRIVER, "metal");
	SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
	int flags = 0;
	if (fullScreen) { flags = SDL_WINDOW_FULLSCREEN; }
	SDL_Init(SDL_INIT_EVERYTHING);
	window.reset(SDL_CreateWindow(title, xpos, ypos, w, h, flags));
	renderer = SDL_CreateRenderer(window.get(), -1, 0);
	SDL_SetRenderDrawColor(renderer, 52, 32, 43, 255);
	SDL_RenderSetScale(renderer, 2, 2);
	//SDL_RenderSetLogicalSize(renderer, w/2, h/2);
	isRunning = true;
}

GameController::~GameController()
{
	SDL_Quit();
}

void GameController::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void GameController::update()
{
	CameraController::update();
	entityManager.update();
}

void GameController::render()
{
    SDL_SetRenderDrawColor(renderer, 52, 32, 43, 255);
	SDL_RenderClear(renderer);
	entityManager.render();
	SDL_RenderPresent(renderer);
}

bool GameController::running() const
{
	return isRunning;
}






