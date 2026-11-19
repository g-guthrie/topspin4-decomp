typedef struct Slot { char pad[0x10]; float v; char p2[0x12c]; } Slot;
typedef struct Blk { char pad[0x104]; int rel; } Blk;
typedef struct Src { char pad[0x42c]; unsigned char dual; char p1[3]; float vals[4]; } Src;
static Slot *rp(int *r) { return (Slot *)((char *)r + *r); }
typedef struct Obj { char pad[0x3c]; Blk *blk; char p1[0x7c]; int a; int b; char p2[0x2c]; unsigned char lock; } Obj;
/* Copies up to four per-slot values into the slots selected by the primary and (when dual) secondary index. */
void fn_889165B8(Obj *o, Src *s)
{
    int a, b, n;
    Slot *sl;
    if (o->lock) return;
    b = -1;
    a = o->a;
    if (s->dual) b = o->b;
    sl = rp(&o->blk->rel);
    n = 0;
    if (a == 0 || b == 0) sl[0].v = s->vals[n++];
    if (a == 1 || b == 1) sl[1].v = s->vals[n++];
    if (a == 2 || b == 2) sl[2].v = s->vals[n++];
    if (a == 3 || b == 3) sl[3].v = s->vals[n];
}
