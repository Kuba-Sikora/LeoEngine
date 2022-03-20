#pragma once

#include "Leo/Core/Base.hpp"
#include "Leo/Core/Window.hpp"
#include "Leo/Events/Event.hpp"
#include "Leo/Events/WindowEvent.hpp"

namespace Leo {

	// Application singleton which the Game class will inherit from
	class Application {

	public:
		Application();
		virtual ~Application();

		static Application& GetInstance() { return *s_Instance;  }

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