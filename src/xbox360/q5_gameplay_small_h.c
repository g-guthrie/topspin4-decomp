/* Top Spin 4 (Xbox 360, Swing_DLL.xex): Q5 gameplay, small functions, batch H (byte-matched). */
typedef unsigned int u32;
typedef unsigned char u8;

#ifdef _MSC_VER
extern void *memcpy(void *dst, const void *src, unsigned int n);
#else
#include <string.h>
#endif

/* ---- 0x888DFA40: count the slots of the pool record (found by hash 0xF895ECB1 under the
 * handle built from lbl_880D85CC) whose +0x1c owner index is non-negative. The slots are a
 * self-relative array {offset, count} at pool+0x214, 0x20 bytes each.
 * Matching note: `n = 0` sits between the two calls, so it lands in r31 before the second call. */
typedef struct Q5Hdl12 { u32 a, b, c; } Q5Hdl12;
typedef struct Q5SlotRec { char pad[0x1c]; int owner; } Q5SlotRec;
typedef struct Q5RelArr { int off; int count; } Q5RelArr;
typedef struct Q5SlotPool { char pad[0x214]; Q5RelArr slots; } Q5SlotPool;
extern Q5Hdl12 *ts4_if_set_u32_off0_8862C0E8(Q5Hdl12 *out, void *src);
extern Q5SlotPool *fn_88923530(u32 pool, Q5Hdl12 h, u32 hash);
extern char lbl_880D85CC[];

/* Swing_DLL.xex 0x888DFA40 */
int ts4_count_owned_slots_888DFA40(void)
{
    Q5Hdl12 h;
    Q5RelArr *a;
    int n;
    int i;
    ts4_if_set_u32_off0_8862C0E8(&h, lbl_880D85CC);
    n = 0;
    a = &fn_88923530(h.c, h, 0xF895ECB1u)->slots;
    for (i = 0; i < a->count; i++) {
        if (((Q5SlotRec *)((char *)a + a->off))[i].owner >= 0)
            n++;
    }
    return n;
}

/* ---- 0x888F70A0: clear the global rig set's dirty flag; for every rig that is active, copy
 * each of its 5 key tracks (count * 12-byte keys, src -> dst) and run fn_8817BE78 on it;
 * then run fn_888CE5D0 on every rig's +0x164 block. Rigs are 0x19c bytes from +0xc. */
typedef struct Q5Key12 { u32 w[3]; } Q5Key12;
typedef struct Q5KeyTrack { Q5Key12 *src; char pad04[4]; Q5Key12 *dst; char pad0c[0x10]; u32 count; char pad20[0x18]; } Q5KeyTrack;
typedef struct Q5Rig { char pad[7]; u8 active; char pad08[0x14]; Q5KeyTrack tracks[5]; char pad134[0x30]; char tail164[0x38]; } Q5Rig;
typedef struct Q5RigSet { char pad[4]; u32 count; u8 dirty; char pad09[3]; Q5Rig rigs[1]; } Q5RigSet;
extern Q5RigSet lbl_88D45CC0;
extern void fn_8817BE78(Q5Rig *rig);
extern void fn_888CE5D0(void *p);

/* Swing_DLL.xex 0x888F70A0 */
void ts4_rigs_restore_888F70A0(void)
{
    Q5RigSet *s = &lbl_88D45CC0;
    u32 i;
    s->dirty = 0;
    for (i = 0; i < s->count; i++) {
        Q5Rig *r = &s->rigs[i];
        if (r->active) {
            int k;
            for (k = 0; k < 5; k++)
                memcpy(r->tracks[k].dst, r->tracks[k].src, r->tracks[k].count * sizeof(Q5Key12));
            fn_8817BE78(r);
        }
        fn_888CE5D0(r->tail164);
    }
}
