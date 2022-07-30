#pragma once
#include "GP_Material.h"
#include "GP_DirectionLight.h"

class GP_LightMaterial : public GP_Material
{
public:
	virtual void Init(LPCWSTR _vertex, LPCWSTR _pixel) override;
	virtual void Render(GP_Object& _obj) override;
	virtual void DeInit() override;

	std::shared_ptr<GP_DirectionLight> directionalLight;

	void SetNormalTexture(LPCWSTR _name);

protected:
	ID3D11Buffer* vertexBuffer;
	struct MaterialVertexBuffer {
		XMFLOAT4X4 worldPosition;
		XMFLOAT4X4 wvp;
		XMFLOAT3 camPosition;
		float padding;
	};

	ID3D11Resource* normalTexture;
	ID3D11ShaderResourceView* normalTextureSRV;

	ID3D11Buffer* pixelBuffer;
	struct MaterialPixelBuffer {
		GP_DirectionLight dirLight;
	};
};

