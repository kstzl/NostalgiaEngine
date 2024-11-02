#pragma once

#include <cassert>

#ifdef NOSTALGIA_BUILD_DLL
#define NOSTALGIA_API __declspec(dllexport)
#else
#define NOSTALGIA_API __declspec(dllimport)
#endif

#define NOSTALGIA_ASSERT(x) assert(x)