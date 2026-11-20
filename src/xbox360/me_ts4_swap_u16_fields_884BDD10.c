/* 0x884BDD10: byte-swaps the u16 at +2 of each of the n 8-byte entries, then the a+b u16 words that follow them */
/* Matched on /Oc (agAH). Entry/word structs with byte arrays; the word count is a hoisted local (ctr loop). */
typedef struct Entry { unsigned char b[8]; } Entry;
typedef struct W { unsigned char b[2]; } W;
typedef struct T { unsigned char a, b, n, pad; Entry e[1]; } T;
void fn_884BDD10(T *t)
{
    int i, cnt;
    unsigned char c;
    W *w;
    for (i = 0; i < t->n; i++) {
        c = t->e[i].b[2];
        t->e[i].b[2] = t->e[i].b[3];
        t->e[i].b[3] = c;
    }
    w = (W *)&t->e[t->n];
    cnt = t->a + t->b;
    for (i = 0; i < cnt; i++) {
        c = w[i].b[0];
        w[i].b[0] = w[i].b[1];
        w[i].b[1] = c;
    }
}
