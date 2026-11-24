/* 0x883DC648: true when ts4_stricmp_ascii_88329868(x, +0x20) is zero */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); or the optional +0x24 key also gives zero. */
typedef struct T { char pad[0x20]; void *a; void *b; } T;
int ts4_stricmp_ascii_88329868(void *x, void *k);
unsigned char ts4_matches_either_883DC648(T *t, void *x)
{
    return !ts4_stricmp_ascii_88329868(x, t->a) || (t->b && !ts4_stricmp_ascii_88329868(x, t->b));
}
