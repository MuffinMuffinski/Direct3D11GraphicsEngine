#include "GP_Skybox.h"

void GP_Skybox::InitBuffer()
{
	//back
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, 0.5f),   XMFLOAT3(0,0,-1), XMFLOAT2(0.25f,0.66f), Color });  // 4 = 0
    vertices.push_back({ XMFLOAT3( 0.5f, -0.5f, 0.5f),   XMFLOAT3(0,0,-1), XMFLOAT2(0.5f,0.66f),  Color });  // 5 = 1
    vertices.push_back({ XMFLOAT3(-0.5f,  0.5f, 0.5f),   XMFLOAT3(0,0,-1), XMFLOAT2(0.25f,0.33f), Color });  // 6 = 2
    vertices.push_back({ XMFLOAT3( 0.5f,  0.5f, 0.5f),   XMFLOAT3(0,0,-1), XMFLOAT2(0.5f,0.33f),  Color });  // 7 = 3

    indicies.push_back(1);
    indicies.push_back(0);
    indicies.push_back(3);

    indicies.push_back(3);
    indicies.push_back(0);
    indicies.push_back(2);

    // left
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, -0.5f), XMFLOAT3(1,0,0), XMFLOAT2(0,0.66f),      Color }); // 0 = 4
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f,  0.5f), XMFLOAT3(1,0,0), XMFLOAT2(0.25f,0.66f),  Color }); // 4 = 5
    vertices.push_back({ XMFLOAT3(-0.5f,  0.5f, -0.5f), XMFLOAT3(1,0,0), XMFLOAT2(0,0.33f),      Color }); // 2 = 6
    vertices.push_back({ XMFLOAT3(-0.5f,  0.5f,  0.5f), XMFLOAT3(1,0,0), XMFLOAT2(0.25f,0.33f),  Color }); // 6 = 7

    indicies.push_back(4);
    indicies.push_back(6);
    indicies.push_back(5);

    indicies.push_back(5);
    indicies.push_back(6);
    indicies.push_back(7);

    // right
    vertices.push_back({ XMFLOAT3(0.5f, -0.5f,  0.5f),  XMFLOAT3(-1,0,0), XMFLOAT2(0.5f,0.66f),  Color });  // 5 = 8
    vertices.push_back({ XMFLOAT3(0.5f, -0.5f, -0.5f),  XMFLOAT3(-1,0,0), XMFLOAT2(0.75f,0.66f), Color });  // 1 = 9
    vertices.push_back({ XMFLOAT3(0.5f,  0.5f,  0.5f),  XMFLOAT3(-1,0,0), XMFLOAT2(0.5f,0.33f),  Color });  // 7 = 10
    vertices.push_back({ XMFLOAT3(0.5f,  0.5f, -0.5f),  XMFLOAT3(-1,0,0), XMFLOAT2(0.75f,0.33f), Color });  // 3 = 11

    indicies.push_back(8);
    indicies.push_back(10);
    indicies.push_back(9);

    indicies.push_back(9);
    indicies.push_back(10);
    indicies.push_back(11);

    //front
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, -0.5f),   XMFLOAT3(0,0,1), XMFLOAT2(1,0.66f),     Color });  // 0 = 12
    vertices.push_back({ XMFLOAT3( 0.5f, -0.5f, -0.5f),   XMFLOAT3(0,0,1), XMFLOAT2(0.75f,0.66f), Color });  // 1 = 13
    vertices.push_back({ XMFLOAT3(-0.5f,  0.5f, -0.5f),   XMFLOAT3(0,0,1), XMFLOAT2(1,0.33f),     Color });  // 2 = 14
    vertices.push_back({ XMFLOAT3( 0.5f,  0.5f, -0.5f),   XMFLOAT3(0,0,1), XMFLOAT2(0.75f,0.33f), Color });  // 3 = 15

    indicies.push_back(12);
    indicies.push_back(13);
    indicies.push_back(14);

    indicies.push_back(14);
    indicies.push_back(13);
    indicies.push_back(15);

    //top
    //TODO Schwarze Randlinien sind noch zu sehen
    vertices.push_back({ XMFLOAT3(-0.5f, 0.5f, -0.5f),  XMFLOAT3(0,-1,0), XMFLOAT2(0.25f,0),     Color });  // 2 = 16
    vertices.push_back({ XMFLOAT3(0.5f, 0.5f, -0.5f),   XMFLOAT3(0,-1,0), XMFLOAT2(0.5f,0),      Color });  // 3 = 17
    vertices.push_back({ XMFLOAT3(-0.5f, 0.5f, 0.5f),   XMFLOAT3(0,-1,0), XMFLOAT2(0.25f,0.33f), Color });  // 6 = 18
    vertices.push_back({ XMFLOAT3(0.5f, 0.5f, 0.5f),    XMFLOAT3(0,-1,0), XMFLOAT2(0.5f,0.33f),  Color });  // 7 = 19

    indicies.push_back(16);
    indicies.push_back(17);
    indicies.push_back(18);

    indicies.push_back(18);
    indicies.push_back(17);
    indicies.push_back(19);

    // bottom                                                                             
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, -0.5f), XMFLOAT3(0,1,0), XMFLOAT2(0.25f,1),     Color });  // 0 = 20
    vertices.push_back({ XMFLOAT3(0.5f, -0.5f, -0.5f),  XMFLOAT3(0,1,0), XMFLOAT2(0.5f,1),      Color });  // 1 = 21
    vertices.push_back({ XMFLOAT3(-0.5f, -0.5f, 0.5f),  XMFLOAT3(0,1,0), XMFLOAT2(0.25f,0.66f), Color });  // 4 = 22
    vertices.push_back({ XMFLOAT3(0.5f, -0.5f, 0.5f),   XMFLOAT3(0,1,0), XMFLOAT2(0.5f, 0.66f), Color });  // 5 = 23

    indicies.push_back(20);
    indicies.push_back(22);
    indicies.push_back(21);

    indicies.push_back(21);
    indicies.push_back(22);
    indicies.push_back(23);
}
