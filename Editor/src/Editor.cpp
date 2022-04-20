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

Editor::Editor(Application* app) : application_(app), running_(false) {
	Framework::WindowProps props = Framework::WindowProps("Editor Window");
	window_ = std::shared_ptr<Framework::Window>(Framework::Window::Create(
		std::bind(&Editor::OnEvent, this, std::placeholders::_1),
		std::bind(&Editor::OnWindowEvent, this, std::placeholders::_1),
		props
	));
}

void Editor::Run() {
	running_ = true;
	application_->AttachToEditor();
	application_->DetachFromEditor();

	while (running_) {
		window_->OnUpdate();
		if (application_->running_)
			application_->OnUpdate();
	}
}

void Editor::OnEvent(Framework::Event& e) {
	application_->OnEvent(e);
}

void Editor::OnWindowEvent(Framework::Event& e) {
	switch (e.GetEventType()) {
		case Framework::EventType::WindowClose:
			running_ = false;
			break;

		case Framework::EventType::WindowResize:
			// casting the Event object to WindowResizeEvent in order to access the
			// width and height
			Framework::WindowResizeEvent resizeEvent = *dynamic_cast<Framework::WindowResizeEvent*>(&e);
			APP_LOG("window resize: {0}px, {1}px", resizeEvent.getWidth(),
				resizeEvent.getHeight());
			break;
	}
}