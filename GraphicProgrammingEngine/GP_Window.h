#pragma once
#include <Windows.h>

#include "GP_Message.h"

class GP_Window
{
public:
	void Init(HINSTANCE _hInstance, int _nShowCmd, INT _width, INT _height, LPCWSTR _name);

	bool Run();

	HWND GetWindowHandler() { return windowHandler; }

private:
	INT width;
	INT height;

	LPCWSTR name;

	HWND windowHandler = NULL;
};

