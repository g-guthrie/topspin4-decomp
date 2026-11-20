/* 0x884C9AC8 near miss (agW, /Oc and /Os): 2 off, r10/r11 swapped on the first two instructions (base/index registers). */
/* The clrrwi copy comes from the second call of the inline accessor (CL1 rule); slot(o->slots, i) and locals did not help. */
typedef struct { char pad[0x24]; char **slots; } O;
static __inline char **slot(O *o, int i) { return &o->slots[i]; }
char *ts4_slot_offset_884C9AC8(O *o, int i, int off)
{
    if (*slot(o, i) != 0) return *slot(o, i) + off;
    return 0;
}
