#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/pattern_formatter.h"

namespace Leo {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {

		s_CoreLogger = spdlog::stdout_color_mt("Leo-Core");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);

		//spdlog::set_pattern(s_CoreLogger*, ">> %^[%T] %n: %v%$");

		s_CoreLogger->error("logger is working");

	}

}