#pragma once

namespace Framework {

	// temporary Input struct (functions defined per platform)
	struct Input {

		static bool IsKeyPressed(void* window, int key);
		static bool IsMouseButtonPressed(void* window, int button);

	};

}
