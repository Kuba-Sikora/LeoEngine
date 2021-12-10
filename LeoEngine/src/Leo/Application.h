#pragma once

#include "Core.h"

namespace Leo {

	class LEO_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// to be defined in client (extern)
	Application* CreateApplication();

}


