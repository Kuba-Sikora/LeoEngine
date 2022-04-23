#include "leopch.hpp"
#include "LayerStack.hpp"

namespace Framework {
	LayerStack* LayerStack::s_Instance = nullptr;

	LayerStack* LayerStack::GetInstance() {
		if (!s_Instance) {
			s_Instance = new LayerStack;
		}
		return s_Instance;
	}

	LayerStack::LayerStack() {
		// reserve memory for 5 layers to avoid unnecessary reallocations
		layers_.reserve(5);
	}

	LayerStack::~LayerStack() {
		CORE_LOG("delete LayerStack");

		// delete all the heap allocated layers
		for (Layer* layer : layers_) {
			delete layer;
		}
	}

	std::vector<Layer*>& LayerStack::GetLayers() {
		return layers_;
	}

	void LayerStack::PushLayerFront(Layer* layer) {
		layers_.insert(layers_.begin(), layer);
	}
	
	void LayerStack::PushLayerBack(Layer* layer) {
		layers_.push_back(layer);
	}

	void LayerStack::OnEvent(Event& e) const {
		if (!e.IsHandled()) {
			for (Layer* layer : layers_) {
				if (layer->OnEvent(e))
					break;
			}
		}
	}
}