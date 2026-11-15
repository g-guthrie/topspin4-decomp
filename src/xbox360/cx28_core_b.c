/* CX28 batch b: node/handle constructors (Swing_DLL.xex). */
typedef unsigned int cx28_u32;
typedef unsigned char cx28_u8;

extern unsigned char lbl_880C1320[];
extern const float lbl_8814B440;
void ts4_assign_formatted_text(void *dst, void *src);

#ifdef _MSC_VER
#pragma pack(push, 4)
#endif
typedef struct cx28_handle {
    int kind;
    void *node;
} cx28_handle;

typedef struct cx28_ref {
    void *owner;
    cx28_handle h;
    long long val;
    int w14;
    cx28_u8 b18;
} cx28_ref;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

extern void *ts4_node_dispatch_8860DCF8(void *heap, int size, int align, int flags);

/* node kind 0x12: {kind, link, index=-1}, 0xc bytes, followed by the reference object */
typedef struct cx28_node12 {
    int kind;
    int link;
    int index;
    cx28_ref ref;
} cx28_node12;

/* Swing_DLL.xex 0x88164E28: allocate a node plus a reference object holding a handle to the node, an owner and a 64-bit value */
cx28_ref *ts4_cx28_new_ref_88164E28(char *self, void *owner, long long val)
{
    cx28_node12 *p = (cx28_node12 *)ts4_node_dispatch_8860DCF8(*(void **)(self + 0x2c), 0x28, 4, 2);
    void *node;
    cx28_handle h;
    cx28_ref *r;
    cx28_ref *res;
    if (p) {
        p->kind = 0x12;
        p->link = 0;
        p->index = -1;
        node = p;
    } else {
        node = 0;
    }
    h.node = node;
    h.kind = 0xc;
    r = &p->ref;
    if (r) {
        r->owner = owner;
        r->val = val;
        r->w14 = 0;
        r->b18 = 0;
        r->h = h;
        res = r;
    } else {
        res = 0;
    }
    return res;
}

typedef struct cx28_node0d {
    int kind;
    int link;
    int index;
    int w0c;
    int limit;
    cx28_ref ref;
} cx28_node0d;

/* Swing_DLL.xex 0x881648F8: as 0x88164E28 with a 0x14-byte node of kind 0xd (limit 0x7fffffff) */
cx28_ref *ts4_cx28_new_ref_881648F8(char *self, void *owner, long long val)
{
    cx28_node0d *p = (cx28_node0d *)ts4_node_dispatch_8860DCF8(*(void **)(self + 0x2c), 0x30, 4, 2);
    void *node;
    cx28_handle h;
    cx28_ref *r;
    cx28_ref *res;
    if (p) {
        p->kind = 0xd;
        p->link = 0;
        p->index = -1;
        p->w0c = 0;
        p->limit = 0x7fffffff;
        node = p;
    } else {
        node = 0;
    }
    h.node = node;
    h.kind = 0x14;
    r = &p->ref;
    if (r) {
        r->owner = owner;
        r->val = val;
        r->w14 = 0;
        r->b18 = 0;
        r->h = h;
        res = r;
    } else {
        res = 0;
    }
    return res;
}

typedef struct cx28_node15 {
    int kind;
    int link;
    char text[12];
    cx28_ref ref;
} cx28_node15;

/* Swing_DLL.xex 0x88164D88: as 0x88164E28 with a node of kind 0x15 holding a text object */
cx28_ref *ts4_cx28_new_ref_88164D88(char *self, void *owner, long long val)
{
    cx28_node15 *p = (cx28_node15 *)ts4_node_dispatch_8860DCF8(*(void **)(self + 0x2c), 0x30, 4, 2);
    void *node;
    cx28_handle h;
    cx28_ref *r;
    cx28_ref *res;
    if (p) {
        p->kind = 0x15;
        p->link = 0;
        ts4_assign_formatted_text(p->text, lbl_880C1320);
        node = p;
    } else {
        node = 0;
    }
    h.node = node;
    h.kind = 0x14;
    r = &p->ref;
    if (r) {
        r->owner = owner;
        r->val = val;
        r->w14 = 0;
        r->b18 = 0;
        r->h = h;
        res = r;
    } else {
        res = 0;
    }
    return res;
}

extern char *lbl_88D45B1C;

typedef struct cx28_node01 {
    int kind;
    int link;
    char text0[12];
    int w14;
    int w18;
    char text1[12];
    char text2[12];
    char text3[12];
    int w40;
    char text4[12];
    int w50;
    int w54;
    cx28_ref ref;
} cx28_node01;

/* Swing_DLL.xex 0x881641B0: as 0x88164E28 with a large kind-1 node of five text objects and two values read from a global */
cx28_ref *ts4_cx28_new_ref_881641B0(char *self, void *owner, long long val)
{
    cx28_node01 *p = (cx28_node01 *)ts4_node_dispatch_8860DCF8(*(void **)(self + 0x2c), 0x74, 4, 2);
    void *node;
    cx28_handle h;
    cx28_ref *r;
    cx28_ref *res;
    if (p) {
        p->kind = 1;
        p->link = 0;
        ts4_assign_formatted_text(p->text0, lbl_880C1320);
        p->w14 = 0;
        p->w18 = 4;
        ts4_assign_formatted_text(p->text1, lbl_880C1320);
        ts4_assign_formatted_text(p->text2, lbl_880C1320);
        ts4_assign_formatted_text(p->text3, lbl_880C1320);
        p->w40 = *(int *)(lbl_88D45B1C + 0x27c);
        ts4_assign_formatted_text(p->text4, lbl_880C1320);
        *(volatile int *)&p->w50 = *(int *)(lbl_88D45B1C + 0x27c);
        *(volatile int *)&p->w54 = 0;
        node = p;
    } else {
        node = 0;
    }
    h.node = node;
    h.kind = 0x58;
    r = &p->ref;
    if (r) {
        r->owner = owner;
        r->val = val;
        r->w14 = 0;
        r->b18 = 0;
        r->h = h;
        res = r;
    } else {
        res = 0;
    }
    return res;
}
