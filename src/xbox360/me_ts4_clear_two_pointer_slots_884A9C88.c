/* 0x884A9C88: p is the +0x20 sub-object of its owner; clears the owner slots +0x28 and +0x2c in x (null-checked owner cast) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
void ts4_clear_pointer_slot_8846AF88(void *x, void *slot);
void ts4_clear_pointer_slot_8846B168(void *x, void *slot);
void ts4_clear_two_pointer_slots_884A9C88(char *p, void *x)
{
    char *o = p - 0x20;
    ts4_clear_pointer_slot_8846AF88(x, o ? p + 8 : 0);
    ts4_clear_pointer_slot_8846B168(x, o ? p + 0xc : 0);
}
