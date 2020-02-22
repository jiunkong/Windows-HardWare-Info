#include "ProcessorInfo.h"

void ProcessorInfo::GetProcessorInfo(ProcessorInfo::SystemInfo& Buffer)
{
	SYSTEM_INFO stSysInfo;
	GetSystemInfo(&stSysInfo);
	Buffer.NumberOfThread = stSysInfo.dwNumberOfProcessors;

    wchar_t ProcessorName[100];
    HKEY HKey;
    DWORD ARR_SIZE = sizeof(ProcessorName);

    RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Hardware\\Description\\System\\CentralProcessor\\0", 0, KEY_QUERY_VALUE, &HKey);
    RegQueryValueEx(HKey, L"ProcessorNameString", NULL, NULL, (LPBYTE)ProcessorName, &ARR_SIZE);
    RegCloseKey(HKey);

    Buffer.ProcessorName = ProcessorName;
}