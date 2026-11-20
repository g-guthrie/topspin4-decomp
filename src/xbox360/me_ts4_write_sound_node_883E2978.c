/* 0x883E2978: writes a 0x90 header unless owned by a live source, the extension, the sound (or its proxy) via slot 1, the state (88309BF0), the table size and every child of the list at +0x78; 0x21 without an owner */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct W W;
typedef struct WVt { void *f0; int (*write)(W *o, void *w); } WVt;
struct W { WVt *vt; char pad[0x98 - 4]; W *proxy; };
typedef struct Sys { char pad[0x20]; void *src; } Sys;
typedef struct Own { char pad[0xac]; Sys *sys; } Own;
typedef struct T {
    char pad0[0x14];
    W *ext;
    char pad1[0x20 - 0x18];
    Own *own;
    char pad2[0x28 - 0x24];
    W *snd;
    char pad3[0x30 - 0x2c];
    void *state;
    char pad4[0x44 - 0x34];
    void *tab;
    short p48;
    short ntab;
    char pad5[0x78 - 0x4c];
    Link kids;
} T;
void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);
int ts4_set_state_flag_88309BF0(void *s, void *w);

int fn_883E2978(T *t, void *w)
{
    Link *n;
    int r;
    if (!t->own)
        return 0x21;
    if (!(t->own->sys ? t->own->sys->src : 0))
        fn_8832EDB0(w, 1, 0x80000, 0x90);
    if (t->ext) {
        r = t->ext->vt->write(t->ext, w);
        if (r)
            return r;
    }
    if (t->snd) {
        W *o = t->snd;
        if (o->proxy)
            o = o->proxy;
        r = o->vt->write(o, w);
        if (r)
            return r;
    }
    if (t->state) {
        r = ts4_set_state_flag_88309BF0(t->state, w);
        if (r)
            return r;
    }
    if (t->tab)
        fn_8832EDB0(w, 1, 0x80000, t->ntab * 4);
    for (n = t->kids.next; n != &t->kids; n = n->next) {
        W *o = n ? (W *)((char *)n - 4) : 0;
        r = o->vt->write(o, w);
        if (r)
            return r;
    }
    return 0;
}
