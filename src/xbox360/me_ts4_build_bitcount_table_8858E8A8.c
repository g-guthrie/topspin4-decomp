/* 0x8858E8A8: fills the 256-entry byte table at +0x872 with the number of set bits of each index. */
/* Matched on /O1 (agAB). Inner shift loop with an unsigned char counter; the cr0 tests mark /O1. */
typedef struct T { char p[0x872]; unsigned char bits[256]; } T;
void fn_8858E8A8(T *t)
{
    int i, v;
    unsigned char n;
    for (i = 0; i < 256; i++) {
        n = 0;
        for (v = i; v; v >>= 1)
            if (v & 1)
                n++;
        t->bits[i] = n;
    }
}
