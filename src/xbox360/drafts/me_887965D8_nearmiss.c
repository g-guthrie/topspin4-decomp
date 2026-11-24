/* nearmiss: 3 off; target computes (IV+t)+*t; all operand orders, C++ SlotTable member, helper-inlined loop give same 3 off */
/* 0x887965D8: 1 when any of the four 0x40-byte slots of the table found by ts4_hash_find_null_888689F8 has flag byte (+0x3c) == 1.
 * Near miss (agAL, /Oc plain or LTCG, 3 off): the target adds (off + t) then *t; every association gives (*t + off) + t.
 * Key finding: ts4_hash_find_null_888689F8 takes no arguments (r3 is not set before the call); cx18_core_c.c declares it
 * with an idx parameter, which is why 88868FA8 (the slot_flag inline) passes r3 through. */
typedef unsigned char u8;
typedef unsigned int u32;
extern int *ts4_hash_find_null_888689F8(void);

static u8 slot_flag(u32 idx)
{
    u8 result = 0;
    int *t = ts4_hash_find_null_888689F8();
    if (t != 0) result = *((u8 *)t + (idx * 0x40 + *t) + 0x3c);
    return result;
}

u8 ts4_any_slot_flag_set_887965D8(void)
{
    u8 result = 0;
    int i;
    for (i = 0; i < 4; i++) {
        if (slot_flag(i) == 1) {
            result = 1;
            break;
        }
    }
    return result;
}
