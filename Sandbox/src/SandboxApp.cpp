#include <LeoEngine.hpp>

class Sandbox : public Leo::Application {

public:
	Sandbox() { APP_LOG("sandbox constructor"); }
	~Sandbox() { APP_LOG("sandbox delete"); }

};

// Initialize engine CreateApplication function
Leo::Application* Leo::CreateApplication() {
	return new Sandbox();
}