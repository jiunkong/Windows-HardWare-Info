#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <sysinfoapi.h>

namespace WindowsHWInfo
{
	class GPUInfo
	{
	public:
		std::wstring GraphicName;
		void operator=(GPUInfo& Target);
		void GetGraphicInfo();
	};

	bool operator==(GPUInfo& A, GPUInfo& B);
	bool operator!=(GPUInfo& A, GPUInfo& B);
}