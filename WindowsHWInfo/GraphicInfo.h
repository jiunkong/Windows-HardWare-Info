#pragma once

#include <iostream>
#include <Windows.h>
#include <sysinfoapi.h>

typedef std::wstring __GPUNAME;

namespace GraphicInfo
{
	typedef struct _GPUInfo {
		__GPUNAME GraphicName;
	} GPUInfo;

	void GetGraphicInfo(GPUInfo& Buffer);
}
