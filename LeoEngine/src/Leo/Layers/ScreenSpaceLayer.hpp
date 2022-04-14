#pragma once

#include "Leo/Layers/Layer.hpp"

namespace Leo {
	
	class ScreenSpaceLayer : public Layer {

	public:
		ScreenSpaceLayer(std::string title) : Layer(title) {}

		virtual void OnEvent(Event& e) override;

		virtual void OnUpdate() override {}
		virtual void OnMount() override {}
		virtual void OnUnmount() override {}

	};

}
