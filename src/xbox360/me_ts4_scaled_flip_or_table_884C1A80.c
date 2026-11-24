/* 0x884C1A80: scale (+0x10) times -neg (+0x18) when d->flip, else times tbl[d->idx] (signed byte index) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char pad[0x10]; float scale; int x14; float neg; float *tbl; } O;
typedef struct { char pad[0xd]; unsigned char flip; signed char idx; } D;
float ts4_scaled_flip_or_table_884C1A80(O *o, int b, D *d)
{
    float r;
    if (d->flip) r = -o->neg;
    else r = o->tbl[d->idx];
    return o->scale * r;
}
