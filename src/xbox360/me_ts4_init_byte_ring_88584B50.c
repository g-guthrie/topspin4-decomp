/* 0x88584B50: clears the count x 8-byte entries at +0x30 and links them into a ring through the next (+5) and prev (+6) bytes; head byte cleared */
/* Matched on /Oc (agAH). Store order prev-then-next decides the induction variable. */
typedef struct Ent { char p[5]; unsigned char next; unsigned char prev; char p2; } Ent;
typedef struct T { char p[0x30]; Ent *ents; char p2[0xc8 - 0x34]; unsigned char count; unsigned char head; } T;
extern void *memset(void *d, int c, unsigned int n);
void fn_88584B50(T *t)
{
    unsigned int n = t->count;
    Ent *e = t->ents;
    unsigned int i;
    memset(e, 0, n * sizeof(Ent));
    for (i = 0; i < n; i++) {
        e[i].prev = (unsigned char)(i - 1);
        e[i].next = (unsigned char)(i + 1);
    }
    e[0].prev = (unsigned char)(n - 1);
    e[n - 1].next = 0;
    t->head = 0;
}
