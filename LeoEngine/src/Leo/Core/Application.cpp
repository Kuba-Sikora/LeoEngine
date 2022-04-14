#include "leopch.hpp"
#include "Leo/Core/FPSTimer.hpp"
#include "Leo/Core/Application.hpp"

#define FPSTIMER_ENABLED

namespace Leo {

	Application::Application() {
		CORE_LOG("application constructor");

		m_Window = std::unique_ptr<Window>(Window::Create(
			std::bind(&Application::OnEvent, this, std::placeholders::_1),
			std::bind(&Application::OnWindowEvent, this, std::placeholders::_1)));
		m_LayerStack = std::unique_ptr<LayerStack>(LayerStack::GetInstance());


		m_LayerStack->PushLayerFront(new ScreenSpaceLayer("screenspace1"));
		m_LayerStack->PushLayerBack(new ScreenSpaceLayer("screenspace2"));
		m_LayerStack->PushLayerFront(new ScreenSpaceLayer("screenspace3"));
	}

	Application::~Application() { CORE_LOG("Application delete"); }

	void Application::OnEvent(Event& e) {
		m_LayerStack->OnEvent(e);
	}

	void Application::OnWindowEvent(Event& e) {
		switch (e.GetEventType()) {
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
