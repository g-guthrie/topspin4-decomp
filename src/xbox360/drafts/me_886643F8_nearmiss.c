/* NEAR MISS (instruction shape identical; 23 lines differ only in register numbering:
 * target zero r9 / hash r7 / temp r8, ours r7 / r8 / r9). Tried flag loop vs unrolled, helper,
 * hash local, do-while, int/unsigned counters.
 * 0x886643F8: reset every slot of the owner's self-relative table to the
 * empty-name hash, clear the twelve per-slot flags in the shared state, and zero the
 * table's fill count. */
typedef struct Slot { int value; unsigned int hash; } Slot;
typedef struct Table { int offset; unsigned int count; char p[4]; int filled; } Table;
typedef struct Shared { char p[0x2f0]; unsigned char flags[12]; } Shared;
typedef struct Ctx { char p[0x44]; Shared *shared; } Ctx;
typedef struct Owner { char p[0x1c]; Ctx *ctx; char p2[0x28 - 0x20]; Table *table; } Owner;
void ts4_reset_slot_table_886643F8(Owner *o)
{
    unsigned int i;
    unsigned int n = o->table->count;
    for (i = 0; i < n; i++)
        ((Slot *)((char *)o->table + (i * sizeof(Slot) + o->table->offset)))->hash = 0x968230B3;
    { Shared *s = o->ctx->shared; int k; for (k = 0; k < 12; k++) s->flags[k] = 0; }
    o->table->filled = 0;
}
