/* CX30 part b: Pam core node helpers (separate unit: ts4_node_dispatch_8860DCF8 is called with a single argument here). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;

/* 0x886202C0 / 0x88620330: obtain a child node from the one at +0x178, register it, grow the byte total at +0x2c by the child's size (vtable slot 14), return the node */
extern void *ts4_node_dispatch_8860DCF8(void *);
extern void ts4_u32_vec_push_back_886187C0(void *, void *);
typedef struct Cx30Nv { u32 (**vt)(struct Cx30Nv *, void *); } Cx30Nv;
typedef struct Cx30Own { u8 pad[0x2c]; u32 f2c; u8 pad2[0x178 - 0x30]; Cx30Nv *f178; } Cx30Own;
#define CX30_ADD_NODE(NAME, GETTER) \
void *NAME(Cx30Own *o) \
{ \
    void *r = GETTER(o->f178); \
    ts4_u32_vec_push_back_886187C0(o, r); \
    o->f2c = o->f178->vt[0xe](o->f178, r) + o->f2c; \
    return r; \
}
extern void *fn_8860DC50(void *);
CX30_ADD_NODE(ts4_owner_add_node_886202C0, ts4_node_dispatch_8860DCF8)
CX30_ADD_NODE(ts4_owner_add_node_88620330, fn_8860DC50)

