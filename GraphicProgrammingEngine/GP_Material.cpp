#include "GP_Core.h"
#include "GP_Material.h"

void GP_Material::Init(LPCWSTR _vertex, LPCWSTR _pixel)
{
	createVertexShader(_vertex);
	createPixelShader(_pixel);
}

void GP_Material::Render(GP_Object& _obj)
{
	CORE_DEVICECONTEXT->IASetInputLayout(inputLayout);
	CORE_DEVICECONTEXT->VSSetShader(vertexShader, nullptr, 0);
	CORE_DEVICECONTEXT->PSSetShader(pixelShader, nullptr, 0);
}

void GP_Material::DeInit()
{
}

void GP_Material::SetSamplerState()
{
	D3D11_SAMPLER_DESC sampdesc;
	ZeroMemory(&sampdesc, sizeof(sampdesc));
	sampdesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	sampdesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sampdesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	sampdesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

	HRESULT hr = CORE_DEVICE->CreateSamplerState(&sampdesc, &samplerState);
	CheckFailed(hr, "GP_Material", 31, "Create Sampler State failed");
}

void GP_Material::SetTexture(LPCWSTR _name)
{
	HRESULT hr = CreateWICTextureFromFile(CORE_DEVICE, _name, &texture, &textureSRV);
	CheckFailed(hr, "GP_Material", 37, "Create Texture from File failed");
	//error Check
}

void GP_Material::createVertexShader(LPCWSTR _name)
{
	ID3DBlob* compiledCode = nullptr;
	
	HRESULT hr = D3DCompileFromFile(
		_name,
		nullptr, nullptr,
		"main",
		"vs_4_0",
		0,0,
		&compiledCode,
		nullptr
	);
	CheckFailed(hr, "GP_Material", 54, "Compile Vertex Shader failed");

	hr = CORE_DEVICE->CreateVertexShader(compiledCode->GetBufferPointer(), compiledCode->GetBufferSize(), nullptr, &vertexShader);
	CheckFailed(hr, "GP_Material", 57, "Create Vertex Shader failed");

	//InputLayout
	createInputLayout(compiledCode);

	compiledCode->Release();
	compiledCode = nullptr;
}

void GP_Material::createPixelShader(LPCWSTR _name)
{
	ID3DBlob* compiledCode = nullptr;

	HRESULT hr = D3DCompileFromFile(
		_name,
		nullptr, nullptr,
		"main",
		"ps_4_0",
		0, 0,
		&compiledCode,
		nullptr
	);
	CheckFailed(hr, "GP_Material", 79, "Compile Pixelshader failed");

	hr = CORE_DEVICE->CreatePixelShader(compiledCode->GetBufferPointer(), compiledCode->GetBufferSize(), nullptr, &pixelShader);
	CheckFailed(hr, "GP_Material", 81, "Create Pixelshader failed");
}

void GP_Material::createInputLayout(ID3DBlob* _blob)
{
	D3D11_INPUT_ELEMENT_DESC elements[4] = {};

	elements[0].SemanticName = "Position";
	elements[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;

	elements[1].SemanticName = "NORMAL";
	elements[1].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	elements[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;

	elements[2].SemanticName = "TEXCOORD";
	elements[2].Format = DXGI_FORMAT_R32G32_FLOAT;
	elements[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;

	elements[3].SemanticName = "COLOR";
	elements[3].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	elements[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;

	// Semantic Name can not contain numbers! 
	//elements[4].SemanticName = "OTHERTEXCOORD";
	//elements[4].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	//elements[4].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;

	HRESULT hr = CORE_DEVICE->CreateInputLayout(elements, 4, _blob->GetBufferPointer(),_blob->GetBufferSize(), &inputLayout);
	CheckFailed(hr, "GP_Material", 104, "Create InputLayout Failed");
}

void GP_Material::CreateBuffer(UINT _size, ID3D11Buffer** _buffer)
{
	D3D11_BUFFER_DESC desc = {};
	desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	desc.ByteWidth = _size;
	desc.Usage = D3D11_USAGE_DYNAMIC;
	desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	HRESULT hr = CORE_DEVICE->CreateBuffer(&desc, nullptr, _buffer);
	CheckFailed(hr, "GP_Material", 116, "Create Buffer Failed")
	//Error Check
}
