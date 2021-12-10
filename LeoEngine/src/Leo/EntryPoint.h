#pragma once

#include "Application.h"

#ifdef LEO_PLATFORM_WINDOWS

extern Leo::Application* Leo::CreateApplication();

int main(int argc, char** argv) {

	std::cout << "Leo Engine Started!" << std::endl;

	auto app = Leo::CreateApplication();
	app->Run();
	delete app;

}

#endif