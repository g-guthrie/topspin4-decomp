/* CW21 part c: float matrix assignment and friends (0x88150000-0x8815ACE0). */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX21_INL static __forceinline
#else
#define CX21_INL static inline
#endif
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
typedef struct Cx21FVec { float *first; float *last; float *cap; } Cx21FVec;
typedef struct Cx21Mat { u32 w; u32 h; Cx21FVec v; } Cx21Mat;
extern void ts4_fvec_resize_88158B28(Cx21FVec *v, u32 n);

/* ---- handle reset ---- */
struct Cx21Ref;
typedef struct Cx21VObj { void (**vtbl)(u32 *, struct Cx21VObj *, struct Cx21Ref *); } Cx21VObj;
typedef struct Cx21Ref { Cx21VObj *obj; u32 id; } Cx21Ref;
typedef struct Cx21Owner { u8 pad[0x27c]; u32 f27c; } Cx21Owner;
extern Cx21Owner *lbl_88D45B1C;


/* 0x881506A0: release the object through its second virtual slot, or load the default id when empty */

/* ---- circular list node release ---- */
typedef struct Cx21Node { struct Cx21Node *next; struct Cx21Node *prev; } Cx21Node;
typedef struct Cx21List { u32 alloc; Cx21Node *head; } Cx21List;
extern void *lbl_88D45B38;
extern void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *node, u32 a);
extern void fn_885651F8(void *node);

/* 0x881530A8: free every node of the list and make the sentinel point to itself */

/* 0x88157B78: free every node of the list, then free the sentinel itself */

/* ---- socket error mapping ---- */
extern int ts4_tailcall_NetDll_WSAGetLastError_884F0390(void);

/* 0x88157928: map the last Winsock error to a small code */

/* ---- object with an embedded sub-object ---- */
typedef struct Cx21Sub { void *vtbl; u32 a, b, c; } Cx21Sub;
typedef struct Cx21Obj430 {
    void *vtbl;
    Cx21Sub sub;
    u8 pad[0x414 - 0x14];
    u32 f414, f418;
    u8 f41c, f41d, f41e, f41f, f420;
    u8 pad2[3];
    u32 f424, f428;
    u8 f42c;
} Cx21Obj430;
extern char lbl_880D5D1C[];
extern char lbl_880D2A90[];
extern u32 lbl_88C6B4AC;
extern void *ts4_node_dispatch_8860DCF8(void *owner, u32 size, u32 align, u32 tag);

CX21_INL void sub_base_init(Cx21Sub *s)
{
    volatile Cx21Sub *v = s;
    v->a = 0;
    v->b = 0;
}
CX21_INL void sub_init(Cx21Sub *s)
{
    sub_base_init(s);
    s->vtbl = lbl_880D5D1C;
    s->a = 0;
    s->b = 0;
    s->c = 0;
}

/* 0x88157DA8: allocate and construct the 0x430-byte object */

typedef struct Cx21Obj434 {
    void *vtbl;
    Cx21Sub sub;
    u8 pad[0x414 - 0x14];
    u32 f414, f418;
    u8 f41c, f41d, f41e, f41f, f420;
    u8 pad2[3];
    u32 f424, f428, f42c;
    u8 f430;
} Cx21Obj434;
extern char lbl_880D20A0[];
extern char lbl_880D2160[];

/* Swing_DLL.xex 0x88172980: allocate and construct the 0x440-byte object (twin ts4_create_obj434_88153A70), vtbl lbl_880D6C28, byte at +0x43c = 0 */
extern char lbl_880D6C28[];
Cx21Obj434 *ts4_create_obj434_88172980(void *owner)
{
    Cx21Obj434 *o = (Cx21Obj434 *)ts4_node_dispatch_8860DCF8(owner, 0x440, 4, 2);
    if (o) {
        sub_init(&o->sub);
        o->vtbl = lbl_880D6C28;
        o->f414 = 1;
        o->f418 = 0;
        o->f41c = 0;
        o->f41d = 1;
        o->f41e = 0;
        o->f41f = 0;
        o->f420 = 0;
        o->f424 = 0;
        o->f428 = 0;
        o->f42c = (u32)-1;
        *(u8 *)((char *)o + 0x43c) = 0;
        lbl_88C6B4AC = 7;
        return o;
    }
    return 0;
}
