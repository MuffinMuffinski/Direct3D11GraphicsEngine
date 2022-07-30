#include "GP_Material.h"
#pragma once
class GP_ReflectionMaterial : public GP_Material
{
public:
	virtual void Init(LPCWSTR _vertex, LPCWSTR _pixel) override;
	virtual void Render(GP_Object& _obj) override;
	virtual void DeInit() override;


	XMFLOAT3 AmbientColor = { 1,1,1 };
	float AmbientStrength = 0.5f;

protected:
	ID3D11Buffer* vertexBuffer;
	struct MaterialVertexBuffer {
		XMFLOAT4X4 worldPosition;
		XMFLOAT4X4 wvp;
		XMFLOAT4X4 worldMatrix;
	};

	ID3D11Buffer* reflectionBuffer;
	struct ReflectionBuffer
	{
		XMFLOAT4X4 reflectionMatrix;
	};
	
	ID3D11Buffer* pixelBuffer;
	struct MaterialPixelBuffer {
		XMFLOAT3 ambient;
		float ambientStrength;
	};
};

