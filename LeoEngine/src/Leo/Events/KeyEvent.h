#pragma once

#include "Leo/Events/Event.h"

namespace Leo {

	// BASE CLASS FOR KEY EVENTS
	class KeyEvent : public Event
	{

	public:
		inline unsigned int getKeyCode() { return m_KeyCode; };

	protected:

		// Constructor is protected - can't create KeyEvent outside Event class
		KeyEvent(unsigned int keyCode)
			: m_KeyCode(keyCode) {}

		unsigned int m_KeyCode;

	};

	// KEY PRESS
	class KeyPressEvent : public KeyEvent
	{

	public:
		KeyPressEvent(unsigned int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int getRepeatCount() { return m_RepeatCount; }

		EVENT_CLASS_TYPE(KeyPress)

	private:
		int m_RepeatCount;

	};

	// KEY RELEASE
	class KeyReleaseEvent : public KeyEvent
	{

	public:
		KeyReleaseEvent(unsigned int keyCode)
			: KeyEvent(keyCode), m_KeyCode(keyCode) {}

		EVENT_CLASS_TYPE(KeyRelease)

	private:
		unsigned int m_KeyCode;
		
	};

}