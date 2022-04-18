#pragma once

#include "Core/Window/Window.hpp"
#include "Events/Event.hpp"
#include "Events/WindowEvent.hpp"
#include "Layers/LayerStack.hpp"
#include "Layers/Layer.hpp"
#include "Layers/ScreenSpaceLayer.hpp"

namespace Leo {

	// Application base class which the Sandbox class will inherit from
	// NOT A SINGLETON! - too much consfusion with inheritance
	class Application {

	public:
		Application();
		virtual ~Application();
		Application(Application& other) = delete;

		void Run();
		void OnEvent(Event& e);
		void OnWindowEvent(Event& e);

		Window& GetWindow() { return *m_Window; };

	private:
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<LayerStack> m_LayerStack;
		bool m_Running = true;

	};

	// to be defined in client (extern)
	Application* CreateApplication();

}