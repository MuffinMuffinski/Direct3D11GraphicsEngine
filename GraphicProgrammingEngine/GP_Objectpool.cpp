#include "GP_Objectpool.h"

void GP_Objectpool::Update()
{
	for (std::shared_ptr<GP_Object> obj : objects) {
		obj->Update();
	}

	for (std::shared_ptr<GP_Object> obj : removeObjects) {
		objects.remove(obj);
	}
	removeObjects.clear();
}

void GP_Objectpool::Render()
{
	for (std::shared_ptr<GP_Object> obj : objects) {
		obj->Render();
	}
}

void GP_Objectpool::AddObject(std::shared_ptr<GP_Object> _obj)
{
	if (_obj == nullptr)
		return;

	objects.push_back(_obj);
}

void GP_Objectpool::RemoveObject(std::shared_ptr<GP_Object> _obj)
{
	if (_obj == nullptr)
		return;

	removeObjects.push_back(_obj);
}
