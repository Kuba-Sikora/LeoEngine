#include "leopch.hpp"

#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"
#include "Events/WindowEvent.hpp"
#include "Platform/Windows/WindowsWindow.hpp"

#include <glad/glad.h>

namespace Leo {

	static bool s_GLFWinitialized = false;

	// called in the Application constructor
	Window* Window::Create(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& closeCallback, const WindowProps& props)
	{
		return new WindowsWindow(eventCallback, closeCallback, props);
	}

	WindowsWindow::WindowsWindow(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& closeCallback, const WindowProps& props)
	{
		Init(eventCallback, closeCallback, props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	// UPDATE FUNCTION CALLED EVERY FRAME
	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	// INITIALIZE THE WINDOW
	void WindowsWindow::Init(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& closeCallback, const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		m_Data.EventCallback = eventCallback;
		m_Data.WindowCallback = closeCallback;

		CORE_WARN("Creating Window '{0}': {1}, {2}", props.Title, props.Width, props.Height);

		// initialize GLFW
		if (!s_GLFWinitialized) {
			if (!glfwInit())
				CORE_CRITICAL("GLFW not initialized");
			else
				CORE_WARN("GLFW initialized");

			s_GLFWinitialized = true;
		}

		// create the application window
		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), NULL, NULL);
		SetVSync(true);
		glfwMakeContextCurrent(m_Window);

		// initialize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			CORE_CRITICAL("failed to initialize GLAD");
		else
			CORE_WARN("GLAD initialized");

		// user pointer to access m_Data
		glfwSetWindowUserPointer(m_Window, &m_Data);

		// setting GLFW callback to be handled by the Application::OnEvent function

		// Window Events
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.WindowCallback(event);
		});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.WindowCallback(event);
		});

		// Key Events
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					KeyPressEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT: {
					KeyPressEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE: {
					KeyReleaseEvent event(key);
					data.EventCallback(event);
					break;
				}
			}
		});

		// Mouse Events
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					MouseButtonPressEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE: {
					MouseButtonReleaseEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double offsetX, double offsetY) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrollEvent event((float)offsetX, (float)offsetY);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMoveEvent event((float)x, (float)y);
			data.EventCallback(event);
		});
	}

	// function called in the destructor
	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::SetVSync(bool state)
	{
		m_Data.VSync = state;

		if (state)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	bool WindowsWindow::IsVSyncEnabled() const
	{
		return m_Data.VSync;
	}

}