/* nearmiss: ~60 off (LTCG /Oc, auto-context); structure right, register shape not. Blocker: the target keeps
 * &self->game (r8) and game+0x110 (r11) as live base pointers and does not CSE the loop pre-check load with the
 * loop-top reload; neither a WbPtr<> smart-pointer member, a reference local nor an inline sub-copy helper reproduces
 * that (C version folds every offset, 66 off). Likely a real class with member functions on the +0x30 member and on
 * the game+0x110 sub-object (unknown types; need the class of vtable/owner of these objects).
 * 0x8888C2B0 (pres): snapshots game state into self: per-entry byte +0x40 of the self-relative entry array
 * (game+0x104, stride 0x140) into self+0x40.., then sub-object bytes/position (vector at sub+0x10 stored as 3 floats)
 * /float, then eight game flag bytes into self+0x58..0x5F. */
#include "vx1_vector.h"
typedef unsigned int u32;
typedef unsigned char u8;
struct WbVec3 { float x, y, z; };
template <class T> struct WbRel { int offset; u32 count;
    T &operator[](u32 i) { char *p = (char *)this; return *(T *)(p + offset + i * sizeof(T)); }
    u32 size() { return count; } };
struct WbEntry { char pad[0x40]; u8 b40; char pad2[0x140 - 0x41]; };
struct WbSub { char pad[0x10]; __vector4 pos; char pad2[0x54 - 0x20]; u8 b54; char pad3[0x8a - 0x55]; u8 b8a; char pad4[0x118 - 0x8b]; float f118; };
struct WbGame { char pad[0x96]; u8 b96; char p1[0xa4 - 0x97]; u8 ba4; char p2[0xcd - 0xa5]; u8 bcd; u8 p3; u8 bcf; char p4[0xd4 - 0xd0]; u8 bd4; u8 bd5; u8 bd6; char p5[0x104 - 0xd7]; WbRel<WbEntry> entries; char p6[4]; WbSub sub; char p7[0x332 - 0x110 - sizeof(WbSub)]; u8 b332; };
template <class T> struct WbPtr { T *p; T *operator->() { return p; } };
struct WbSelf { char pad[0x30]; WbPtr<WbGame> game; char pad2[0xc]; u8 b40[4]; u8 b44; u8 b45; char pad3[2]; WbVec3 pos; float f54; u8 b58[8]; };

static __inline void wb_store3(__vector4 *dst, __vector4 v)
{
    __stvewx(__vspltw(v, 0), dst, 0);
    __stvewx(__vspltw(v, 1), dst, 4);
    __stvewx(__vspltw(v, 2), dst, 8);
}

static __inline void wb_copy_sub(WbSelf *self, WbSub *s)
{
    self->b44 = s->b8a;
    self->b45 = s->b54;
    WbVec3 tmp;
    wb_store3((__vector4 *)&tmp, s->pos);
    self->pos = tmp;
    self->f54 = s->f118;
}

extern "C" void fn_8888C2B0(WbSelf *self)
{
    WbPtr<WbGame> &g = self->game;
    for (u32 i = 0; i < g->entries.size(); i++)
        self->b40[i] = g->entries[i].b40;
    wb_copy_sub(self, &g->sub);
    self->b58[0] = g->b96;
    self->b58[1] = g->ba4;
    self->b58[2] = g->bcd;
    self->b58[3] = g->bcf;
    self->b58[4] = g->bd4;
    self->b58[5] = g->bd5;
    self->b58[6] = g->bd6;
    self->b58[7] = g->b332;
}
