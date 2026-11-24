/*
 * R2 (gameplay core): swing-animation ring buffer of 0x84-byte entries.
 */
struct R2RingItem {
    unsigned char pad00[4];
    unsigned char *link4;             /* +0x04 */
    unsigned char pad08[0x6c - 8];
    unsigned char *owner_flag_ptr;    /* +0x6c, points at a record whose byte +0x2d is cleared */
};

struct R2RingOwnerState {
    unsigned char pad00[0x10];
    unsigned char *style;             /* +0x10 (style +0x40 read) */
    unsigned char pad14[0x28c - 0x14];
    int value_28c;                    /* +0x28c */
};

struct R2RingOwnerDefs {
    unsigned char pad00[0xc];
    unsigned char *defs;              /* +0x0c (defs + 0x60 passed) */
};

struct R2RingBuffer {
    unsigned char *begin;             /* +0x00 */
    unsigned char *end;               /* +0x04 */
    unsigned int pad08;
    unsigned int cursor;              /* +0x0c */
    unsigned int index;               /* +0x10 */
    unsigned int count;               /* +0x14 */
};

struct R2RingHost {
    unsigned char pad00[0x20];
    struct R2RingOwnerState *state;   /* +0x20 */
    unsigned char pad24[4];
    struct R2RingOwnerDefs *defs;     /* +0x28 */
    unsigned char pad2c[0xd4 - 0x2c];
    struct R2RingBuffer ring;         /* +0xd4 */
};

void fn_886DBF40(unsigned int *link_slot, unsigned int link_value, unsigned char *defs_60, unsigned int style_40, int minus_one, int value_28c);

/* Swing_DLL.xex 0x886DC9C0: release one ring entry (recycle), advance the ring cursor. */
void ts4_r2_swing_ring_release_entry_886DC9C0(struct R2RingHost *self, struct R2RingItem *item)
{
    struct R2RingBuffer *ring;
    unsigned int last;
    unsigned int idx;

    if ((struct R2RingHost *)((unsigned char *)self->state + 0x30) == self) {
        if (item->owner_flag_ptr != 0) {
            item->owner_flag_ptr[0x2d] = 0;
        }
    }
    {
        unsigned int *slot = (unsigned int *)(item->link4 + 4);
        fn_886DBF40(slot, *slot, self->defs->defs + 0x60, *(unsigned int *)(self->state->style + 0x40), -1, self->state->value_28c);
    }
    ring = &self->ring;
    idx = ring->index;
    ring->count = ring->count - 1;
    if (idx == 0) {
        last = (ring->end - ring->begin) / 0x84 - 1;
    } else {
        last = idx - 1;
    }
    if ((unsigned char *)item == ring->begin + last * 0x84) {
        if (idx == 0) {
            ring->index = last;
        } else {
            ring->index = idx - 1;
        }
        return;
    }
    ring->cursor = ring->cursor + 1;
    if (ring->cursor == (ring->end - ring->begin) / 0x84) {
        ring->cursor = 0;
    }
}
