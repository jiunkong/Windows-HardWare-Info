#include <WindowsHWInfo.h>
#include <iostream>
#include <string>

/*using namespace WindowsHWInfo;
using namespace WindowsHWInfo::GraphicInfo;
using namespace WindowsHWInfo::MemoryInfo;
using namespace WindowsHWInfo::OSInfo;
using namespace WindowsHWInfo::ProcessorInfo;*/

int main()
{
	//Graphic
	WindowsHWInfo::GPUInfo GPUInfo;
	GPUInfo.GetGraphicInfo();
	std::wcout << L"Graphic Card : " << GPUInfo.GraphicName << std::endl;

	//Processor
	WindowsHWInfo::ProcessorInfo CPUInfo;
	CPUInfo.GetProcessorInfo();
	 std::wstring str = (L"CPU : " + CPUInfo.ProcessorName + L", " + std::to_wstring(CPUInfo.NumberOfThread) + L" Thread");
	 std::wcout << str << std::endl;

	 //Memory
	 WindowsHWInfo::MemoryStatus MemStatus;
	 MemStatus.IsInterger = false;
	 MemStatus.ReturnUnit = WindowsHWInfo::MemoryUnit::GigaByte;
	 MemStatus.GetMemoryInfo();
	 std::cout << "Total Physics Memory : " << MemStatus.TotalPhysicsMemory << "GB" << std::endl;
	 std::cout << "Available Physics Memory : " << MemStatus.AvailPhysicsMemory << "GB" << std::endl;
	 std::cout << "Total Virtual Memory : " << MemStatus.TotalVirtualMemory << "GB" << std::endl;
	 std::cout << "Available Virtual Memory : " << MemStatus.AvailVirtualMemory << "GB" << std::endl;
	 std::cout << "Memory Usage : " << MemStatus.MemoryUtilization << "%" << std::endl;

	 //OS
	 WindowsHWInfo::OperatingSystemInfo OSInfo;
	 OSInfo.GetOSInfo();
	 std::wcout << OSInfo.WindowsVersion << std::endl;
	 std::cout << "Windows Bit : " << (OSInfo.WindowsBit == WindowsHWInfo::OSbit::_32bit ? "32bit" : "64bit") << std::endl;

	 return 0;
}