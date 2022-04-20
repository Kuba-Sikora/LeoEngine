#include "Editor.hpp"

Editor* Editor::s_Instance = nullptr;

Editor* Editor::Construct(Application* app) {
	if (!s_Instance) {
		s_Instance = new Editor(app);
	}
	return s_Instance;
}

Editor* Editor::Get() {
	return s_Instance;
}

Editor::Editor(Application* app) : application_(app) {}

void Editor::Start() {
	running_ = true;

	while (running_) {
		if (application_->running_)
			application_->Update();
	}
}
