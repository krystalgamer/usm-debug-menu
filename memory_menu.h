#pragma once

#include "debug_menu.h"
#include "script_memtrack.h"
#include "slab_allocator.h"

int g_mem_checkpoint_debug_0 {-1};

void set_memtrack_checkpoint(debug_menu_entry *)
{
    g_mem_checkpoint_debug_0 = mem_set_checkpoint();
    debug_menu::hide();
}

void dump_memtrack_data(debug_menu_entry *)
{
    mem_check_leaks_since_checkpoint(g_mem_checkpoint_debug_0, 1u);
    mem_print_stats("\nMemory log\n");
    debug_menu::hide();
}

void create_memory_menu(debug_menu *parent)
{
    auto *memory_menu = create_menu("Memory", debug_menu::sort_mode_t::undefined);
    auto *v2 = create_menu_entry(memory_menu);
    parent->add_entry(v2);
    
    script_memtrack::create_debug_menu(memory_menu);

    auto *entry = create_menu_entry(mString {"Dump MemTrack Data Since Last Checkpoint"});
    entry->set_game_flags_handler(dump_memtrack_data);
    memory_menu->add_entry(entry);

    entry = create_menu_entry(mString {"Set MemTrack Checkpoint"});
    entry->set_game_flags_handler(set_memtrack_checkpoint);
    memory_menu->add_entry(entry);
    
    slab_allocator::create_slab_debug_menu(memory_menu);
}
