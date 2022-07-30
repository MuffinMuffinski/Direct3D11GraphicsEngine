#include "GP_Mesh.h"
#include "GP_Core.h"

void GP_Mesh::Init()
{
	InitBuffer();
	CreateBuffer();
}

void GP_Mesh::Render()
{
	static UINT offset = 0;

	CORE_DEVICECONTEXT->IASetVertexBuffers(0, 1, &vertexBuffer, &vertexStride, &offset);
	CORE_DEVICECONTEXT->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R16_UINT, 0);
	CORE_DEVICECONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	CORE_DEVICECONTEXT->DrawIndexed(indicies.size(), 0, 0);
}

void GP_Mesh::DeInit()
{
	if (vertexBuffer != nullptr) {
		vertexBuffer->Release();
		vertexBuffer = nullptr;
	}

	if (indexBuffer != nullptr) {
		indexBuffer->Release();
		indexBuffer = nullptr;
	}
}

void GP_Mesh::InitBuffer()
{
	//Die Vorlage
	//http://www.richardssoftware.net/2013/07/shapes-demo-with-direct3d11-and-slimdx.html
}

void GP_Mesh::CreateBuffer()
{
	vertexStride = sizeof(GP_Vertex);
	{
		D3D11_BUFFER_DESC desc = {};
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		desc.ByteWidth = vertices.size() * vertexStride;

		D3D11_SUBRESOURCE_DATA data = {};
		data.pSysMem = vertices.data();


		HRESULT hr = CORE_DEVICE->CreateBuffer(&desc, &data, &vertexBuffer);
		CheckFailed(hr, "GP_Mesh", 49, "Create Buffer failed");

	}
	{
		D3D11_BUFFER_DESC desc = {};
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		desc.ByteWidth = indicies.size() * sizeof(WORD);

		D3D11_SUBRESOURCE_DATA data = {};
		data.pSysMem = indicies.data();

		HRESULT hr = CORE_DEVICE->CreateBuffer(&desc, &data, &indexBuffer);
		CheckFailed(hr, "GP_Mesh", 63, "Create Index Buffer failed");
	}
}