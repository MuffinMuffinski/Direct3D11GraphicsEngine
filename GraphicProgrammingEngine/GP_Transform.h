#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class GP_Transform
{
public:
	void Init();
	void Update();

	void SetPosition(float _x, float _y, float _z) { position = { _x,_y,_z }; dirty = true; }
	void SetPosition(XMFLOAT3 _pos) { position = _pos; dirty = true; }

	void AddDirection(XMFLOAT3 _dir);
	void AddDirection(XMVECTOR _dir);

	XMFLOAT3 GetPosition() { return position; }

	void SetEulerAngle(float _x, float _y, float _z) { eulerAngle = { _x,_y, _z }; dirty = true; }
	void SetEulerAngle(XMFLOAT3 _euler) { eulerAngle = _euler; dirty = true; }

	XMFLOAT3 GetEulerAngle() { return eulerAngle; }

	void SetScale(float _x, float _y, float _z) { scale = { _x,_y,_z }; dirty = true; }
	void SetScale(XMFLOAT3 _scale) { scale = _scale; dirty = true; }

	XMFLOAT3 GetScale() { return scale; }

	XMMATRIX GetworldMatrix() { return worldMat; }
	XMMATRIX GetRotationMatrix() { return rotationMat; }

private:
	XMFLOAT3 position = {0,0,0};
	XMFLOAT3 eulerAngle = {0,0,0};
	XMFLOAT3 scale = {1,1,1};

	XMMATRIX worldMat;
	XMMATRIX translationMat;
	XMMATRIX rotationMat;
	XMMATRIX scalingMat;

	bool dirty = false;

	void UpdateWordMatrix();
};

