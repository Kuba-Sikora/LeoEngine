#include "Application.hpp"
#include "Editor.hpp"
#include "Framework.hpp"

#ifdef LEO_PLATFORM_WINDOWS

// the entry point of the engine
int main(int argc, char** argv) {
	Framework::Log::Init();

	CORE_WARN("initialized Core Log");
	APP_LOG("initialized Client Log");

	Application* app = Application::GetInstance();
	Editor* editor = Editor::Construct(app);

	editor->Start();

	delete app;
	delete editor;
}

#endif