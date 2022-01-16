#pragma once

#include "Leo/Core/Application.h"
#include "Leo/Core/Log.h"

#ifdef LEO_PLATFORM_WINDOWS

extern Leo::Application* Leo::CreateApplication();

int main(int argc, char** argv)
{
	Leo::Log::Init();
	
	CORE_WARN("initialized Core Log");
	APP_INFO("initialized Client Log");

	Leo::Application* app = Leo::CreateApplication();
	app->Run();
	delete app;
}

#endif