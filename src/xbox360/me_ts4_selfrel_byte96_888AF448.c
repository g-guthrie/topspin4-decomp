/* 0x888AF448: reads byte +0x96 of the self-relative (-1 = null) record held at +0x8; 0 when the holder is null. */
/* Matched on /Oc (agAB). Holder typed int (signed cmpwi); ternary resolve. */
typedef struct R { char p[0x96]; unsigned char b; } R;
typedef struct T { char p[8]; int off; } T;
unsigned char fn_888AF448(T *t)
{
    int o = t->off;
    if (o) {
        R *p = *(int *)o != -1 ? (R *)(*(int *)o + o) : 0;
        return p->b;
    }
    return 0;
}
