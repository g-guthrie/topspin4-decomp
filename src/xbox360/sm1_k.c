/* SM1 batch k (default /O2): clamps and checked getters. */
typedef unsigned int u32;

/* Swing_DLL.xex 0x883304A0: clamp two floats into [lo, hi], store them and forward the object */
extern float lbl_88001A20, lbl_88001A68;
extern int fn_8832FB38(void *);
typedef struct Ts4Pair48 { char pad[0x48]; float a, b; } Ts4Pair48;
int ts4_set_clamped_pair_883304A0(Ts4Pair48 *t, float x, float y) {
    float hi = lbl_88001A68;
    float lo = lbl_88001A20;
    if (x < hi) { if (!(x >= lo)) x = lo; } else x = hi;
    if (y < hi) { if (!(y >= lo)) y = lo; } else y = hi;
    t->a = x;
    t->b = y;
    return fn_8832FB38(t);
}

/* 0x88325148: read two floats when the owned object has the capability bit; 0x24 without owner, 0x31 without the capability */
typedef struct Ts4CapOwner { char pad[0x4c]; struct { char pad[0x20]; u32 flags; } *owner; char pad2[0x120]; float first, second; } Ts4CapOwner;
int ts4_get_two_floats_if_capable_88325148(Ts4CapOwner *t, float *a, float *b) { if (t->owner == 0) return 0x24; if ((t->owner->flags & 0x10) == 0) return 0x31; if (a) *a = t->first; if (b) *b = t->second; return 0; }

/* 0x882A2788: free a singly linked chain (child at +0xc) releasing each node's payload and the node itself */
extern void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *, int);
typedef struct Ts4ChainNode { char pad[8]; void *payload; struct Ts4ChainNode *next; } Ts4ChainNode;
void ts4_free_chain_882A2788(Ts4ChainNode *n) { if (n) { ts4_free_chain_882A2788(n->next); n->next = 0; ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(n->payload, (int)0xB1800000); ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(n, 0x24800000); } }

/* 0x88346150: store a float into one of four slots chosen by index (this-adjusted object) */
int ts4_set_float_slot_by_index4_adj1c_88346150(char *t, u32 idx, float x) {
    char *p = t ? t - 0x1c : 0;
    if (idx > 3) return 0;
    switch (idx) {
    case 0: *(float *)(p + 0x144) = x; break;
    case 1: *(float *)(p + 0x14c) = x; break;
    case 2: *(float *)(p + 0x13c) = x; break;
    case 3: *(float *)(p + 0x154) = x; break;
    }
    return 0;
}

/* 0x88356178: forward a scaled integer field minus an offset to the sub-object at +0x10 */
extern float lbl_88002638;
extern int fn_88323FF8(void *, float, int);
typedef struct Ts4Scaled270 { char pad[0x270]; struct { char pad[0x2b8]; int value; } *info; } Ts4Scaled270;
int ts4_forward_scaled_field_88356178(Ts4Scaled270 *t) { fn_88323FF8((char *)t + 0x10, (float)t->info->value * lbl_88002638 - lbl_88001A68, 1); return 0; }
