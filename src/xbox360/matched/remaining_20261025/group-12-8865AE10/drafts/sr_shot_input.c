/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Shot-input functions preserve load/store order because the state block may alias player storage. Five listed functions are included; 0x8826B640 is excluded. Field roles and signatures remain provisional.
 */
#include "sr_common.h"

/* Reconstruction note:
 * one draft name per address everywhere in this translation unit. Bodies come from their reviewed variants:
 * 0x8826B640 V1R, 0x88659C48 V2R-ret (in 88681B80/V2R), 0x8865AE10 V1, 0x88681848 V1R, 0x88681B80 V2R, 0x88696020 V3R2; every other body keeps its V3R2 text.
 * Calls to in-file addresses use the draft names; ts4_memset is outside the TU and keeps its name. R2c: 0x8817B608 (fn_8817B608) is defined in its own unit sr_angle_wrap.c .
 */

/* 0x8865AE10-0x8865AEB8 (168 B): main state 1. Type R+8 (1/2/3) -> P+0x482/483/484 = 1; P+0x480 = 1; P+0x4B5 = 0;
 * if the S-block byte +5/+6/+7 of that type is set, S-block +1 = 1. The S block pointer is loaded once. */
void fn_8865AE10(sr_u8 *s)
{
    sr_u8 c = 0;
    sr_u8 *blk = SR_PTR(s, 0x20);
    sr_s32 t = (sr_s32)SR_U32(SR_PTR(s, 0x28), 8);
    switch (t) {
    case 1:
        c = SR_U8(blk, 5);
        SR_U8(SR_P(SR_OWNER_S(s)), 0x482) = 1;
        break;
    case 2:
        c = SR_U8(blk, 6);
        SR_U8(SR_P(SR_OWNER_S(s)), 0x483) = 1;
        break;
    case 3:
        c = SR_U8(blk, 7);
        SR_U8(SR_P(SR_OWNER_S(s)), 0x484) = 1;
        break;
    }
    SR_U8(SR_P(SR_OWNER_S(s)), 0x480) = 1;
    SR_U8(SR_P(SR_OWNER_S(s)), 0x4B5) = 0;
    if (c == 0) {
        return;
    }
    SR_U8(blk, 1) = 1;
}

/* 0x88659BB0-0x88659C44 (148 B): type R+8 -> one-hot S-block +2/+3/+4 (types 1/2/3; 0 and >3 unsigned: no change). */
void fn_88659BB0(sr_u8 *s);

/* 0x88659C48-0x88659CA0 (88 B): one-hot S-block +4/+3/+2 -> R+8 = 3/2/1 (first set byte wins; none: no store).
 * Writes only r10/r11 and keeps r3 (sr_clobber.py), which its callers rely on. */
/* Reconstruction note: 0x88659C48 returns its argument (the listing keeps r3; 0x88681B80 passes it on). */
sr_u8 *fn_88659C48(sr_u8 *s)
{
    sr_u8 *blk = SR_PTR(s, 0x20);
    if (SR_U8(blk, 4) != 0) {
        SR_U32(SR_PTR(s, 0x28), 8) = 3;
        return s;
    }
    if (SR_U8(blk, 3) != 0) {
        SR_U32(SR_PTR(s, 0x28), 8) = 2;
        return s;
    }
    if (SR_U8(blk, 2) == 0) {
        return s;
    }
    SR_U32(SR_PTR(s, 0x28), 8) = 1;
    return s;
}

/* 0x88672750-0x88672824 (212 B): polar dwell test. Returns (low byte) 1 when desc[0] <= mag (S-block +8; NaN mag or
 * desc passes, as ble is taken on unordered) AND |wrap(angle - desc[1])| < desc[2] (angle = S-block +0xC) AND, after
 * incrementing the counter R+0xC, counter >= desc[3] (signed, via the subfc/adde idiom on 64-bit registers: the
 * value is 2 when the counter wraps from 0xFFFFFFFF and desc[3] is negative). The counter is reset to 0 only when
 * the magnitude test fails. */
