/*
 * GA6: gameplay state resets.
 */
typedef unsigned int ts4_word;

void ts4_reset_core_886E0C48(void *obj);

/* Layout of the object at owner +0x28 (reset targets only). */
struct Ga6Flags14 { char pad_00[0x34]; unsigned char b34; char pad_35[0x20]; unsigned char b55; };
struct Ga6Sim {
    char pad_00[0x14];
    struct Ga6Flags14 *flags;  /* +0x14 */
    char pad_18[0xE0];
    ts4_word wf8, wfc;         /* +0xF8, +0xFC */
    unsigned char b100;        /* +0x100 */
    char pad_101;
    unsigned char b102;        /* +0x102 */
    char pad_103[0x3BE];
    unsigned char b4c1;        /* +0x4C1 */
};
struct Ga6Pair2C { char pad_00[0x10]; unsigned char b10, b11; };
struct Ga6ResetOwner {
    char pad_00[0x28];
    struct Ga6Sim *sim;        /* +0x28 */
    struct Ga6Pair2C *pair;    /* +0x2C */
};

/* Re-run the sim refresh, then clear its latch words and flags. */
void ga6_reset_sim_flags_886E2BF8(struct Ga6ResetOwner *self)
{
    ts4_reset_core_886E0C48(self->sim);
    self->sim->wf8 = 0;
    self->sim->wfc = 0;
    self->sim->b102 = 0;
    self->sim->flags->b55 = 0;
    self->sim->flags->b34 = 0;
    self->sim->b4c1 = 0;
    self->sim->b100 = 0;
    self->pair->b10 = 0;
    self->pair->b11 = 0;
}

struct Ga6HoldOwner; struct Ga6HoldRec;
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ga6_apply_hold_886D9698(struct Ga6HoldOwner *self, struct Ga6HoldRec *rec, int arg);

/* Self-relative array of 16-bit indices: offset to the first index (-1 = none) and the count. */
struct Ga6IndexSet {
    int rel;                   /* +0x00 */
    ts4_word count;            /* +0x04 */
    char pad_08[0x10];
    short main_index;          /* +0x18 */
};

/* Apply ga6_apply_hold_886D9698 to the main entry and then to every entry named by the index set (stride 0x1C, self-relative). */
void ga6_apply_index_set_886DBE90(struct Ga6IndexSet *self, int *table, void *ctx, ts4_word arg)
{
    unsigned short *end;
    unsigned short *p;
    ga6_apply_hold_886D9698(ctx, (void *)((char *)table + (*table + self->main_index * 0x1C)), arg);
    end = 0;
    if (self->rel != -1)
        end = (unsigned short *)((char *)self + (self->count * 2 + self->rel));
    p = 0;
    if (self->rel != -1)
        p = (unsigned short *)((char *)self + self->rel);
    for (; p != end; p++)
        ga6_apply_hold_886D9698(ctx, (void *)((char *)table + (*table + (short)*p * 0x1C)), arg);
}

/* ---- destructors ---- */
void ts4_destroy_owned_object(void *object);
void ts4_registry_dispatch_888860A0(void *buffer);
void ts4_object_dtor_886CA260(void *sub);
void ts4_object_dtor_886DABD0(void *sub);
void fn_886D0EB0(void *sub);
void ts4_loop_call_seq_u32_off0_881B68A8(void *a, ts4_word b);
struct Ga6OwnerChain;
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ga6_destroy_owner_chain_886D36D8(struct Ga6OwnerChain *self);
void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
extern char lbl_880F378C[], lbl_880D6B70[], lbl_880F37A4[], lbl_880F3794[], lbl_880F37A8[];
extern void *lbl_88D45AF4;
extern void *lbl_88D45AF8;

struct Ga6Sub430 { void *vtbl; char pad_04[8]; void *owned_0c; /* +0x0C */ };
struct Ga6BigObj {
    void *vtbl;                /* +0x00 */
    char pad_04[0x42C];
    struct Ga6Sub430 sub430;   /* +0x430 */
};

/* Teardown of the big object: release owned parts and reset the embedded sub-objects. */

/* Teardown: clear the globals, release buffer, owned objects and parts. */

/* ---- reverse walk of an item vector ---- */
void ts4_clear_three_vectors_886C3658(void *self);
int ts4_anim_layer_index_886C66C0(void *obj);
void fn_886D4978(void *self, void *obj, ts4_word item, int index);

struct Ga6StlVec { ts4_word pad_00; ts4_word *begin; ts4_word *end; };
struct Ga6ItemVec { char pad_00[0x58]; struct Ga6StlVec items; /* +0x58 */ };

/* Walk the item vector backwards from the end, handing each item and its index to fn_886D4978, until the
 * item that sits at the object's current index has been visited. */

