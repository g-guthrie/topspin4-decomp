/* Swing_DLL.xex 0x8877E908: forwards the global data handle (lbl_88D45954->+0x40) by hash 0x40476A42 and clears the 1-byte
 * flags of fields 0x1866042C, 0x78C8C4DB and 0xB01F4F95; returns 0. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4KeyOwner { char pad[0x40]; Out key; } Ts4KeyOwner;
extern Ts4KeyOwner *lbl_88D45954;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

int ts4_clear_three_flags_8877E908(void)
{
    u32 k1, k2, k3, k4;
    Out key, o1;
    Out *p;
    k1 = 0x40476A42u;
    key = lbl_88D45954->key;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    k2 = 0x1866042Cu;
    { Out o2; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, &k2, 0);
      *(u8 *)TS4_SLOT10(p, 1) = 0; }
    k3 = 0x78C8C4DBu;
    { Out o3; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o3, (In *)&o1, &k3, 0);
      *(u8 *)TS4_SLOT10(p, 1) = 0; }
    k4 = 0xB01F4F95u;
    { Out o4; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o4, (In *)&o1, &k4, 0);
      *(u8 *)TS4_SLOT10(p, 1) = 0; }
    return 0;
}
