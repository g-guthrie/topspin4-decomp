/* agF 2026-11-19: not changed (13). Pure scheduling after fn_886A0FC0, same residue class as 0x886B4D00. */
/* agD round 2: still 13 plain and LTCG. Block-local pointers in Slots and for the Track vt, self_ref, Lanes call through a local, Ring with a Quad-cast ctor, non-forceinline Track: no change. */
/* agD 2026-11-19: Track ctor as `vt = lbl_880D7600; arr_init(ring);` with the 88695568 Quad-cast arr_init reproduces all ten dead addis: 121 -> 13 off (size now right). Remaining: right after the fn_886A0FC0 call the target stores slots w[0..2] before the vtable lis and spreads the track addis; ours hoists them. Block-local pointers in Slots, vt local, init orders: no change. */
/* agentA2 (2026-11-18 tips pass): not retried beyond the 8869FAD8 sibling test (Quad-cast/inline-init history ctor does not produce the dead addi); 121 off. */
/* 0x886A7AC8 near miss (121 off, C++ /Oc, ctor ??0Coach@@QAA@XZ; diff is mostly a shift from 10 missing unused addi).
 * Coach constructor: vtable lbl_880F44B4, graph at +0x40 (ts4_set_u32_off0_8867C870), lanes at +0xD8 (fn_886A0FC0),
 * 12 zero slots, five 0x44-byte tracks (vtable lbl_880D7600, 12-word ring at +0x14), pool from
 * ts4_if_call_seq_u32_lbl_88D45B38_8826C140, self_ref, misc zeros. Prologue through +0x70 matches with base class
 * CoachBase (vt + f4..f14) and member init lists. Open: target emits addi rX,this,t then addi rX,rX,0x14 (unused) per
 * track; tried ring loop, this-alias, Quad sub-structs, Ring as second base (none give it). */
typedef unsigned int u32;
extern "C" const void *lbl_880F44B4[];
extern "C" const void *lbl_880D7600[];
extern "C" void ts4_set_u32_off0_8867C870(void *p);
extern "C" void fn_886A0FC0(void *p);
extern "C" void *ts4_if_call_seq_u32_lbl_88D45B38_8826C140(void);
struct Quad { u32 w[4]; };
static __forceinline void quad_init(Quad *q) { q->w[0] = 0; q->w[1] = 0; q->w[2] = 0; q->w[3] = 0; }
static __forceinline void arr_init(u32 *b) { Quad *q = (Quad *)b; quad_init(&q[0]); quad_init(&q[1]); quad_init(&q[2]); }
struct Ring { u32 w[12]; __forceinline Ring() { w[0]=0; w[1]=0; w[2]=0; w[3]=0; w[4]=0; w[5]=0; w[6]=0; w[7]=0; w[8]=0; w[9]=0; w[10]=0; w[11]=0; } };
struct TrackBase { const void **vt; __forceinline TrackBase() { vt = lbl_880D7600; } };
struct Track { const void **vt; u32 a, b, c, d; u32 ring[12];
    __forceinline Track() { vt = lbl_880D7600; arr_init(ring); a = 0; b = 0; c = 0; d = 0; } };
struct Graph { char raw[0x94]; __forceinline Graph() { ts4_set_u32_off0_8867C870(this); } };
struct Head { u32 a, b, c; Graph g; __forceinline Head() : a(0), b(0), c(0), g() {} };
struct Lanes { u32 w[6]; __forceinline Lanes() { w[0] = 0; w[1] = 0; w[2] = 0; w[3] = 0; w[4] = 0; w[5] = 0; fn_886A0FC0(this); } };
struct Slots { u32 w[12]; __forceinline Slots() { w[0]=0; w[1]=0; w[2]=0; w[3]=0; w[4]=0; w[5]=0; w[6]=0; w[7]=0; w[8]=0; w[9]=0; w[10]=0; w[11]=0; } };
struct CoachBase { const void **vt; u32 f4, f8, fc, f10, f14;
    __forceinline CoachBase() : f4(0), f8(0), fc(0), f10(0), f14(0) { vt = lbl_880F44B4; } };
struct Coach : CoachBase {
    u32 f18; char _1c[8]; u32 f24, f28, f2c; char _30[4];
    u32 f34, f38, f3c; Graph graph; void *pool; Lanes lanes; Coach *self_ref; Slots slots; char _124[0x34];
    Track t0, t1, t2, t3, t4;
    Coach();
};
Coach::Coach() : f34(0), f38(0), f3c(0)
{
    f28 = 0; f2c = 0; f18 = 0;
    pool = ts4_if_call_seq_u32_lbl_88D45B38_8826C140();
    self_ref = this;
    f24 = 0;
}
