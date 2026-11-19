/* Swing_DLL.xex 0x8894EE70: forwards the global data handle lbl_88C6B410 by hash 0xC853BC87 into *out; unless the result is
 * null, writes a, b and the string lbl_880D371C to fields 0xAB2046F8, 0x32291742, 0x35991C25 and copies flag 0xB01F4F95 from lbl_880D0529. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
extern Out lbl_88C6B410;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
typedef struct Ts4Hash { u32 v; } Ts4Hash;
void *fn_8861CE00(Out *out, Out *in, Ts4Hash hash, u32 value);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
extern char lbl_880D371C[];
extern const u8 lbl_880D0529;
extern void ts4_clone_byte_with_object_context(Out *p, const u8 *src);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

static __inline u8 ts4_handle_is_null(const Out *h)
{
    return h->f0 == 0 || h->f4 == 0x000FFFFFu;
}

Out *ts4_make_checked_handle_8894EE70(Out *out, u32 a, u32 b)
{
    u32 k1, k3;
    Out key;
    Out *p;
    Out tmp;
    k1 = 0xC853BC87u;
    key = lbl_88C6B410;
    ts4_handle_forward_88610778(out, &key, &k1);
    if (!ts4_handle_is_null(out)) {
        { Ts4Hash h; h.v = 0xAB2046F8u; fn_8861CE00(&tmp, out, h, a); }
        { Ts4Hash h; h.v = 0x32291742u; fn_8861CE00(&tmp, out, h, b); }
        { Ts4Hash h; h.v = 0x35991C25u; fn_8861CE00(&tmp, out, h, (u32)lbl_880D371C); }
        k3 = 0xB01F4F95u;
        p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k3, 0);
        ts4_clone_byte_with_object_context(p, &lbl_880D0529);
    }
    return out;
}
