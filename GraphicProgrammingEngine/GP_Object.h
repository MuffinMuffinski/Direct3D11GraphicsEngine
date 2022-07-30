#pragma once
#include <memory>

#include "GP_Mesh.h"
#include "GP_Material.h"
#include "GP_Transform.h"

class GP_Object
{
public:
	void Init(std::shared_ptr<GP_Mesh> _mesh, std::shared_ptr<GP_Material> _mat);
	void Update();
	void Render();
	
	std::shared_ptr<GP_Mesh> Mesh;
	std::shared_ptr<GP_Material> Material;
	std::unique_ptr<GP_Transform> Transform;
};

