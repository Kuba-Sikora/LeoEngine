#include "leopch.h" 
#include "Leo/Core/FPSTimer.h"
#include "Leo/Core/Application.h"

#define FPSTIMER_ENABLED

namespace Leo {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create(
			std::bind(&Application::onEvent, this, std::placeholders::_1),
			std::bind(&Application::onWindowEvent, this, std::placeholders::_1)
		));
	}

	Application::~Application() 
	{

	}

	void Application::onEvent(Event& e)
	{
	}

	void Application::onWindowEvent(Event& e)
	{
		switch (e.getEventType())
		{
			case EventType::WindowClose:
			{
				m_Running = false;
				break;
			}
			case EventType::WindowResize:
			{
				// casting the Event object to WindowResizeEvent in order to access the width and height
				WindowResizeEvent resizeEvent = *(WindowResizeEvent*) &e;
				CORE_LOG("window resize: {0}px, {1}px", resizeEvent.getWidth(), resizeEvent.getHeight());
				break;
			}
		}
	}

	void FPSTimer::onInterval()
	{
		CORE_LOG("FPS: {0}", getCount());
	}

	void Application::Run()
	{

#ifdef FPSTIMER_ENABLED
		// initialize timer
		FPSTimer timer;
		timer.setInterval(1);
		timer.init();

		int seconds = 0;
#endif

		CORE_LOG("VSync: ", m_Window->isVSyncEnabled());

		while (m_Running)
		{
			m_Window->onUpdate();

#ifdef FPSTIMER_ENABLED
			timer.update();
#endif

		}
	}

}
