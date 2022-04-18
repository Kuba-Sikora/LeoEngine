#pragma once

#include "Layers/Layer.hpp"

namespace Leo {
	
	class ScreenSpaceLayer : public Layer {

	public:
		ScreenSpaceLayer(std::string title) : Layer(title) {}

		virtual bool OnEvent(Event& e) override;

		virtual void OnUpdate() override {}
		virtual void OnMount() override {}
		virtual void OnUnmount() override {}

	};

}
