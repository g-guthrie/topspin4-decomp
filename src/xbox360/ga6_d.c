#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/*
 * GA6: gameplay object init / teardown helpers (call-through and field-reset wrappers).
 */
typedef unsigned int ts4_word;

void ts4_object_finalize(void *object);
void ts4_destroy_owned_object(void *object);

void ts4_vec204_move_tail_881B9148(void *object);
void ts4_dc20e_erase_88263A08(void *list, ts4_word first, ts4_word last);
void fn_886D9788(void *self);
void ts4_vector24_reserve_10_882660C0(void *object);
void fn_88264F28(void *object, int size);
void ts4_r2_swing_ring_release_entry_886DC9C0(void *owner, ts4_word item);
void fn_886C7500(void);
void fn_886E2410(void *self);

struct Ga6Teardown {
    char pad_00[4];
    char sub_04[0xC];
    char sub_10[0xC];
    ts4_word list_1c, list_20;
    char pad_24[0x24];
    ts4_word field_48;
};

/* Reset +0x48, then finalize the sub-objects at +0x10 and +0x04 and release the list at +0x1C. */
void ga6_teardown_886D98E0(struct Ga6Teardown *self)
{
    fn_886D9788(self);
    self->field_48 = 0;
    ts4_object_finalize(self->sub_10);
    ts4_dc20e_erase_88263A08(&self->list_1c, self->list_1c, self->list_20);
    ts4_object_finalize(self->sub_04);
}

/* Destroy the three owned sub-objects held by the inner block at +0x14 (its +0x04, +0x10 and +0x1C). */
struct Ga6OwnedBlock {
    char pad_00[4];
    void *owned_04;
    char pad_08[8];
    void *owned_10;
};
struct Ga6Owner3 {
    char pad_00[0x14];
    struct Ga6OwnedBlock inner; /* +0x14 */
    char pad_28[8];
    void *owned_30;             /* +0x30 */
};
static void ga6_release_block(struct Ga6OwnedBlock *in)
{
    if (in->owned_10)
        ts4_destroy_owned_object(in->owned_10);
    if (in->owned_04)
        ts4_destroy_owned_object(in->owned_04);
}

struct Ga6Cleared88 {
    char pad_00[8];
    unsigned char flag_08;
    char pad_09[7];
    char sub_10[0x0C];
    ts4_word w1c;
    char pad_20[0x20];
    ts4_word w40[0x10];
    char pad_80[8];
    ts4_word w88;
};

/* Zero the state words (+0x40..+0x74, +0x1C, +0x88, flag +0x08) then reset the sub-object at +0x10. */
void ga6_reset_state_886E7E70(struct Ga6Cleared88 *self)
{
    self->w88 = 0;
    self->w40[0] = 0; self->w40[1] = 0; self->w40[2] = 0; self->w40[3] = 0;
    self->w40[4] = 0; self->w40[5] = 0; self->w40[6] = 0; self->w40[7] = 0;
    self->w40[8] = 0; self->w40[9] = 0; self->w40[10] = 0; self->w40[11] = 0;
    self->w40[12] = 0; self->w40[13] = 0;
    self->w1c = 0;
    self->flag_08 = 0;
    ts4_vec204_move_tail_881B9148(self->sub_10);
}

/* Finalize the sub-object at +0x20, clear state and reset the sub-object at +0x10. */
struct Ga6Cleared20 {
    char pad_00[8];
    unsigned char flag_08;
    char pad_09[7];
    char sub_10[0x0C];
    ts4_word w1c;
    char sub_20[4];
};
void ga6_reset_state_886E7F78(struct Ga6Cleared20 *self)
{
    self->w1c = 0;
    ts4_object_finalize(self->sub_20);
    self->flag_08 = 0;
    ts4_vec204_move_tail_881B9148(self->sub_10);
}

/* Constructor: store the id at +4, init the +8 object and two 0x10-byte blocks at +0x14 and +0x20. */
struct Ga6Triple {
    char pad_00[4];
    ts4_word id;
    char sub_08[0xC];
    char sub_14[0xC];
    char sub_20[0xC];
};
void ga6_init_triple_886CEF20(struct Ga6Triple *self, ts4_word id)
{
    self->id = id;
    ts4_vector24_reserve_10_882660C0(self->sub_08);
    fn_88264F28(self->sub_14, 0x10);
    fn_88264F28(self->sub_20, 0x10);
}
