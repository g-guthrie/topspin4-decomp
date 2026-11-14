/* Swing_DLL.xex 0x88945298-0x88947464, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern Out lbl_88C6B428;
extern Out lbl_88C6B434;
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 a, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 a, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

/* 0x88945298 */
Out *ts4_hash_service_byte_88945298(Out *self, u8 value)
{
    u32 k1, k2, k3;
    Out cp, o1;
    Out *p;
    u8 *r;
    k1 = 0x90A5180Au;
    cp = lbl_88C6B434;
    ts4_handle_forward_88610778(self, &cp, &k1);
    k2 = 0x20F5FAA9u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o1, (In *)self, (u32)(unsigned long)&k2, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = value;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o1, (In *)self, (u32)(unsigned long)&k3, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = 0;
    return self;
}

/* 0x88947358 */
Out *ts4_hash_service_word_88947358(Out *self, u32 *valp)
{
    u32 k1, k2, k3;
    Out cp, o1;
    Out *p;
    u32 *slot;
    u8 *r;
    k1 = 0xEC7AE339u;
    cp = lbl_88C6B428;
    ts4_handle_forward_88610778(self, &cp, &k1);
    k2 = 0xFF3A7B97u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164F60(&o1, (In *)self, (u32)(unsigned long)&k2, 0);
    slot = (u32 *)TS4_SLOT10(p, 4);
    *slot = *valp;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o1, (In *)self, (u32)(unsigned long)&k3, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = 0;
    return self;
}
