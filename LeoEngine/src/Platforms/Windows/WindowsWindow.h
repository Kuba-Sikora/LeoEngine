#pragma once

#include "Leo/Core/Base.h"
#include "Leo/Core/Window.h"

#include <GLFW/glfw3.h>

namespace Leo {

	class LEO_API WindowsWindow : public Window
	{

	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() override { return m_Data.Width; }
		inline unsigned int getHeight() override { return m_Data.Height; }

	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
		};

		WindowData m_Data;

	};

}