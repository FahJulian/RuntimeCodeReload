#pragma once

#define SN_RCR_DLL_PATH "C:\\dev\\RuntimeCodeReload\\bin\\Debug\\x64\\Test.dll"
#include "../../LIB/src/RuntimeCodeReload.h"

namespace dll
#define SN_RCR_NAMESPACE "dll"
{
	template<typename T>
	struct A
	{
	};

	struct B
	{
	};

	SN_RCR_FUNCTION_1_ARGS(int, function10, const volatile int * const volatile * const volatile, p);

	template<typename C>
	SN_RCR_FUNCTION_0_ARGS(int, function, C);
	template<typename C>
	SN_RCR_FUNCTION_1_ARGS(int, function, int, a, C);
	template<typename C>
	SN_RCR_FUNCTION_2_ARGS(int, function, int, a, int, b, C);

	template<typename C>
	SN_RCR_FUNCTION_2_ARGS(int, function2, C, a, int, b, C);

	template<typename C>
	SN_RCR_FUNCTION_8_ARGS(int, function8, int, a, int, b, int, c, int, d, int, e, int, f, int, g, int, h, C);

	class Class1
	{
	public:
		template<typename C>
		SN_RCR_MEMBER_FUNCTION_0_ARGS(C, method0, C);

		template<typename C>
		SN_RCR_MEMBER_FUNCTION_1_ARGS(C, method1, int, a, C);

		template<typename C>
		SN_RCR_MEMBER_FUNCTION_2_ARGS(C, method2, int, a, float, b, C);
	};
}
