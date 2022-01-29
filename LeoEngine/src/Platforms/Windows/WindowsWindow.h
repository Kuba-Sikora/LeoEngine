#pragma once

#include "Leo/Core/Base.h"
#include "Leo/Core/Window.h"

#include <GLFW/glfw3.h>

namespace Leo {

	class WindowsWindow : public Window
	{

	public:
		WindowsWindow(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return m_Data.Width; }
		inline unsigned int getHeight() const override { return m_Data.Height; }

		bool isVSyncEnabled() const override;
		void setVSync(bool state) override;

	private:
		virtual void init(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props);
		virtual void shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			// callback functions from the Application
			EventCallbackFn eventCallback; // onEvent
			WindowEventCallbackFn windowCallback; // onWindowEvent
		};

		WindowData m_Data;

	};

}