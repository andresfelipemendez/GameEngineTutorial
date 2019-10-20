#pragma once
#include "Actor.h"

class Asteroid :
	public Actor
{
public:
	Asteroid(Game* game);
	~Asteroid();

	class CircleComponent* GetCircle() { return mCircle; }
private:
	class CircleComponent* mCircle;
};

