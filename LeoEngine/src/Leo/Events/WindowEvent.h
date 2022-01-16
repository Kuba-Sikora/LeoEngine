#pragma once

#include "Leo/Events/Event.h"

namespace Leo {

	// WINDOW CLOSE
	class LEO_API WindowClose : public Event
	{

	public:
		WindowClose() {}

		EVENT_CLASS_TYPE(WindowClose)

	};

	// WINDOW RESIZE
	class LEO_API WindowResize : public Event
	{

	public:
		WindowResize(int width, int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int getWidth() { return m_Width; };
		inline unsigned int getHeight() { return m_Height; };

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "Window resize: " << m_Width << ", " << m_Height;
			return ss.str();
		}

	private:
		unsigned int m_Width, m_Height;

	};

}
