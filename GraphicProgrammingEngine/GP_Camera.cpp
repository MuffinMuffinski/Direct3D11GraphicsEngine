#include "GP_Core.h"
#include "GP_Camera.h"

void GP_Camera::Init(INT _width, INT _height)
{
	Transform = std::make_unique<GP_Transform>();
	Transform->Init();

	width = _width;
	height = _height;
}

void GP_Camera::Update()
{
#pragma region Camera Input

	keyboard.Reset();
	auto key = Keyboard::Get().GetState();
	keyboard.Update(key);

	float speed = 5.0f * CORE_DELTATIME;

	if (key.W)
	{
		Transform->AddDirection(localForward * speed);
	}

	if (key.A)
	{
		Transform->AddDirection(localLeft * speed);
	}
	if (key.S)
	{
		Transform->AddDirection(localBackward * speed);
	}
	if (key.D)
	{
		Transform->AddDirection(localRight * speed);
	}

	XMFLOAT3 tempEuler = Transform->GetEulerAngle();
	speed *= 0.2f;

	if (key.Up)
	{
		tempEuler.x -= speed;
	}
	if (key.Down)
	{
		tempEuler.x += speed;
	}
	if (key.Left)
	{
		tempEuler.y -= speed;
	}
	if (key.Right)
	{
		tempEuler.y += speed;
	}

	Transform->SetEulerAngle(tempEuler);

#pragma endregion

	XMMATRIX rotationMatrix = XMMatrixRotationRollPitchYaw(Transform->GetEulerAngle().x, Transform->GetEulerAngle().y, Transform->GetEulerAngle().z);
	camTarget = XMVector3TransformCoord(XMVectorSet(0, 0, 1, 0), rotationMatrix);
	camTarget += XMLoadFloat3(&Transform->GetPosition());

	XMVECTOR upDir = XMVector3TransformCoord(XMVectorSet(0, 1, 0, 0), rotationMatrix);
	view = XMMatrixLookAtLH(XMLoadFloat3(&Transform->GetPosition()), camTarget, upDir);

	//for free look camera
	XMMATRIX localRotationMatrix = XMMatrixRotationRollPitchYaw(Transform->GetEulerAngle().x, Transform->GetEulerAngle().y, 0);
	localForward = XMVector3TransformCoord(dForward, localRotationMatrix);
	localBackward = XMVector3TransformCoord(dBackward, localRotationMatrix);
	localRight = XMVector3TransformCoord(dRight, localRotationMatrix);
	localLeft = XMVector3TransformCoord(dLeft, localRotationMatrix);

	projection = XMMatrixPerspectiveFovLH(
		XM_PI * 0.33333333f, // field of view
		static_cast<float>(width) / static_cast<float>(height), // Aspect Ratio
		nearPlane, farPlane // near & far clipping plane
	);

	viewProjection = view * projection;

	Transform->Update();
}
