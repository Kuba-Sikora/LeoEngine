#include "leopch.h" 
#include "Leo/Core/FPSTimer.h"
#include "Leo/Core/Application.h"

#define FPSTIMER_ENABLED

namespace Leo {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() 
	{

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
