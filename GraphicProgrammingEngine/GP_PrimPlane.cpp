#include "GP_PrimPlane.h"

void GP_PrimPlane::InitBuffer()
{
	vertices.push_back({ XMFLOAT3(-0.5f, 0, -0.5f), XMFLOAT3(0,1,0), XMFLOAT2(0,0), Color });
	vertices.push_back({ XMFLOAT3(0.5f, 0, -0.5f), XMFLOAT3(0,1,0), XMFLOAT2(1,0), Color });
	vertices.push_back({ XMFLOAT3(-0.5f, 0, 0.5f), XMFLOAT3(0,1,0), XMFLOAT2(0,1), Color });
	vertices.push_back({ XMFLOAT3(0.5f, 0, 0.5f), XMFLOAT3(0,1,0), XMFLOAT2(1,1), Color });

	indicies.push_back(0);
	indicies.push_back(3);
	indicies.push_back(1);

	indicies.push_back(0);
	indicies.push_back(2);
	indicies.push_back(3);
}
