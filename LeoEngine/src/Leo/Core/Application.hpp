#pragma once

#include "Leo/Core/Base.hpp"
#include "Leo/Core/Window.hpp"
#include "Leo/Events/Event.hpp"
#include "Leo/Events/WindowEvent.hpp"
#include "Leo/Layers/LayerStack.hpp"
#include "Leo/Layers/Layer.hpp"
#include "Leo/Layers/ScreenSpaceLayer.hpp"

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