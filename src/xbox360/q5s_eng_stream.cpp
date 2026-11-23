/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex): stream wrapper forwarders (q5s eng).
 * Route: LTCG (/Oc). Context: flags(/Ob1):src/xbox360/cx15_core_b.c (callees kept as real calls via --include)
 * and src/xbox360/pp1_pool_primer.c. Spec: work/specs/Q5S/q5s_eng_stream.json.
 *
 * Both functions are vtable slots of the wrapper class (vtables 0x880DF220 / 0x880F7DB0). They pass the
 * wrapper itself as a one-word by-value stream reference: the original converts `this` implicitly to a
 * small class with a constructor, which makes cl spill it (stw r3,0x50(r1); addi r11,r1,0x50; lwz r5,0(r11))
 * instead of turning the call into a tail call.
 */
typedef unsigned char u8;
typedef unsigned int u32;

struct Ts4StreamRef {
    void *p;
    Ts4StreamRef(void *q) : p(q) {}
};

extern "C" u32 ts4_run_blk_mode1_88630E08(void *self, u32 a, Ts4StreamRef b, u32 c, u32 d, u32 e);
extern "C" u32 ts4_run_blk_mode3_88630D98(void *self, Ts4StreamRef a, u32 b, u32 c);

struct Ts4StreamWrap {
    u8 pad0[0x18];
    void *blk;                                     /* +0x18 block runner passed to the mode callees */
};

/* Swing_DLL.xex 0x88631138 */
extern "C" u32 ts4_stream_io_mode1_forward_88631138(Ts4StreamWrap *self, u32 a, u32 c, u32 d, u32 e)
{
    return ts4_run_blk_mode1_88630E08(self->blk, a, self, c, d, e);
}

/* Swing_DLL.xex 0x88631100 */
extern "C" u32 ts4_stream_io_mode3_forward_88631100(Ts4StreamWrap *self, u32 b, u32 c)
{
    return ts4_run_blk_mode3_88630D98(self->blk, self, b, c);
}
