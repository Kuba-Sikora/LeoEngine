#pragma once

#include "Leo/Core/Base.h"
#include "Leo/Core/Window.h"
#include "Leo/Events/Event.h"
#include "Leo/Events/WindowEvent.h"

namespace Leo {

	class LEO_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
		void onEvent(Event& e);
		void onWindowEvent(Event& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// to be defined in client (extern)
	Application* CreateApplication();

}


