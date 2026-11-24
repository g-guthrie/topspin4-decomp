/* 0x883D2120: claim first empty slot (marks 0x0FACE0FF) or bump counter */
/* Matched on /Oc /Os (agAH). Pointer-null check of the slot array is the addic. form. */
typedef struct Tbl { char pad[0x3c]; unsigned int count; int pad40; void *slots[1]; } Tbl;
unsigned int fn_883D2120(Tbl *t, unsigned int *next)
{
    void **s = t->slots;
    unsigned int i;
    if (s) {
        for (i = 0; i < t->count; i++) {
            if (s[i] == 0) {
                t->slots[i] = (void *)0x0FACE0FF;
                return i;
            }
        }
    }
    return (*next)++;
}
