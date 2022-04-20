#include "leopch.hpp"

#include "Application.hpp"
#include "FPSTimer.hpp"

#define FPSTIMER_ENABLED

Application* Application::s_Instance = nullptr;

Application* Application::GetInstance() {
	if (!s_Instance) {
		s_Instance = new Application;
	}
	return s_Instance;
}

Application::Application() {
	CORE_LOG("application constructor");

	window_ = std::unique_ptr<Framework::Window>(Framework::Window::Create(
		std::bind(&Application::OnEvent, this, std::placeholders::_1),
		std::bind(&Application::OnWindowEvent, this, std::placeholders::_1)));
	// m_LayerStack = std::unique_ptr<LayerStack>(LayerStack::GetInstance());


	// m_LayerStack->PushLayerFront(new ScreenSpaceLayer("Screenspace Layer"));
}

Application::~Application() { CORE_LOG("delete Application"); }

void Application::OnEvent(Framework::Event& e) {
	// m_LayerStack->OnEvent(e);
}

void Application::OnWindowEvent(Framework::Event& e) {
	switch (e.GetEventType()) {
		case Framework::EventType::WindowClose:
			running_ = false;
			break;

		case Framework::EventType::WindowResize:
			// casting the Event object to WindowResizeEvent in order to access the
			// width and height
			Framework::WindowResizeEvent resizeEvent = *dynamic_cast<Framework::WindowResizeEvent*>(&e);
			CORE_LOG("window resize: {0}px, {1}px", resizeEvent.getWidth(),
				resizeEvent.getHeight());
			break;
	}
}

void FPSTimer::onInterval() { CORE_LOG("FPS: {0}", getCount()); }

void Application::Update() {
	window_->OnUpdate();
}

