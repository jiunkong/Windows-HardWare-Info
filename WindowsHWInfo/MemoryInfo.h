#pragma once

#include <iostream>
#include <Windows.h>
#include <sysinfoapi.h>

typedef short __UNIT;
typedef double __MEMINFO;

namespace MemoryInfo
{
	const int __DIV = 1024;

	enum MemoryUnit {
		Byte,
		KiloByte,
		MegaByte,
		GigaByte,
	};

	typedef struct _MemoryStatus {
		__UNIT ReturnUnit = MemoryUnit::Byte;
		__MEMINFO MemoryUtilization;
		__MEMINFO TotalPhysicsMemory;
		__MEMINFO AvailPhysicsMemory;
		__MEMINFO TotalVirtualMemory;
		__MEMINFO AvailVirtualMemory;
		bool IsInterger = true;
	} MemoryStatus;

	void GetMemoryInfo(MemoryStatus& Buffer);
}

