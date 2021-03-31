#pragma once

#include <iostream>

#include "sonic/debug/Log.h"

#include "DllReloader.h"

#include "Client.h"

typedef unsigned int Entity;

void testFunctions()
{
	float f = 0.0f;

	dll::function2<float>(f, int());
	dll::function2<const float>(f, int());
	dll::function2<float*>(&f, int());
	dll::function2<float* volatile>(&f, int());
	dll::function2<float* const>(&f, int());
	dll::function2<float* volatile const>(&f, int());
	dll::function2<const float*>(&f, int());
	dll::function2<const float* volatile>(&f, int());
	dll::function2<const float* const>(&f, int());
	dll::function2<const float* volatile const>(&f, int());
	dll::function2<float&>(f, int());
	dll::function2<float&&>(std::move(f), int());
	dll::function2<const float&>(f, int());
	dll::function2<const float&&>(std::move(f), int());
	dll::function2<volatile float*>(&f, int());
	dll::function2<volatile float* volatile>(&f, int());
	dll::function2<volatile float* const>(&f, int());
	dll::function2<volatile float* volatile const>(&f, int());
	dll::function2<volatile const float*>(&f, int());
	dll::function2<volatile const float* volatile>(&f, int());
	dll::function2<volatile const float* const>(&f, int());
	dll::function2<volatile const float* volatile const>(&f, int());
	dll::function2<volatile float&>(f, int());
	dll::function2<volatile float&&>(std::move(f), int());
	dll::function2<volatile const float&>(f, int());
	dll::function2<volatile const float&&>(std::move(f), int());
	dll::function2<volatile float>(f, int());
	dll::function2<volatile const float>(f, int());

	dll::function2<dll::B>({ }, int());
	sonic::Log::trace(dll::function2<dll::A<dll::B>>({ }, int()));

	sonic::Log::trace(dll::function<int>());
	sonic::Log::trace(dll::function<int>(3));
	sonic::Log::trace(dll::function<int>(8, 9));

	dll::Class1 instance;
	sonic::Log::trace(instance.method0<float>());
	sonic::Log::trace(instance.method1<float>(3));
	sonic::Log::trace(instance.method2<float>(5, 6.0f));

	int* p = nullptr;
	dll::function10(&p);
}

int main()
{
	sonic::Log::init("C:/dev/RuntimeCodeReload/log/log.log", std::cout, sonic::Log::ALL, sonic::Log::ALL);

	sonic::DllReloader::Settings settings;
	settings.compilerExePath = "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Tools\\MSVC\\14.28.29910\\bin\\HostX86\\x64\\cl.exe";
	settings.linkerExePath = "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Tools\\MSVC\\14.28.29910\\bin\\HostX86\\x64\\link.exe";
	settings.tmpDir = "C:\\Users\\fahju\\AppData\\Roaming\\Sonic\\tmp\\";
	settings.includeDirs = { "C:\\dev\\runtimecodereload\\lib\\src\\" };
	settings.libDirs = { "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Tools\\MSVC\\14.28.29910\\lib\\x64\\uwp" };
	settings.configuration = sonic::DllReloader::Configuration::DEBUG;

	sonic::String dllPath = SN_RCR_DLL_PATH;

	sonic::DllReloader::init(settings);
	sonic::DllReloader::reloadDll(dllPath, true, {
		"C:\\dev\\RuntimeCodeReload\\DLL\\src\\Client.cpp"
	});

	testFunctions();

	std::cin.get();

	sonic::DllReloader::reloadDll(dllPath, true, {
		"C:\\dev\\RuntimeCodeReload\\DLL\\src\\Client.cpp"
	});

	testFunctions();
}
