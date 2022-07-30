#pragma once
#include <memory>
#include <list>

#include "GP_Object.h"

class GP_Objectpool
{
public:
	void Update();
	void Render();

	void AddObject(std::shared_ptr<GP_Object> _obj);
	void RemoveObject(std::shared_ptr<GP_Object> _obj);
private:
	std::list<std::shared_ptr<GP_Object>> objects;
	std::list<std::shared_ptr<GP_Object>> removeObjects;
};

