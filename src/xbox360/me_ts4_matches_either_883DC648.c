/* 0x883DC648: true when fn_88329868(x, +0x20) is zero */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); or the optional +0x24 key also gives zero. */
typedef struct T { char pad[0x20]; void *a; void *b; } T;
int fn_88329868(void *x, void *k);
unsigned char ts4_matches_either_883DC648(T *t, void *x)
{
    return !fn_88329868(x, t->a) || (t->b && !fn_88329868(x, t->b));
}
