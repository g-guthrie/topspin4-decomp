/* 0x884F7D80: builds a 4-bit mask of the slots at +0x50 whose object has a nonzero word at +4 and passes it to fn_884F7D18(mask, 1). */
/* Matched on /O1 (agAB). Loop with t->slot[i] read twice; /O1 keeps it a bdnz loop. */
typedef struct O { int p0; int v; } O;
typedef struct T { char p[0x50]; O *slot[4]; } T;
int fn_884F7D18(unsigned int mask, int a);
int fn_884F7D80(T *t)
{
    unsigned int mask = 0;
    int i;
    for (i = 0; i < 4; i++)
        if (t->slot[i])
            mask |= (t->slot[i]->v != 0) << i;
    return fn_884F7D18(mask, 1);
}
