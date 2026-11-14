/* Swing_DLL.xex 0x8833CEC8-0x8833CF4C, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
struct item { u32 pad0[2]; float value; u32 pad1[9]; };
struct obj;
struct objvt { u8 pad[0x28]; int (*apply)(struct obj *self, int index, float value); };
struct obj {
    struct objvt *vt; u8 pad0[0x14]; u32 key; u8 pad1[0x88]; int count; struct item *items; u8 pad2[0xd0]; s16 last;
};
extern u32 lbl_88B3302C;
int ts4_apply_items_8833CEC8(struct obj *self)
{
    int i;
    self->last = -1;
    lbl_88B3302C = self->key;
    for (i = 0; i < self->count; i++) {
        int rc = self->vt->apply(self, i, self->items[i].value);
        if (rc != 0) {
            return rc;
        }
    }
    return 0;
}
