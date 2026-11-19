/* NEAR MISS (agO, 2026-11-19): 2 off on plain and LTCG (/Oc): li r6,0 and stw v(10),0x58(r1) are swapped.
 * Lookalike of 888B1780. Tried v in/outside the block, before/after k2, initialiser forms. */
/* Swing_DLL.xex 0x888E1FC0: looks up the data handle named lbl_880D435C; unless it is null, forwards it by hash 0xA1CAA5E7, writes 10
 * to field 0xCFA6377B (ts4_get_u32_off0_8822AFE8) and copies flag 0xB01F4F95 from lbl_880CBA07. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
extern char lbl_880D435C[];
extern const u8 lbl_880CBA07;
extern Out *ts4_if_set_u32_off0_8862C0E8(Out *out, void *src);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_881644F0(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
extern void ts4_get_u32_off0_8822AFE8(Out *h, u32 *value);
extern void ts4_clone_byte_with_object_context(Out *p, const u8 *src);

static __inline u8 ts4_handle_is_null(const Out *h)
{
    return h->f0 == 0 || h->f4 == 0x000FFFFFu;
}

void ts4_set_ten_by_name_888E1FC0(void)
{
    u32 k1, k2, k3, v;
    Out key, o1;
    Out *p;
    ts4_if_set_u32_off0_8862C0E8(&key, lbl_880D435C);
    if (ts4_handle_is_null(&key))
        return;
    k1 = 0xA1CAA5E7u;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    { Out tmp;
    v = 10;
    k2 = 0xCFA6377Bu;
    p = (Out *)ts4_init_range_and_run_service_opt_881644F0(&tmp, (In *)&o1, &k2, 0);
    ts4_get_u32_off0_8822AFE8(p, &v); }
    { Out tmp;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)&o1, &k3, 0);
    ts4_clone_byte_with_object_context(p, &lbl_880CBA07); }
}
