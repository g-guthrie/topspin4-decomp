/* 0x8848B140: turns the cursor (+0xC) into a 32-byte record index from the group base (+0x20 -> +0x28, records after a 0x30 header) and returns the last position in the group id bytes (+0xC, count +0x10) holding it as a u16; -1 when +0x1C is 0. */
/* Matched on /Oc (agAB). Group pointer in a block local; countdown for loop with break. */
typedef struct G { char p[0xc]; unsigned char *ids; int n; char p14[0x28 - 0x14]; char *base; } G;
typedef struct T { char p[0xc]; char *cur; char p10[0x1c - 0x10]; int ok; G *g; } T;
int fn_8848B140(T *t)
{
    int i, k;
    if (t->ok == 0)
        return -1;
    k = (t->cur - t->g->base - 0x30) >> 5;
    {
        G *g = t->g;
        for (i = g->n - 1; i >= 0; i--)
            if (g->ids[i] == k)
                break;
    }
    return (unsigned short)i;
}
