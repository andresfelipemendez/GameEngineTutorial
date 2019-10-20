#pragma once
#include "MoveComponent.h"
#include <cstdint>

class InputComponent : public MoveComponent
{
public:
	InputComponent(class Actor* owner);

	void ProcessInput(const uint8_t* keyState) override;

	float GetMaxForward() const { return mMaxForwardSpeed; }
	float GetMaxAngular() const { return mMaxAngularSpeed; }
	int GetForwardKey() const { return mForwardKey; }
	int GetBackKey() const { return mBackKey; }
	int GetClockWiseKey() const { return mClockWiseKey; }
	int GetCounterClockWiseKey() const { return mCounterClockWiseKey; }

	void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }
	void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }
	void SetForwardKey(int key) { mForwardKey = key; }
	void SetBackKey(int key) { mBackKey = key; }
	void SetClockWiseKey(int key) { mClockWiseKey = key; }
	void SetCounterClockWiseKey(int key) { mCounterClockWiseKey = key; }

private:
	float mMaxForwardSpeed;
	float mMaxAngularSpeed;

	int mForwardKey;
	int mBackKey;

	int mClockWiseKey;
	int mCounterClockWiseKey;
};

