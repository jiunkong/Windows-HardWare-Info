#include "GraphicInfo.h"

void WindowsHWInfo::GPUInfo::GetGraphicInfo()
{
    DISPLAY_DEVICE Display;
    WCHAR GPUName[128];

    ZeroMemory(GPUName, sizeof(GPUName));
    memset(&Display, 0, sizeof(DISPLAY_DEVICE));
    Display.cb = sizeof(Display);
    EnumDisplayDevices(NULL, 0, &Display, 0);

    this->GraphicName = Display.DeviceString;
}

void WindowsHWInfo::GPUInfo::operator=(WindowsHWInfo::GPUInfo& Target)
{
    this->GraphicName = Target.GraphicName;
}

bool WindowsHWInfo::operator==(WindowsHWInfo::GPUInfo& A, WindowsHWInfo::GPUInfo& B)
{
    return (A.GraphicName == B.GraphicName);
}

bool WindowsHWInfo::operator!=(WindowsHWInfo::GPUInfo& A, WindowsHWInfo::GPUInfo& B)
{
    return (A.GraphicName != B.GraphicName);
}
