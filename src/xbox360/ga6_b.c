/*
 * GA6: reference-count style helpers and indexed-array wrappers in the gameplay code.
 */
typedef unsigned int ts4_word;

struct Ga6Counted {
    ts4_word pad_00;
    ts4_word count;            /* +0x04 */
};

void ga6_finish_request_886D7AE0(void *owner, struct Ga6Counted *item);
void ga6_add_reference_886D2AF0(void *owner, struct Ga6Counted *item, int arg);

/* Drop one count from item; the last count is released through ga6_finish_request_886D7AE0 (zero is a no-op). */
void ga6_release_count_886D9640(void *owner, struct Ga6Counted *item)
{
    ts4_word count = item->count;
    if (count == 0)
        return;
    if (count == 1) {
        ga6_finish_request_886D7AE0(owner, item);
        return;
    }
    item->count = count - 1;
}

/* Negative arg releases one count, otherwise forward to ga6_add_reference_886D2AF0. */
void ga6_release_or_forward_886D9668(void *owner, struct Ga6Counted *item, int arg)
{
    if (arg < 0) {
        ts4_word count = item->count;
        if (count == 0)
            return;
        if (count == 1) {
            ga6_finish_request_886D7AE0(owner, item);
            return;
        }
        item->count = count - 1;
        return;
    }
    ga6_add_reference_886D2AF0(owner, item, arg);
}

/* ---- self-relative array element wrappers ---- */
void fn_886DF020(void *owner, void *entry);
void ga6_apply_hold_886D9698(ts4_word a, void *entry, ts4_word b);

struct Ga6Block34 {
    char pad_00[0xC];
    char *table;               /* +0x0C base of a table whose header sits at +0x50 */
};
struct Ga6Owner2C {
    char pad_00[0x2C];
    void *child;               /* +0x2C */
    char pad_30[4];
    struct Ga6Block34 *block;  /* +0x34 */
};

/* Entry idx (stride 0x8C) of the self-relative table in block +0x34; forward to fn_886DF020 with child +0x2C. */
void ga6_dispatch_entry_8c_886DFD88(struct Ga6Owner2C *self, int idx)
{
    int *hdr = (int *)(self->block->table + 0x50);
    char *entry = (char *)hdr + *hdr + idx * 0x8C;
    fn_886DF020(self->child, entry);
}

struct Ga6Indexed {
    char pad_00[0xC];
    short index;               /* +0x0C */
};

/* Entry (stride 0x1C) selected by the short index at +0x0C in the self-relative array at hdr. */
void ga6_dispatch_indexed_entry_886DA810(struct Ga6Indexed *self, int *hdr, ts4_word a, ts4_word b)
{
    char *entry = (char *)hdr + *hdr + self->index * 0x1C;
    ga6_apply_hold_886D9698(a, entry, b);
}
