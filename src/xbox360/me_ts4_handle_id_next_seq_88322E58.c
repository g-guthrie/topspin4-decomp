/* 0x88322E58: advances the 16-bit sequence of the handle id at +0x50 (kind:4 | index:12 | seq:16), taken from the id itself or from the counter at +0x40, wrapping 0xFFFF to 1; with the global flag the new id also becomes the counter */
/* Matched on /Oc (agAH). Explicit masks on both halves of the kind|index merge give rlwimi. */
typedef struct Tab { char pad[0x40]; unsigned int counter; char pad44[0xc]; unsigned int id; } Tab;
int fn_88322E58(Tab *t, unsigned char global)
{
    unsigned int id = t->id;
    unsigned int kind = id >> 28;
    unsigned int idx = (id >> 16) & 0xFFF;
    unsigned int base = id;
    unsigned int seq;
    if (!global)
        base = t->counter;
    seq = (base & 0xFFFF) + 1;
    if (seq > 0xFFFF)
        seq = 1;
    id = ((((kind << 12) & 0xF000) | (idx & 0xFFF)) << 16) | seq;
    t->id = id;
    if (global)
        t->counter = id;
    return 0;
}
