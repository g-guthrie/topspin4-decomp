/* Swing_DLL.xex 0x888C8370-0x888C8B30, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Holder { char pad[0x1c]; u32 kind; char pad2[0x20]; Out key; } Ts4Holder;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
typedef void (*Ts4SlotStr)(Ts4Obj *self, Out *arg, u32 a, const char *s, u64 n);
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#pragma intrinsic(strlen)
#else
#include <string.h>
#endif
extern char lbl_880D3AC4[];
extern char lbl_880D3AE0[];
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88165D80(Out *out, In *in, u32 a, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 a, u32 count);
extern void *ts4_init_range_and_run_service_opt_881644F0(Out *out, In *in, u32 a, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 a, u32 count);
#define TS4_SLOT(q, i, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[i])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

void ts4_hash_service_str_888C8370(Ts4Holder *h, u32 value)
{
    u32 k1, k2, k3, k4;
    Out cp, o1, o2;
    Out *p;
    const char *s;
    u32 len;
    u32 *slot;
    u8 *r;
    k1 = 0x2980E51Eu;
    cp = h->key;
    ts4_handle_forward_88610778(&o1, &cp, &k1);
    if (h->kind == 0xF5BF4F97u) {
        s = lbl_880D3AC4;
    } else {
        s = lbl_880D3AE0;
    }
    len = (u32)strlen(s);
    k2 = 0xF59526D0u;
    p = (Out *)ts4_init_range_and_run_service_opt_88165D80(&o2, (In *)&o1, (u32)(unsigned long)&k2, len + 1);
    ((Ts4SlotStr)((Ts4Obj *)(unsigned long)p->f0)->vt[11])((Ts4Obj *)(unsigned long)p->f0, p, p->f4, s, (u64)len + 1);
    k3 = 0x634DE3B3u;
    p = (Out *)ts4_init_range_and_run_service_opt_881644F0(&o2, (In *)&o1, (u32)(unsigned long)&k3, 0);
    slot = (u32 *)TS4_SLOT(p, 10, 4);
    *slot = value;
    k4 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, (u32)(unsigned long)&k4, 0);
    r = (u8 *)TS4_SLOT(p, 10, 1);
    *r = 0;
}

void ts4_hash_service_str_888C84E8(Ts4Holder *h, u32 value)
{
    u32 k1, k2, k3, k4;
    Out cp, o1, o2;
    Out *p;
    const char *s;
    u32 len;
    u32 *slot;
    u8 *r;
    k1 = 0x92C26F7Au;
    cp = h->key;
    ts4_handle_forward_88610778(&o1, &cp, &k1);
    if (h->kind == 0xF5BF4F97u) {
        s = lbl_880D3AC4;
    } else {
        s = lbl_880D3AE0;
    }
    len = (u32)strlen(s);
    k2 = 0xF59526D0u;
    p = (Out *)ts4_init_range_and_run_service_opt_88165D80(&o2, (In *)&o1, (u32)(unsigned long)&k2, len + 1);
    ((Ts4SlotStr)((Ts4Obj *)(unsigned long)p->f0)->vt[11])((Ts4Obj *)(unsigned long)p->f0, p, p->f4, s, (u64)len + 1);
    k3 = 0x634DE3B3u;
    p = (Out *)ts4_init_range_and_run_service_opt_881644F0(&o2, (In *)&o1, (u32)(unsigned long)&k3, 0);
    slot = (u32 *)TS4_SLOT(p, 10, 4);
    *slot = value;
    k4 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, (u32)(unsigned long)&k4, 0);
    r = (u8 *)TS4_SLOT(p, 10, 1);
    *r = 0;
}

void ts4_hash_service_str_888C8660(Ts4Holder *h, u32 value)
{
    u32 k1, k2, k3, k4;
    Out cp, o1, o2;
    Out *p;
    const char *s;
    u32 len;
    u32 *slot;
    u8 *r;
    k1 = 0x0B757B08u;
    cp = h->key;
    ts4_handle_forward_88610778(&o1, &cp, &k1);
    if (h->kind == 0xF5BF4F97u) {
        s = lbl_880D3AC4;
    } else {
        s = lbl_880D3AE0;
    }
    len = (u32)strlen(s);
    k2 = 0xF59526D0u;
    p = (Out *)ts4_init_range_and_run_service_opt_88165D80(&o2, (In *)&o1, (u32)(unsigned long)&k2, len + 1);
    ((Ts4SlotStr)((Ts4Obj *)(unsigned long)p->f0)->vt[11])((Ts4Obj *)(unsigned long)p->f0, p, p->f4, s, (u64)len + 1);
    k3 = 0x634DE3B3u;
    p = (Out *)ts4_init_range_and_run_service_opt_881644F0(&o2, (In *)&o1, (u32)(unsigned long)&k3, 0);
    slot = (u32 *)TS4_SLOT(p, 10, 4);
    *slot = value;
    k4 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, (u32)(unsigned long)&k4, 0);
    r = (u8 *)TS4_SLOT(p, 10, 1);
    *r = 0;
}

void ts4_hash_service_str2_888C8970(Ts4Holder *h, u32 value, u32 value2)
{
    u32 k1, k2, k3, k4, k5;
    Out cp, o1, o2;
    Out *p;
    const char *s;
    u32 len;
    u32 *slot;
    u8 *r;
    k1 = 0xBBCA67C4u;
    cp = h->key;
    ts4_handle_forward_88610778(&o1, &cp, &k1);
    if (h->kind == 0xF5BF4F97u) {
        s = lbl_880D3AC4;
    } else {
        s = lbl_880D3AE0;
    }
    len = (u32)strlen(s);
    k2 = 0xF59526D0u;
    p = (Out *)ts4_init_range_and_run_service_opt_88165D80(&o2, (In *)&o1, (u32)(unsigned long)&k2, len + 1);
    ((Ts4SlotStr)((Ts4Obj *)(unsigned long)p->f0)->vt[11])((Ts4Obj *)(unsigned long)p->f0, p, p->f4, s, (u64)len + 1);
    k3 = 0x634DE3B3u;
    p = (Out *)ts4_init_range_and_run_service_opt_881644F0(&o2, (In *)&o1, (u32)(unsigned long)&k3, 0);
    slot = (u32 *)TS4_SLOT(p, 10, 4);
    *slot = value;
    k4 = 0xFF3A7B97u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164F60(&o2, (In *)&o1, (u32)(unsigned long)&k4, 0);
    slot = (u32 *)TS4_SLOT(p, 10, 4);
    *slot = value2;
    k5 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, (u32)(unsigned long)&k5, 0);
    r = (u8 *)TS4_SLOT(p, 10, 1);
    *r = 0;
}
