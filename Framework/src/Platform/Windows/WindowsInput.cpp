#include "leopch.hpp"
#include <GLFW/glfw3.h>
#include "Input/Input.hpp"

namespace Framework {

	bool Input::IsKeyPressed(void* window, int key) {
		const int state = glfwGetKey(static_cast<GLFWwindow*>(window), key);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(void* window, int button) {
		const int state = glfwGetMouseButton(static_cast<GLFWwindow*>(window), button);
		return state == GLFW_PRESS;
	}

}