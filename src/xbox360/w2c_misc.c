/*
 * W2C: small gameplay functions rebuilt with real structs. Built with /Oc /fp:precise.
 * Each function was verified with tools/fn_check.py; see work/specs/W2C/w2c_misc.json.
 */
#include "w2c_types.h"

/* Swing_DLL.xex 0x8865C000: clears three consecutive words of the owned sub-object. */
struct W2cClr8865C000 { W2C_PAD(0x12c); unsigned w[3]; };
struct W2cOwn8865C000 { W2C_PAD(0x28); struct W2cClr8865C000 *sub; };
void ts4_clear_owned_triple_8865C000(struct W2cOwn8865C000 *s)
{
    unsigned *q = &s->sub->w[0];
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
}

/* Swing_DLL.xex 0x8865AEB8: four pointers into the owner's tables stored into this. */
struct W2cX8865AEB8 { W2C_PAD(0x6c); char *q; };
struct W2cS8865AEB8 { W2C_PAD(0x44); struct W2cX8865AEB8 *x; W2C_PAD(0x2c); char *r; };
struct W2cM8865AEB8 { W2C_PAD(8); struct W2cS8865AEB8 *s; };
struct W2cT8865AEB8 { W2C_PAD(0x1c); struct W2cM8865AEB8 *m; char *a, *b, *c, *d; };
void ts4_bind_table_ptrs_8865AEB8(struct W2cT8865AEB8 *t)
{
    char *p = t->m->s->r;
    t->c = p + 0xe80;
    t->d = p + 0xebc;
    t->b = t->m->s->x->q + 0x92c;
    t->a = p + 0x480;
}

/* Swing_DLL.xex 0x889C0998: -1 mask of "callee returned nonzero". */
extern unsigned long ts4_if_call_seq_u32_off44_8864BB40(unsigned long a, unsigned long b);
int ts4_nonzero_mask_889C0998(unsigned long a, unsigned long b)
{
    return 0 != ts4_if_call_seq_u32_off44_8864BB40(a, b) ? -1 : 0;
}

/* Swing_DLL.xex 0x8865E940: copies the 8-byte entry (idx mod count) of a self-relative table. */
struct W2cHdr8865E940 { int rel; int count; };
struct W2cEnt8865E940 { unsigned a, b; };
struct W2cQ8865E940 { W2C_PAD(0x4cc); struct W2cHdr8865E940 h; };
struct W2cP8865E940 { W2C_PAD(0x74); struct W2cQ8865E940 *q; };
struct W2cO8865E940 { W2C_PAD(8); struct W2cP8865E940 *p; };
void ts4_table_entry_mod_8865E940(struct W2cO8865E940 *o, int idx, struct W2cEnt8865E940 *out)
{
    struct W2cHdr8865E940 *h = &o->p->q->h;
    struct W2cEnt8865E940 *e = (struct W2cEnt8865E940 *)((char *)h + (idx % h->count) * 8 + h->rel);
    *out = *e;
}

/* Swing_DLL.xex 0x8865A5E0: empties the pointer vector at +0x7c (end = copy(end, end, begin)). */
extern char *fn_88562DC0(char *dest, const char *src, unsigned n);
struct W2cVec8865A5E0 { char **begin; char **end; };
struct W2cO8865A5E0 { W2C_PAD(0x7c); struct W2cVec8865A5E0 v; };
static __forceinline char **w2c_copy_8865A5E0(char **first, char **last, char **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned n = (unsigned)((char *)last - (char *)first);
        dest = (char **)fn_88562DC0((char *)dest, (const char *)first, n);
        return (char **)((char *)dest + n);
    }
}
void ts4_vector_clear_8865A5E0(struct W2cO8865A5E0 *o)
{
    struct W2cVec8865A5E0 *v = &o->v;
    v->end = w2c_copy_8865A5E0(v->end, v->end, v->begin);
}

