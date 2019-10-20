#pragma once


#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <vector>

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;
	bool mIsRunning;
	bool mUpdatingActors;
	std::vector<class Actor*>mPendingActors;
	std::vector<class Actor*>mActors;
};

