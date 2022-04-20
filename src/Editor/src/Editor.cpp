#include "Editor.hpp"

Editor* Editor::s_Instance = nullptr;

Editor* Editor::GetInstance() {
	if (!s_Instance) {
		s_Instance = new Editor;
	}
	return s_Instance;
}

Editor::Editor() {}

void Editor::Start() {
	running_ = true;

	while (running_) {
		if (application_->running_)
			application_->Update();
	}
}
