/* Q5: renderer self-relative pair-table lookups (Pam Display area, 0x886F3500-0x886F3600).
 * Plain route, no flags. The owner block holds two self-relative tables of {key, value} pairs
 * at +0x08 and +0x14; each table word is the byte offset from the table word to its first pair.
 * The extra `dst` local is load-bearing: it shifts the local numbering so the element address is
 * built as (index*8 + table) + rel, as in the original (see the OP1 operand-order rule). */
typedef unsigned int u32;

typedef struct Q5SrPair { u32 key; u32 value; } Q5SrPair;
typedef struct Q5SrTable { int rel; } Q5SrTable;           /* self-relative offset to pair 0 */
typedef struct Q5SrBlock {
    u32 w00, w04;
    Q5SrTable a;                                            /* +0x08 */
    u32 w0c, w10;
    Q5SrTable b;                                            /* +0x14 */
} Q5SrBlock;
typedef struct Q5SrOwner { u32 w00, w04, w08; Q5SrBlock *block; } Q5SrOwner;   /* block at +0x0c */
typedef struct Q5SrDesc { char p00[0x30]; u32 index_a; u32 index_b; } Q5SrDesc; /* +0x30, +0x34 */
typedef struct Q5SrSelf {
    u32 w00, w04, w08;
    Q5SrDesc *desc;                                         /* +0x0c */
    char p10[0x10];
    u32 value_b;                                            /* +0x20 */
    u32 value_a;                                            /* +0x24 */
} Q5SrSelf;

/* Swing_DLL.xex 0x886F3588: self->value_b = owner table B pair[self->desc->index_b].value */
void ts4_sr_lookup_table_b_886F3588(Q5SrSelf *self, Q5SrOwner *owner)
{
    Q5SrSelf *dst = self;
    Q5SrDesc *desc = self->desc;
    Q5SrBlock *block = owner->block;
    u32 index = desc->index_b;
    u32 offset = index * 8;
    Q5SrTable *table = &block->b;
    int rel = table->rel;
    Q5SrPair *entry = (Q5SrPair *)((char *)table + offset + rel);
    dst->value_b = entry->value;
}
