/* 0x882D1F40: forces count(+0x54) to 4 unless kind(+8) is 4, then allocates n(+0x68)*16 bytes into +0x58 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns E_OUTOFMEMORY (0x8007000E) on failure. */
typedef struct T { int f0; int f4; unsigned kind; char pad[0x54 - 0xC]; unsigned count; void *table; char pad2[0x68 - 0x5C]; unsigned n; } T;
void *fn_88888668(unsigned size, unsigned tag);
int ts4_alloc_entry_table_882D1F40(T *t)
{
    if (t->kind != 4)
        t->count = 4;
    if (t->count) {
        t->table = fn_88888668(t->n << 4, 0x24810000);
        if (!t->table)
            return 0x8007000E;
    }
    return 0;
}
