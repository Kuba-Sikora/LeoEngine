#pragma once

#include "Leo/Core/Base.h"
#include "Leo/Core/Window.h"

namespace Leo {

	class LEO_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// to be defined in client (extern)
	Application* CreateApplication();

}


