typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define TS4_FI static __forceinline
#else
#define TS4_FI static inline
#endif
typedef struct W7bModule { char pad[0x74]; char *state; } W7bModule;
typedef struct W7bOwner { char pad[4]; W7bModule *module; } W7bOwner;
typedef struct W7bRelArray { int off; u32 count; } W7bRelArray;
typedef struct W7bRelHolder { char pad[0xc]; W7bRelArray arr; } W7bRelHolder;
TS4_FI char *w7b_rel8_begin(W7bRelArray *c)
{
    char *r = 0;
    if (c->off != -1) r = (char *)c + c->off;
    return r;
}
TS4_FI char *w7b_rel8_end(W7bRelArray *c)
{
    char *r = 0;
    if (c->off != -1) r = (char *)c + c->off + c->count * 8;
    return r;
}
void ts4_clear_flags_886626D8(W7bOwner *o)
{
    char *m = o->module->state;
    W7bRelHolder *cs = (W7bRelHolder *)(m + 0x40c);
    char *end = w7b_rel8_end(&cs->arr);
    char *it = w7b_rel8_begin(&cs->arr);
    for (; it != end; it += 8) *(u8 *)(it + 4) = 0;
}

/* Swing_DLL.xex 0x88668568: bump per-entry counters in two self-relative tables */
struct W7bRel68 { int rel; };
struct W7bE168 { char pad[0x10]; int c10; };
struct W7bE268 { char pad[0x1c]; int c1c; };
struct W7bQ68 { char pad[0x28]; unsigned char b28; char pad2[0x4c - 0x29]; struct W7bRel68 h1; char pad3[0x5c - 0x50]; struct W7bRel68 h2; };
struct W7bA68 { char pad[0x94]; unsigned char b94; char pad2[0xd8 - 0x95]; int idx; };
struct W7bO68 { char pad[0x20]; struct W7bA68 *a; char pad2[0x28 - 0x24]; struct W7bQ68 *q; };
static __inline void w7b_inc68(int *p) { (*p)++; }
void ts4_count_event_88668568(struct W7bO68 *o)
{
    struct W7bA68 *a = o->a;
    struct W7bRel68 *h;
    struct W7bE168 *e1;
    struct W7bE268 *e2;
    int idx;
    if (!a->b94) return;
    idx = a->idx;
    h = &o->q->h1;
    e1 = (struct W7bE168 *)((char *)h + (idx * 64 + h->rel));
    w7b_inc68(&e1->c10);
    h = &o->q->h2;
    e2 = (struct W7bE268 *)((char *)h + (idx * 0x134 + h->rel));
    w7b_inc68(&e2->c1c);
    o->q->b28 = 1;
}
