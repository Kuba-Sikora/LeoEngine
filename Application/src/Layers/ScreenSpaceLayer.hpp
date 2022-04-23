#pragma once

#include "Layer.hpp"

namespace Framework {
	
	class ScreenSpaceLayer : public Layer {

	public:
		ScreenSpaceLayer(std::string title) : Layer(std::move(title)) {}

		virtual bool OnEvent(Event& e) override;

		virtual void OnUpdate() override {}
		virtual void OnMount() override {}
		virtual void OnUnmount() override {}

	};

}
