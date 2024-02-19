#include "slf.h"

void vm_stack_add_offset(slf* function, DWORD size) {
	function->stack_ptr += size;
}

void vm_stack_push(slf* function, void* data, DWORD size) {
	memcpy((void*)function->stack_ptr, data, size);
	vm_stack_add_offset(function, size);
}

void vm_stack_pop(slf* function, DWORD size) {
	function->stack_ptr -= size;
}
