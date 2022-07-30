#include "GP_Mesh_Pyramid.h"

void GP_Mesh_Pyramid::InitBuffer()
{

	//bottom plane
	vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, -0.5f), XMFLOAT3(0,-1,0), XMFLOAT2(0,0), Color }); // 0
	vertices.push_back({ XMFLOAT3(0.5f, -0.5f, -0.5f),  XMFLOAT3(0,-1,0), XMFLOAT2(1,0), Color }); // 1
	vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, 0.5f),  XMFLOAT3(0,-1,0), XMFLOAT2(0,1), Color }); // 2
	vertices.push_back({ XMFLOAT3(0.5f, -0.5f, 0.5f),   XMFLOAT3(0,-1,0), XMFLOAT2(1,1), Color }); // 3

	indicies.push_back(0);
	indicies.push_back(1);
	indicies.push_back(3);

	indicies.push_back(2);
	indicies.push_back(0);
	indicies.push_back(3);


	//front
	vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, -0.5f), XMFLOAT3(0,0,-1), XMFLOAT2(0,0), Color }); // 0 = 4
	vertices.push_back({ XMFLOAT3(0.5f, -0.5f, -0.5f),  XMFLOAT3(0,0,-1), XMFLOAT2(1,0), Color }); // 1 = 5
	vertices.push_back({ XMFLOAT3(0, 0.5f, 0),         XMFLOAT3(0,0,-1), XMFLOAT2(0,1), Color }); // 4 = 6
	indicies.push_back(4);
	indicies.push_back(6);
	indicies.push_back(5);
	//back
	vertices.push_back({ XMFLOAT3(0.5f, -0.5f, 0.5f),   XMFLOAT3(0,0,1), XMFLOAT2(0,0), Color }); // 3 = 7
	vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, 0.5f),  XMFLOAT3(0,0,1), XMFLOAT2(1,0), Color }); // 2 = 8
	vertices.push_back({ XMFLOAT3(0, 0.5f, 0),         XMFLOAT3(0,0,1), XMFLOAT2(0,1), Color }); // 4 = 9
	indicies.push_back(7);
	indicies.push_back(9);
	indicies.push_back(8);
	//right
	vertices.push_back({ XMFLOAT3(0.5f, -0.5f, -0.5f),  XMFLOAT3(1,0,0), XMFLOAT2(0,0), Color }); // 1 = 10
	vertices.push_back({ XMFLOAT3(0.5f, -0.5f, 0.5f),   XMFLOAT3(1,0,0), XMFLOAT2(1,0), Color }); // 3 = 11
	vertices.push_back({ XMFLOAT3(0, 0.5f, 0),         XMFLOAT3(1,0,0), XMFLOAT2(0,1), Color }); // 4 = 12
	indicies.push_back(10);
	indicies.push_back(12);
	indicies.push_back(11);
	//left											    
	vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, 0.5f),  XMFLOAT3(-1,0,0), XMFLOAT2(0,0), Color }); // 2 = 13
	vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, -0.5f), XMFLOAT3(-1,0,0), XMFLOAT2(1,0), Color }); // 0 = 14
	vertices.push_back({ XMFLOAT3(0, 0.5f, 0),         XMFLOAT3(-1,0,0), XMFLOAT2(0,1), Color }); // 4 = 15
	indicies.push_back(13);
	indicies.push_back(15);
	indicies.push_back(14);
													    
}
