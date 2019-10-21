#include "InputComponent.h"
#include "Actor.h"

InputComponent::InputComponent(Actor* owner)
	:MoveComponent(owner)
	,mForwardKey(0)
	,mBackKey(0)
	,mClockWiseKey(0)
	,mCounterClockWiseKey(0)
{
}

void InputComponent::ProcessInput(const uint8_t* keyState)
{
	float forwardSpeed = 0.0f;
	if (keyState[mForwardKey]) {
		forwardSpeed -= mMaxForwardSpeed;
	}

	if (keyState[mBackKey])
	{
		forwardSpeed += mMaxForwardSpeed;
	}
	SetForwardSpeed(forwardSpeed);

	float angularSpeed = 0.0f;
	if (keyState[mClockWiseKey])
	{
		angularSpeed -= mMaxAngularSpeed;
	}
	if (keyState[mCounterClockWiseKey])
	{
		angularSpeed += mMaxAngularSpeed;
	}
	SetAngularSpeed(angularSpeed);
}
