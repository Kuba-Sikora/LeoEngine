#include "leopch.hpp"
#include "Leo/Layers/ScreenSpaceLayer.hpp"

namespace Leo {
	
	void ScreenSpaceLayer::OnEvent(Event& e) { CORE_LOG("{0}: {1}", m_Title, e.ToString()); }

}