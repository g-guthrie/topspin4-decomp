/* agD 2026-11-19: Slot ctor via the 88695568 Quad-cast arr_init (dead +0x14 addis), slots as nine named members (an array of 9 becomes a loop once arr_init is used), Track a[] via quad_init((Quad *)a) (dead addi this+0x330): 263 -> 92 off plain, 81 on LTCG + primer, size right. Remaining: scheduling only; the target stores the Root vtable before the member-init zeros and spreads the vtable lis/addis; block-local vt pointer and body-moved zeros made it worse. */
/* agentA2 (2026-11-18 tips pass): not retried beyond the 8869FAD8 sibling test (same dead addi +0x14 residue); 263 off. */
/* near miss 0x886B4D00 (ME agent B): 263 off (/Oc, plain and LTCG). Store order of the constructor body, the base vptr
 * stores and the member-initialiser zeros all match; what shifts everything is the target's dead
 * 'addi rX,slot,0x14' this-pointer computations for the 0x30-byte member at +0x14 of each 0x44-byte slot.
 * Tried: Inner as plain ctor, via pointer, returning this, as a base, split in two, nested Quad[3]. */
extern "C" {
#include "../ts4_vector.h"
}
inline void *operator new(unsigned int, void *p) { return p; }
extern "C" const char lbl_880F434C[], lbl_880D7600[], lbl_880D75FC[];
extern "C" float g_ts4_event_value;
struct Quad { int w[4]; };
static __forceinline void quad_init(Quad *q) { q->w[0] = 0; q->w[1] = 0; q->w[2] = 0; q->w[3] = 0; }
static __forceinline void arr_init(int *b) { Quad *q = (Quad *)b; quad_init(&q[0]); quad_init(&q[1]); quad_init(&q[2]); }
struct Inner { int w[12]; Inner() { w[0] = 0; w[1] = 0; w[2] = 0; w[3] = 0; w[4] = 0; w[5] = 0; w[6] = 0; w[7] = 0; w[8] = 0; w[9] = 0; w[10] = 0; w[11] = 0; } };
struct SlotBase { const void *vt; SlotBase() { vt = lbl_880D7600; } };
struct Slot { const void *vt; int a, b, c, d; int in[12];
    Slot() { vt = lbl_880D7600; arr_init(in); a = 0; b = 0; c = 0; d = 0; } };
struct TrackBase { const void *vt; TrackBase() { vt = lbl_880D75FC; } };
struct Track : TrackBase { int a[4]; float level; int f348, f34c; char p350[0x360 - 0x350]; int f360, f364; unsigned char b368; char p369[3];
    int r[6]; int p384; int s[3];
    Track() { quad_init((Quad *)a); r[0] = 0; r[1] = 0; r[2] = 0; r[3] = 0; r[4] = 0; r[5] = 0; s[0] = 0; s[1] = 0; s[2] = 0; level = g_ts4_event_value; } };
struct Root { const void *vt; Root() { vt = lbl_880F434C; } };
struct Zero6 { int w[6]; Zero6() { w[0] = 0; w[1] = 0; w[2] = 0; w[3] = 0; w[4] = 0; w[5] = 0; } };
struct Rally : Root {
    char p4[0x10 - 4]; unsigned char b10; char p11[3]; int f14, f18, f1c, f20; char p24[4]; int f28, f2c, f30, f34; char p38[4]; int f3c, f40;
    int g[19]; unsigned char b90, b91, b92, b93; Zero6 h; int k[8]; Slot s0, s1, s2, s3, s4, s5, s6, s7, s8; Track track;
    int f394, f398; unsigned char b39c; char p39d[0x3a8 - 0x39d]; int f3a8, f3ac, f3b0, f3b4; unsigned char b3b8, b3b9; char p3ba[2]; int f3bc; __vector4 v3c0;
    Rally();
};
Rally::Rally() : f20(0), f30(0), f34(0), f3c(0)
{
    b10 = 0; f14 = -1; f18 = -1; f28 = 0; f2c = 0; f1c = 0; f40 = 0;
    b90 = 0;
    g[0] = 0; g[1] = 0; g[2] = 0; g[3] = 0; g[4] = 0; g[5] = 0; g[6] = 0; g[7] = 0; g[8] = 0; g[9] = 0; g[10] = 0; g[11] = 0; g[12] = 0; g[13] = 0; g[14] = 0; g[15] = 0; g[16] = 0;
    b91 = 0; g[17] = 0; b92 = 0; g[18] = 0; b93 = 0;
    k[0] = 0; k[1] = 0; v3c0 = __vspltisw(0); k[2] = 0; k[3] = 0; k[4] = 0; k[5] = 0; k[6] = 0; k[7] = 0;
    track.f360 = 0; track.f364 = 0; track.f348 = 0; track.f34c = 0; track.b368 = 0;
    f394 = 0; f398 = 0; b39c = 0; f3b0 = 0; f3ac = 0; f3a8 = 0; f3b4 = 0; b3b8 = 1; b3b9 = 0; f3bc = -1;
}

