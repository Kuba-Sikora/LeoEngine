#pragma once

#include "Window/Window.hpp"

#include <GLFW/glfw3.h>

namespace Framework {

	// WindowsWindow is class derived from the abstract Window class
	// uses the GLFW library to render the window
	// not a singleton - might add support for multiple windows

	class WindowsWindow final : public Window {

	public:
		WindowsWindow(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props);
		~WindowsWindow() override;

		void OnUpdate() override;

		[[nodiscard]] unsigned int GetWidth() const override { return data_.Width; }
		[[nodiscard]] unsigned int GetHeight() const override { return data_.Height; }
		[[nodiscard]] std::string GetTitle() const override { return data_.Title; }

		[[nodiscard]] bool IsVSyncEnabled() const override;
		void SetVSync(bool state) override;

		[[nodiscard]] void* GetNativeWindow() const override { return native_window_; }

	private:
		void Init(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props);
		void Shutdown();

		GLFWwindow* native_window_{};

		struct WindowData {
			std::string Title;
			unsigned int Width{}, Height{};
			bool VSync{};

			// callback functions from the Application
			EventCallbackFn EventCallback; // OnEvent
			WindowEventCallbackFn WindowCallback; // OnWindowEvent
		};

		WindowData data_;

	};

}