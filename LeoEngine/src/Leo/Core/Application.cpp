#include "leopch.hpp"
#include "Leo/Core/FPSTimer.hpp"
#include "Leo/Core/Application.hpp"

#define FPSTIMER_ENABLED

namespace Leo {

	// declaration for the static s_Instance member -> to be set inside the Application constructor
	Application* Application::s_Instance = nullptr;

	Application::Application() {
		if (s_Instance) {
			CORE_LOG("Application already exists");
		}
		else {
			s_Instance = this;
			m_Window = std::unique_ptr<Window>(Window::Create(
				std::bind(&Application::OnEvent, this, std::placeholders::_1),
				std::bind(&Application::OnWindowEvent, this, std::placeholders::_1)));
		}
	}

	Application::~Application() { CORE_LOG("Application delete"); }

	void Application::OnEvent(Event& e) {}

	void Application::OnWindowEvent(Event& e) {
		switch (e.getEventType()) {
			case EventType::WindowClose:
				m_Running = false;
				break;

			case EventType::WindowResize:
				// casting the Event object to WindowResizeEvent in order to access the
				// width and height
				WindowResizeEvent resizeEvent = *(WindowResizeEvent*)&e;
				CORE_LOG("window resize: {0}px, {1}px", resizeEvent.getWidth(),
					resizeEvent.getHeight());
				break;
		}
	}

	void FPSTimer::onInterval() { CORE_LOG("FPS: {0}", getCount()); }

	void Application::Run() {
#ifdef FPSTIMER_ENABLED
		// initialize timer
		FPSTimer timer;
		timer.setInterval(1);
		timer.init();

		int seconds = 0;
#endif

		CORE_LOG("VSync: ", m_Window->IsVSyncEnabled());

		while (m_Running) {
			m_Window->OnUpdate();

#ifdef FPSTIMER_ENABLED
			timer.update();
#endif
		}
	}

}
