#include <LeoCore.h>

class Sandbox : public Leo::Application
{

public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

// Initialize engine CreateApplication function
Leo::Application* Leo::CreateApplication()
{
	return new Sandbox();
}