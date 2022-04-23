#pragma once

#include "Framework.hpp"

// Application class contains all the game logic
class Application {

public:
	~Application();
	Application(Application& other) = delete;

	static Application* GetInstance();

	void OnUpdate();
	void OnEvent(Framework::Event& e);
	void OnWindowEvent(Framework::Event& e);

	[[nodiscard]] bool IsKeyPressed(int key) const;
	[[nodiscard]] bool IsMouseButtonPressed(int button) const;

	// Detached view - own window
	void DetachFromEditor();
	void AttachToEditor();

	[[nodiscard]] std::shared_ptr<Framework::Window> GetWindow() const { return window_; };

private:
	Application();

	static Application* s_Instance;

	std::shared_ptr<Framework::Window> window_;
	bool running_ = true;
	bool detached_ = false;

	friend class Editor;

};

