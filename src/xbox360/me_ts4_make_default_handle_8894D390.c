/* Swing_DLL.xex 0x8894D390: initialises *out to the null handle {0, 0xFFFFF, 0}, assigns it the global handle lbl_88C6B428
 * forwarded by hash 0x4743BE01, writes *a to field 0x4463883A (fn_8861CE00), clears flag 0xB01F4F95; returns out. agO: plain only (LTCG 22 off). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
extern Out lbl_88C6B428;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern Out *ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
typedef struct Ts4Hash { u32 v; } Ts4Hash;
void *fn_8861CE00(Out *out, Out *in, Ts4Hash hash, u32 value);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out *ts4_make_default_handle_8894D390(Out *out, const u32 *a)
{
    u32 k1, k3;
    Out key;
    Out *p;
    out->f0 = 0;
    out->f4 = 0x000FFFFFu;
    out->f8 = 0;
    k1 = 0x4743BE01u;
    key = lbl_88C6B428;
    { Out t; *out = *ts4_handle_forward_88610778(&t, &key, &k1); }
    { Out tmp; Ts4Hash h; h.v = 0x4463883Au; fn_8861CE00(&tmp, out, h, *a); }
    { Out tmp;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k3, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0; }
    return out;
}
