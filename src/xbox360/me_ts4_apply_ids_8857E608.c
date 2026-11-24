/* 0x8857E608: 0x57 for flags outside 0xC, zero flags or a null id list; else fn_8857E4E0(flags, id) for each id until one fails */
/* Matched on /O1 (agAH). /O1, result local with break. */
extern unsigned int fn_8857E4E0(unsigned int flags, unsigned int id);
unsigned int fn_8857E608(unsigned int flags, const unsigned int *ids, unsigned int count)
{
    unsigned int r = 0, i;
    if ((flags & ~0xCu) || !flags || !ids)
        return 0x57;
    for (i = 0; i < count; i++) {
        r = fn_8857E4E0(flags, ids[i]);
        if (r)
            break;
    }
    return r;
}
