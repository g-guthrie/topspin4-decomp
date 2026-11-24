/* Swing_DLL.xex 0x8877E630: forwards the global data handle (lbl_88D45AD4->+0xBC) by hash 0xDE7743D5, sets the 1-byte
 * field 0xF40CCD04 to !(lbl_88D45A48->+0x71) and clears the 1-byte flag of field 0xB01F4F95; returns 0. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4KeyOwner { char pad[0xbc]; Out key; } Ts4KeyOwner;
typedef struct Ts4FlagOwner { char pad[0x71]; u8 flag; } Ts4FlagOwner;
extern Ts4KeyOwner *lbl_88D45AD4;
extern Ts4FlagOwner *lbl_88D45A48;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

int ts4_publish_inverse_flag_8877E630(void)
{
    u32 k1, k2, k3;
    Out key, o1;
    Out *p;
    u8 *r;
    u8 flag;
    Ts4FlagOwner *fo = lbl_88D45A48;
    k1 = 0xDE7743D5u;
    key = lbl_88D45AD4->key;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    k2 = 0xF40CCD04u;
    flag = fo->flag;
    { Out o2; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, &k2, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = flag == 0; }
    k3 = 0xB01F4F95u;
    { Out o3; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o3, (In *)&o1, &k3, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = 0; }
    return 0;
}
