/* Swing_DLL.xex 0x88328C18-0x88328C9C, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
extern float lbl_88001A68;
extern float lbl_88001A20;
struct info { u8 pad[0x20]; u32 flags; };
struct obj { u8 pad0[0x4c]; struct info *info; u8 pad1[0x120]; float a; float b; u8 pad2[0x8]; float c; float d; };
extern int fn_88328AF8(struct obj *self, u32 a, u32 b, u32 c, float x, float y);
int ts4_clamp_pair_88328C18(struct obj *self, u32 r4, u32 r5, float x, float y)
{
    if (self->info == 0) {
        return 0x24;
    }
    if ((self->info->flags & 0x10) == 0) {
        return 0x31;
    }
    if (x < lbl_88001A20) x = lbl_88001A20;
    if (y < lbl_88001A20) y = lbl_88001A20;
    if (x > lbl_88001A68) x = lbl_88001A68;
    if (y > lbl_88001A68) y = lbl_88001A68;
    self->c = x;
    self->d = y;
    return fn_88328AF8(self, r4, r5, 0, self->a, self->b);
}
