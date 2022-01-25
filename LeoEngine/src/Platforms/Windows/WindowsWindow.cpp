#include "leopch.h"

#include "Platforms/Windows/WindowsWindow.h"
#include "Leo/Events/WindowEvent.h"
#include "Leo/Events/KeyEvent.h"
#include "Leo/Events/MouseEvent.h"

namespace Leo {

	static bool s_GLFWinitialized = false;

	// called in the Application constructor
	Window* Window::Create(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& closeCallback, const WindowProps& props)
	{
		return new WindowsWindow(eventCallback, closeCallback, props);
	}

	WindowsWindow::WindowsWindow(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& closeCallback, const WindowProps& props)
	{
		init(eventCallback, closeCallback, props);
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
	void WindowsWindow::init(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& closeCallback, const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		m_Data.eventCallback = eventCallback;
		m_Data.windowCallback = closeCallback;

		CORE_LOG("Creating Window '{0}': {1}, {2}", props.Title, props.Width, props.Height);

		if (!s_GLFWinitialized)
		{
			if (!glfwInit())
				CORE_CRITICAL("GLFW not initialized");

			s_GLFWinitialized = true;
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), NULL, NULL);
		setVSync(true);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);

		// setting GLFW callback to be handled by the Application::onEvent function

		// Window Events
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.windowCallback(event);
		});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.windowCallback(event);
		});

		// Key Events
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleaseEvent event(key);
					data.eventCallback(event);
					break;
				}
			}
		});

		// Mouse Events
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleaseEvent event(button);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double offsetX, double offsetY)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrollEvent event((float)offsetX, (float)offsetY);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMoveEvent event((float)x, (float)y);
			data.eventCallback(event);
		});
	}

	// function called in the destructor
	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::setVSync(bool state)
	{
		m_Data.VSync = state;

		if (state)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	bool WindowsWindow::isVSyncEnabled() const
	{
		return m_Data.VSync;
	}

}