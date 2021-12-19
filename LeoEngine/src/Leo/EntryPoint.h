#pragma once

#include "Application.h"
#include "Log.h"

#ifdef LEO_PLATFORM_WINDOWS

extern Leo::Application* Leo::CreateApplication();

int main(int argc, char** argv) {

	std::cout << "Leo Engine Started!" << std::endl;

	Leo::Log::Init();

	Leo::Application* app = Leo::CreateApplication();
	app->Run();
	delete app;

}

#endif