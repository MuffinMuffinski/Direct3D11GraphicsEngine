#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class GP_DirectionLight
{
public:
	
	XMFLOAT3 m_direction;
	float specularStrength;
	XMFLOAT3 m_color;
	float m_intensity;
	
};

