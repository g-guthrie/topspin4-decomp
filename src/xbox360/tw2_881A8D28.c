/* Twin of 0x88187AB8 (ts4_destroy_owned_range_88187AB8 in src/xbox360/cw4_core_a.c). 0x18-byte entries, owned at +0xc. */
typedef unsigned int u32;
extern void ts4_destroy_owned_object(void *p);
typedef struct Cw4Elem18 { u32 pad[3]; void *owned; u32 pad2[2]; } Cw4Elem18;
void ts4_destroy_owned_range_881A8D28(Cw4Elem18 *begin, Cw4Elem18 *end)
{
    Cw4Elem18 *p;
    for (p = begin; p != end; p++) {
        if (p->owned) ts4_destroy_owned_object(p->owned);
    }
}
