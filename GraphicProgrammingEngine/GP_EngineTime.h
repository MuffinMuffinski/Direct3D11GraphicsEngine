#pragma once
#pragma comment(lib, "Winmm.lib")

class GP_EngineTime
{
public:
	int Init();
	void Update();
	void DeInit();

	float GetDeltaTime() { return _deltaTime; }

private:
	float _deltaTime = 0.0f;
	float _lastTimestamp = 0.0f;
};