sr_u32 fn_88672750(sr_u8 *s, sr_u8 *desc);

/* 0x88681AE0-0x88681B7C (156 B): P+0x3A8..0x3AB bytes and P+0x3AC = 0, then memset(P+0x3A8, 0, 8) (0x8857C630), then
 * (P+0x3A8)+4 = P'+0x610 (P re-read through the owner chain). The original stores an UNINITIALISED stack byte to
 * P+0x3AB (lbz r8,0x53(r1)); the memset overwrites it before any read, so the draft stores 0 there. This is a
 * documented deviation that holds only under the memset contract (hooks/sr_hooks.h). */
void fn_88681AE0(sr_u8 *s);

/* 0x88681958-0x88681ADC (388 B): sub-state transition. 0: dwell(desc+0x30) -> S-block +0x35 = 1, return 1.
 * 1: if P+0x98 != 0x7FFFFFFF and >= 0 and cfg2+0x744 > P+0x98 - now -> result 2, P+0x68C = 0.0; then if any of
 * dwell(desc+0x40/+0x60/+0x50) (evaluated in that order, stopping at the first true) -> P+0x68C = 1.0, return 2.
 * 2: return 3. >= 3: return the input. Returns the input register unchanged otherwise. */
sr_u32 fn_88681958(sr_u8 *s, sr_u32 state);

/* 0x88681848-0x88681958 (272 B): sub-state enter (state > 3 unsigned: nothing). 0: R+8 = 1. 1: S+0x34 = now.
 * 2: R+8 = 3 if dwell(desc+0x60), else 2 if dwell(desc+0x50), else 1; then 0x88659BB0(S); S-block +1 = 1;
 * S+0x30 = now. 3: S-block +0x36 = 1. */
/* Reconstruction note: calls to functions defined in this
 * translation unit use their draft names, one name per address: fn_88672750 -> fn_88672750, fn_88659BB0 -> fn_88659BB0. Code otherwise identical to V1. */
void fn_88681848(sr_u8 *s, sr_u32 state)
{
    switch (state) {
    case 0:
        SR_U32(SR_PTR(s, 0x28), 8) = 1;
        break;
    case 1:
        SR_U32(s, 0x34) = SR_NOW(SR_OWNER_S(s));
        break;
    case 2:
        if (fn_88672750(s, SR_PTR(s, 0x24) + 0x60) & 0xFF) {
            SR_U32(SR_PTR(s, 0x28), 8) = 3;
        } else if (fn_88672750(s, SR_PTR(s, 0x24) + 0x50) & 0xFF) {
            SR_U32(SR_PTR(s, 0x28), 8) = 2;
        } else {
            SR_U32(SR_PTR(s, 0x28), 8) = 1;
        }
        fn_88659BB0(s);
        SR_U8(SR_PTR(s, 0x20), 1) = 1;
        SR_U32(s, 0x30) = SR_NOW(SR_OWNER_S(s));
        break;
    case 3:
        SR_U8(SR_PTR(s, 0x20), 0x36) = 1;
        break;
    }
}

/* 0x8826B640-0x8826B6B4 (116 B): sub-state driver over the record {+0 state pointer, +4 S, +8 last, +0xC count}.
 * Up to 8 transitions: next = 0x88681958(S, cur); stop when next == cur (32-bit compare); else cur = next,
 * 0x88681848(S, next), count = 0. Then *state = cur, +8 = cur, +0xC += 1. */
/* Reconstruction note: calls to functions defined in this
 * translation unit use their draft names, one name per address: fn_88681958 -> fn_88681958, fn_88681848 -> fn_88681848. Code otherwise identical to V1. */
void fn_8826B640(sr_u8 *sub);

