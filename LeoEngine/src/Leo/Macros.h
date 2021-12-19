#pragma once

#ifdef LEO_PLATFORM_WINDOWS
	#ifdef LEO_BUILD_DLL
		#define LEO_API __declspec(dllexport)
	#else
		#define LEO_API __declspec(dllimport)
	#endif
#else
	#error Leo Engine only supports Windows
#endif