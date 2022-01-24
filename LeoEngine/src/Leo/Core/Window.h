#pragma once

#include "leopch.h"
#include "Leo/Events/Event.h"

namespace Leo {

	// properties needed to create the window
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Leo Engine",
			unsigned int width = 1280,
			unsigned int height = 720
		)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// abstract window class (platform independent)
	class LEO_API Window
	{

	public:

		virtual ~Window() {};
		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual bool isVSyncEnabled() const = 0;
		virtual void setVSync(bool state) = 0;

		// create function to be defined per platform
		static Window* Create(const WindowProps& props = WindowProps());
	};

}