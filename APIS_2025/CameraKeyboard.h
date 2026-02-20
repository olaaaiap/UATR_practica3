#pragma once
#include "Camera.h"

class CameraKeyboard : public Camera
{
	void step(float timeStep) override;
};

