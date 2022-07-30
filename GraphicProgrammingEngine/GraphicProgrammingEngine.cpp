#include "GraphicProgrammingEngine.h"
#include <Windows.h>

#include "GP_Core.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd) {

	if (CORE->Init(hInstance, hPrevInstance, lpCmdLine, nShowCmd) == 0) {
		CORE->Run();
		CORE->Finish();
	}

	return 0;
}