#pragma once

#include "leopch.hpp"
#include "Events/Event.hpp"

namespace Framework {

	// properties needed to create the window
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(
			std::string title = "Leo Engine Window",
			const unsigned int width = 1280,
			const unsigned int height = 720
		) : Title(std::move(title)), Width(width), Height(height) {}
	};

	class Window {

	public:
		using WindowEventCallbackFn = std::function<void(Event&)>;
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() { CORE_LOG("delete Window"); };
		virtual void OnUpdate() = 0;

		[[nodiscard]] virtual unsigned int GetWidth() const = 0;
		[[nodiscard]] virtual unsigned int GetHeight() const = 0;
		[[nodiscard]] virtual std::string GetTitle() const = 0;

		[[nodiscard]] virtual bool IsVSyncEnabled() const = 0;
		virtual void SetVSync(bool state) = 0;

		[[nodiscard]] virtual void* GetNativeWindow() const = 0;

		// Create() function to be defined per platform
		// having the WidowCloseCallback separately so that the OnEvent function inside Application doesn't have to check if every event is a Close event
		static Window* Create(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props = WindowProps());

	};

}
