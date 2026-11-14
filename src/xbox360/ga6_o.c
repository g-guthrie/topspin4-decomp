/*
 * GA6: gameplay entry filters and list sweeps.
 */
typedef unsigned int ts4_word;

extern float lbl_8814B440;

void fn_886DC610(void *self, void *entry);
unsigned char ts4_data_condition_eval_886C9F08(void *table, void *key, void *item);
void fn_88263908(void *vec, void *where, void *item, int count, int flag);
unsigned char fn_886CB778(void *a, void *b);

struct Ga6Entry98 {
    char pad_00[0x84];
    ts4_word w84;              /* +0x84 */
    float f88;                 /* +0x88 */
    char pad_8c[0xC];
};
struct Ga6EntryList {
    char pad_00[0xC];
    struct Ga6Entry98 *cur;    /* +0x0C */
    char pad_10[4];
    struct Ga6Entry98 *end;    /* +0x14 */
};

static unsigned char ga6_entry_is_idle(struct Ga6Entry98 *e, float zero)
{
    return e->w84 == 0 && e->f88 == zero;
}

/* Erase every idle entry (no pending word and a zero timer) from the list. */
void ga6_erase_idle_entries_886DC708(struct Ga6EntryList *self)
{
    struct Ga6Entry98 *e = self->cur;
    float zero;
    if (e != self->end) {
        zero = lbl_8814B440;
        do {
            if (ga6_entry_is_idle(e, zero))
                fn_886DC610(self, e);
            else
                e++;
        } while (e != self->end);
    }
}

struct Ga6PtrVec { void **begin; void **end; void **cap; };
struct Ga6Range { void **first; void **last; };
struct Ga6Searcher { char pad_00[0x15C]; char *table_base; /* +0x15C */ };

/* Collect every item of range that the table accepts for key into out. */
void ga6_collect_matching_886CEAC8(struct Ga6Searcher *self, void *key, struct Ga6Range *range, struct Ga6PtrVec *out)
{
    void **last = range->last;
    void **p = range->first;
    if (p != last) {
        do {
            char *base = self->table_base;
            void *item = *p;
            if (ts4_data_condition_eval_886C9F08(base + 0x5AC, key, item)) {
                if (out->end != out->cap) {
                    if (out->end)
                        *out->end = item;
                    out->end = out->end + 1;
                } else {
                    fn_88263908(out, out->end, p, 1, 1);
                }
            }
            p++;
        } while (p != last);
    }
}

struct Ga6Pair2 {
    int id;                    /* +0x00 */
    char pad_04[4];
    ts4_word mask_a;           /* +0x08 */
    ts4_word mask_b;           /* +0x0C */
    char pad_10[0x14];
    unsigned char enabled;     /* +0x24 */
};

static unsigned char ga6_masks_overlap(struct Ga6Pair2 *a, struct Ga6Pair2 *b)
{
    return (a->mask_a & b->mask_a) != 0 && (a->mask_b & b->mask_b) != 0;
}

/* True when b is enabled, shares both masks with a, and (when both have ids) the pair test accepts them. */
unsigned char ga6_pair_accepts_886D0CE0(struct Ga6Pair2 *a, void *unused, struct Ga6Pair2 *b)
{
    unsigned char r = 0;
    (void)unused;
    if (b->enabled && ga6_masks_overlap(a, b))
        r = a->id == -1 || b->id == -1 || fn_886CB778(a, b);
    return r;
}
