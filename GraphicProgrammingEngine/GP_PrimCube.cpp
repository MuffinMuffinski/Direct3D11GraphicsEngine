#include "GP_PrimCube.h"

void GP_PrimCube::InitBuffer()
{
    // front (0, 0, 0)
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, -0.5f), XMFLOAT3(0,0,-1), XMFLOAT2(1,1), Color }); // 0
    vertices.push_back({ XMFLOAT3(0.5f, -0.5f, -0.5f),  XMFLOAT3(0,0,-1), XMFLOAT2(0,1), Color }); // 1
    vertices.push_back({ XMFLOAT3(-0.5f, 0.5f, -0.5f),  XMFLOAT3(0,0,-1), XMFLOAT2(1,0), Color }); // 2
    vertices.push_back({ XMFLOAT3(0.5f, 0.5f, -0.5f),   XMFLOAT3(0,0,-1), XMFLOAT2(0,0), Color }); // 3

    indicies.push_back(0);
    indicies.push_back(2);
    indicies.push_back(1);

    indicies.push_back(1);
    indicies.push_back(2);
    indicies.push_back(3); 

    // back (0, 180, 0)
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5, 0.5f),   XMFLOAT3(0,0,1), XMFLOAT2(1,1), Color });  // 5
    vertices.push_back({ XMFLOAT3(0.5f, -0.5f, 0.5f),   XMFLOAT3(0,0,1), XMFLOAT2(0,1), Color });  // 4
    vertices.push_back({ XMFLOAT3(-0.5f, 0.5f, 0.5f),   XMFLOAT3(0,0,1), XMFLOAT2(1,0), Color });  // 7
    vertices.push_back({ XMFLOAT3(0.5f, 0.5f, 0.5f),    XMFLOAT3(0,0,1), XMFLOAT2(0,0), Color });  // 6

    indicies.push_back(5);
    indicies.push_back(7);
    indicies.push_back(4);

    indicies.push_back(4);
    indicies.push_back(7);
    indicies.push_back(6);

    // top (-90, 0, 0)                                                                                      
    vertices.push_back({ XMFLOAT3(-0.5f, 0.5f, -0.5f),  XMFLOAT3(0,1,0), XMFLOAT2(1,1), Color });  // 2
    vertices.push_back({ XMFLOAT3(0.5f, 0.5f, -0.5f),   XMFLOAT3(0,1,0), XMFLOAT2(0,1), Color });  // 3
    vertices.push_back({ XMFLOAT3(-0.5f, 0.5f, 0.5f),   XMFLOAT3(0,1,0), XMFLOAT2(1,0), Color });  // 6
    vertices.push_back({ XMFLOAT3(0.5f, 0.5f, 0.5f),    XMFLOAT3(0,1,0), XMFLOAT2(0,0), Color });  // 7

    indicies.push_back(8);
    indicies.push_back(10);
    indicies.push_back(9);

    indicies.push_back(9);
    indicies.push_back(10);
    indicies.push_back(11);

    // bottom  (90, 0, 0)                                                                                 
    vertices.push_back({ XMFLOAT3(0.5f, -0.5f, -0.5f),  XMFLOAT3(0,-1,0), XMFLOAT2(0,0), Color }); // 1
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, -0.5f), XMFLOAT3(0,-1,0), XMFLOAT2(1,0), Color }); // 0
    vertices.push_back({ XMFLOAT3(0.5f, -0.5f, 0.5f),   XMFLOAT3(0,-1,0), XMFLOAT2(0,1), Color }); // 5
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, 0.5f),  XMFLOAT3(0,-1,0), XMFLOAT2(1,1), Color }); // 4

    indicies.push_back(12);
    indicies.push_back(14);
    indicies.push_back(13);

    indicies.push_back(13);
    indicies.push_back(14);
    indicies.push_back(15);

    // left (0, -90, 0)
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, -0.5f), XMFLOAT3(-1,0,0), XMFLOAT2(1,1), Color }); // 0
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, 0.5f),  XMFLOAT3(-1,0,0), XMFLOAT2(0,1), Color }); // 4
    vertices.push_back({ XMFLOAT3(-0.5f, 0.5f, -0.5f),  XMFLOAT3(-1,0,0), XMFLOAT2(1,0), Color }); // 2
    vertices.push_back({ XMFLOAT3(-0.5f, 0.5f, 0.5f),   XMFLOAT3(-1,0,0), XMFLOAT2(0,0), Color }); // 6

    indicies.push_back(16);
    indicies.push_back(17);
    indicies.push_back(18);

    indicies.push_back(18);
    indicies.push_back(17);
    indicies.push_back(19);

    // right (0, 90, 0)
    vertices.push_back({ XMFLOAT3(0.5f, -0.5f, 0.5f),   XMFLOAT3(1,0,0), XMFLOAT2(1,1), Color });  // 5
    vertices.push_back({ XMFLOAT3(0.5f, -0.5f, -0.5f),  XMFLOAT3(1,0,0), XMFLOAT2(0,1), Color });  // 1
    vertices.push_back({ XMFLOAT3(0.5f, 0.5f, 0.5f),    XMFLOAT3(1,0,0), XMFLOAT2(1,0), Color });  // 7
    vertices.push_back({ XMFLOAT3(0.5f, 0.5f, -0.5f),   XMFLOAT3(1,0,0), XMFLOAT2(0,0), Color });  // 3

    indicies.push_back(20);
    indicies.push_back(21);
    indicies.push_back(22);

    indicies.push_back(22);
    indicies.push_back(21);
    indicies.push_back(23);
}
