/* 0x883E3700: when the instance list at +0x78 is empty, creates def-count instances (1 without a def), binds each to the def (taking a reference), copies a/b, sets flags 4 or 0x24 and links it at the tail; 0x2C on allocation failure. fn_883E13B8 returns int here; another file declares it void */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Def3 { int p0; int count; } Def3;
typedef struct Def2 { char pad[0xc]; Def3 *d; } Def2;
typedef struct Def { char pad[8]; int refs; Def2 *d; } Def;
typedef struct T T;
typedef struct Inst { int vt; Link link; char pad[0x18 - 0xc]; int a; int p1c; int b; unsigned int flags; char pad2[0x54 - 0x28]; T *owner; } Inst;
struct T { char pad[0x14]; Def *def; int a; int p1c; int b; unsigned int flags; char pad2[0x78 - 0x28]; Link head; };
extern const char lbl_880395AC[];
Inst *ts4_if_get_u32_lbl_88B3302C_883DBC98(void *ctx, int a, const char *file, int line);
int fn_883E13B8(Inst *d, Def *def);

int fn_883E3700(T *t, void *ctx)
{
    int count, i, r;
    if (t->head.next != &t->head)
        return 0;
    count = t->def ? t->def->d->d->count : 1;
    for (i = 0; i < count; i++) {
        Inst *o = ts4_if_get_u32_lbl_88B3302C_883DBC98(ctx, 0, lbl_880395AC, 0x37b);
        if (!o)
            return 0x2c;
        r = fn_883E13B8(o, t->def);
        if (r)
            return r;
        if (t->def)
            t->def->refs++;
        o->a = t->a;
        o->b = t->b;
        o->flags = 4;
        if (t->flags & 0x20)
            o->flags = 0x24;
        o->owner = t;
        {
            Link *n = &o->link, *h = &t->head;
            n->prev = h->prev;
            n->next = h;
            h->prev = n;
            n->prev->next = n;
        }
    }
    return 0;
}
