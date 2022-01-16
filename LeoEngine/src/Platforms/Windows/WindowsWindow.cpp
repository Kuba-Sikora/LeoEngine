#include "leopch.h"

#include "Platforms/Windows/WindowsWindow.h"
#include "Leo/Core/Log.h"

namespace Leo {

	static bool s_GLFWinitialized = false;

	// called in the Application constructor
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	// UPDATE FUNCTION CALLED EVERY FRAME
	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	// function called in the constructor
	void WindowsWindow::init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		CORE_INFO("Creating Window '{0}': {1}, {2}", props.Title, props.Width, props.Height);

		if (!s_GLFWinitialized)
		{
			int success = glfwInit();
			CORE_INFO(success);

			s_GLFWinitialized = true;
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
	}

	// function called in the destructor
	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

}