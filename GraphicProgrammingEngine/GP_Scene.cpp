#include "GP_Core.h"
#include "GP_Scene.h"

void GP_Scene::Init()
{

	//DIRECTIONAL LIGHT
	directionalLight = std::make_shared<GP_DirectionLight>();
	directionalLight->m_color = { 1,1,1};
	directionalLight->m_direction = { 0, -0.5, 0.5 };
	directionalLight->m_intensity =  5.0f ;

	directionalLightMaterial = std::make_shared<GP_LightMaterial>();
	directionalLightMaterial->Init(L"VSPhongShader.hlsl", L"PSPhongShader.hlsl");
	directionalLightMaterial->SetSamplerState();
	directionalLightMaterial->SetTexture(L"bricks2.jpg");
	directionalLightMaterial->SetNormalTexture(L"bricks2_normal.jpg");
	directionalLightMaterial->directionalLight = directionalLight;


	//CUBE
	cube = std::make_shared<GP_PrimCube>();
	cube->Init();

	brickMaterial = std::make_shared<GP_LightMaterial>();
	brickMaterial->Init(L"VSNormal.hlsl", L"PSNormal.hlsl");
	brickMaterial->SetSamplerState();
	brickMaterial->SetTexture(L"bricks2.jpg");
	brickMaterial->SetNormalTexture(L"bricks2_normal.jpg");

	brickMaterial->directionalLight = directionalLight;

	brickCube = std::make_shared<GP_Object>();
	brickCube->Init(cube, brickMaterial);
	brickCube->Transform->SetEulerAngle(45,45,0);

	CORE_OBJECTPOOL->AddObject(brickCube);

	//PYRAMID
	pyramid = std::make_shared<GP_Mesh_Pyramid>();
	pyramid->Init();

	pyramidMaterial = std::make_shared<GP_LightMaterial>();
	pyramidMaterial->Init(L"VSPhongShader.hlsl", L"PSPhongShader.hlsl");
	pyramidMaterial->SetSamplerState();
	pyramidMaterial->SetTexture(L"sand.jpg");
	pyramidMaterial->SetNormalTexture(L"bricks2_normal.jpg");
	pyramidMaterial->directionalLight = directionalLight;

	pyramidObject = std::make_shared<GP_Object>();
	pyramidObject->Init(pyramid, pyramidMaterial);
	pyramidObject->Transform->SetPosition(-2, 0, 0);
	CORE_OBJECTPOOL->AddObject(pyramidObject);

	//SPHERE
	sphere = std::make_shared<GP_Mesh_Sphere>();
	sphere->Init();

	sphereMaterial = std::make_shared<GP_LightMaterial>();
	sphereMaterial->Init(L"VSPhongShader.hlsl", L"PSPhongShader.hlsl");
	sphereMaterial->SetSamplerState();
	sphereMaterial->SetTexture(L"SphereTexture.png");
	sphereMaterial->SetNormalTexture(L"bricks2_normal.jpg");
	sphereMaterial->directionalLight = directionalLight;
	
	reflectionMaterial = std::make_shared<GP_ReflectionMaterial>();
	reflectionMaterial->Init(L"VSReflectionShader.hlsl", L"PSReflectionShader.hlsl");
	reflectionMaterial->SetSamplerState();
	reflectionMaterial->SetTexture(L"SphereTexture.png");
	reflectionMaterial->AmbientStrength = 0;

	sphereObject = std::make_shared<GP_Object>();
	sphereObject->Init(sphere, sphereMaterial);
	sphereObject->Transform->SetPosition(2, 0, 0);
	sphereObject->Transform->SetScale(0.4f, 0.4f, 0.4f);

	reflectionObject = std::make_shared<GP_Object>();
	reflectionObject->Init(sphere, reflectionMaterial);
	reflectionObject->Transform->SetPosition(2, 2, 0);
	reflectionObject->Transform->SetScale(0.4f, 0.4f, 0.4f);

	CORE_OBJECTPOOL->AddObject(sphereObject);
	CORE_OBJECTPOOL->AddObject(reflectionObject);



	//PLANE
	plane = std::make_shared<GP_PrimPlane>();
	plane->Init();

	/*planeMaterial = std::make_shared<GP_LightMaterial>();
	planeMaterial->Init(L"VSPhongShader.hlsl", L"PSPhongShader.hlsl");
	planeMaterial->SetSamplerState();
	planeMaterial->SetTexture(L"bricks2.jpg");
	planeMaterial->SetNormalTexture(L"bricks2_normal.jpg");
	planeMaterial->directionalLight = directionalLight;*/

	planeMaterial2 = std::make_shared<GP_LightMaterial>();
	planeMaterial2->Init(L"VSNormal.hlsl", L"PSNormal.hlsl");
	planeMaterial2->SetSamplerState();
	planeMaterial2->SetTexture(L"bricks2.jpg");
	planeMaterial2->SetNormalTexture(L"bricks2_normal.jpg");
	planeMaterial2->directionalLight = directionalLight;

	/*greyPlane = std::make_shared<GP_Object>();
	greyPlane->Init(plane, planeMaterial);
	greyPlane->Transform->SetEulerAngle(0, 0, 0);
	greyPlane->Transform->SetPosition(-10, -2, 0);
	greyPlane->Transform->SetScale(20, 1, 20);

	CORE_OBJECTPOOL->AddObject(greyPlane);*/

	greyPlane2 = std::make_shared<GP_Object>();
	greyPlane2->Init(plane, planeMaterial2);
	greyPlane2->Transform->SetEulerAngle(0, 0, 0);
	greyPlane2->Transform->SetPosition(0, -2, 0);
	greyPlane2->Transform->SetScale(20, 1, 20);

	CORE_OBJECTPOOL->AddObject(greyPlane2);


	//SKYBOX
	skybox = std::make_shared<GP_Skybox>();
	skybox->Init();

	skyboxMaterial = std::make_shared<GP_SimpleTextureMat>();
	skyboxMaterial->Init(L"VSSimpleTexture.hlsl", L"PSSimpleTexture.hlsl");
	skyboxMaterial->SetSamplerState();
	skyboxMaterial->SetTexture(L"skybox_texture.jpg");
	skyboxMaterial->AmbientColor = { 0, 0, 0 };

	skyboxObject = std::make_shared<GP_Object>();
	skyboxObject->Init(skybox, skyboxMaterial);
	skyboxObject->Transform->SetEulerAngle(0, 0, 0);
	skyboxObject->Transform->SetScale({ 999,999,999 });

	CORE_OBJECTPOOL->AddObject(skyboxObject);
}

void GP_Scene::Update()
{
	XMFLOAT3 brickRotation = brickCube->Transform->GetEulerAngle();
	brickCube->Transform->SetEulerAngle(brickRotation.x, brickRotation.y + 15 * CORE_DELTATIME, brickRotation.z);

	XMFLOAT3 sphereRotation = sphereObject->Transform->GetEulerAngle();
	sphereObject->Transform->SetEulerAngle(sphereRotation.x, sphereRotation.y + 15 * CORE_DELTATIME, sphereRotation.z); 

	XMFLOAT3 pyramidRotation = pyramidObject->Transform->GetEulerAngle();
	pyramidObject->Transform->SetEulerAngle(pyramidRotation.x, pyramidRotation.y + 15 * CORE_DELTATIME, pyramidRotation.z);

	skyboxObject->Transform->SetPosition( CORE_MAINCAM->Transform->GetPosition());
}
