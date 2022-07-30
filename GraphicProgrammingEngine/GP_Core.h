#pragma once
#include <Windows.h>
#include <memory>
#include <Keyboard.h>

#include "GP_Message.h"
#include "GP_Window.h"
#include "GP_Renderer.h"
#include "GP_Objectpool.h"
#include "GP_Camera.h"
#include "GP_Scene.h"
#include "GP_EngineTime.h"

// Macros
#define CORE GP_Core::Instance()
#define CORE_DEVICECONTEXT GP_Core::Instance()->GetDeviceContext()
#define CORE_DEVICE GP_Core::Instance()->GetDevice()
#define CORE_MAINCAM GP_Core::Instance()->GetMainCamera()
#define CORE_OBJECTPOOL GP_Core::Instance()->GetObjectPool()
#define CORE_DELTATIME GP_Core::Instance()->time->GetDeltaTime()

class GP_Core
{
public:
	GP_Core();

	static std::shared_ptr<GP_Core> Instance();

	int Init(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,	int nShowCmd);

	void Run();
	void Finish();

	inline ID3D11DeviceContext* GetDeviceContext() { return renderer->D3DDeviceContext(); }
	inline ID3D11Device* GetDevice() { return renderer->D3DDevice(); }

	inline const std::shared_ptr<GP_Camera> GetMainCamera() { return mainCamera; }

	inline const std::shared_ptr<GP_Objectpool> GetObjectPool() { return objectPool; }

	std::unique_ptr<GP_EngineTime> time;
private:
	static std::shared_ptr<GP_Core> instance;

	std::unique_ptr<GP_Window> window;

	std::unique_ptr<GP_Renderer> renderer;

	std::shared_ptr<GP_Camera> mainCamera;

	std::shared_ptr<GP_Objectpool> objectPool;

	std::unique_ptr<GP_Scene> scene;

	std::unique_ptr<Keyboard> keyboard;


	bool isRunning = false;

	void Update();
	void Render();
};

