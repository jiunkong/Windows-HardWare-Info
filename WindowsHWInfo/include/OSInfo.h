#pragma once

#include <iostream>
#include <Windows.h>
#include <sysinfoapi.h>
#include <string>

namespace WindowsHWInfo
{
	enum OSbit {
		_32bit = 1,
		_64bit
	};

	class OperatingSystemInfo
	{
	public:
		std::wstring WindowsVersion;
		OSbit WindowsBit;
		void operator=(OperatingSystemInfo& Target);
		void GetOSInfo();
	private:
		bool Is64Bit();
	};

	bool operator==(OperatingSystemInfo& A, OperatingSystemInfo& B); // 전부 같을때 true
	bool operator!=(OperatingSystemInfo& A, OperatingSystemInfo& B); // 하나라도 다르면 true
	bool operator|=(OperatingSystemInfo& A, OperatingSystemInfo& B); // 하나라도 같으면 true
	bool operator&=(OperatingSystemInfo& A, OperatingSystemInfo& B); // 전부 다르면 true
}
