/*
 * GA4: gameplay helpers that call through MSVC virtual-call thunks (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * The thunk class layout follows src/xbox360/ga3_c.cpp (pointer-to-member constants lower to a direct
 * call of ??_9TS4VcallClass<addr>@@$B...). Slot offset = thunk digit + 1 for single-digit suffixes.
 */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

class TS4VcallClass88286E38 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
};
#define GA4_VCALL_88286E38_SLOT2(p) (((TS4VcallClass88286E38 *)(p))->*(&TS4VcallClass88286E38::slot_002))()

extern "C" void ts4_call_seq_fn_8890DDA8_8867A068(void *e);
extern "C" void ts4_if_call_seq_u32_off28_88691230(void *e);

struct Ga4Elem2AC { ts4_u8 b[0x2AC]; };
struct Ga4Elem3C { ts4_u8 b[0x3C]; };
struct Ga4Elem3D0 { ts4_u8 b[0x3D0]; };
struct Ga4Elem1B0 { ts4_u8 b[0x1B0]; };
struct Ga4Elem50 { ts4_u8 b[0x50]; };
struct Ga4Pools {
    ts4_u8 pad_00[0xC];
    Ga4Elem1B0 *a_begin; Ga4Elem1B0 *a_end;   /* +0x0C */
    ts4_u8 pad_14[0x10];
    Ga4Elem3C *b_begin; Ga4Elem3C *b_end;     /* +0x24 */
    ts4_u8 pad_2c[0x10];
    Ga4Elem2AC *c_begin; Ga4Elem2AC *c_end;   /* +0x3C */
    ts4_u8 pad_44[0x10];
    Ga4Elem50 *d_begin; Ga4Elem50 *d_end;     /* +0x54 */
    ts4_u8 pad_5c[0x1C];
    Ga4Elem3D0 *e_begin; ts4_u32 e_count;     /* +0x78 */
};
struct Ga4PoolHost { ts4_u8 pad_00[0x64]; Ga4Pools *pools; };

/* Release every element of the five pools (virtual release thunk or element destructor each).
   Swing_DLL.xex 0x8869F428 */
extern "C" void ga4_release_pools_8869F428(Ga4PoolHost *self)
{
    Ga4Elem2AC *c, *c_end;
    Ga4Elem3C *b, *b_end;
    Ga4Elem3D0 *e, *e_end;
    Ga4Elem1B0 *a, *a_end;
    Ga4Elem50 *d, *d_end;
    c_end = self->pools->c_end;
    for (c = self->pools->c_begin; c != c_end; c++) GA4_VCALL_88286E38_SLOT2(c);
    b_end = self->pools->b_end;
    for (b = self->pools->b_begin; b != b_end; b++) GA4_VCALL_88286E38_SLOT2(b);
    e = self->pools->e_begin;
    e_end = e + self->pools->e_count;
    for (; e != e_end; e++) GA4_VCALL_88286E38_SLOT2(e);
    a_end = self->pools->a_end;
    for (a = self->pools->a_begin; a != a_end; a++) ts4_call_seq_fn_8890DDA8_8867A068(a);
    d_end = self->pools->d_end;
    for (d = self->pools->d_begin; d != d_end; d++) ts4_if_call_seq_u32_off28_88691230(d);
}
