/*
 * CL2 part e: callback-pointer functions (if (g_cb) g_cb(...) gives clrrwi before mtctr).
 * Swing_DLL.xex, Xbox 360, cl.exe 16.00.10224.00, plain route, no flags.
 */
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wcast-function-type-mismatch"
#endif
typedef unsigned char u8;
typedef unsigned int u32;
#ifdef _MSC_VER
typedef u32 cl2_uptr;
#else
typedef unsigned long cl2_uptr;
#endif
struct Hd;
struct HVt { void *s[5]; int (*run5)(struct Hd *self, int a, int *p); void *s6; int (*run)(struct Hd *self, int a, int b, int *p); };
struct Hd { struct HVt *vt; u8 pad[0x6c - 4]; u32 off; };
typedef void (*Cb2)(int ev, int a, int b, struct Hd *h);
extern Cb2 lbl_88D3E3AC;
extern void *lbl_88D459B4;
u32 *fn_88883CD0(void *g);
struct Hd *ts4_if_call_seq_u32_lbl_88D3E3B4_8818A0F8(void);
int ts4_dispatch_881991A0(int a, int b, int *p)
{
    int dflt[2];
    struct Hd *h;
    int r;
    dflt[0] = 1000;
    dflt[1] = 0;
    if (p == 0) p = dflt;
    h = *(struct Hd **)fn_88883CD0(lbl_88D459B4);
    if (h == (struct Hd *)-1 || h == 0) h = ts4_if_call_seq_u32_lbl_88D3E3B4_8818A0F8();
    if (*p == 1000) { u32 *g2 = fn_88883CD0(lbl_88D459B4); u32 b = (u32)(cl2_uptr)(g2 + 1); u8 *q = (u8 *)(cl2_uptr)(h->off + b); *p = q[1]; }
    if (lbl_88D3E3AC) lbl_88D3E3AC(2, a, b, h);
    r = h->vt->run(h, a, b, p);
    if (lbl_88D3E3AC) lbl_88D3E3AC(3, r, b, h);
    return r;
}

extern void (*lbl_88D3E3B0)(void);
int ts4_dispatch2_88199068(struct Hd *h, int b, int *p)
{
    int dflt[2];
    int r;
    dflt[0] = 1000;
    dflt[1] = 0;
    if (p == 0) p = dflt;
    if (h == 0) {
        h = *(struct Hd **)fn_88883CD0(lbl_88D459B4);
        if (h == (struct Hd *)-1 || h == 0) h = ts4_if_call_seq_u32_lbl_88D3E3B4_8818A0F8();
    }
    if (*p == 1000) { u32 *g2 = fn_88883CD0(lbl_88D459B4); u32 bs = (u32)(cl2_uptr)(g2 + 1); u8 *q = (u8 *)(cl2_uptr)(h->off + bs); *p = q[1]; }
    p[1] = (int)(cl2_uptr)h;
    if (lbl_88D3E3AC) lbl_88D3E3AC(0, 0, b, h);
    r = h->vt->run5(h, b, p);
    if (lbl_88D3E3AC) lbl_88D3E3AC(1, r, b, h);
    if ((u32)r == 0 && lbl_88D3E3B0) lbl_88D3E3B0();
    return r;
}

struct Cl2TNode { struct Cl2TNode *next; };
struct Cl2TObj;
struct Cl2TVT { void *s[6]; void (*fn)(struct Cl2TObj *self, struct Cl2TNode *n); };
struct Cl2TObj { struct Cl2TVT *vt; };
struct Cl2TObj *fn_88198E08(struct Cl2TNode *n);
struct Cl2HT { u32 w0; struct Cl2TNode **tab; u32 w8, wc; int count; };
void ts4_table_flush_881DA980(struct Cl2HT *self)
{
    int i = 0;
    int k;
    for (k = 0; i < self->count; ++i, ++k) {
        struct Cl2TNode *n = self->tab[k];
        while (n) {
            struct Cl2TNode *next = n->next;
            struct Cl2TObj *o = fn_88198E08(n);
            if (o) {
                if (lbl_88D3E3AC) ((void (*)(int, struct Cl2TNode *, int, struct Cl2TObj *))lbl_88D3E3AC)(4, n, 0, o);
                o->vt->fn(o, n);
                if (lbl_88D3E3AC) ((void (*)(int, struct Cl2TNode *, int, struct Cl2TObj *))lbl_88D3E3AC)(5, n, 0, o);
            }
            n = next;
        }
        self->tab[k] = 0;
    }
}

/* ---- 0x88606788: run vslot 26 on slot objects until the first empty slot ---- */
struct Cl2SO;
struct Cl2SVt { void *s[26]; void (*act)(struct Cl2SO *self); };
struct Cl2SO { struct Cl2SVt *vt; };
struct Cl2Slot { u32 a; u32 b; struct Cl2SO *obj; };
struct Cl2Mgr { u8 pad[0xec]; struct Cl2Slot slots[30]; };
void ts4_slots_run_88606788(struct Cl2Mgr *m)
{
    struct Cl2Slot *e = (struct Cl2Slot *)((char *)m + 0x164);
    struct Cl2Slot *s = m->slots;
    for (; s < e; ++s) {
        if (!s->obj) break;
        s->obj->vt->act(s->obj);
    }
}
