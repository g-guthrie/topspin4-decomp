/* 0x883F8388: allocates the owner's child node (883DBC98, line 0x6C2), binds the source def (fn_883E13B8, ref +1), caches its short id when 883E0778 is 0, copies owner/+0x18/+0x24, runs fn_883E3700 when +0x24 bit 2 is set and stores the node at owner->f138->f10; 0x2C on allocation failure */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
unsigned int ts4_get_bits_0_1c_7_883E0778(const char *object);
typedef struct Info { char pad[0xc]; char *fc; char pad2[0xc]; int f1c; } Info;
typedef struct Def { char pad[8]; int refs; Info *fc; } Def;
typedef struct Src { char pad[0x14]; Def *def; char pad2[0xc]; unsigned int f24; } Src;
typedef struct Dst {
    char pad[0x14]; Def *def; int f18; char pad1[4]; void *owner; unsigned int f24;
    char pad2[0x18]; short f40;
} Dst;
typedef struct Mid { char pad[0xc]; int fc; Dst *dst; } Mid;
typedef struct Owner { char pad[0x138]; Mid *mid; } Owner;
typedef struct A { char pad[0xc]; int fc; Src *src; } A;
extern const char lbl_88039FA4[];
Dst *ts4_if_get_u32_lbl_88B3302C_883DBC98(void *ctx, int a, const char *file, int line);
void fn_883E13B8(Dst *d, Def *def);
int fn_883E3700(Dst *d, void *ctx);
int ts4_create_child_from_def_883F8388(A *a, Owner *o, void *ctx)
{
    Mid *m = o->mid;
    Src *s = a->src;
    Dst *d;
    int r;
    m->fc = a->fc;
    d = ts4_if_get_u32_lbl_88B3302C_883DBC98(ctx, 0, lbl_88039FA4, 0x6c2);
    if (!d)
        return 0x2c;
    fn_883E13B8(d, s->def);
    d->def->refs++;
    if ((int)ts4_get_bits_0_1c_7_883E0778(s->def->fc->fc) == 0)
        d->f40 = (short)s->def->fc->f1c;
    d->f24 = s->f24;
    d->owner = o;
    d->f18 = 0;
    if (d->f24 & 4) {
        r = fn_883E3700(d, ctx);
        if (r)
            return r;
    }
    m->dst = d;
    return 0;
}
