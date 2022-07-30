#pragma once
#include "GP_SimpleTextureMat.h"
#include "GP_PrimPlane.h"
#include "GP_PrimCube.h"
#include "GP_Skybox.h"
#include "GP_DirectionLight.h"
#include "GP_LightMaterial.h"
#include "GP_PrimPlane.h"
#include "GP_Mesh_Sphere.h"
#include "GP_Mesh_Pyramid.h"
#include "GP_ReflectionMaterial.h"

class GP_Scene
{
public:
	virtual void Init();

	virtual void Update();

private:
	std::shared_ptr<GP_PrimCube> cube;
	std::shared_ptr<GP_LightMaterial> brickMaterial;
	std::shared_ptr<GP_Object> brickCube;

	std::shared_ptr<GP_Mesh_Sphere> sphere;
	std::shared_ptr<GP_LightMaterial> sphereMaterial;
	std::shared_ptr<GP_Object> sphereObject;

	std::shared_ptr<GP_ReflectionMaterial> reflectionMaterial;
	std::shared_ptr<GP_Object> reflectionObject;

	std::shared_ptr<GP_Mesh_Pyramid> pyramid;
	std::shared_ptr<GP_LightMaterial> pyramidMaterial;
	std::shared_ptr<GP_Object> pyramidObject;

	std::shared_ptr<GP_PrimPlane> plane;
	std::shared_ptr<GP_LightMaterial> planeMaterial;
	std::shared_ptr<GP_LightMaterial> planeMaterial2;
	std::shared_ptr<GP_Object> greyPlane;
	std::shared_ptr<GP_Object> greyPlane2;

	std::shared_ptr<GP_Skybox> skybox;
	std::shared_ptr<GP_SimpleTextureMat> skyboxMaterial;
	std::shared_ptr<GP_Object> skyboxObject;

	std::shared_ptr<GP_DirectionLight> directionalLight;
	std::shared_ptr<GP_LightMaterial> directionalLightMaterial;

};

