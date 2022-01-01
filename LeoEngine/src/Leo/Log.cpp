#include "leopch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/pattern_formatter.h"

namespace Leo {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		s_CoreLogger = spdlog::stdout_color_mt("LEO-CORE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

		// set logger formatting
		spdlog::set_pattern(*s_CoreLogger, ">> %^[%H:%M:%S.%e] %n: %v%$");
		spdlog::set_pattern(*s_ClientLogger, ">> %^[%H:%M:%S.%e] %n: %v%$");
	}

}