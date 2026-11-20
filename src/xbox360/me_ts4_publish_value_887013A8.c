/* Swing_DLL.xex 0x887013A8: forwards the global data handle (lbl_88D45AD4->+0xBC) by hash 0x7C78B5F5, clears the 1-byte
 * fields 0xD91411DA and 0xB01F4F95, and when value is non-zero passes it to field 0x735BAF9F (ts4_get_u32_off0_8822AFE8). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4KeyOwner { char pad[0xbc]; Out key; } Ts4KeyOwner;
extern Ts4KeyOwner *lbl_88D45AD4;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_881644F0(Out *out, In *in, u32 *key, u32 count);
extern void ts4_get_u32_off0_8822AFE8(Out *h, u32 *value);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

void ts4_publish_value_887013A8(u32 value)
{
    u32 k1, k2, k3, k4;
    Out key, o1;
    Out *p;
    k1 = 0x7C78B5F5u;
    key = lbl_88D45AD4->key;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    k2 = 0xD91411DAu;
    { Out o2; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, &k2, 0);
      *(u8 *)TS4_SLOT10(p, 1) = 0; }
    k3 = 0xB01F4F95u;
    { Out o3; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o3, (In *)&o1, &k3, 0);
      *(u8 *)TS4_SLOT10(p, 1) = 0; }
    if (value != 0) {
        u32 v = value;
        Out o4;
        k4 = 0x735BAF9Fu;
        ts4_get_u32_off0_8822AFE8((Out *)ts4_init_range_and_run_service_opt_881644F0(&o4, (In *)&o1, &k4, 0), &v);
    }
}
