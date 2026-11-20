/* NEAR MISS fn_886B8078: 13 off (size 0x3C vs 0x40: target copies owner via r11 and computes self+0x24 into r31), LTCG + primer, /Oc. */
/* Swing_DLL.xex 0x886B8078: forward this object's request block to the owner's handler sub-object. */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
struct Ts4FwOwner { ts4_u8 pad_00[0x8]; ts4_u32 a; ts4_u8 pad_0c[0x1C]; ts4_u32 b; };
struct Ts4FwSelf { ts4_u8 pad_00[0x1C]; struct Ts4FwOwner *owner; ts4_u8 pad_20[4]; ts4_u8 block[4]; };
ts4_u8 *ts4_selected_variant_886A0EC8(struct Ts4FwOwner *o);
void fn_886B6448(void *handler, void *block, ts4_u32 a, ts4_u32 b);

void ts4_forward_request_886B8078(struct Ts4FwSelf *self)
{
    struct Ts4FwOwner *o = self->owner;
    void *blk = self->block;
    ts4_u32 b = o->b;
    ts4_u32 a = o->a;
    fn_886B6448(ts4_selected_variant_886A0EC8(o) + 0x18, blk, a, b);
}
