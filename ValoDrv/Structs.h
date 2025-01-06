#pragma once

#include <ntddk.h>

typedef struct _r {
    INT32 Security;
    INT32 ProcessId;
    ULONGLONG Address;
    ULONGLONG Buffer;
    ULONGLONG Size;
    BOOLEAN Write;
} r, * pr;

typedef struct _b {
    INT32 Security;
    INT32 ProcessId;
    ULONGLONG* Address;
} b, * pb;

typedef struct _gr {
    ULONGLONG* guarded;
} gr, * pgr;


typedef struct _SystemBigpoolEntry {
    PVOID VirtualAddress;
    ULONG_PTR NonPaged : 1;
    ULONG_PTR SizeInBytes;
    UCHAR Tag[4];
} SystemBigpoolEntry, * PSystemBigpoolEntry;

typedef struct _SystemBigpoolInformation {
    ULONG Count;
    SystemBigpoolEntry AllocatedInfo[1];
} SystemBigpoolInformation, * PSystemBigpoolInformation;

typedef enum _SystemInformationClass {
    SystemBigpoolInformationClass = 0x42,
} SystemInformationClass;

#define PageOffsetSize 12

typedef struct _LDR_DATA_TABLE_ENTRY {
	LIST_ENTRY InLoadOrderLinks;
	LIST_ENTRY InMemoryOrderLinks;
	LIST_ENTRY InInitializationOrderLinks;
	PVOID DllBase;
	PVOID EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
	ULONG Flags;
	USHORT LoadCount;
	USHORT TlsIndex;
	LIST_ENTRY HashLinks;
	PVOID SectionPointer;
	ULONG CheckSum;
	ULONG TimeDateStamp;
	PVOID LoadedImports;
	PVOID EntryPointActivationContext;
	PVOID PatchInformation;
	LIST_ENTRY ForwarderLinks;
	LIST_ENTRY ServiceTagLinks;
	LIST_ENTRY StaticLinks;
	PVOID ContextInformation;
	ULONG OriginalBase;
	LARGE_INTEGER LoadTime;
} LDR_DATA_TABLE_ENTRY, * PLDR_DATA_TABLE_ENTRY;
