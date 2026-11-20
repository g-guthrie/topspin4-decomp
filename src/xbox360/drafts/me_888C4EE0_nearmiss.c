/* 0x888C4EE0: sets the on byte (+0x18) of entry (i * 2 + j) (0x1C bytes) of the self-relative table at b(+0x254)+0x738: 1, or (j == 0) when the lock byte at +0x23C is set. */
/* Near miss (agAB, /Oc): 1 off. The target keeps `and r8,mask,r8` after the subic/subfe mask; the compiler folds v & mask
 * to clrlwi because v is the constant 1. int/unsigned v, ?: and -(j == 0) masks all tried. */
typedef struct E { char p[0x18]; unsigned char on; char p19[0x1c - 0x19]; } E;
typedef struct R { int off; } R;
typedef struct B { char p[0x738]; R rel; } B;
typedef struct T { char p[0x23c]; unsigned char lock; char p23d[0x254 - 0x23d]; B *b; } T;
void fn_888C4EE0(T *t, int i, int j)
{
    unsigned char v = 1;
    R *r;
    if (t->lock)
        v = (unsigned char)(v & (j ? 0 : -1));
    r = &t->b->rel;
    ((E *)((char *)r + r->off))[i * 2 + j].on = v;
}
