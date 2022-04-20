#pragma once

#include "Application.hpp"
#include "Framework.hpp"

class Editor {

public:
	~Editor() { APP_LOG("Editor delete"); }

	static Editor* Construct(Application* app);
	static Editor* Get();

	void Run();

	void OnUpdate();
	void OnEvent(Framework::Event& e);
	void OnWindowEvent(Framework::Event& e);

	std::shared_ptr<Framework::Window> GetWindow() const { return window_; };

private:
	Editor(Application* app);

	static Editor* s_Instance;

	bool running_;

	Application* application_;
	std::shared_ptr<Framework::Window> window_;

};