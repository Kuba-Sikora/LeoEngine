#pragma once

#include "Framework.hpp"

// Application class contains all the game logic
class Application {

public:
	~Application();
	Application(Application& other) = delete;

	static Application* GetInstance();

	void Update();
	void OnEvent(Framework::Event& e);
	void OnWindowEvent(Framework::Event& e);

	Framework::Window& GetWindow() const { return *window_; };

private:
	Application();

	static Application* s_Instance;

	std::unique_ptr<Framework::Window> window_;
	bool running_ = true;

	friend class Editor;

};

