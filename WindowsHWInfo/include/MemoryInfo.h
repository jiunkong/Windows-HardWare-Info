#pragma once

#include <iostream>
#include <Windows.h>
#include <sysinfoapi.h>

namespace WindowsHWInfo
{
	enum MemoryUnit {
		Byte,
		KiloByte,
		MegaByte,
		GigaByte,
	};

	class MemoryStatus
	{
	public:
		MemoryUnit ReturnUnit = MemoryUnit::Byte;
		DWORD MemoryUtilization;
		double TotalPhysicsMemory;
		double AvailPhysicsMemory;
		double TotalVirtualMemory;
		double AvailVirtualMemory;
		double IsInterger = true;
		void operator=(MemoryStatus& Target);
		void GetMemoryInfo();
	private:
		const int __DIV = 1024;
	};

	bool operator==(MemoryStatus& A, MemoryStatus& B); // 전부 같을때 true
	bool operator!=(MemoryStatus& A, MemoryStatus& B); // 하나라도 다르면 true
	bool operator|=(MemoryStatus& A, MemoryStatus& B); // 하나라도 같으면 true
	bool operator&=(MemoryStatus& A, MemoryStatus& B); // 전부 다르면 true
}
