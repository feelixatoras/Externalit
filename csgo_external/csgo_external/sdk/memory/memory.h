#pragma once
#include "../sdk.h"


#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

typedef struct _CLIENT_ID
{
	HANDLE UniqueProcess;
	HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _UNICODE_STRING
{
	USHORT Length;
	USHORT MaximumLength;
	PWSTR  Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _OBJECT_ATTRIBUTES {
	ULONG           Length;
	HANDLE          RootDirectory;
	PUNICODE_STRING ObjectName;
	ULONG           Attributes;
	PVOID           SecurityDescriptor;
	PVOID           SecurityQualityOfService;
}  OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

typedef NTSTATUS(NTAPI* NtWVM) (HANDLE ProcessHandle, LPVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToRead, PULONG NumberOfBytesReaded);
typedef NTSTATUS(NTAPI* NtRVM)(HANDLE ProcessHandle, LPVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToRead, PULONG NumberOfBytesReaded);
typedef NTSTATUS(NTAPI* NtOP)(PHANDLE ProcessHandle, ACCESS_MASK AccessMask, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientID);


namespace sdk {
	class cmemory {
	private:
		HMODULE ntdll;
		NtRVM ntreadvirtualmemory;
		NtWVM ntwritevirtualmemory;
		NtOP NtOpenProcess;
		HANDLE hprocess;
		uint32_t processid;
	
	public:
		cmemory();
		~cmemory();
		template <class T>
		T read(DWORD address)
		{
			T ret;
			ntreadvirtualmemory(hprocess, reinterpret_cast<LPVOID>(address), &ret, sizeof(T), NULL);
			return ret;
		}
		template <class T>
		void write(DWORD address, T buffer)
		{
			ntwritevirtualmemory(hprocess, reinterpret_cast<LPVOID>(address), &buffer, sizeof(T), NULL);
		}
		void write(DWORD address, void* buffer, size_t size) {
			ntwritevirtualmemory(hprocess, reinterpret_cast<LPVOID>(address), &buffer, size, NULL);
		}
		template<class T>
		void write_prot(DWORD address, T buffer)
		{
			DWORD oldProtect;
			VirtualProtectEx(hprocess, reinterpret_cast<LPVOID>(address), sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);
			write(address, buffer);
			VirtualProtectEx(hprocess, reinterpret_cast<LPVOID>(address), sizeof(T), oldProtect, NULL);
		}
		void attach(std::string process);	
		bool free_memory(void* address, size_t size = 0);
		void execute(void* shellcode, void* parameter = nullptr);
		void* allocate(size_t size);
		void get_processid(std::string process);
		uint32_t get_module(std::string module_name);
	}; extern cmemory* c_memory;



}






