#include "leopch.h" 
#include "Leo/Core/Log.h"
#include "Leo/Core/FPSTimer.h"
#include "Leo/Core/Application.h"

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
		CORE_INFO("FPS: {0}", getCount());
	}

	void Application::Run()
	{
		// initialize timer
		FPSTimer timer;
		timer.setInterval(1);
		timer.resetCycle();

		int seconds = 0;

		while (m_Running)
		{
			m_Window->onUpdate();
			timer.update();
		}
	}

}
