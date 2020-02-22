#pragma once

#include <iostream>
#include <Windows.h>
#include <sysinfoapi.h>

typedef std::wstring __OSNAME;
typedef int __OSBIT;

namespace OSInfo
{
	enum OSbit {
		_32bit = 1,
		_64bit
	};

	typedef struct _OperatingSystemInfo {
		__OSNAME WindowsVersion;
		__OSBIT WindowsBit;
	} OperatingSystemInfo;

	bool Is64Bit();
	void GetOSInfo(OperatingSystemInfo& Buffer);
}
