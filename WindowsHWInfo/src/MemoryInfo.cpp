#include "MemoryInfo.h"

void WindowsHWInfo::MemoryStatus::GetMemoryInfo()
{
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	
	this->MemoryUtilization = statex.dwMemoryLoad;

	if (this->IsInterger)
	{
		DWORDLONG temp[4] = { statex.ullTotalPhys, statex.ullAvailPhys, statex.ullTotalVirtual, statex.ullAvailVirtual };
		for (int i = 0; i < this->ReturnUnit; i++)
		{
			for (int i = 0; i < 4; i++)
			{
				temp[i] /= this->__DIV;
			}
		}
		this->TotalPhysicsMemory = static_cast<double>(temp[0]);
		this->AvailPhysicsMemory = static_cast<double>(temp[1]);
		this->TotalVirtualMemory = static_cast<double>(temp[2]);
		this->AvailVirtualMemory = static_cast<double>(temp[3]);
	}
	else
	{
		double temp[4] = { static_cast<double>(statex.ullTotalPhys), static_cast<double>(statex.ullAvailPhys), static_cast<double>(statex.ullTotalVirtual), static_cast<double>(statex.ullAvailVirtual) };
		for (int i = 0; i < this->ReturnUnit; i++)
		{
			for (int i = 0; i < 4; i++)
			{
				temp[i] /= this->__DIV;
			}
		}
		this->TotalPhysicsMemory = temp[0];
		this->AvailPhysicsMemory = temp[1];
		this->TotalVirtualMemory = temp[2];
		this->AvailVirtualMemory = temp[3];
	}
}

void WindowsHWInfo::MemoryStatus::operator=(WindowsHWInfo::MemoryStatus& Target)
{
	this->TotalPhysicsMemory = Target.TotalPhysicsMemory;
	this->AvailPhysicsMemory = Target.AvailPhysicsMemory;
	this->TotalVirtualMemory = Target.TotalVirtualMemory;
	this->AvailVirtualMemory = Target.AvailVirtualMemory;
	this->IsInterger = Target.IsInterger;
	this->MemoryUtilization = Target.MemoryUtilization;
	this->ReturnUnit = Target.ReturnUnit;
}

bool WindowsHWInfo::operator==(WindowsHWInfo::MemoryStatus& A, WindowsHWInfo::MemoryStatus& B)
{
	return (A.IsInterger == B.IsInterger && A.ReturnUnit == B.ReturnUnit && A.TotalPhysicsMemory == B.TotalPhysicsMemory && A.AvailPhysicsMemory == B.AvailPhysicsMemory && A.TotalVirtualMemory == B.TotalVirtualMemory && A.AvailVirtualMemory == B.AvailVirtualMemory && A.MemoryUtilization == B.MemoryUtilization);
}

bool WindowsHWInfo::operator!=(WindowsHWInfo::MemoryStatus& A, WindowsHWInfo::MemoryStatus& B)
{
	return !(A == B);
}

bool WindowsHWInfo::operator|=(WindowsHWInfo::MemoryStatus& A, WindowsHWInfo::MemoryStatus& B)
{
	return (A.IsInterger == B.IsInterger || A.ReturnUnit == B.ReturnUnit || A.TotalPhysicsMemory == B.TotalPhysicsMemory || A.AvailPhysicsMemory == B.AvailPhysicsMemory || A.TotalVirtualMemory == B.TotalVirtualMemory || A.AvailVirtualMemory == B.AvailVirtualMemory || A.MemoryUtilization == B.MemoryUtilization);
}

bool WindowsHWInfo::operator&=(WindowsHWInfo::MemoryStatus& A, WindowsHWInfo::MemoryStatus& B)
{
	return !(A |= B);
}