#pragma once

#include "func_wrapper.h"

void *arch_memalign(size_t Alignment, size_t Size) {
#if 0
    if constexpr (0) {
        if (mem_first_memalign()) {
            mem_on_first_allocation();

            mem_first_memalign() = false;
        }

        auto *mem = arch_memalign_internal(Alignment, Size);
        if (mem == nullptr) {
            debug_print_va("tried to allocate %d bytes", Size);
            mem_print_stats("mem_memalign failed");
        }

        return mem;

    } else
#endif
    {
        return (void *) CDECL_CALL(0x005357B0, Alignment, Size);
    }
}

void *arch_malloc(size_t Size) {
    return (void *) CDECL_CALL(0x00535780, Size);
}

void *mem_freealign(void *Memory) {
    return (void *) CDECL_CALL(0x0058EC80, Memory);
}

void mem_print_stats(const char *a1) {
    printf("mem_print_stats: %s\n", a1);
    printf("peak: %10lu   curr: %10lu   free: %10lu\n", 0ul, 0ul, 0ul);
}

int mem_set_checkpoint()
{
    return 0;
}

void mem_check_leaks_since_checkpoint(int , unsigned int )
{
}


