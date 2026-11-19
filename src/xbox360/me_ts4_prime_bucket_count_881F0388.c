/* 0x881F0388: bucket count for count / load factor: the first prime in the lbl_880E9258 table at or above it (the value itself at the -1 terminator) */
/* Matched on /Oc (agAH). The no-op clamp to 0xFFFFFFFF is kept by the compiler (li -1; cmplw; mr). */
typedef struct T { char p[0x20]; float load; } T;
extern const unsigned int lbl_880E9258[];
unsigned int fn_881F0388(T *t, unsigned int count)
{
    unsigned int want = (unsigned int)((float)count / t->load);
    unsigned int n = want > 0xFFFFFFFFu ? 0xFFFFFFFFu : want;
    unsigned int i = 0;
    if (n > 0x11)
        while (n > lbl_880E9258[++i])
            ;
    if (lbl_880E9258[i] == 0xFFFFFFFFu)
        return n;
    return lbl_880E9258[i];
}
