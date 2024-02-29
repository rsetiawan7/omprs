#include "core.hpp"

OMPRSCore::OMPRSCore(const std::string& gamemode_name)
{
#if _WIN32
	proc_handle = LoadLibrary(("omprsgamemode\\" + gamemode_name + ".dll").c_str());
#else
	// overwrite dlopen flags set by open.mp
	component_handle = dlopen("components/omprs.so", RTLD_GLOBAL | RTLD_NOW);

	proc_handle = dlopen(("omprsgamemode/" + gamemode_name + ".so").c_str(), RTLD_GLOBAL | RTLD_NOW);
#endif
}

OMPRSCore::~OMPRSCore()
{
#ifdef __unix__
	dlclose(component_handle);
#endif
}