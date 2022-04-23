#pragma once

#include "Event.hpp"

namespace Framework {

	// WINDOW CLOSE
	class WindowCloseEvent : public Event {

	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)

	};

	// WINDOW RESIZE
	class WindowResizeEvent : public Event {

	public:
		WindowResizeEvent(int width, int height)
			: width_(width), height_(height) {}

		[[nodiscard]] unsigned int GetWidth() const { return width_; };
		[[nodiscard]] unsigned int GetHeight() const { return height_; };

		[[nodiscard]] std::string ToString() const override {
			std::stringstream ss;
			ss << "Window resize: " << width_ << ", " << height_;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int width_, height_;

	};

}
