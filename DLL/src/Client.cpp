#include "Client.h"

#include <iostream>

namespace dll
{
	template<>
	SN_RCR_API int dll::function<int>()
	{
		return 20;
	}

	template<>
	SN_RCR_API int dll::function<int>(int a)
	{
		return a + 20;
	}

	template<>
	SN_RCR_API int dll::function<int>(int a, int b)
	{
		return a * b + 20;
	}

	template<> 
	SN_RCR_API int dll::function2<float>(float f, int a) 
	{ 
		return 1; 
	}

	template<> 
	SN_RCR_API int dll::function2<const float>(const float f, int a) 
	{ 
		return 2; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile float>(volatile float f, int a) 
	{ 
		return 3; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile const float>(volatile const float f, int a) 
	{ 
		return 4; 
	}

	template<> 
	SN_RCR_API int dll::function2<float&>(float& f, int a) 
	{ 
		return 5; 
	}

	template<> 
	SN_RCR_API int dll::function2<const float&>(const float& f, int a) 
	{ 
		return 6; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile float&>(volatile float& f, int a) 
	{ 
		return 7; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile const float&>(volatile const float& f, int a) 
	{ 
		return 8; 
	}

	template<> 
	SN_RCR_API int dll::function2<float&&>(float&& f, int a) 
	{ 
		return 9; 
	}

	template<> 
	SN_RCR_API int dll::function2<const float&&>(const float&& f, int a) 
	{ 
		return 20; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile float&&>(volatile float&& f, int a) 
	{ 
		return 11; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile const float&&>(volatile const float&& f, int a) 
	{ 
		return 12; 
	}

	template<> 
	SN_RCR_API int dll::function2<const float*>(const float* f, int a) 
	{ 
		return 13; 
	}

	template<> 
	SN_RCR_API int dll::function2<const float* const>(const float* const f, int a) 
	{ 
		return 14; 
	}

	template<> 
	SN_RCR_API int dll::function2<float* const>(float* const f, int a) 
	{ 
		return 15; 
	}

	template<> 
	SN_RCR_API int dll::function2<float*>(float* f, int a) 
	{ 
		return 16; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile float*>(volatile float* f, int a) 
	{ 
		return 17; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile float* const>(volatile float* const f, int a) 
	{ 
		return 18; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile const float*>(volatile const float* f, int a) 
	{ 
		return 19; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile const float* const>(volatile const float* const f, int a) 
	{ 
		return 20; 
	}

	template<> 
	SN_RCR_API int dll::function2<const float* volatile>(const float* volatile f, int a) 
	{ 
		return 21; 
	}

	template<> 
	SN_RCR_API int dll::function2<const float* volatile const>(const float* volatile const f, int a) 
	{ 
		return 22; 
	}

	template<> 
	SN_RCR_API int dll::function2<float* volatile const>(float* volatile const f, int a) 
	{ 
		return 23; 
	}

	template<> 
	SN_RCR_API int dll::function2<float* volatile>(float* volatile f, int a) 
	{ 
		return 24; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile float* volatile>(volatile float* volatile f, int a) 
	{ 
		return 25; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile float* volatile const>(volatile float* volatile const f, int a) 
	{ 
		return 26; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile const float* volatile>(volatile const float* volatile f, int a) 
	{ 
		return 27; 
	}

	template<> 
	SN_RCR_API int dll::function2<volatile const float* volatile const>(volatile const float* volatile const f, int a) 
	{ 
		return 28; 
	}

	template<> 
	SN_RCR_API int dll::function2<dll::B>(dll::B f, int a) 
	{ 
		return 28; 
	}

	template<> 
	SN_RCR_API int dll::function2<dll::A<dll::B>>(dll::A<dll::B> f, int a) 
	{ 
		return 28; 
	}

	template<>
	SN_RCR_API float dll::Class1::method0<float>()
	{
		return 1.0f;
	}

	template<>
	SN_RCR_API float dll::Class1::method1<float>(int a)
	{
		return 1.1f;
	}

	template<>
	SN_RCR_API float dll::Class1::method2<float>(int a, float b)
	{
		return 1.2f;
	}

	SN_RCR_API int dll::function10(const volatile int* const volatile* const volatile p)
	{
		return 0;
	}
}
