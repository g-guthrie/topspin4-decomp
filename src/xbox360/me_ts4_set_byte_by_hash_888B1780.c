/* Swing_DLL.xex 0x888B1780: unless the data handle at lbl_88D45964->+0x74 is null, forwards it by hash 0xDCCF9CD0, copies
 * value into the 1-byte field 0xF40CCD04 and copies flag 0xB01F4F95 from lbl_880CB15E (self unused). agO: LTCG only. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Global { char pad[0x74]; Out key; } Ts4Global;
extern Ts4Global *lbl_88D45964;
extern const u8 lbl_880CB15E;
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
extern void ts4_clone_byte_with_object_context(Out *p, const u8 *src);

static __inline u8 ts4_handle_is_null(const Out *h)
{
    return h->f0 == 0 || h->f4 == 0x000FFFFFu;
}

void ts4_set_byte_by_hash_888B1780(void *self, u8 value)
{
    u32 k1, k2, k3;
    Out key, o1;
    Out *p;
    key = lbl_88D45964->key;
    if (ts4_handle_is_null(&key))
        return;
    k1 = 0xDCCF9CD0u;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    { Out tmp;
    k2 = 0xF40CCD04u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)&o1, &k2, 0);
    ts4_clone_byte_with_object_context(p, &value); }
    { Out tmp;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)&o1, &k3, 0);
    ts4_clone_byte_with_object_context(p, &lbl_880CB15E); }
}
