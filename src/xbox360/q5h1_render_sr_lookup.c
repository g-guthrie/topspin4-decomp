/* Q5h1 clone: renderer self-relative pair-table lookup, table A variant (Pam Display area).
 * Clone of ts4_sr_lookup_table_b_886F3588 (q5_render_sr_lookup.c). Differences from the template,
 * from diffing ts4_sr_lookup_table_b_886F3588 against ts4_sr_lookup_table_a_886F35B8:
 *   block table at +0x08 (template +0x14), index from desc +0x30 (template +0x34),
 *   store to self +0x24 (template +0x20).
 * The extra `dst` local is kept on purpose: it fixes the operand order of the two adds. */
typedef unsigned int u32;

typedef struct Q5h1Pair { u32 key; u32 value; } Q5h1Pair;
typedef struct Q5h1Table { int rel; } Q5h1Table;            /* self-relative offset to pair 0 */
typedef struct Q5h1Block {
    u32 w00, w04;
    Q5h1Table a;                                            /* +0x08 */
    u32 w0c, w10;
    Q5h1Table b;                                            /* +0x14 */
} Q5h1Block;
typedef struct Q5h1Owner { u32 w00, w04, w08; Q5h1Block *block; } Q5h1Owner;   /* block at +0x0c */
typedef struct Q5h1Desc { char p00[0x30]; u32 index_a; u32 index_b; } Q5h1Desc; /* +0x30, +0x34 */
typedef struct Q5h1Self {
    u32 w00, w04, w08;
    Q5h1Desc *desc;                                         /* +0x0c */
    char p10[0x10];
    u32 value_b;                                            /* +0x20 */
    u32 value_a;                                            /* +0x24 */
} Q5h1Self;

/* Swing_DLL.xex 0x886F35B8: self->value_a = owner table A pair[self->desc->index_a].value */
void ts4_sr_lookup_table_a_886F35B8(Q5h1Self *self, Q5h1Owner *owner)
{
    Q5h1Self *dst = self;
    Q5h1Desc *desc = self->desc;
    Q5h1Block *block = owner->block;
    u32 index = desc->index_a;
    u32 offset = index * 8;
    Q5h1Table *table = &block->a;
    int rel = table->rel;
    Q5h1Pair *entry = (Q5h1Pair *)((char *)table + offset + rel);
    dst->value_a = entry->value;
}
