/* 0x886EC460: renderer: reset five cached indices (+0x68, +0x6C, +0x70, +0x78, +0x80) to -1 and set the dirty byte +0x324 */
/* Matched on /Oc (LTCG) (agAL). LTCG route. The +0x6C field is unsigned (0xFFFFFFFF): its constant gets its own li, the int -1 fields share one. */
typedef struct RenderSlotState {
    unsigned char pad[0x68]; int a; unsigned int b; int c; int pad74; int d; int pad7c; int e;
    unsigned char pad84[0x324 - 0x84]; unsigned char dirty;
} RenderSlotState;

void ts4_render_slot_reset_886EC460(RenderSlotState *p)
{
    p->a = -1;
    p->b = 0xFFFFFFFF;
    p->c = -1;
    p->d = -1;
    p->e = -1;
    p->dirty = 1;
}
