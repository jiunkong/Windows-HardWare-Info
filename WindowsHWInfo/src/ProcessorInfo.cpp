#include "ProcessorInfo.h"

void WindowsHWInfo::ProcessorInfo::GetProcessorInfo()
{
	SYSTEM_INFO stSysInfo;
	GetSystemInfo(&stSysInfo);
	this->NumberOfThread = stSysInfo.dwNumberOfProcessors;

    wchar_t ProcessorName[100];
    HKEY HKey;
    DWORD ARR_SIZE = sizeof(ProcessorName);

    RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Hardware\\Description\\System\\CentralProcessor\\0", 0, KEY_QUERY_VALUE, &HKey);
    RegQueryValueEx(HKey, L"ProcessorNameString", NULL, NULL, (LPBYTE)ProcessorName, &ARR_SIZE);
    RegCloseKey(HKey);

    this->ProcessorName = ProcessorName;
}

void WindowsHWInfo::ProcessorInfo::operator=(WindowsHWInfo::ProcessorInfo& Target)
{
    this->NumberOfThread = Target.NumberOfThread;
    this->ProcessorName = Target.ProcessorName;
}

bool WindowsHWInfo::operator==(WindowsHWInfo::ProcessorInfo& A, WindowsHWInfo::ProcessorInfo& B)
{
    return (A.NumberOfThread == B.NumberOfThread && A.ProcessorName == B.ProcessorName);
}

bool WindowsHWInfo::operator!=(WindowsHWInfo::ProcessorInfo& A, WindowsHWInfo::ProcessorInfo& B)
{
    return !(A == B);
}

bool WindowsHWInfo::operator|=(WindowsHWInfo::ProcessorInfo& A, WindowsHWInfo::ProcessorInfo& B)
{
    return (A.NumberOfThread == B.NumberOfThread || A.ProcessorName == B.ProcessorName);
}

bool WindowsHWInfo::operator&=(WindowsHWInfo::ProcessorInfo& A, WindowsHWInfo::ProcessorInfo& B)
{
    return !(A |= B);
}