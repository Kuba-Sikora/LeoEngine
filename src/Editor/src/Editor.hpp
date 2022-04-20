#pragma once

#include "Application.hpp"
#include "Framework.hpp"

class Editor {

public:
	static Editor* GetInstance();

	void Start();

private:
	Editor();

	static Editor* s_Instance;

	bool running_;

	Application* application_;
	std::unique_ptr<Framework::Window> window_;

};