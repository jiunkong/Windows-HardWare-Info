#include "OSInfo.h"

bool WindowsHWInfo::OperatingSystemInfo::Is64Bit()
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

void WindowsHWInfo::OperatingSystemInfo::GetOSInfo()
{
    wchar_t ProductName[100];

    HKEY HKey;

    DWORD c_size = 100;

    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\", 0, KEY_QUERY_VALUE, &HKey) != ERROR_SUCCESS)
    {
        this->WindowsVersion = L"Fail to Open OSInfo";
        return;
    }
    if (RegQueryValueEx(HKey, L"ProductName", NULL, NULL, (LPBYTE)ProductName, &c_size) != ERROR_SUCCESS)
    {
        this->WindowsVersion = L"Fail to Load the WindowsVersion";
        return;
    }

    this->WindowsVersion = ProductName;

    RegCloseKey(HKey);

    if (this->Is64Bit())
        this->WindowsBit = WindowsHWInfo::OSbit::_64bit;
    else
        this->WindowsBit = WindowsHWInfo::OSbit::_32bit;
}

void WindowsHWInfo::OperatingSystemInfo::operator=(WindowsHWInfo::OperatingSystemInfo& Target)
{
    this->WindowsBit = Target.WindowsBit;
    this->WindowsVersion = Target.WindowsVersion;
}

bool WindowsHWInfo::operator==(WindowsHWInfo::OperatingSystemInfo& A, WindowsHWInfo::OperatingSystemInfo& B)
{
    return (A.WindowsBit == B.WindowsBit && A.WindowsVersion == B.WindowsVersion);
}

bool WindowsHWInfo::operator!=(WindowsHWInfo::OperatingSystemInfo& A, WindowsHWInfo::OperatingSystemInfo& B)
{
    return !(A == B);
}

bool WindowsHWInfo::operator|=(WindowsHWInfo::OperatingSystemInfo& A, WindowsHWInfo::OperatingSystemInfo& B)
{
    return (A.WindowsBit == B.WindowsBit || A.WindowsVersion == B.WindowsVersion);
}

bool WindowsHWInfo::operator&=(WindowsHWInfo::OperatingSystemInfo& A, WindowsHWInfo::OperatingSystemInfo& B)
{
    return !(A |= B);
}