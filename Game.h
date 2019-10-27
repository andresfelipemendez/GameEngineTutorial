#pragma once

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <unordered_map>
#include <string>
#include <vector>
#include "Math.h"


class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	class Renderer* GetRenderer() { return mRenderer; };
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	std::vector<class Actor *> mActors;
	std::vector<class Actor*>mPendingActors;
	
	class Renderer* mRenderer;

	Uint32 mTicksCount;
	bool mIsRunning;
	bool mUpdatingActors;

	class CameraActor* mCameraActor;	
};

