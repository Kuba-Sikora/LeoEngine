#pragma once

#include "Event.hpp"

namespace Framework {

	// BASE CLASS FOR KEY EVENTS
	class KeyEvent : public Event {

	public:
		[[nodiscard]] unsigned int GetKeyCode() const { return key_code_; };

	protected:

		// Constructor is protected - can't create KeyEvent instances (only their derived types)
		KeyEvent(unsigned int keyCode)
			: key_code_(keyCode) {}

		unsigned int key_code_;

	};

	// KEY PRESS
	class KeyPressEvent : public KeyEvent {

	public:
		KeyPressEvent(unsigned int keyCode, int repeatCount)
			: KeyEvent(keyCode), repeat_count_(repeatCount) {}

		[[nodiscard]] int GetRepeatCount() const { return repeat_count_; }

		EVENT_CLASS_TYPE(KeyPress)

	private:
		int repeat_count_;

	};

	// KEY RELEASE
	class KeyReleaseEvent : public KeyEvent {

	public:
		KeyReleaseEvent(unsigned int keyCode)
			: KeyEvent(keyCode) {}

		EVENT_CLASS_TYPE(KeyRelease)


	};

}