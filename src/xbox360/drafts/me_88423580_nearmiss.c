/* 0x88423580: Initialises a word mask over caller storage: words, capFlags 0x80000000 (not owned), last = bits/8 - 1, then fills bits/8 words with 0xFFFFFFFF. */
/* Near miss (agAH): 1 off: stwx operand order (target stwx r10,r11(index),r9(base)); a[i], i[a], byte offsets on either side and unsigned or int casts all give the base first. */
typedef struct WordMask { unsigned int *words; unsigned int capFlags; int last; } WordMask;
void fn_88423580(WordMask *m, unsigned int *words, unsigned int bits)
{
    int n = bits >> 3;
    int i;
    m->words = words;
    m->capFlags = 0x80000000;
    m->last = n - 1;
    for (i = 0; i < n; i++)
        m->words[i] = 0xFFFFFFFF;
}
