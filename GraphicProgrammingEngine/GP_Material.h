#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>

#include <DirectXMath.h>

#include "GP_Message.h"
#include "WICTextureLoader.h"

#pragma comment(lib, "d3dcompiler.lib")

using namespace DirectX;

class GP_Object;
class GP_Material
{
public:
	virtual void Init(LPCWSTR _vertex, LPCWSTR _pixel);
	virtual void Render(GP_Object& _obj);
	virtual void DeInit();

	void SetSamplerState();

	void SetTexture(LPCWSTR _name);

protected:
	void createVertexShader(LPCWSTR _name);
	void createPixelShader(LPCWSTR _name);
	void createInputLayout(ID3DBlob* _blob);

	void CreateBuffer(UINT _size, ID3D11Buffer** _buffer);

	template<typename T>
	void SetVertexBuffer(ID3D11Buffer* _buffer, UINT _bufferSlot, T& _bufferStruct, ID3D11DeviceContext* _context);

	template<typename T>
	void SetPixelBuffer(ID3D11Buffer* _buffer, UINT _bufferSlot, T& _bufferStruct, ID3D11DeviceContext* _context);

	ID3D11VertexShader* vertexShader;
	ID3D11PixelShader* pixelShader;

	ID3D11InputLayout* inputLayout;

	ID3D11Resource* texture;
	ID3D11ShaderResourceView* textureSRV;

	ID3D11SamplerState* samplerState;
};

template<typename T>
inline void GP_Material::SetVertexBuffer(ID3D11Buffer* _buffer, UINT _bufferSlot, T& _bufferStruct, ID3D11DeviceContext* _context) {
	D3D11_MAPPED_SUBRESOURCE data = {};
	HRESULT hr = _context->Map(_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &data);
	CheckFailed(hr, "GP_Material", 54, "Map Vertex Buffer failed");

	_bufferStruct = reinterpret_cast<T>(data.pData);

	_context->Unmap(_buffer, 0);
	_context->VSSetConstantBuffers(_bufferSlot, 1, &_buffer);
}

template<typename T>
inline void GP_Material::SetPixelBuffer(ID3D11Buffer* _buffer, UINT _bufferSlot, T& _bufferStruct, ID3D11DeviceContext* _context) {
	D3D11_MAPPED_SUBRESOURCE data = {};
	HRESULT hr = _context->Map(_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &data);
	CheckFailed(hr, "GP_Material", 66, "Map Pixel Buffer failed");

	_bufferStruct = reinterpret_cast<T>(data.pData);

	_context->Unmap(_buffer, 0);
	_context->PSSetConstantBuffers(_bufferSlot, 1, &_buffer);
}