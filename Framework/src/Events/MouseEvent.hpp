#pragma once

#include "Event.hpp"

namespace Framework {

	// BASE BUTTON EVENT CLASS
	class MouseButtonEvent : public Event {

	public:
		[[nodiscard]] unsigned int GetButtonCode() const { return button_code_; };

	protected:
		MouseButtonEvent(unsigned int buttonCode)
			: button_code_(buttonCode) {}

		unsigned int button_code_;

	};

	//BUTTON PRESS EVENT
	class MouseButtonPressEvent : public MouseButtonEvent {

	public:
		MouseButtonPressEvent(unsigned int buttonCode)
			: MouseButtonEvent(buttonCode) {}

		EVENT_CLASS_TYPE(MouseButtonPress)

	};

	// BUTTON RELEASE EVENT
	class MouseButtonReleaseEvent : public MouseButtonEvent {

	public:
		MouseButtonReleaseEvent(unsigned int buttonCode)
			: MouseButtonEvent(buttonCode) {}

		EVENT_CLASS_TYPE(MouseButtonRelease)

	};

	// MOUSE MOVE EVENT
	class MouseMoveEvent : public Event {

	public:
		MouseMoveEvent(float x, float y)
			: mouse_x_(x), mouse_y_(y) {}

		[[nodiscard]] float GetX() const { return mouse_x_; };
		[[nodiscard]] float GetY() const { return mouse_y_; };

		EVENT_CLASS_TYPE(MouseMove)

	private:
		float mouse_x_, mouse_y_;

	};

	// MOUSE SCROLL EVENT (Supports horizontal scrolling)
	class MouseScrollEvent : public Event {

	public:
		MouseScrollEvent(float offsetX, float offsetY)
			: offset_x_(offsetX), offset_y_(offsetY) {}

		[[nodiscard]] float GetOffsetX() const { return offset_x_; };
		[[nodiscard]] float GetOffsetY() const { return offset_y_; };

		EVENT_CLASS_TYPE(MouseScroll)

	private:
		float offset_x_;
		float offset_y_;

	};

}