struct Ga6OwnerChain {
    void *data;                /* +0x00 */
    ts4_word len;              /* +0x04 */
    char pad_08[0x14];
    void *o1c;                 /* +0x1C */
    char pad_20[8];
    void *o28;                 /* +0x28 */
    char pad_2c[4];
    void *o30;
    void *o34;                 /* +0x34 */
    char pad_38[8];
    void *o40;                 /* +0x40 */
    char pad_44[8];
    void *o4c;                 /* +0x4C */
    char pad_50[8];
    void *o58;                 /* +0x58 */
    char pad_5c[8];
    void *o64;                 /* +0x64 */
    char pad_68[8];
    void *o70;                 /* +0x70 */
    char pad_74[8];
    void *o7c;                 /* +0x7C */
    char pad_80[8];
    void *o88;                 /* +0x88 */
};
void ts4_loop_get_u32_off0_88266680(void *data, ts4_word len);

/* Destroy every owned sub-object from the highest offset down, then the backing buffer. */
void ga6_destroy_owner_chain_886D36D8(struct Ga6OwnerChain *self)
{
    if (self->o88) ts4_destroy_owned_object(self->o88);
    if (self->o7c) ts4_destroy_owned_object(self->o7c);
    if (self->o70) ts4_destroy_owned_object(self->o70);
    if (self->o64) ts4_destroy_owned_object(self->o64);
    if (self->o58) ts4_destroy_owned_object(self->o58);
    if (self->o4c) ts4_destroy_owned_object(self->o4c);
    if (self->o40) ts4_destroy_owned_object(self->o40);
    if (self->o34) ts4_destroy_owned_object(self->o34);
    if (self->o28) ts4_destroy_owned_object(self->o28);
    if (self->o1c) ts4_destroy_owned_object(self->o1c);
    ts4_loop_get_u32_off0_88266680(self->data, self->len);
    if (self->data) ts4_destroy_owned_object(self->data);
}

void ga6_acquire_hold_886CE5B0(void *self, void *item);
void ga6_release_hold_886D7B88(void *self, void *item);
void fn_886D2E78(void *self);

struct Ga6Rel { int rel; ts4_word count; };
struct Ga6HoldSet {
    struct Ga6Rel acquire;     /* +0x00 0x14-byte entries */
    ts4_word pad_08;
    struct Ga6Rel release;     /* +0x0C 0x10-byte entries */
    ts4_word w10;              /* +0x10 (overlaps release.count) */
};

/* Run the acquire step for every 0x14-byte entry and the release step for every 0x10-byte entry, then reset. */
void ga6_run_hold_set_886D7C28(void *self, struct Ga6HoldSet *set)
{
    ts4_word zero = 0;
    char *end = 0;
    char *p;
    struct Ga6Rel *rel2;
    if (set->acquire.rel != -1)
        end = (char *)set + (set->acquire.count * 0x14 + set->acquire.rel);
    p = 0;
    if (set->acquire.rel != -1)
        p = (char *)set + set->acquire.rel;
    for (; p != end; p += 0x14)
        ga6_acquire_hold_886CE5B0(self, p);
    rel2 = &set->release;
    end = 0;
    if (rel2->rel != -1)
        end = (char *)rel2 + (rel2->count * 0x10 + rel2->rel);
    p = 0;
    if (rel2->rel != -1)
        p = (char *)rel2 + rel2->rel;
    for (; p != end; p += 0x10)
        ga6_release_hold_886D7B88(self, p);
    set->release.count = zero;
    set->acquire.count = zero;
    fn_886D2E78(self);
}

extern float lbl_8814B440;
void ga6_finish_request_886D7AE0(void *self, void *item);
void ga6_add_reference_886D2AF0(void *self, void *item);

struct Ga6Held16 { ts4_word w00; ts4_word count; };
struct Ga6HoldRec { short first; short pad_02; short second; short pad_06; float amount; };
struct Ga6HoldTable { int rel; };
struct Ga6HoldCfg { char pad_00[0x6C]; struct Ga6HoldTable table; /* +0x6C */ };
struct Ga6HoldOwner { char pad_00[0x48]; struct { char pad[0xC]; struct Ga6HoldCfg *cfg; } *p48; };

/* Take (arg >= 0) or release (arg < 0) one hold on the record's first entry, and on its second entry when amount > 0. */
void ga6_apply_hold_886D9698(struct Ga6HoldOwner *self, struct Ga6HoldRec *rec, int arg)
{
    struct Ga6HoldCfg *cfg = self->p48->cfg;
    struct Ga6HoldTable *table = &cfg->table;
    struct Ga6Held16 *entry = (struct Ga6Held16 *)((char *)table + (table->rel + rec->first * 0x10));
    if (arg < 0) {
        if (entry->count != 0) {
            if (entry->count == 1)
                ga6_finish_request_886D7AE0(self, entry);
            else
                entry->count = entry->count - 1;
        }
    } else {
        ga6_add_reference_886D2AF0(self, entry);
    }
    if (rec->amount > lbl_8814B440) {
        entry = (struct Ga6Held16 *)((char *)table + (table->rel + rec->second * 0x10));
        if (arg < 0) {
            if (entry->count != 0) {
                if (entry->count == 1)
                    ga6_finish_request_886D7AE0(self, entry);
                else
                    entry->count = entry->count - 1;
            }
        } else {
            ga6_add_reference_886D2AF0(self, entry);
        }
    }
}