/* 0x88681B80-0x88681CFC (380 B): main state 0. Always: S-block +0 = 0, S-block +0x35 = 0. Returns when Q+0x18C > 0
 * (signed; the neg/andc/bit-31 idiom). Then: counter *(S+0x2C) > cfg+0x9AC and (M44+0x1C set, M44+0x1D clear) ->
 * R[0] = 3, S-block +2 = 1, 0x88659C48, S-block +0 = 1, 0x88681AE0, S-block +0x40 = 0. Else any of S-block +4/+3/+2
 * -> R[0] = 1, 0x88659C48, S-block +0 = 1, 0x88681AE0, S-block +0x40 = 0. Else dwell(desc+0x30) and R+0x1C ->
 * R[0] = 2, S-block +0x36 = 0, +0x35 = 1, 0x88681AE0. */
/* Reconstruction note: the two compound conditions are 8-bit flags
 * (`clrlwi; cmplwi` before the test); V2: the positive test is likewise an 8-bit flag of `q > 0` (`neg; andc; srwi 31; cmplwi`);
 * 0x88659C48 returns its argument and the caller passes that value to 0x88681AE0 (no `mr r3,r31` between the calls;
 * prototype changed only in the variant header). */
/* Reconstruction note: calls to functions defined in this translation unit use
 * their draft names (fn_88659C48 -> fn_88659C48, fn_88681AE0 -> fn_88681AE0,
 * fn_88672750 -> fn_88672750). */
void fn_88681B80(sr_u8 *s)
{
    sr_u8 *blk = SR_PTR(s, 0x20);
    sr_u32 q = SR_U32(SR_PTR(SR_OWNER_S(s), 0x78), 0x18C);
    sr_u8 *owner, *m44, *cfg;
    sr_u8 flag;
    sr_u8 any;
    SR_U8(blk, 0) = 0;
    SR_U8(SR_PTR(s, 0x20), 0x35) = 0;
    if ((sr_u8)((sr_s32)q > 0)) {
        return;
    }
    owner = SR_OWNER_S(s);
    m44 = SR_PTR(SR_PTR(owner, 0x48), 0x44);
    flag = (sr_u8)(SR_U8(m44, 0x1C) != 0 && SR_U8(m44, 0x1D) == 0);
    cfg = SR_PTR(SR_PTR(owner, 0x44), 0x6C);
    if ((sr_s32)SR_U32(SR_PTR(s, 0x2C), 0) > (sr_s32)SR_U32(cfg, 0x9AC) && flag) {
        sr_u8 *t;
        SR_U32(SR_PTR(s, 0x28), 0) = 3;
        SR_U8(blk, 2) = 1;
        t = fn_88659C48(s);
        SR_U8(blk, 0) = 1;
        fn_88681AE0(t);
        SR_U32(SR_PTR(s, 0x20), 0x40) = 0;
        return;
    }
    any = (sr_u8)(SR_U8(blk, 4) != 0 || SR_U8(blk, 3) != 0 || SR_U8(blk, 2) != 0);
    if (any) {
        sr_u8 *t;
        SR_U32(SR_PTR(s, 0x28), 0) = 1;
        t = fn_88659C48(s);
        SR_U8(blk, 0) = 1;
        fn_88681AE0(t);
        SR_U32(SR_PTR(s, 0x20), 0x40) = 0;
        return;
    }
    if (fn_88672750(s, SR_PTR(s, 0x24) + 0x30) & 0xFF) {
        sr_u8 *r = SR_PTR(s, 0x28);
        if (SR_U8(r, 0x1C) != 0) {
            SR_U32(r, 0) = 2;
            SR_U8(blk, 0x36) = 0;
            SR_U8(blk, 0x35) = 1;
            fn_88681AE0(s);
        }
    }
}

/* 0x88696020-0x88696170 (336 B): S update (vtable 0x880F4D10 +0x08). If R+0x3A: R[0] = 0, S-block +0x40 = 0,
 * R+0x3A = 0. ++*(S+0x2C). S-block +1 = 0, +0x36 = 0. If R+0x1C == 0 and S-block +8 == 0.0 (fcmpu equal; -0.0
 * equal; NaN not): R+0x1C = 1. Then only if *(S+0x2C) > cfg+0x9A8 (signed): switch on R[0] (unsigned):
 * 0 -> 0x88681B80, 1 -> 0x8865AE10, 2 -> 0x8826B640(S+0x3C) then 0x88659BB0, 3 -> S-block +1 = 1, > 3 nothing. */
