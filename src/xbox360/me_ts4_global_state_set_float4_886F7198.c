/* 0x886F7198: Copies four floats into the state object at lbl_88D45AD4 + 0x15720 (fields +0x13e0..+0x13ec) and sets dirty bit 0x4000 in its 64-bit flag word at +0. */
/* Matched on /Oc (agAH). Copy through a small Float4 copy helper; inline per-field stores let the compiler hoist the ld of the flag word above the float stores. */
typedef struct Float4 { float x, y, z, w; } Float4;
static void Float4_Copy(Float4 *d, const Float4 *s) { d->x = s->x; d->y = s->y; d->z = s->z; d->w = s->w; }
typedef struct DirtyState { unsigned __int64 dirty; char pad[0x13d8]; Float4 value; } DirtyState;
extern char *lbl_88D45AD4;

void fn_886F7198(const Float4 *c)
{
    DirtyState *st = *(DirtyState **)(lbl_88D45AD4 + 0x15720);
    Float4_Copy(&st->value, c);
    st->dirty |= 0x4000;
}
