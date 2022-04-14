#pragma once

#include "Leo/Events/Event.hpp"

namespace Leo {

	// WINDOW CLOSE
	class WindowCloseEvent : public Event {

	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)

	};

	// WINDOW RESIZE
	class WindowResizeEvent : public Event {

	public:
		WindowResizeEvent(int width, int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int getWidth() { return m_Width; };
		inline unsigned int getHeight() { return m_Height; };

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Window resize: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int m_Width, m_Height;

	};

}
