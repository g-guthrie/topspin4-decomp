/* 0x886EC980: renderer: reset five cached indices to -1, set the dirty byte +0x324 and clear the count at +0x32C (886EC460 plus one store) */
/* Matched on /Oc (LTCG) (agAL). LTCG route; same unsigned +0x6C field as 886EC460. */
typedef struct RenderSlotState {
    unsigned char pad[0x68]; int a; unsigned int b; int c; int pad74; int d; int pad7c; int e;
    unsigned char pad84[0x324 - 0x84]; unsigned char dirty; unsigned char pad325[0x32c - 0x325]; int count;
} RenderSlotState;

void ts4_render_slot_reset_count_886EC980(RenderSlotState *p)
{
    p->a = -1;
    p->b = 0xFFFFFFFF;
    p->c = -1;
    p->d = -1;
    p->e = -1;
    p->dirty = 1;
    p->count = 0;
}
