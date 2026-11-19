/* NEAR MISS (agO, 2026-11-19): 2 real instructions off on plain (/Oc). The target recomputes n + 1 for the slot-11 call
 * (two addi from r31); MSVC CSEs it. A u64 slot argument gets the separate addi but adds rldicl/extsw. Same shape: 88702E00. */
/* Swing_DLL.xex 0x88944378: forwards the global data handle lbl_88C6B434 by hash 0x856A8D54 into *out, writes the byte ranges
 * a and b (length last - first + 1) to fields 0xA12DE6EC and 0x21ABF4C0 (vtable slot 11), clears flag 0xB01F4F95; returns out. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Range { const char *first, *last; } Ts4Range;
extern Out lbl_88C6B434;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
typedef void (*Ts4SlotRange)(Ts4Obj *self, Out *arg, u32 a, const char *s, u32 n);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88165D80(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))
#define TS4_SLOT11(q, s, n) ((Ts4SlotRange)((Ts4Obj *)(unsigned long)(q)->f0)->vt[11])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (s), (n))

Out *ts4_make_range_pair_handle_88944378(Out *out, const Ts4Range *a, const Ts4Range *b)
{
    u32 k1, k2, k3, k4;
    Out key;
    Out *p;
    k1 = 0x856A8D54u;
    key = lbl_88C6B434;
    ts4_handle_forward_88610778(out, &key, &k1);
    { Out tmp; const char *s; u32 n;
    k2 = 0xA12DE6ECu;
    n = (u32)(a->last - a->first); s = a->first;
    p = (Out *)ts4_init_range_and_run_service_opt_88165D80(&tmp, (In *)out, &k2, n + 1);
    TS4_SLOT11(p, s, n + 1); }
    { Out tmp; const char *s; u32 n;
    k3 = 0x21ABF4C0u;
    n = (u32)(b->last - b->first); s = b->first;
    p = (Out *)ts4_init_range_and_run_service_opt_88165D80(&tmp, (In *)out, &k3, n + 1);
    TS4_SLOT11(p, s, n + 1); }
    { Out tmp;
    k4 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k4, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0; }
    return out;
}
