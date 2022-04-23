#include "leopch.hpp"

#include "Application.hpp"
#include "Editor.hpp"

Application* Application::s_Instance = nullptr;

Application* Application::GetInstance() {
	if (!s_Instance) {
		s_Instance = new Application;
	}
	return s_Instance;
}

Application::Application() {
	APP_LOG("application constructor");

	
	// m_LayerStack = std::unique_ptr<LayerStack>(LayerStack::GetInstance());


	// m_LayerStack->PushLayerFront(new ScreenSpaceLayer("Screenspace Layer"));
}

Application::~Application() { APP_LOG("delete Application"); }

void Application::OnEvent(Framework::Event& e) {
	// m_LayerStack->OnEvent(e);
}

void Application::OnWindowEvent(Framework::Event& e) {

	// When App is detached
	switch (e.GetEventType()) {
		case Framework::EventType::WindowClose:
			running_ = false;
			AttachToEditor();
			break;

		case Framework::EventType::WindowResize:
			// casting the Event object to WindowResizeEvent in order to access the
			// width and height
			Framework::WindowResizeEvent resizeEvent = *dynamic_cast<Framework::WindowResizeEvent*>(&e);
			APP_LOG("window resize: {0}px, {1}px", resizeEvent.GetWidth(),
				resizeEvent.GetHeight());
			break;
	}
}

// UPDATE FUNCTION CALLED EVERY FRAME
void Application::OnUpdate() {
	if (detached_)
		window_->OnUpdate();

	if (IsKeyPressed(GLFW_KEY_UP))
		APP_LOG("Up Arrow Pressed");
}

void Application::DetachFromEditor() {
	detached_ = true;
	const Framework::WindowProps props = Framework::WindowProps("Application Window");
	window_ = std::shared_ptr<Framework::Window>(Framework::Window::Create(
		[this](auto&& placeHolder1) { OnEvent(std::forward<decltype(placeHolder1)>(placeHolder1)); },
		[this](auto&& placeHolder1) { OnWindowEvent(std::forward<decltype(placeHolder1)>(placeHolder1)); },
		props
	));
}

void Application::AttachToEditor() {
	detached_ = false;
	window_ = Editor::Get()->GetWindow();
}

bool Application::IsKeyPressed(int key) const {
	return Framework::Input::IsKeyPressed(window_->GetNativeWindow(), key);
}

bool Application::IsMouseButtonPressed(int button) const {
	return Framework::Input::IsMouseButtonPressed(window_->GetNativeWindow(), button);
}

