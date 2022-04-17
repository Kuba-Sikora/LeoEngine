#pragma once

#include "leopch.hpp"
#include <Leo/Events/Event.hpp>

namespace Leo {

	// abstract Layer class (derived layers can implement their own on methods)
	class Layer {

	public:
		Layer() = delete;
		Layer(std::string title)
			: m_Title(title) {
			CORE_LOG("Layer constructor: {0}", m_Title);
		}

		Layer(const Layer& other) { CORE_LOG("Copied Layer {0}", m_Title); }
		
		// virtual destructor to avoid memory leakage when derived layer classes are deleted as the polymorphic Layer type 
		// deleting a derived layer class as Layer type will call the decosntructor of both Layer class and the Derived class
		virtual ~Layer() {}

		std::string GetTitle() { return m_Title; }

		virtual void OnMount() = 0;
		virtual void OnUnmount() = 0;
		virtual void OnUpdate() = 0;

		// return true if event should stop propagating and be marked as handled
		// else return false
		virtual bool OnEvent(Event& e) = 0;

	protected:
		std::string m_Title;
	};

}