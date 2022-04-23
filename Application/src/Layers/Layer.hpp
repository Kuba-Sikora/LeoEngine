#pragma once

#include "leopch.hpp"
#include "Events/Event.hpp"

namespace Framework {

	// abstract Layer class (derived layers can implement their own on methods)
	class Layer {

	public:
		Layer() = delete;

		explicit Layer(std::string title)
			: title_(std::move(title)) {
			CORE_LOG("Layer constructor: {0}", title_);
		}

		Layer(const Layer& other) { CORE_LOG("Copied Layer {0}", title_); }
		
		// virtual destructor to avoid memory leakage when derived layer classes are deleted as the polymorphic Layer type 
		// deleting a derived layer class as Layer type will call the deconstructor of both Layer class and the Derived class
		virtual ~Layer() = default;

		std::string GetTitle() { return title_; }

		virtual void OnMount() = 0;
		virtual void OnUnmount() = 0;
		virtual void OnUpdate() = 0;

		// return true if event should stop propagating and be marked as handled
		// else return false
		virtual bool OnEvent(Event& e) = 0;

	protected:
		std::string title_;
	};

}