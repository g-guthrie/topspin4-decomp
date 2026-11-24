/* nearmiss (q5s 2026-11-24): 2 off; li r6 vs stw v scheduling; C++ const-ref temporaries share slots (22 off), target has distinct slots so real locals */
/* agP 2026-11-19: same 8822AFE8 constant-by-address family; pointer-local store of v (tips agO r3) does not apply, still 2. */
/* agentA2 2026-11-18: still 2 (/Oc): named cnt/key-pointer locals for the 881644F0 call args (the trick that fixed 886CB3A8) do not move li r6,0. */
/* 0x886AC9D8 near miss (2 off, /Oc plain; scheduling of `li r6,0` vs the `v = 5` store). Sets option service
 * defaults (two ts4_slot_flush_888DC7F8 calls) and, when the 0xA1CAA5E7 view of the root handle is missing, creates it with
 * 0xCFA6377B = 5 and 0xB01F4F95 = "" (lbl_880C8F26). Tried: v before k3, call split, adjacent {key,val} struct (7); also call-result temp, block-local init, inline setter, zero local (still 2). Sweep 2026-11-18 (still 2): block-local restrict/plain/volatile store of v, volatile k3, comma-in-arg, u8/ptr 4th param, three local orders, LTCG. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
extern const char lbl_880D435C[];
extern const char lbl_880C8F26[];
void *ts4_find_service(u32 hash);
void ts4_slot_flush_888DC7F8(void *svc, int idx, u32 flag, u32 a, int b);
void ts4_if_set_u32_off0_8862C0E8(Out *out, const char *name);
Out *ts4_handle_forward_88610A48(Out *out, Out *in, u32 *key);
void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
void *ts4_init_range_and_run_service_opt_881644F0(Out *out, Out *in, u32 *key, u32 count);
u32 ts4_get_u32_off0_8822AFE8(void *obj, u32 *val);
void *ts4_init_range_and_run_service_opt_88164450(Out *out, Out *in, u32 *key, u32 count);
void ts4_clone_byte_with_object_context(void *obj, const char *s);
static __inline u8 ref_invalid(Out *r) { return r->f0 == 0 || r->f4 == 0xFFFFF; }
void ts4_options_defaults_init(void)
{
    u32 key, k2, k3, v, k4;
    Out ref, root, node, o;
    void *svc = ts4_find_service(0x9C70EAF3u);
    ts4_slot_flush_888DC7F8(svc, 0, 1, 5, -1);
    ts4_slot_flush_888DC7F8(svc, 1, 1, 5, -1);
    ts4_if_set_u32_off0_8862C0E8(&root, lbl_880D435C);
    key = 0xA1CAA5E7u;
    ts4_handle_forward_88610A48(&ref, &root, &key);
    if (ref_invalid(&ref)) {
        k2 = 0xA1CAA5E7u;
        ts4_handle_forward_88610778(&node, &root, &k2);
        k3 = 0xCFA6377Bu;
        v = 5;
        ts4_get_u32_off0_8822AFE8(ts4_init_range_and_run_service_opt_881644F0(&o, &node, &k3, 0), &v);
        k4 = 0xB01F4F95u;
        ts4_clone_byte_with_object_context(ts4_init_range_and_run_service_opt_88164450(&o, &node, &k4, 0), lbl_880C8F26);
    }
}
