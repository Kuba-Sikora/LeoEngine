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

		inline unsigned int GetWidth() const override { return data_.Width; }
		inline unsigned int GetHeight() const override { return data_.Height; }

		bool IsVSyncEnabled() const override;
		void SetVSync(bool state) override;

		void* GetNativeWindow() const override { return native_window_; }

	private:
		virtual void Init(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* native_window_;

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			// callback functions from the Application
			EventCallbackFn EventCallback; // OnEvent
			WindowEventCallbackFn WindowCallback; // OnWindowEvent
		};

		WindowData data_;

	};

}