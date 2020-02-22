#pragma once

#include <iostream>
#include <Windows.h>
#include <sysinfoapi.h>

typedef std::wstring __NAMEINFO;
typedef DWORD __THREADCOUNT;

namespace ProcessorInfo
{
	typedef struct _SystemInfo {
		__THREADCOUNT NumberOfThread;
		__NAMEINFO ProcessorName;
	} SystemInfo;

	void GetProcessorInfo(SystemInfo& Buffer);
}
