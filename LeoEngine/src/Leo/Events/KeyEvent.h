#pragma once

#include "Leo/Events/Event.h"

namespace Leo {

	// BASE CLASS FOR KEY EVENTS
	class LEO_API KeyEvent : public Event
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
	class LEO_API KeyPressEvent : public KeyEvent
	{

	public:
		KeyPressEvent(unsigned int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int getRepeatCount()
		{

		}

		EVENT_CLASS_TYPE(KeyPress)

	private:
		int m_RepeatCount;

	};

	// KEY RELEASE
	class LEO_API KeyReleaseEvent : public KeyEvent
	{

	public:
		KeyReleaseEvent(unsigned int keyCode)
			: KeyEvent(keyCode), m_KeyCode(keyCode) {}

		EVENT_CLASS_TYPE(KeyRelease)

	private:
		unsigned int m_KeyCode;
		
	};

}