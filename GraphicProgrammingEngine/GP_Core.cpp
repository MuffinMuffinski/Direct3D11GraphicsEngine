#include "GP_Core.h"

GP_Core::GP_Core()
{
}

std::shared_ptr<GP_Core> GP_Core::instance = nullptr;

std::shared_ptr<GP_Core> GP_Core::Instance()
{
	if (instance == nullptr)
		instance = std::make_shared<GP_Core>();

	return instance;
}

int GP_Core::Init(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Message("Hallo Welt")
	keyboard = std::make_unique<Keyboard>();

	window = std::make_unique<GP_Window>();
	window->Init(hInstance, nShowCmd, 1920, 1080, L"Graphic Programming Engine");
	Message("Window wurde erstellt")

	renderer = std::make_unique<GP_Renderer>();
	renderer->Init(window->GetWindowHandler(), 1920, 1080, true);
	Message("Renderer wurde erstellt")

	mainCamera = std::make_shared<GP_Camera>();
	mainCamera->Init(1920, 1080);
	mainCamera->Transform->SetPosition(0, 0, -7);

	objectPool = std::make_shared<GP_Objectpool>();

	scene = std::make_unique<GP_Scene>();
	scene->Init();

	time = std::make_unique<GP_EngineTime>();
	time->Init();

	return 0;
}

void GP_Core::Run()
{
	isRunning = true;
	while (isRunning)
	{
		if (!window->Run())
			break;

		Update();
		Render();
	}
}

void GP_Core::Finish()
{
}

void GP_Core::Update()
{
	time->Update();

	mainCamera->Update();

	scene->Update();

	objectPool->Update();
}

void GP_Core::Render()
{
	renderer->BeginScene(0, 0.7f, 0.5f);

	objectPool->Render();

	//Hier kommt der andere Renderkram

	renderer->EndScene();
}
