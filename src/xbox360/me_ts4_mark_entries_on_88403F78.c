/* 0x88403F78: sets the on byte (+4) of each entry (array at +0xC, count +0x10) whose level (short array at +4) is positive, or of every entry when only_live is 0. */
/* Matched on /Oc (agAB). Count hoisted; element pointer read into a local before the test. */
typedef struct E { int p0; unsigned char on; } E;
typedef struct T { int p0; short *lv; int p8; E **ents; int n; } T;
void fn_88403F78(T *t, char only_live)
{
    int i, n = t->n;
    for (i = 0; i < n; i++) {
        E *e = t->ents[i];
        if (t->lv[i] > 0 || !only_live)
            e->on = 1;
    }
}
