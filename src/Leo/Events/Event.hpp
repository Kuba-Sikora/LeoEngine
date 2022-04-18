#pragma once

#include "leopch.hpp"

namespace Leo {

	// EVENT TYPES
	enum class EventType {
		None = 0,
		KeyPress, KeyRelease, // keyboard events
		MouseButtonPress, MouseButtonRelease, // mouse button events
		MouseMove, MouseScroll, // other mouse events
		WindowClose, WindowResize, // windows events
	};

	// EVENT
	class Event {

	public:
		bool IsHandled() { return m_Handled; }
		void StopPropagation() { m_Handled = true; }

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

	protected:
		bool m_Handled = false;

	};

}

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
	                           virtual EventType GetEventType() const override { return GetStaticType(); }\
	                           virtual const char* GetName() const override { return #type; }