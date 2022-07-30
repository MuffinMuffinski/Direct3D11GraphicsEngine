#include "GP_Mesh_Sphere.h"
#include <SimpleMath.h>

#define _USE_MATH_DEFINES
#include <math.h>

void GP_Mesh_Sphere::InitBuffer()
{
	int stackCount = 20;
	int sliceCount = 20;
	float radius = 1.5f;

	float lengthInv = 1.0f;

	// Top Point
	vertices.push_back({ XMFLOAT3(0, radius, 0), XMFLOAT3(0,1,0), XMFLOAT2(0,0), Color });

	auto phiStep = M_PI / stackCount;
	auto thetaStep = 2.0f * M_PI / sliceCount;

	for (int i = 1; i <= stackCount - 1; i++)
	{
		auto phi = i * phiStep;
		for (int j = 0; j <= sliceCount; j++)
		{
			auto theta = j * thetaStep;
			XMFLOAT3 p = XMFLOAT3(
				(radius * sin(phi) * cos(theta)),
				(radius * cos(phi)),
				(radius * sin(phi) * sin(theta))
			);
			
			XMFLOAT3 n = p;
			//n.Normalize

			n.x = p.x * lengthInv;
			n.y = p.y * lengthInv;
			n.z = p.z * lengthInv;

			XMFLOAT2 uv = XMFLOAT2(theta / (M_PI * 2), phi / M_PI);
			vertices.push_back({ p, n, uv, Color });
		}
	}
	// Add Bottom Point
	vertices.push_back({ XMFLOAT3(0, -radius, 0), XMFLOAT3(0,-1,0), XMFLOAT2(0,1), Color });

	for (int i = 1; i <= sliceCount; i++)
	{
		indicies.push_back(0);
		indicies.push_back(i + 1);
		indicies.push_back(i);
	}

	auto baseIndex = 1;
	auto ringVertexCount = sliceCount + 1;
	for (int i = 0; i < stackCount - 2; i++)
	{
		for (int j = 0; j < sliceCount; j++)
		{
			indicies.push_back(baseIndex + i * ringVertexCount + j);
			indicies.push_back(baseIndex + i * ringVertexCount + j + 1);
			indicies.push_back(baseIndex + (i + 1) * ringVertexCount + j);

			indicies.push_back(baseIndex + (i + 1) * ringVertexCount + j);
			indicies.push_back(baseIndex + i * ringVertexCount + j + 1);
			indicies.push_back(baseIndex + (i + 1) * ringVertexCount + j + 1);
		}
	}
	auto southPoleIndex = vertices.size() - 1;
	baseIndex = southPoleIndex - ringVertexCount;
	for (int i = 0; i < sliceCount; i++)
	{
		indicies.push_back(southPoleIndex);
		indicies.push_back(baseIndex + i);
		indicies.push_back(baseIndex + i + 1);
	}

}