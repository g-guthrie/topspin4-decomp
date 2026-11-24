/* Q5h1 clone: VMX box test forwarder (equivalent tier).
 * Clone of ts4_vec_box_test_forward_886C8C48 (eq_q5_forwarders.c). The sister 0x886C90F0 has the same
 * 0x20-byte frame and forwards the same seven pointer arguments, but to fn_886C8C68 instead of fn_886C8878.
 * fn_886C8C68 is declared with the same prototype as the template's callee. */
typedef unsigned char u8;

/* 16-byte aligned float4 as the vector code reads it (lvx128). */
typedef struct Q5h1Vec4 { float v[4]; } Q5h1Vec4;
/* Two consecutive float4 rows (the callee reads +0x00 and +0x10 of each input). */
typedef struct Q5h1VecPair { Q5h1Vec4 row[2]; } Q5h1VecPair;

/* Same prototype as fn_886C8878 in the template (VMX box/segment test, returns a bool). */
extern u8 fn_886C8C68(const Q5h1VecPair *a, const Q5h1VecPair *b, const Q5h1VecPair *c, Q5h1Vec4 *out0,
                      Q5h1Vec4 *out1, Q5h1Vec4 *out2, Q5h1Vec4 *out3);

/* Swing_DLL.xex 0x886C90F0: forward all seven arguments to fn_886C8C68 and return its result. */
/* byte-gap: 8 off; original keeps a frame around a non-tail call (sister of 0x886C8C48) */
u8 ts4_vec_box_test_forward_886C90F0(const Q5h1VecPair *a, const Q5h1VecPair *b, const Q5h1VecPair *c,
                                     Q5h1Vec4 *out0, Q5h1Vec4 *out1, Q5h1Vec4 *out2, Q5h1Vec4 *out3)
{
    return fn_886C8C68(a, b, c, out0, out1, out2, out3);
}
