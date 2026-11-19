/* 0x88411FE8: walks the offset array (+0x40, count +0x44) from the end, starting from the total at +0x74, and returns the largest gap between neighbours rounded up to 16 plus 0x90. */
/* Matched on /Oc (agAB). while (i) { i--; ... } countdown loop gives the ctr loop with the decrementing offset. */
typedef struct T { char p[0x40]; int *sizes; int n; char p48[0x74 - 0x48]; int total; } T;
int fn_88411FE8(T *t)
{
    int best = 0, prev = t->total;
    int i = t->n;
    while (i) {
        int cur;
        i--;
        cur = t->sizes[i];
        if (best <= prev - cur)
            best = prev - cur;
        prev = cur;
    }
    return ((best + 15) & ~15) + 0x90;
}
