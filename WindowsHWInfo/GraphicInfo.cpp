#include "GraphicInfo.h"

void GraphicInfo::GetGraphicInfo(GraphicInfo::GPUInfo& Buffer)
{
    DISPLAY_DEVICE Display;
    WCHAR GPUName[128];

    ZeroMemory(GPUName, sizeof(GPUName));
    memset(&Display, 0, sizeof(DISPLAY_DEVICE));
    Display.cb = sizeof(Display);
    EnumDisplayDevices(NULL, 0, &Display, 0);

    Buffer.GraphicName = Display.DeviceString;
}