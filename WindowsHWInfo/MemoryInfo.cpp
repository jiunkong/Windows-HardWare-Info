#include "MemoryInfo.h"

void MemoryInfo::GetMemoryInfo(MemoryInfo::MemoryStatus& Buffer)
{
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	
	Buffer.MemoryUtilization = statex.dwMemoryLoad;

	if (Buffer.IsInterger)
	{
		DWORDLONG temp[4] = { statex.ullTotalPhys, statex.ullAvailPhys, statex.ullTotalVirtual, statex.ullAvailVirtual };
		for (int i = 0; i < Buffer.ReturnUnit; i++)
		{
			for (int i = 0; i < 4; i++)
			{
				temp[i] /= MemoryInfo::__DIV;
			}
		}
		Buffer.TotalPhysicsMemory = static_cast<__MEMINFO>(temp[0]);
		Buffer.AvailPhysicsMemory = static_cast<__MEMINFO>(temp[1]);
		Buffer.TotalVirtualMemory = static_cast<__MEMINFO>(temp[2]);
		Buffer.AvailVirtualMemory = static_cast<__MEMINFO>(temp[3]);
	}
	else
	{
		__MEMINFO temp[4] = { static_cast<__MEMINFO>(statex.ullTotalPhys), static_cast<__MEMINFO>(statex.ullAvailPhys), static_cast<__MEMINFO>(statex.ullTotalVirtual), static_cast<__MEMINFO>(statex.ullAvailVirtual) };
		for (int i = 0; i < Buffer.ReturnUnit; i++)
		{
			for (int i = 0; i < 4; i++)
			{
				temp[i] /= MemoryInfo::__DIV;
			}
		}
		Buffer.TotalPhysicsMemory = temp[0];
		Buffer.AvailPhysicsMemory = temp[1];
		Buffer.TotalVirtualMemory = temp[2];
		Buffer.AvailVirtualMemory = temp[3];
	}
}