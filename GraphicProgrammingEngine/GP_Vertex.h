#pragma once
#include <DirectXMath.h>

using namespace DirectX;

struct GP_Vertex {
	XMFLOAT3 position;
	XMFLOAT3 normal;
	XMFLOAT2 uv;
	XMFLOAT4 color;
	//XMFLOAT4 uv1;       //for reflection shader
	//XMFLOAT3 tangent;   //for bump mapping
	//XMFLOAT3 biNormal;  //for bump mapping

	GP_Vertex(XMFLOAT3 _pos, XMFLOAT3 _norm, XMFLOAT2 _uv, XMFLOAT4 _col) :
		position(_pos),
		normal(_norm),
		uv(_uv),
		color(_col) {}
		//uv1({1,1,1,1}) {}

};