/* Swing_DLL.xex 0x88649678: runs two steps on element idx (stride 0x94) of a self-relative array. */
extern void fn_88648880(void *elem, unsigned a, void *x);
extern void fn_88645C58(void *elem, void *x);
struct W2cHdr88649678 { int rel; };
struct W2cElem88649678 { W2C_PAD(0x84); void *x; W2C_PAD(0xc); };
struct W2cO88649678 { W2C_PAD(0x1c); struct W2cHdr88649678 *h; };
void ts4_step_array_elem_88649678(struct W2cO88649678 *o, int idx, unsigned a)
{
    struct W2cHdr88649678 *h1 = o->h;
    struct W2cHdr88649678 *h2 = (struct W2cHdr88649678 *)((char *)h1 + h1->rel);
    struct W2cElem88649678 *e = (struct W2cElem88649678 *)((char *)h2 + (idx * 0x94 + h2->rel)) - 1;
    void *x = e->x;
    if (x != 0) {
        fn_88648880(e, a, x);
        fn_88645C58(e, x);
    }
}

/* Swing_DLL.xex 0x8864BC88: destructor body, shuts down when active and destroys the members. */
extern char lbl_880F9574[];
extern void ts4_if_call_seq_u32_off0_8864BC08(void *self);
extern void ts4_msg_view_dtor_886047F8(void *view);
extern void fn_88278560(void *member);
struct W2cSub8864BC88 { const void *vt; char view[4]; };
struct W2cO8864BC88 {
    W2C_PAD(4);
    void *active;
    W2C_PAD(4);
    char m0c[0xc];
    char m18[0x14];
    char m2c[0xc];
    char m38[0x24];
    struct W2cSub8864BC88 sub;
};
static __forceinline void w2c_sub_dtor_8864BC88(struct W2cSub8864BC88 *s)
{
    s->vt = lbl_880F9574;
    ts4_msg_view_dtor_886047F8(s->view);
}
void ts4_dtor_members_8864BC88(struct W2cO8864BC88 *o)
{
    if ((long)o->active != 0)
        ts4_if_call_seq_u32_off0_8864BC08(o);
    w2c_sub_dtor_8864BC88(&o->sub);
    fn_88278560(o->m38);
    fn_88278560(o->m2c);
    fn_88278560(o->m18);
    fn_88278560(o->m0c);
}

/* Swing_DLL.xex 0x88673860: constructor, looks up service 0xF0E4652B and zeroes three 200-entry tables. */
extern void *ts4_find_service(unsigned hash);
extern void *ts4_object_finalize(void *p);
struct W2cO88673860 {
    void *service;
    W2C_PAD(4);
    char fin[0x30];
    unsigned a[200];
    unsigned b[200];
    unsigned char c[200];
};
void *ts4_init_service_tables_88673860(struct W2cO88673860 *o)
{
    void *r;
    int i;
    o->service = ts4_find_service(0xF0E4652B);
    r = ts4_object_finalize(o->fin);
    for (i = 0; i < 200; i++) {
        o->a[i] = 0;
        o->b[i] = 0;
        o->c[i] = 0;
    }
    return r;
}

/* Swing_DLL.xex 0x8864DBD8: runs the handler of the current state (1, 4 or 5); on success stamps the time. */
extern unsigned ts4_get_u32__imp_KeTimeStampBundle_8857B830();
extern unsigned char ts4_if_call_seq_u32_off28_8864D470(void *o);
extern unsigned char fn_8864D910(void *o);
extern unsigned char ts4_recv_header_8864DA90(void *o);
struct W2cO8864DBD8 { W2C_PAD(4); int state; W2C_PAD(0x128); unsigned long long stamp; };
int ts4_run_state_handler_8864DBD8(struct W2cO8864DBD8 *o)
{
    int s = o->state;
    int ok = s == 4 || s == 5 || s == 1;
    if ((unsigned char)ok) {
        unsigned char r = 0;
        switch (s) {
        case 1: r = ts4_recv_header_8864DA90(o); break;
        case 4: r = fn_8864D910(o); break;
        case 5: r = ts4_if_call_seq_u32_off28_8864D470(o); break;
        }
        if (!r)
            return -1;
        o->stamp = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    }
    return 0;
}
