#pragma once
#include <vector>
#include "Math.h"
#include <cstdint>

class Actor
{
public:
	enum State {
		EActive,
		EPaused,
		EDead
	};

	Actor(class Game* game);
	virtual ~Actor();

	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	virtual void UpdateActor(float deltaTime);

	void ProcessInput(const uint8_t* keyState);
	virtual void ActorInput(const uint8_t* keyState);

	const Vector3& GetPosition() const { return mPosition; }
	void SetPosition(const Vector3& pos) { 
		mPosition = pos; 
		mRecomputeWorldTransform = true;
	}
	
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }

	const Quaternion& GetRotation() const { return mRotation; }
	void SetRotation(const Quaternion& rotation) { 
		mRotation = rotation; 
		mRecomputeWorldTransform = true;
	}
	
	void ComputeWorldTransform();
	const Matrix4& GetWorldTransform() const { return mWorldTransform; }

	Vector3 GetForward() const {
		return Vector3::Transform(Vector3::UnitX, mRotation);
	}

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	class Game* GetGame() { return mGame; }

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

private:
	State mState;

	Matrix4 mWorldTransform;
	Vector3 mPosition;
	Quaternion mRotation;
	float mScale;
	bool mRecomputeWorldTransform;

	std::vector<class Component*> mComponents;
	class Game* mGame;

};

