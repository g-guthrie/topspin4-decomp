/* nearmiss: 3 off (q5s 2026-11-24); concrete blocker: constant passed by address (stack temp) is stored one slot earlier than in the target; C++ const-ref member setter same 3 off, by-value 7 off (same family as 88701280). */
/* NEAR MISS (agO, 2026-11-19): 3 off on plain and LTCG (/Oc): the constant 4 for field 0x735BAF9F is materialised before
 * the stb in our build, after it in the target (same residue as 888E1FC0). */
/* Swing_DLL.xex 0x887011A8: forwards the data handle at lbl_88D45AD4->+0xBC by hash 0xCE952F7E, clears flag 0xB01F4F95
 * and writes 4 to field 0x735BAF9F (ts4_get_u32_off0_8822AFE8). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
typedef struct Ts4Global { char pad[0xbc]; Out key; } Ts4Global;
extern Ts4Global *lbl_88D45AD4;
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_881644F0(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
extern void ts4_get_u32_off0_8822AFE8(Out *h, u32 *value);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

void ts4_reset_mode_four_887011A8(void)
{
    u32 k1, k2, k3, v;
    Out key, o1;
    Out *p;
    k1 = 0xCE952F7Eu;
    key = lbl_88D45AD4->key;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    { Out tmp;
    k2 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)&o1, &k2, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0; }
    { Out tmp;
    k3 = 0x735BAF9Fu;
    v = 4;
    p = (Out *)ts4_init_range_and_run_service_opt_881644F0(&tmp, (In *)&o1, &k3, 0);
    ts4_get_u32_off0_8822AFE8(p, &v); }
}
