/* NEAR MISS (agO round 2, 2026-11-19): 4 off on plain and LTCG (/Oc), two swaps: the flag-param stb vs the vt load at entry,
 * and the constant v store vs addi r5 (the 8822AFE8 by-address constant residue). */
/* Swing_DLL.xex 0x886FC638: calls virtual slot 9 of self; unless the handle at lbl_88D45AD4->+0xBC is null, forwards it by 0xA71E882B,
 * writes 0x7B365F4D to field 0x7E34EDF8, copies flag into 0x0E2BBF35 and 0xB01F4F95 from lbl_880C8FA7; returns 1 (0 when null). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Global { char pad[0xbc]; Out key; } Ts4Global;
typedef struct Self Self;
typedef struct SelfVt { void *s[9]; void (*refresh)(Self *self); } SelfVt;
struct Self { SelfVt *vt; };
extern Ts4Global *lbl_88D45AD4;
extern const u8 lbl_880C8FA7;
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
extern void ts4_get_u32_off0_8822AFE8(Out *h, u32 *value);
extern void ts4_clone_byte_with_object_context(Out *p, const u8 *src);

static __inline u8 ts4_handle_is_null(Out h)
{
    return h.f0 == 0 || h.f4 == 0x000FFFFFu;
}

int ts4_publish_flag_886FC638(Self *self, u8 flag)
{
    u32 k1, k2, k3, k4, v;
    Out *p;
    self->vt->refresh(self);
    if (!ts4_handle_is_null(lbl_88D45AD4->key)) {
    Out key, o1;
    k1 = 0xA71E882Bu;
    key = lbl_88D45AD4->key;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    { Out tmp;
    k2 = 0x7E34EDF8u;
    v = 0x7B365F4Du;
    p = (Out *)ts4_init_range_and_run_service_opt_88164F60(&tmp, (In *)&o1, &k2, 0);
    ts4_get_u32_off0_8822AFE8(p, &v); }
    { Out tmp;
    k3 = 0x0E2BBF35u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)&o1, &k3, 0);
    ts4_clone_byte_with_object_context(p, &flag); }
    { Out tmp;
    k4 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)&o1, &k4, 0);
    ts4_clone_byte_with_object_context(p, &lbl_880C8FA7); }
    return 1;
    }
    return 0;
}
