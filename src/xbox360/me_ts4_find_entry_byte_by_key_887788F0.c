/* 0x887788F0: scan 0x98-byte entries for a matching key word, return the entry byte at +0x8D or 0 */
/* Matched on /Oc (agAB). Plain indexed for loop with an early return. */
typedef struct E { char p[0x74]; unsigned int key; char p78[0x8d - 0x78]; unsigned char val; char p8e[0x98 - 0x8e]; } E;
typedef struct T { char p[0xa4]; E *arr; unsigned int n; } T;
unsigned char fn_887788F0(T *t, unsigned char key)
{
    unsigned int i;
    for (i = 0; i < t->n; i++)
        if (key == t->arr[i].key)
            return t->arr[i].val;
    return 0;
}
