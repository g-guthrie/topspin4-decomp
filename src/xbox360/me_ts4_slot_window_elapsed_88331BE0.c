/* 0x88331BE0: Finds the slot (of 32) whose kind/sub match the query and returns whether now - start exceeds its window. Returns 0 if flag bit 0 is set or nothing matches. */
/* Matched on /Oc (agAH). Plain loop with an early return. */
typedef struct Slot { unsigned char kind; unsigned char sub; char pad[2]; unsigned int window; unsigned int start; } Slot;
typedef struct Table { char p0[0xc]; unsigned int flags; char p10[0x14]; Slot slots[32]; } Table;
typedef struct Query { int p0; unsigned int now; unsigned char kind; unsigned char sub; } Query;
int fn_88331BE0(Table *t, const Query *q)
{
    int i;
    if (t->flags & 1)
        return 0;
    for (i = 0; i < 32; i++) {
        if (t->slots[i].kind == q->kind && t->slots[i].sub == q->sub)
            return q->now - t->slots[i].start > t->slots[i].window;
    }
    return 0;
}
