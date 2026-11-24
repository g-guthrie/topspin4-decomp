/*
 * GA6: small gameplay wrappers (Top Spin 4, Xbox 360, Swing_DLL.xex), 0x886CE5B0..0x886E7F78.
 * Many of these resolve an element of a self-relative array (offset word at the header,
 * element = header + offset + index * stride) and tail-call a worker.
 */
typedef unsigned int ts4_word;

/* Worker callees (placeholder symbols). */
void ts4_walk_clamped_886DFA60(void *dest, float value, ts4_word arg, ts4_word size);
void fn_886CEB68(void *self, ts4_word a, ts4_word b, ts4_word c, ts4_word d, void *entry);

struct Ga6Ctx158 {
    char pad_00[0x560];
    int entry_index;           /* +0x560 */
};

struct Ga6OwnerB {
    char pad_00[0x15C];
    struct Ga6Ctx158 *ctx;     /* +0x15C */
    char pad_160[4];
    char *table;               /* +0x164 self-relative table header lives at table + 0x14 */
};

/* Forward a float property of the object (+0x18) to the sub-object at +0x58 with size 0x40. */
void ga6_forward_scalar_886E2088(char *self, ts4_word arg)
{
    ts4_walk_clamped_886DFA60(self + 0x58, *(float *)(self + 0x18), arg, 0x40);
}

/* Look up the current entry (stride 0x1C) in the self-relative table and forward to the worker. */
void ga6_dispatch_current_entry_886CECB8(struct Ga6OwnerB *self, ts4_word a, ts4_word b, ts4_word c, ts4_word d)
{
    int *hdr = (int *)(self->table + 0x14);
    char *entry = (char *)hdr + *hdr + self->ctx->entry_index * 0x1C;
    fn_886CEB68(self, a, b, c, d, entry);
}
