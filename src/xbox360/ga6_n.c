/*
 * GA6: gameplay request lifecycle (find, finish and release of queued entries).
 */
typedef unsigned int ts4_word;

void fn_88644990(void *a, void *b);
void fn_886D9CB0(void *a, float value);
void ga6_run_while_type4_886D7A60(void *self, void *key);
void ts4_if_addr_lbl_880F7AEC_88647200(void *obj);

struct Ga6Request {
    int state;                 /* +0x00 */
    ts4_word handle;           /* +0x04 */
    char pad_08[4];
    ts4_word link;             /* +0x0C */
};
struct Ga6RequestSlot { struct Ga6Request *request; };
struct Ga6RequestList {
    char pad_00[4];
    struct Ga6RequestSlot *begin;  /* +0x04 */
    struct Ga6RequestSlot *end;    /* +0x08 */
};

/* Finish the queued entry that refers to key: mark it 4 if it was 1, run the completion hook, release the key's link
 * and set the entry state to 6. */
void ga6_finish_request_886D7AE0(struct Ga6RequestList *self, struct Ga6Request *key)
{
    struct Ga6RequestSlot *slot = self->begin;
    struct Ga6Request *entry;
    for (; slot != self->end; slot++) {
        entry = slot->request;
        if (key == (struct Ga6Request *)(unsigned long)entry->handle) {
            if (entry->state == 1)
                entry->state = 4;
            ga6_run_while_type4_886D7A60(self, key);
            if (key->link != 0)
                ts4_if_addr_lbl_880F7AEC_88647200(key);
            else
                key->handle = 0;
            entry->state = 6;
            return;
        }
    }
}

struct Ga6FlagBlock {
    char pad_00[0xC];
    int id;                    /* +0x0C */
    char pad_10[4];
    unsigned char flag_14;
    char pad_15;
    unsigned char flag_16, flag_17;
};
struct Ga6SceneOwner { char pad_00[0x518]; int id; };
struct Ga6Scene {
    char pad_00[0x10];
    struct { char pad[0x48]; struct Ga6FlagBlock *flags; } *info;  /* +0x10 */
    struct Ga6SceneOwner *owner;                                   /* +0x14 */
    char pad_18[8];
    struct { char pad[0xB8]; void *w_b8; } *target;                /* +0x20 */
    char pad_24[0xC];
    char sub_30[0x18];
    float value;                                                   /* +0x48 */
};
/* If the flag block is active and belongs to the current owner id, run the target and sub updates. */
void ga6_apply_flags_886DAD28(struct Ga6Scene *self)
{
    struct Ga6FlagBlock *flags = self->info->flags;
    if (flags->flag_14 && flags->id == self->owner->id) {
        if (flags->flag_17)
            fn_88644990(self->target->w_b8, self->target);
        if (flags->flag_16)
            fn_886D9CB0(self->sub_30, self->value);
    }
}

unsigned char fn_886CF518(void *entry, void *key, ts4_word arg);
void ts4_vec16_resize_88262F70(void *item, int value);
void fn_886CF1E0(void *entry, void *item, ts4_word base, ts4_word offset);
void fn_886C9AC0(void *owner, void *item, void *cfg, ts4_word extra);

struct Ga6SlotEntry { ts4_word w00, w04; };
struct Ga6EntryTable { char pad_00[0x68]; char sub_68[0x88]; struct Ga6SlotEntry **entries; /* +0xF0 */ };
struct Ga6QueueCfg {
    char pad_00[0x10];
    struct Ga6EntryTable *table;   /* +0x10 */
    char pad_14[8];
    struct { char pad[8]; ts4_word w08; } *p1c;  /* +0x1C */
};
struct Ga6Queue {
    struct Ga6QueueCfg *cfg;   /* +0x00 */
    void *owner;               /* +0x04 */
    char pad_08[0x18];
    ts4_word extra;            /* +0x20 */
};
struct Ga6QueueItem {
    char pad_00[0x28];
    struct { char pad[0x14]; ts4_word slot; } *src;  /* +0x28 */
    ts4_word key[1];           /* +0x2C */
};
/* Queue the item into its slot entry when the entry accepts the key or the caller forces it. */
