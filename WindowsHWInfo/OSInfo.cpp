#include "OSInfo.h"

bool OSInfo::Is64Bit()
{
#if defined(_WIN64)
    return true;
#elif defined(_WIN32)
    bool f64 = false;
    return IsWow64Process(GetCurrentProcess(), (PBOOL)&f64) && f64;
#else
    return false;
#endif
}

void OSInfo::GetOSInfo(OSInfo::OperatingSystemInfo& Buffer)
{
    wchar_t ProductName[100];

    HKEY HKey;

    DWORD c_size = 100;

    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\", 0, KEY_QUERY_VALUE, &HKey) != ERROR_SUCCESS)
    {
        Buffer.WindowsVersion = L"Fail to Open OSInfo";
        return;
    }
    if (RegQueryValueEx(HKey, L"ProductName", NULL, NULL, (LPBYTE)ProductName, &c_size) != ERROR_SUCCESS)
    {
        Buffer.WindowsVersion = L"Fail to Load the WindowsVersion";
        return;
    }

    Buffer.WindowsVersion = ProductName;

    RegCloseKey(HKey);

    if (OSInfo::Is64Bit())
        Buffer.WindowsBit = OSInfo::OSbit::_64bit;
    else
        Buffer.WindowsBit = OSInfo::OSbit::_32bit;
}