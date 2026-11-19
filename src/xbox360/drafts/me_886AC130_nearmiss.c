/* 0x886AC130 near miss (87 off, /Oc plain). Object ctor: base fn_88617D88, vtable lbl_880F4524, hash 0x629B9E5B at +0x2F4/+0x2FC,
 * floats from lbl_8814B440 and g_ts4_script_constants[14] (-1.0f), then allocates a 0x790 slot block (pool 2) into +0x38.
 * Residue: self in r30 vs target r31 (target keeps zero in r30), float constants reloaded per store; target's addi r11,self+0x2F4
 * hints at a C++ member sub-object ctor. Tried C, extern "C" C++, float locals (worse). */
typedef unsigned int u32; typedef unsigned char u8;
extern const void *lbl_880F4524[];
extern void *lbl_88D45B38;
extern float g_ts4_event_value;
extern const float g_ts4_script_constants[];
void fn_88617D88(void *self);
void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
typedef struct Slots {
    char _0[8]; u32 a[9]; char _2c[0x714]; u32 b740, b744; u8 c748, c749, c74a, c74b, c74c; char _74d[3];
    u32 d750, d754, d758, d75c, d760; u8 e764; char _765[0x2B];
} Slots;
typedef struct Obj {
    const void **vt; char _4[0x18]; u8 f1c, f1d, f1e; char _1f; u32 f20, f24, f28, f2c, f30; char _34[4]; Slots *slots;
    char _3c[0x2B8]; u32 key; u32 f2f8; u32 key2; float f300, f304, f308; u8 b30c, b30d, b30e, b30f, b310, b311, b312; char _313;
    float f314; u32 f318; u8 b31c, b31d; char _31e[0x52]; u32 f370; u8 b374, b375; char _376[2]; u32 f378;
    u8 b37c, b37d, b37e, b37f; u32 f380, f384; float f388; u8 b38c, b38d; char _38e[2]; u32 f390, f394, f398; char _39c[8]; u8 b3a4, b3a5;
} Obj;
Obj *ts4_obj_ctor_886AC130(Obj *self)
{
    Slots *s;
    fn_88617D88(self);
    self->vt = lbl_880F4524;
    self->f1c = 0; self->f1d = 0; self->f1e = 0;
    self->f20 = 0; self->f24 = 0; self->f28 = 0; self->f2c = 0; self->f30 = 0;
    self->f2f8 = 0; self->key2 = 0;
    self->key = 0x629B9E5Bu; self->key2 = 0x629B9E5Bu;
    { float z = g_ts4_event_value; self->f300 = z; self->f304 = z; self->f308 = z; }
    self->b30c = 0; self->b30d = 0; self->b30e = 0; self->b30f = 0; self->b310 = 0; self->b312 = 0; self->b311 = 0;
    self->f314 = g_ts4_script_constants[14]; self->f318 = 0; self->b31c = 0; self->b31d = 0;
    self->f370 = 0; self->b374 = 0; self->b375 = 0; self->f378 = 0;
    self->b37c = 0; self->b37d = 0; self->b37e = 0; self->b37f = 0; self->f380 = 0; self->f384 = 1;
    self->f388 = g_ts4_script_constants[14]; self->b38c = 0; self->b38d = 1; self->f390 = 0; self->f394 = 0; self->f398 = 0;
    self->b3a4 = 0; self->b3a5 = 0;
    s = (Slots *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x790, 4, 0, 2);
    if (s) {
        s->a[0] = 0; s->a[1] = 0; s->a[2] = 0; s->a[3] = 0; s->a[4] = 0; s->a[5] = 0; s->a[6] = 0; s->a[7] = 0; s->a[8] = 0;
        s->b740 = 0; s->b744 = 0; s->c748 = 0; s->c749 = 0; s->c74a = 0; s->c74b = 0; s->c74c = 0;
        s->d750 = 1; s->d754 = 0; s->d758 = 0; s->d75c = 0; s->d760 = 0; s->e764 = 0;
        self->slots = s;
    } else self->slots = 0;
    return self;
}
