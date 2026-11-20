/* 0x88279A30: std::fill of 0x30-byte records (Vec3, 16-byte pair, Vec3) over [first, last) from one value */
/* Matched on /Oc (agAL). Plain route. Member-wise assignment inline with a Vec3 copy inline per member gives the val+0x10/val+0x20 base registers; plain struct members give 25 off. */
typedef unsigned __int64 u64;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Pair64 { u64 a, b; } Pair64;
typedef struct Rec30 { Vec3 p; float pad0c; Pair64 q; Vec3 r; float pad2c; } Rec30;

static void vcopy(Vec3 *d, const Vec3 *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

static void rec_assign(Rec30 *d, const Rec30 *s)
{
    vcopy(&d->p, &s->p);
    d->q = s->q;
    vcopy(&d->r, &s->r);
}

void ts4_rec30_fill_88279A30(Rec30 *first, Rec30 *last, const Rec30 *val)
{
    for (; first != last; ++first)
        rec_assign(first, val);
}
