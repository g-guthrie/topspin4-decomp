/* Swing_DLL.xex 0x888C8CA0: picks 0xF45DF21A when self->mode (+0x1C) is 0xF5BF4F97, else 0xFB2C1DD5; forwards the global
 * data handle (lbl_88D45954->+0x40) by hash 0xA40B50BB, clears the 1-byte flag 0xB01F4F95 and writes the pick to field 0xFE11D138. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4KeyOwner { char pad[0x40]; Out key; } Ts4KeyOwner;
typedef struct Ts4Mode { char pad[0x1c]; u32 mode; } Ts4Mode;
extern "C" Ts4KeyOwner *lbl_88D45954;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern "C" void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern "C" void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 *key, u32 count);
extern "C" void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

extern "C" void ts4_publish_mode_hash_888C8CA0(Ts4Mode *self)
{
    u32 k1, k2, k3;
    Out key, o1;
    Out *p;
    struct Id { u32 v; Id(u32 x) : v(x) {} };
    const Id &pr = (self->mode == 0xF5BF4F97u) ? Id(0xF45DF21Au) : Id(0xFB2C1DD5u);
    u32 val = pr.v;
    k1 = 0xA40B50BBu;
    key = lbl_88D45954->key;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    k2 = 0xB01F4F95u;
    { Out o2; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, &k2, 0);
      *(u8 *)TS4_SLOT10(p, 1) = 0; }
    k3 = 0xFE11D138u;
    { Out o3; p = (Out *)ts4_init_range_and_run_service_opt_88164F60(&o3, (In *)&o1, &k3, 0);
      *(u32 *)TS4_SLOT10(p, 4) = val; }
}
