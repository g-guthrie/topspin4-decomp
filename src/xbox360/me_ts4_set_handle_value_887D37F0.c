/* Swing_DLL.xex 0x887D37F0: copies the data handle at owner->+0xFC->+0x24, forwards it by hash 0x1807DA76, writes *value into
 * the 4-byte slot of field 0x0E804B21 and clears the 1-byte flag of field 0xB01F4F95; returns 1. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4DataNode { char pad[0x24]; Out key; } Ts4DataNode;
typedef struct Ts4Owner { char pad[0xfc]; Ts4DataNode *data; } Ts4Owner;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

int ts4_set_handle_value_887D37F0(Ts4Owner *self, const u32 *value)
{
    u32 k1, k2, k3;
    Out key, o1, o2, o3;
    Out *p;
    u32 *slot;
    u8 *r;
    k1 = 0x1807DA76u;
    key = self->data->key;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    k2 = 0x0E804B21u;
    ts4_init_range_and_run_service_opt_88164F60(&o2, (In *)&o1, &k2, 0);
    slot = (u32 *)TS4_SLOT10(&o2, 4);
    *slot = *value;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o3, (In *)&o1, &k3, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = 0;
    return 1;
}
