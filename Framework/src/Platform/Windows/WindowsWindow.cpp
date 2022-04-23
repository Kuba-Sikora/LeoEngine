#include "leopch.hpp"

#include "WindowsWindow.hpp"
#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"
#include "Events/WindowEvent.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Framework {

	static bool s_GLFWinitialized = false;

	// called in the Application constructor
	Window* Window::Create(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props) {
		return new WindowsWindow(eventCallback, windowCallback, props);
	}

	WindowsWindow::WindowsWindow(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props) {
		Init(eventCallback, windowCallback, props);
		CORE_LOG("{0} constructed", props.Title);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
		CORE_LOG("{0} deleted", data_.Title);
	}

	// UPDATE FUNCTION CALLED EVERY FRAME
	void WindowsWindow::OnUpdate() {
		glfwSwapBuffers(native_window_);
		glfwPollEvents();
	}

	// INITIALIZE THE WINDOW
	void WindowsWindow::Init(const EventCallbackFn& eventCallback, const WindowEventCallbackFn& windowCallback, const WindowProps& props) {
		data_.Title = props.Title;
		data_.Width = props.Width;
		data_.Height = props.Height;

		data_.EventCallback = eventCallback;
		data_.WindowCallback = windowCallback;

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
		native_window_ = glfwCreateWindow(static_cast<int>(data_.Width), static_cast<int>(data_.Height), data_.Title.c_str(), nullptr, nullptr);
		SetVSync(true);
		glfwMakeContextCurrent(native_window_);

		// initialize GLAD
		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
			CORE_CRITICAL("failed to initialize GLAD");
		else
			CORE_WARN("GLAD initialized");

		// user pointer to access data_
		glfwSetWindowUserPointer(native_window_, &data_);

		// setting GLFW callback to be handled by the Application::OnEvent function

		// Window Events
		glfwSetWindowCloseCallback(native_window_, [](GLFWwindow* window) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			WindowCloseEvent event;
			data.WindowCallback(event);
		});

		glfwSetWindowSizeCallback(native_window_, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.WindowCallback(event);
		});

		// Key Events
		glfwSetKeyCallback(native_window_, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			switch (action) {
				case GLFW_PRESS:
				{
					KeyPressEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleaseEvent event(key);
					data.EventCallback(event);
					break;
				}
			}
		});

		// Mouse Events
		glfwSetMouseButtonCallback(native_window_, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			switch (action) {
				case GLFW_PRESS:
				{
					MouseButtonPressEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleaseEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(native_window_, [](GLFWwindow* window, double offsetX, double offsetY) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			MouseScrollEvent event((float)offsetX, (float)offsetY);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(native_window_, [](GLFWwindow* window, double x, double y) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			MouseMoveEvent event((float)x, (float)y);
			data.EventCallback(event);
		});
	}

	// function called in the destructor
	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(native_window_);
	}

	void WindowsWindow::SetVSync(const bool state) {
		data_.VSync = state;

		if (state)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	bool WindowsWindow::IsVSyncEnabled() const {
		return data_.VSync;
	}

}
