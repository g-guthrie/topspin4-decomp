/* 0x88592188: fills the eight bytes at +0xE34 with fn_8858EE40(t, 3), returns 0 while the byte at +0x2EB7 is set, else whether fn_885924B8(t, vals, t+0xDB4) is non-zero */
/* Matched on /O1 (agAH). cmplwi on cr0 for the busy byte points to /O1. */
typedef struct T { char p[0xdb4]; char cfg[0x80]; unsigned char vals[8]; char p2[0x2eb7 - 0xe3c]; unsigned char busy; } T;
extern unsigned char fn_8858EE40(T *t, int k);
extern unsigned char fn_885924B8(T *t, unsigned char *vals, void *cfg);
int fn_88592188(T *t)
{
    int i;
    for (i = 0; i < 8; i++)
        t->vals[i] = fn_8858EE40(t, 3);
    if (t->busy)
        return 0;
    return 0 != fn_885924B8(t, t->vals, t->cfg);
}
