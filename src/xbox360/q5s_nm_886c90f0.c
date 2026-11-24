/* Swing_DLL.xex 0x886C90F0: VMX box/segment test forwarder.
 *
 * Passes its seven pointer arguments and four by-value vectors straight through to fn_886C8C68 and
 * returns its bool. The vectors are why the original keeps a 0xA0-byte frame around a non-tail call:
 * fn_886C8C68 reads v1..v4 without writing them first (they bracket two pairs of lanes in its
 * vcmpgefp128 range tests, lo0 <= x <= hi0 and lo1 <= y <= hi1), so its prototype carries four
 * __vector4 parameters after the seven pointers. Their slots grow the outgoing parameter save area
 * from 0x40 to 0x80 bytes (frame 0x60 -> 0xA0), and cl keeps the bl instead of a tail branch.
 * fn_check (plain, also with /Oc): MATCH, size 0x20. */
#include "vx1_vector.h"

typedef unsigned char u8;

/* 16-byte aligned float4 as the vector code reads it (lvx128). */
typedef struct Q5sBoxVec4 { float v[4]; } Q5sBoxVec4;
/* Two consecutive float4 rows (the callee reads +0x00 and +0x10 of each input). */
typedef struct Q5sBoxVecPair { Q5sBoxVec4 row[2]; } Q5sBoxVecPair;

extern u8 fn_886C8C68(const Q5sBoxVecPair *a, const Q5sBoxVecPair *b, const Q5sBoxVecPair *c, Q5sBoxVec4 *out0,
                      Q5sBoxVec4 *out1, Q5sBoxVec4 *out2, Q5sBoxVec4 *out3, __vector4 lo0, __vector4 hi0,
                      __vector4 lo1, __vector4 hi1);

u8 ts4_vec_box_test_forward_886C90F0(const Q5sBoxVecPair *a, const Q5sBoxVecPair *b, const Q5sBoxVecPair *c,
                                     Q5sBoxVec4 *out0, Q5sBoxVec4 *out1, Q5sBoxVec4 *out2, Q5sBoxVec4 *out3,
                                     __vector4 lo0, __vector4 hi0, __vector4 lo1, __vector4 hi1)
{
    return fn_886C8C68(a, b, c, out0, out1, out2, out3, lo0, hi0, lo1, hi1);
}
