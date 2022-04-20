#pragma once

#include "Event.hpp"

namespace Framework {

	// BASE BUTTON EVENT CLASS
	class MouseButtonEvent : public Event {

	public:
		inline unsigned int getButtonCode() { return m_ButtonCode; };

	protected:
		MouseButtonEvent(unsigned int buttonCode)
			: m_ButtonCode(buttonCode) {}

		unsigned int m_ButtonCode;

	};

	//BUTTON PRESS EVENT
	class MouseButtonPressEvent : public MouseButtonEvent {

	public:
		MouseButtonPressEvent(unsigned int buttonCode)
			: MouseButtonEvent(buttonCode), m_ButtonCode(buttonCode) {}

		EVENT_CLASS_TYPE(MouseButtonPress)

	private:
		unsigned int m_ButtonCode;

	};

	// BUTTON RELEASE EVENT
	class MouseButtonReleaseEvent : public MouseButtonEvent {

	public:
		MouseButtonReleaseEvent(unsigned int buttonCode)
			: MouseButtonEvent(buttonCode), m_ButtonCode(buttonCode) {}

		EVENT_CLASS_TYPE(MouseButtonRelease)

	private:
		unsigned int m_ButtonCode;

	};

	// MOUSE MOVE EVENT
	class MouseMoveEvent : public Event {

	public:
		MouseMoveEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float getX() { return m_MouseX; };
		inline float getY() { return m_MouseY; };

		EVENT_CLASS_TYPE(MouseMove)

	private:
		float m_MouseX, m_MouseY;

	};

	// MOUSE SCROLL EVENT (Supports horizontal scrolling)
	class MouseScrollEvent : public Event {

	public:
		MouseScrollEvent(float offsetX, float offsetY)
			: m_OffsetX(offsetX), m_OffsetY(offsetY) {}

		inline float getOffsetX() { return m_OffsetX; };
		inline float getOffsetY() { return m_OffsetY; };

		EVENT_CLASS_TYPE(MouseScroll)

	private:
		float m_OffsetX;
		float m_OffsetY;

	};

}