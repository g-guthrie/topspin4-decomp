/* Swing_DLL.xex 0x88325050-0x883250D4, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
extern float lbl_88001A68;
extern float lbl_88001A20;
struct info { u8 pad[0x20]; u32 flags; };
struct obj { u8 pad0[0x4c]; struct info *info; u32 pad1; u32 flags; u8 pad2[0x100]; float a; float b; float c; };
int ts4_set_range_88325050(struct obj *self, float a, float b, float c)
{
    if (self->info == 0) {
        return 0x24;
    }
    if ((self->info->flags & 0x10) == 0) {
        return 0x31;
    }
    if (a > b) {
        return 0x25;
    }
    if (c > lbl_88001A68) {
        c = lbl_88001A68;
    } else if (c < lbl_88001A20) {
        c = lbl_88001A20;
    }
    self->a = a;
    self->b = b;
    self->c = c;
    self->flags |= 0x10;
    return 0;
}
