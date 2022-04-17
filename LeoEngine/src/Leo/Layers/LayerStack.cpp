#include "leopch.hpp"
#include "Leo/Layers/LayerStack.hpp"

namespace Leo {

	LayerStack* LayerStack::s_Instance = nullptr;

	LayerStack* LayerStack::GetInstance() {
		if (!s_Instance) {
			s_Instance = new LayerStack;
		}
		return s_Instance;
	}

	LayerStack::LayerStack() {
		// reserve memory for 5 layers to avoid unnecessary reallocations
		m_Layers.reserve(5);
	}

	LayerStack::~LayerStack() {
		CORE_LOG("delete LayerStack");

		// delete all the heap allocated layers
		for (Layer* layer : m_Layers) {
			delete layer;
		}
	}

	std::vector<Layer*>& LayerStack::GetLayers() {
		return m_Layers;
	}

	void LayerStack::PushLayerFront(Layer* layer) {
		m_Layers.insert(m_Layers.begin(), layer);
	}
	
	void LayerStack::PushLayerBack(Layer* layer) {
		m_Layers.push_back(layer);
	}

	void LayerStack::OnEvent(Event& e) {
		for (Layer* layer : m_Layers) {
			layer->OnEvent(e);

			if (e.handled)
				break;
		}
	}
}