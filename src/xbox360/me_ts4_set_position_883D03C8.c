/* 0x883D03C8: maps x into [lo, hi] (+0x2C/+0x30) as a clamped 0..1 ratio; on change either queues it as the fade target (flag 1) or applies it directly, flags all, flushes the owner's kind-0x30 items and ticks the owner (fn_883CC388); sets flag 2 when the owner is idle */
/* Matched on /O1 plain only (work/army/ME/v.py chk); the zero constant is a float local; OSYS() is the null-guarded owner->q->sys macro re-read at each use. */
typedef struct Link { struct Link *next; } Link;
typedef struct Mode { char pad[0x1C]; float fade; char p20[0x28 - 0x20]; unsigned int flags; } Mode;
typedef struct Item { int p0; Link link; char p8[0x14 - 8]; Mode *mode; } Item;
typedef struct Lst { char pad[0x18]; Link items; } Lst;
typedef struct Q { void *sys; } Q;
typedef struct Own { char pad[0x60]; unsigned int flags; char p64[0xAC - 0x64]; Q *q; char pb0[0x138 - 0xB0]; Lst *lst; } Own;
typedef struct T { char pad[0x14]; Mode *mode; float cur, target, c20; char p24[4]; unsigned int flags; float lo, hi; char p34[4]; Own *own; } T;
void ts4_flag_all_883CF138(T *t);
int fn_883CF9B8(Item *it, int a);
int fn_883CC388(Own *o);
#define OSYS(o) ((o)->q ? (o)->q->sys : 0)
int ts4_set_position_883D03C8(T *t, float x)
{
    float z = 0.0f, p;
    Link *l;
    int r;
    if (t->mode->flags & 0x30) return 0;
    p = z;
    if (t->hi != t->lo) {
        p = (x - t->lo) / (t->hi - t->lo);
        if (p > 1.0f) p = 1.0f; else if (p < z) p = z;
    }
    if (t->cur != p) {
        if (t->mode->fade != z && t->own && (t->own->flags & 0x1000) && OSYS(t->own)) {
            t->target = p;
            t->flags |= 1;
        } else {
            t->cur = p;
            t->c20 = p;
        }
        ts4_flag_all_883CF138(t);
        if (t->own && OSYS(t->own)) {
            Link *h = &t->own->lst->items;
            for (l = h->next; l != h; l = l->next) {
                Item *it = l ? (Item *)((char *)l - 4) : 0;
                if (it->mode->flags & 0x30) {
                    r = fn_883CF9B8(it, 0);
                    if (r) return r;
                }
            }
            r = fn_883CC388(t->own);
            if (r) return r;
        }
    }
    if (t->own && !(t->own->flags & 0x1000) && OSYS(t->own))
        t->flags |= 2;
    return 0;
}
