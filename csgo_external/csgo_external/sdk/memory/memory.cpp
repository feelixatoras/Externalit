#include "memory.h"

namespace sdk {
	cmemory* c_memory = new cmemory();
	cmemory::cmemory() {
		ntdll = LoadLibrary("ntdll.dll");
		NtReadVirtualMemory = (NtRVM)GetProcAddress(ntdll, "NtReadVirtualMemory");
		NtWriteVirtualMemory = (NtWVM)GetProcAddress(ntdll, "NtWriteVirtualMemory");
		NtOpenProcess = (NtOP)GetProcAddress(ntdll, "NtOpenProcess");
	}

	cmemory::~cmemory() {
		CloseHandle(hprocess);
	}

	void cmemory::attach(std::string process) {
		//get_processid(process);
		Sleep(50);
		CLIENT_ID cid = { (HANDLE)processid, NULL };

		OBJECT_ATTRIBUTES oa;
		InitializeObjectAttributes(&oa, 0, 0, 0, 0);

		HANDLE temphandle = NULL;
		NTSTATUS ntStatus = NtOpenProcess(&temphandle, PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, &oa, &cid);

		SetLastError(ntStatus);
		hprocess = temphandle;
	}


	void cmemory::get_processid(std::string process) {
		PROCESSENTRY32 entry;
		entry.dwSize = sizeof(PROCESSENTRY32);

		HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

		if (Process32First(snapshot, &entry) == TRUE)
		{
			while (Process32Next(snapshot, &entry) == TRUE)
			{
				if (_stricmp(entry.szExeFile, process.c_str()) == 0)
				{
					processid = entry.th32ProcessID;
					CloseHandle(snapshot);
				}
			}
		}

	}

	uint32_t cmemory::get_module(std::string module_name)
	{
		HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processid);

		MODULEENTRY32 entry;
		entry.dwSize = sizeof(entry);

		do
		{
			if (!strcmp(entry.szModule, (LPSTR)module_name.c_str()))
			{
				CloseHandle(handle);
				return (DWORD)entry.modBaseAddr;
			}

		} while (Module32Next(handle, (LPMODULEENTRY32)&entry));

		return NULL;
	}
	bool cmemory::free_memory(void* address, size_t size) {
		return VirtualFreeEx(hprocess, address, size, MEM_RELEASE);
	}
	void* cmemory::allocate(size_t size) {
		return VirtualAllocEx(hprocess, 0, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	}
	void cmemory::execute(void* shellcode, void* parameter) {
		auto execute_thread = CreateRemoteThread(hprocess, nullptr, NULL, static_cast<LPTHREAD_START_ROUTINE>(shellcode), parameter, NULL, nullptr);
		WaitForSingleObject(execute_thread, INFINITE);
		CloseHandle(execute_thread);
	}
}