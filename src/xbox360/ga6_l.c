/*
 * GA6: gameplay manager loops over self-relative arrays, validity checks and constructors.
 */
typedef unsigned int ts4_word;

void fn_886E3328(ts4_word slot, void *self, void *item, void *record, ts4_word extra);
void fn_886D9070(void *self);
void fn_886E5178(void *self);
void ga6_flush_subsystem_886DAF38(void *self);
void fn_886CDFD8(void *self);
void ts4_step_array_elem_88649678(void *obj, ts4_word index, void *rec);
void fn_886DBF40(void *a, ts4_word b, void *c, ts4_word d, int e, ts4_word f);
void fn_886E7270(void *self);
void fn_886E7798(void *self);
void fn_886E7110(void *self);
void fn_886D0F78(void *sub);

extern char lbl_880F3794[];
struct Ga6TypeRec { ts4_word type_id; };
struct Ga6Globals40 { char pad_00[0x24]; struct Ga6TypeRec *rec; };
extern struct Ga6Globals40 *lbl_88D45940;

/* Visit every element of a self-relative pointer array (header at arg+0): hand slot i, the item and its 0x530-byte record to fn_886E3328. */
struct Ga6ItemList { int rel; int count; };
struct Ga6Visitor {
    char pad_00[0x48];
    ts4_word extra;            /* +0x48 */
    int *records_hdr;          /* +0x4C: self-relative array of 0x530-byte records */
    ts4_word *slots;           /* +0x50 */
};

/* Run the per-frame update chain; when an effect is attached, forward it with the owner's counter + 1. */
struct Ga6EffectRec { char pad_00[0x70]; char data[1]; };
struct Ga6EffectHolder { char pad_00[0xA0]; ts4_word enabled; };
struct Ga6OwnerCtr { char pad_00[0x518]; ts4_word counter; };
struct Ga6Updater {
    char pad_00[0x14];
    struct Ga6OwnerCtr *owner; /* +0x14 */
    char pad_18[8];
    char *effect_rec;          /* +0x20 */
    void *effect;              /* +0x24 */
};
void ga6_update_chain_886E5378(struct Ga6Updater *self)
{
    fn_886D9070(self);
    fn_886E5178(self);
    ga6_flush_subsystem_886DAF38(self);
    fn_886CDFD8(self);
    if (*(ts4_word *)(self->effect_rec + 0xA0) != 0 && self->effect)
        ts4_step_array_elem_88649678(self->effect, self->owner->counter + 1, self->effect_rec + 0x70);
}

/* Per-record loop: forward each 0x98-byte entry of the pending list to fn_886DBF40, then mark all entries consumed. */
struct Ga6SlotEntry { char pad_00[4]; ts4_word *slot; };
struct Ga6CfgA { char pad_00[0xC]; char *p0c; };
struct Ga6Env {
    char pad_00[0x10];
    struct { char pad[0x40]; ts4_word w40; } *cfg;     /* +0x10 */
    char pad_14[4];
    struct Ga6CfgA *cfg_a;                              /* +0x18 */
    char pad_1c[0x270];
    ts4_word w28c;                                      /* +0x28C */
};
struct Ga6Pending {
    char pad_00[8];
    struct Ga6Env *env;        /* +0x08 */
    char *cur;                 /* +0x0C */
    char pad_10[4];
    char *end;                 /* +0x14 */
};
void ga6_flush_pending_886DC690(struct Ga6Pending *self)
{
    char *entry = self->cur;
    ts4_word w40 = self->env->cfg->w40;
    if (entry != self->end) {
        do {
            struct Ga6Env *env = self->env;
            ts4_word *slot = *(ts4_word **)(entry + 4);
            fn_886DBF40(slot + 1, slot[1], env->cfg_a->p0c + 0x60, w40, -1, env->w28c);
            entry += 0x98;
        } while (entry != self->end);
    }
    self->end = self->cur;
}

/* Run the three update stages unless the global descriptor has the expected type id. */

struct Ga6WideObj {
    void *vtbl;                /* +0x00 */
    char pad_04[0xC];
    ts4_word w10, w14, w18, w1c, w20;
    char pad_24[0xC];
    char sub_30[0x120];
    ts4_word w150, w154, w158, w15c, w160, w164;
};

static unsigned char ga6_descriptor_has_type(void)
{
    return lbl_88D45940 && lbl_88D45940->rec->type_id == 0x165BBDE9u;
}

/* Run the three update stages unless the global descriptor has the expected type id. */
void ga6_update_unless_typed_886E79A8(void *self)
{
    if (!ga6_descriptor_has_type()) {
        fn_886E7270(self);
        fn_886E7798(self);
        fn_886E7110(self);
    }
}
