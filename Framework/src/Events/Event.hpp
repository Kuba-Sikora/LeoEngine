#pragma once

#include "leopch.hpp"

namespace Framework {

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
		// virtual constructor for polymorphism
		virtual ~Event() = default;

		[[nodiscard]] bool IsHandled() const { return handled_; }
		void StopPropagation() { handled_ = true; }

		[[nodiscard]] virtual EventType GetEventType() const = 0;
		[[nodiscard]] virtual const char* GetName() const = 0;
		[[nodiscard]] virtual std::string ToString() const { return GetName(); }

	protected:
		bool handled_ = false;

	};

}

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
	                           virtual EventType GetEventType() const override { return GetStaticType(); }\
	                           virtual const char* GetName() const override { return #type; }