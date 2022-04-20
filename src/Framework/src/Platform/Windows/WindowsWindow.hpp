#pragma once

#include "Window/Window.hpp"

#include <GLFW/glfw3.h>

namespace Framework {

	// WindowsWindow is class derived from the abstract Window class
	// uses the GLFW library to render the window
	// not a singleton - might add support for multiple windows

	class WindowsWindow : public Window {

	public:
		WindowsWindow(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		bool IsVSyncEnabled() const override;
		void SetVSync(bool state) override;

	private:
		virtual void Init(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			// callback functions from the Application
			EventCallbackFn EventCallback; // OnEvent
			WindowEventCallbackFn WindowCallback; // OnWindowEvent
		};

		WindowData m_Data;

	};

}