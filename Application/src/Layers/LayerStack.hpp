#pragma once

#include "leopch.hpp"
#include "Layer.hpp"

namespace Framework {

	// LayerStack is a singleton class that includes a std::vector of all the mounted Layers
	class LayerStack {

	public:
		LayerStack(LayerStack& other) = delete;
		~LayerStack();

		static LayerStack* GetInstance();

		std::vector<Layer*>& GetLayers();

		void PushLayerFront(Layer* layer);
		void PushLayerBack(Layer* layer);
		void PopLayerFront(Layer* layer);
		void PopLayerBack(Layer* layer);

		void OnEvent(Event& e) const;

	private:
		LayerStack();

		static LayerStack* s_Instance;

		// - a vector that stores pointers to all the layers (cannot store abstract classes by value)
		// - emplace method is used to push layers in order to avoid unnecessary copying
		std::vector<Layer*> layers_;

	};

}