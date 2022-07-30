#include "GP_Object.h"

void GP_Object::Init(std::shared_ptr<GP_Mesh> _mesh, std::shared_ptr<GP_Material> _mat)
{
	Transform = std::make_unique<GP_Transform>();
	Transform->Init();

	Mesh = _mesh;
	Material = _mat;
}

void GP_Object::Update()
{
	Transform->Update();
}

void GP_Object::Render()
{
	Material->Render(*this);

	Mesh->Render();
}
