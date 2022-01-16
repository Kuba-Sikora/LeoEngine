#pragma once

#include "Leo/Core/Base.h"
#include "leopch.h"

namespace Leo {

	// EVENT TYPES
	enum class EventType
	{
		None = 0,
		KeyPress, KeyRelease, // keyboard events
		MouseButtonPress, MouseButtonRelease, // mouse button events
		MouseMove, MouseScroll, // other mouse events
		WindowClose, WindowResize, // windows events
	};

	// EVENT
	class LEO_API Event
	{

	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual std::string toString() const { return getName(); }

	protected:
		bool m_Handled = false;

	};

	// EVENT DISPATCHER
	class LEO_API EventDispatcher
	{

	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

	private:
		Event& m_Event;

	};

}

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
	                           virtual EventType getEventType() const override { return getStaticType(); }\
	                           virtual const char* getName() const override { return #type; }