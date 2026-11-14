/* Family SWB2 (jump-table switch). */
unsigned int ts4_map_id_to_slot_88883F38(void);
void fn_881B1A98(void *out, void *obj, unsigned int hash);

int ts4_hash_by_kind_887A7128(void *obj)
{
    unsigned int hash = 0;
    char buf[8];

    switch (ts4_map_id_to_slot_88883F38()) {
    case 0: hash = 0xE33E3B9C; break;
    case 1: hash = 0xF3E12338; break;
    case 2: hash = 0xA5984597; break;
    case 3: hash = 0xA8D9CB68; break;
    case 4: hash = 0xFBA5CCA8; break;
    case 5: hash = 0x98045053; break;
    case 6: hash = 0x96F9CCF5; break;
    case 7:
    case 8: hash = 0x34251E88; break;
    case 9: hash = 0x24DBC8E9; break;
    case 10: hash = 0xD7A33283; break;
    case 11: hash = 0x96C17F36; break;
    }
    fn_881B1A98(buf, obj, hash);
    return 1;
}

