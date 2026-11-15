/* W8A batch B: gameplay functions with virtual calls and self-relative tables (plain route, /Oc) */

/* 0x88655BC8: drain the pending queue through the owner, then reset the counters. */
struct W8aObj88655BC8;
typedef struct W8aVt88655BC8 { void *p0; unsigned char (*f1)(struct W8aObj88655BC8 *, int, int); unsigned char (*f2)(struct W8aObj88655BC8 *); } W8aVt88655BC8;
typedef struct W8aObj88655BC8 { W8aVt88655BC8 *vt; } W8aObj88655BC8;
typedef struct W8aS88655BC8 { char pad[4]; int f4; W8aObj88655BC8 *f8; unsigned fc; unsigned f10; } W8aS88655BC8;
unsigned char fn_886553A8(W8aS88655BC8 *s);
unsigned char ts4_flush_queue_88655BC8(W8aS88655BC8 *s)
{
    unsigned char r;
    unsigned char ok;
    if (s->fc == s->f10)
        return 1;
    r = s->f8->vt->f1(s->f8, 1, s->f4);
    while (s->fc != s->f10) {
        unsigned char b = fn_886553A8(s);
        r = b & r;
    }
    ok = s->f8->vt->f2(s->f8);
    s->fc = 0;
    s->f10 = 0;
    return ok & r;
}

/* 0x88655EC8: saturating increment of one byte counter in a self-relative table, guarded by the owner's checks. */
struct O19;
typedef struct Hd19 { int rel; unsigned count; } Hd19;
typedef struct X19 { char pad[0x48]; Hd19 h; } X19;
typedef struct Vt19 { char pad[0x30]; unsigned char (*f30)(struct O19 *); char p2[0x4c - 0x34]; X19 *(*f4c)(struct O19 *, int); } Vt19;
typedef struct O19 { Vt19 *vt; } O19;
typedef struct S19 { char pad[0x1c]; O19 o; char p2[0x78 - 0x20]; unsigned f78; } S19;
void ts4_bump_counter_88655EC8(S19 *s, int a, unsigned b, unsigned c)
{
    int pad0 = 0;
    int pad1 = 0;
    O19 *o = &s->o;
    X19 *x;
    if (o->vt->f30(o) && s->f78 == c) {
        x = o->vt->f4c(o, 0);
        if (a < 4 && (unsigned)a < x->h.count) {
            Hd19 *h = &x->h;
            Hd19 *e = (Hd19 *)((char *)h + (a * 0x1c + h->rel));
            if (b < e->count) {
                unsigned char *base = (unsigned char *)e + e->rel;
                int v = base[b];
                if (255 - v >= 1)
                    base[b] = v + 1;
                else
                    base[b] = 0xff;
            }
        }
    }
    (void)pad0;
    (void)pad1;
}
