#pragma once

#include "Leo/Core/Base.h"
#include "Leo/Core/Window.h"
#include "Leo/Events/Event.h"
#include "Leo/Events/WindowEvent.h"

namespace Leo {

	// Application singleton which the Game class will inherit from
	class Application {

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		void OnWindowEvent(Event& e);

		Window& GetWindow() { return *m_Window; };

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		static Application* s_Instance;

	};

	// to be defined in client (extern)
	Application* CreateApplication();

}