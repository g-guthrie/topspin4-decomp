/* 0x887D9A10: runs ts4_slots_all_ok_887D90D8 on the current entry (index +0xC) of the 0x24-byte entry vector (begin/end at +0/+4); 1 when the vector is empty or the index is out of range. */
/* Matched on /Oc (agAB). The current-entry lookup is an inline helper returning 0 when empty or out of range; the caller tests that pointer. */
typedef struct Ent { char p[0x24]; } Ent;
typedef struct T { Ent *begin; Ent *end; int p8; unsigned int idx; } T;
unsigned int ts4_slots_all_ok_887D90D8(void *self);
static Ent *cur(T *t) { unsigned int n = t->end - t->begin; if (n == 0 || t->idx >= n) return 0; return &t->begin[t->idx]; }
unsigned int fn_887D9A10(T *t)
{
    Ent *e = cur(t);
    if (e)
        return ts4_slots_all_ok_887D90D8(e);
    return 1;
}
