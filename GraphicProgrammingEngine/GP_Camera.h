#pragma once
#include <memory>
#include <d3d11.h>
#include <DirectXMath.h>
#include <Keyboard.h>

#include "GP_Message.h"
#include "GP_Transform.h"


class GP_Camera
{
public:
	void Init(INT _width, INT _height);
	void Update();

	std::unique_ptr<GP_Transform> Transform;

	XMMATRIX GetViewProjectionMatrix() { return viewProjection; }
private:
	XMMATRIX view = {};
	XMMATRIX projection = {};
	XMMATRIX viewProjection = {};

	INT width;
	INT height;

	float nearPlane = 0.3f;
	//Orientation for skybox placing / render distance
	float farPlane = 1000.0f;

	XMVECTOR camTarget;

	XMVECTOR dForward  = XMVectorSet(0, 0,  1, 0);
	XMVECTOR dBackward = XMVectorSet(0, 0, -1, 0);
	XMVECTOR dRight    = XMVectorSet( 1, 0, 0, 0);
	XMVECTOR dLeft     = XMVectorSet(-1, 0, 0, 0);
	XMVECTOR dUp       = XMVectorSet(0,  1, 0, 0);
	XMVECTOR dDown     = XMVectorSet(0, -1, 0, 0);

	XMVECTOR localForward;
	XMVECTOR localBackward;
	XMVECTOR localRight;
	XMVECTOR localLeft;

	DirectX::Keyboard::KeyboardStateTracker keyboard;
};

