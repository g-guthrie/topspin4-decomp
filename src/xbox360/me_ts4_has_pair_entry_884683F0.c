/* 0x884683F0: writes 1 to *out when one of the first n (+0x21) 4-byte entries matches both key bytes, scanning from the end, else 0. */
/* Matched on /Oc (agAB). void with an out byte (the target stores through r3); countdown for loop. */
typedef struct K { unsigned char a, b; } K;
typedef struct E { unsigned char a, b; char p[2]; } E;
typedef struct T { E e[8]; unsigned char p20; unsigned char n; } T;
void fn_884683F0(unsigned char *out, T *t, const K *k)
{
    int i;
    for (i = t->n - 1; i >= 0; i--) {
        if (t->e[i].a == k->a && t->e[i].b == k->b) {
            *out = 1;
            return;
        }
    }
    *out = 0;
}
