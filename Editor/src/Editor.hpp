#pragma once

#include "Application.hpp"
#include "Framework.hpp"

class Editor {

public:
	static Editor* Construct(Application* app);
	static Editor* Get();

	void Start();

private:
	Editor(Application* app);

	static Editor* s_Instance;

	bool running_;

	Application* application_;
	std::unique_ptr<Framework::Window> window_;

};