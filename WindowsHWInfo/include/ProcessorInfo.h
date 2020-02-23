#pragma once

#pragma comment(lib, "pdh.lib")
#include <iostream>
#include <Windows.h>
#include <sysinfoapi.h>
#include <string>

namespace WindowsHWInfo
{
	class ProcessorInfo
	{
	public:
		DWORD NumberOfThread;
		std::wstring ProcessorName;
		void operator=(ProcessorInfo& Target);
		void GetProcessorInfo();
	};

	bool operator==(ProcessorInfo& A, ProcessorInfo& B); // 전부 같을때 true
	bool operator!=(ProcessorInfo& A, ProcessorInfo& B); // 하나라도 다르면 true
	bool operator|=(ProcessorInfo& A, ProcessorInfo& B); // 하나라도 같으면 true
	bool operator&=(ProcessorInfo& A, ProcessorInfo& B); // 전부 다르면 true
}
