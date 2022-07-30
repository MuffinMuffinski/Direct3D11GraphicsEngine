#include "GP_Transform.h"

void GP_Transform::Init()
{
	translationMat = XMMatrixIdentity();
	rotationMat    = XMMatrixIdentity();
	scalingMat     = XMMatrixIdentity();

	UpdateWordMatrix();
}

void GP_Transform::Update()
{
	if (dirty) 
	{
		UpdateWordMatrix();
		dirty = false;
	}
}

void GP_Transform::AddDirection(XMFLOAT3 _dir)
{
	position.x += _dir.x;
	position.y += _dir.y;
	position.z += _dir.z;
}

void GP_Transform::AddDirection(XMVECTOR _dir)
{
	XMFLOAT3 dir;
	XMStoreFloat3(&dir, _dir);
	position.x += dir.x;
	position.y += dir.y;
	position.z += dir.z;
}

void GP_Transform::UpdateWordMatrix()
{
	translationMat = XMMatrixTranslation(position.x, position.y, position.z);

	rotationMat = XMMatrixRotationRollPitchYaw(
		XMConvertToRadians(eulerAngle.x),
		XMConvertToRadians(eulerAngle.y),
		XMConvertToRadians(eulerAngle.z)
	);

	scalingMat = XMMatrixScaling(scale.x, scale.y, scale.z);

	worldMat = scalingMat * rotationMat * translationMat;
}
