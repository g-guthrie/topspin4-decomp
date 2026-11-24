/* 0x88941E20: ready test: owner set, three vectors non-empty and index not -1 */
/* Matched on /Oc (agAH). The owner test is 'ok = 0 != t->owner' (addi/subic/subfe), returned as is when false. */
typedef struct Vec { void **begin; void **end; } Vec;
typedef struct T { char p0[0x1c]; void *owner; char p20[0x64]; Vec a; char p8c[0x20]; Vec c; char pb4[4]; Vec b; char pc0[0x2c]; int index; } T;
unsigned char fn_88941E20(T *t)
{
    unsigned char ok = 0 != t->owner;
    if (!ok)
        return ok;
    return t->a.begin != t->a.end && t->b.begin != t->b.end && t->c.begin != t->c.end && t->index != -1;
}
