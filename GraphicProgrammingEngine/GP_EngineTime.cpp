#include "GP_EngineTime.h"
#include <Windows.h>
#include <string>

int GP_EngineTime::Init()
{
	_lastTimestamp = timeGetTime() / 1000.0f;

	return 0;
}

void GP_EngineTime::Update()
{
	float actualTimestamp = timeGetTime() / 1000.0f;
	_deltaTime = actualTimestamp - _lastTimestamp;
	_lastTimestamp = actualTimestamp;

}

void GP_EngineTime::DeInit()
{
}