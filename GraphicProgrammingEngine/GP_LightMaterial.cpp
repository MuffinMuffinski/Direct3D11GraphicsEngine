#include "GP_Core.h"
#include "GP_LightMaterial.h"

void GP_LightMaterial::Init(LPCWSTR _vertex, LPCWSTR _pixel)
{
	GP_Material::Init(_vertex, _pixel);

	CreateBuffer(sizeof(MaterialVertexBuffer), &vertexBuffer);
	CreateBuffer(sizeof(MaterialPixelBuffer), &pixelBuffer);
}

void GP_LightMaterial::Render(GP_Object& _obj)
{
	GP_Material::Render(_obj);

	MaterialVertexBuffer* vertex = {};
	SetVertexBuffer(vertexBuffer, 0, vertex, CORE_DEVICECONTEXT);
	XMStoreFloat4x4(&(vertex->worldPosition), XMMatrixTranspose(_obj.Transform->GetworldMatrix()));
	XMStoreFloat4x4(&(vertex->wvp), XMMatrixTranspose(_obj.Transform->GetworldMatrix() * CORE_MAINCAM->GetViewProjectionMatrix()));
	vertex->camPosition = CORE_MAINCAM->Transform->GetPosition();

	MaterialPixelBuffer* pixel = {};
	SetPixelBuffer(pixelBuffer, 0, pixel, CORE_DEVICECONTEXT);
	pixel->dirLight = *directionalLight;


	CORE_DEVICECONTEXT->PSSetShaderResources(0, 1, &textureSRV);
	CORE_DEVICECONTEXT->PSSetShaderResources(1, 1, &normalTextureSRV);
	CORE_DEVICECONTEXT->PSSetSamplers(0, 1, &samplerState);
}

void GP_LightMaterial::DeInit()
{
	GP_Material::DeInit();
}

void GP_LightMaterial::SetNormalTexture(LPCWSTR _name)
{
	
		HRESULT hr = CreateWICTextureFromFile(CORE_DEVICE, _name, &normalTexture, &normalTextureSRV);
		CheckFailed(hr, "GP_Material", 37, "Create Texture from File failed");
		//error Check
	
}
