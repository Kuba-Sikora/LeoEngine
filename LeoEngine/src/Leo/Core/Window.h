#pragma once

#include "leopch.h"
#include "Leo/Events/WindowEvent.h"

namespace Leo {

	// properties needed to create the window
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(
			const std::string& title = "Leo Engine",
			unsigned int width = 1280,
			unsigned int height = 720
		) : Title(title), Width(width), Height(height) {}
	};

	// abstract window class (platform independent)
	class Window {

	public:
		using WindowEventCallbackFn = std::function<void(Event&)>;
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual bool IsVSyncEnabled() const = 0;
		virtual void SetVSync(bool state) = 0;

		// Create() function to be defined per platform
		// having the WidowCloseCallback separately so that the onEvent function inside Application doesn't have to check is every event is a Close event
		static Window* Create(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props = WindowProps());

	};

}