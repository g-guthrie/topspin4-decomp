/* 0x883FFB90: finalizes four owned slots, returning the first error */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); then sets +0x14 = 1 and clears +0x10. */
typedef struct T { void *slot[4]; int f10; int f14; } T;
int ts4_finalize_owned_and_clear_883FF908(void **slot);
int ts4_finalize_four_slots_883FFB90(T *t)
{
    int i, r;
    for (i = 0; i < 4; i++) {
        r = ts4_finalize_owned_and_clear_883FF908(&t->slot[i]);
        if (r)
            return r;
    }
    t->f14 = 1;
    t->f10 = 0;
    return r;
}
