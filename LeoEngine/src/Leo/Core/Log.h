#pragma once

#include "Leo/Core/Base.h"

#include <spdlog/spdlog.h>

namespace Leo {

	class LEO_API Log
	{

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() 
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

// Core Log macros
#define CORE_ERROR(...)   ::Leo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_WARN(...)    ::Leo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_LOG(...)    ::Leo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_TRACE(...)   ::Leo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_CRITICAL(...)   ::Leo::Log::GetCoreLogger()->critical(__VA_ARGS__)
						  
// Client Log macros	  
#define APP_ERROR(...)        ::Leo::Log::GetClientLogger()->error(__VA_ARGS__)
#define APP_WARN(...)         ::Leo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define APP_LOG(...)         ::Leo::Log::GetClientLogger()->info(__VA_ARGS__)
#define APP_TRACE(...)        ::Leo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define APP_CRITICAL(...)        ::Leo::Log::GetClientLogger()->critical(__VA_ARGS__)