/* Reconstruction note: the reload of the guest 32-bit word at s+0x28 and its
 * conversion to the target pointer type are written explicitly with SR_GUEST_PTR, defined in the variant header).
 * V3 = V2 plus: the R[0] = 0 store goes through the R pointer re-read as a 32-bit integer and
 * converted back (the original zero-extends it with rlwinm r10,r10,0,0,31 = clrrwi r10,r10,0 before stw).
 * V2: declaration-only extern by its upstream symbols.txt name (the symbol registry);
 * the original compares against the 0.0f stored at g_ts4_event_value (0x8814B440). */
extern const float g_ts4_event_value;
/* Reconstruction note: calls to functions defined in this
 * translation unit use their draft names, one name per address: fn_88659BB0 -> fn_88659BB0, fn_88681B80 -> fn_88681B80, fn_8865AE10 -> fn_8865AE10, fn_8826B640 -> fn_8826B640. Code otherwise identical to V3. */
void fn_88696020(sr_u8 *s)
{
    sr_u8 *r = SR_PTR(s, 0x28);
    sr_u32 st;
    if (SR_U8(r, 0x3A) != 0) {
        SR_U32(SR_GUEST_PTR(SR_U32(s, 0x28)), 0) = 0; /* reload the guest 32-bit word at s+0x28, convert to the target pointer type */
        SR_U32(SR_PTR(s, 0x20), 0x40) = 0;
        SR_U8(SR_PTR(s, 0x28), 0x3A) = 0;
    }
    SR_U32(SR_PTR(s, 0x2C), 0) = SR_U32(SR_PTR(s, 0x2C), 0) + 1;
    SR_U8(SR_PTR(s, 0x20), 1) = 0;
    SR_U8(SR_PTR(s, 0x20), 0x36) = 0;
    r = SR_PTR(s, 0x28);
    if (SR_U8(r, 0x1C) == 0 && *(float *)(SR_PTR(s, 0x20) + 8) == g_ts4_event_value) {
        SR_U8(r, 0x1C) = 1;
    }
    if (!((sr_s32)SR_U32(SR_PTR(s, 0x2C), 0) >
          (sr_s32)SR_U32(SR_PTR(SR_PTR(SR_OWNER_S(s), 0x44), 0x6C), 0x9A8))) {
        return;
    }
    st = SR_U32(SR_PTR(s, 0x28), 0);
    switch (st) {
    case 0:
        fn_88681B80(s);
        break;
    case 1:
        fn_8865AE10(s);
        break;
    case 2:
        fn_8826B640(s + 0x3C);
        fn_88659BB0(s);
        break;
    case 3:
        SR_U8(SR_PTR(s, 0x20), 1) = 1;
        break;
    }
}

/* 0x88696170-0x886962C0 (336 B): S reset (vtable +0x34). Mapper entry (idx = owner+0x14; mapper =
 * *(*(M48+0x1C)+0xD0); entries {+0x1C begin, +0x20 end} stride 0x34; count = (end - begin) / 52 signed divw):
 * if entry+0x20 < count (unsigned) and >= 0 (signed): entry+0x24 = 0. S block: bytes 0..7, +0x34..+0x38, +0x48 = 0,
 * floats +8..+0x30 = 0.0. R+8 = 0; S+0x30 = -1; S+0x34 = 0; P+0x688 = P+0x68C = 0.0. If *(*(S+0x3C)) != 0:
 * set it 0, 0x88681848(*(S+0x40), 0), S+0x48 = 0. Then 0x8826B640(S+0x3C); R+8 = 1. */
void fn_88696170(sr_u8 *s);
