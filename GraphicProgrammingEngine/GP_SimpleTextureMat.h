#pragma once
#include "GP_Material.h"

class GP_SimpleTextureMat : public GP_Material
{
public:
	virtual void Init(LPCWSTR _vertex, LPCWSTR _pixel) override;
	virtual void Render(GP_Object& _obj) override;
	virtual void DeInit() override;

	XMFLOAT3 AmbientColor = { 1,0,0};
	float AmbientStrength = 0.5f;
protected:
	ID3D11Buffer* vertexBuffer;
	struct MaterialVertexBuffer {
		XMFLOAT4X4 worldPosition;
		XMFLOAT4X4 wvp;
		XMFLOAT3 camPosition;
		float padding;
	};

	ID3D11Buffer* pixelBuffer;
	struct MaterialPixelBuffer {
		XMFLOAT3 ambient;
		float ambientStrength;
	};
};

