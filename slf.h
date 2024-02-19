#pragma once
#ifndef SLF_H
#define SLF_H

#include <stdint.h>
#include <windows.h>

struct vm_executable;



typedef struct {
	uint8_t unk[0x20];
	struct vm_executable** vmexecutable;
}script_object;

typedef struct {
	uint8_t unk[0x2C];
	script_object* object;
}script_instance;


typedef struct {
	DWORD unk;
}script_executable;

typedef struct unknown_struct {
	DWORD unk;
	script_executable* scriptexecutable;
}unknown_struct;

typedef struct vm_executable{
	unknown_struct* unk_struct;
	DWORD unk[2];
	DWORD params;
}vm_executable;

typedef struct {
	uint8_t unk[0xC];
	script_instance* instance;
	vm_executable* vmexecutable;
}vm_thread;

typedef struct {
	uint8_t unk[0x184];
	DWORD stack_ptr;
	vm_thread* thread;
}slf;


void vm_stack_add_offset(slf* function, DWORD size);
void vm_stack_push(slf* function, void* data, DWORD size);
void vm_stack_pop(slf* function, DWORD size);
#endif

