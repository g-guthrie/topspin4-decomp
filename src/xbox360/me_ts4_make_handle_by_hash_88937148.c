/* Swing_DLL.xex 0x88937148: *out starts as {0, 0xFFFFF, 0}, becomes the data handle at lbl_88D45AD4->+0xBC forwarded by *hash,
 * then the 1-byte flag 0xB01F4F95 is cleared; returns out. agO: LTCG route only (plain is 12 off). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
typedef struct Ts4Global { char pad[0xbc]; Out key; } Ts4Global;
extern Ts4Global *lbl_88D45AD4;
extern Out *ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out *ts4_make_handle_by_hash_88937148(Out *out, u32 *hash)
{
    u32 k3;
    Out key, fwd;
    Out *p;
    out->f0 = 0; out->f8 = 0; out->f4 = 0xFFFFF;
    k3 = 0xB01F4F95u;
    key = lbl_88D45AD4->key;
    *out = *ts4_handle_forward_88610778(&fwd, &key, hash);
    { Out tmp; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k3, 0);
      *(u8 *)TS4_SLOT10(p, 1) = 0; }
    return out;
}
