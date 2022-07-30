#pragma once
#include <iostream>

#define Message(_message) { AllocConsole(); freopen("CONOUT$", "w", stdout); std::cout<< _message << std::endl; }

#define CheckFailed(_hr, _classname, _line , _message) if (FAILED(_hr)) { AllocConsole(); freopen("CONOUT$", "w", stdout); std::cout << "Error: " << _classname << " | Line: " << _line << " Message: " << _message << std::endl; }

class GP_Message
{
};

