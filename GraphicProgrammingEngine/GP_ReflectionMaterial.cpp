#include "GP_Core.h"
#include "GP_ReflectionMaterial.h"

void GP_ReflectionMaterial::Init(LPCWSTR _vertex, LPCWSTR _pixel)
{
	GP_Material::Init(_vertex, _pixel);

	CreateBuffer(sizeof(MaterialVertexBuffer), &vertexBuffer);
	CreateBuffer(sizeof(ReflectionBuffer), &reflectionBuffer);
	CreateBuffer(sizeof(MaterialPixelBuffer), &pixelBuffer);
}

void GP_ReflectionMaterial::Render(GP_Object& _obj)
{
	GP_Material::Render(_obj);

	MaterialVertexBuffer* vertex = {};
	SetVertexBuffer(vertexBuffer, 0, vertex, CORE_DEVICECONTEXT);
	XMStoreFloat4x4(&(vertex->worldPosition), XMMatrixTranspose(_obj.Transform->GetworldMatrix()));
	XMStoreFloat4x4(&(vertex->wvp), XMMatrixTranspose(_obj.Transform->GetworldMatrix() * CORE_MAINCAM->GetViewProjectionMatrix()));

	ReflectionBuffer* reflection = {};
	SetVertexBuffer(reflectionBuffer, 1, reflection, CORE_DEVICECONTEXT);

	MaterialPixelBuffer* pixel = {};
	SetPixelBuffer(pixelBuffer, 0, pixel, CORE_DEVICECONTEXT);
	pixel->ambient = AmbientColor;
	pixel->ambientStrength = AmbientStrength;

	CORE_DEVICECONTEXT->PSSetShaderResources(0, 1, &textureSRV);
	CORE_DEVICECONTEXT->PSSetSamplers(0, 1, &samplerState);
}

void GP_ReflectionMaterial::DeInit()
{
	GP_Material::DeInit();
}


