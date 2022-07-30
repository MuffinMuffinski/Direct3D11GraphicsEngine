#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include <vector>

#include "GP_Vertex.h"

class GP_Mesh
{
public:
	void Init();
	void Render();
	void DeInit();

	XMFLOAT4 Color = XMFLOAT4(0, 0, 0, 1);
protected:
	virtual void InitBuffer();
	void CreateBuffer();

	std::vector<GP_Vertex> vertices;
	std::vector<WORD> indicies;

	ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11Buffer* indexBuffer = nullptr;

	UINT vertexStride = 0;
};

