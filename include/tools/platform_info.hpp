#pragma once

// Platform detection using predefined macros
#ifdef __CYGWIN__

    #pragma message( "Compiling with CYGWIN" )

    /* Windows x64  */
    #define MOON_PLATFORM_WINDOWS

	#define MOON_WINDOWS_CYGWIN

#elif __clang__ && (defined(_WIN32) || defined(_WIN64))

    #pragma message( "Compiling with CLANG LLMV" )

    /* Windows x64  */
    #define MOON_PLATFORM_WINDOWS

	#define MOON_WINDOWS_CLANG

#elif _WIN32 || _WIN64

#error "compiler not supported. Please, use CYGWIN"

#elif defined(__APPLE__) || defined(__OSX__) || defined(__MACH__)
	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	 * so we must check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define MOON_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define MOON_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif
#elif defined(__ANDROID__)
	#define MOON_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define MOON_PLATFORM_LINUX

	#if defined(GCC)
		#define MOON_LINUX_GCC
	#elif defined(__clang__)
		#define MOON_LINUX_CLANG
	#endif
#else
	/* Unknown compiler/platform */
	#error "Unknown platform!"
#endif // End of platform detection