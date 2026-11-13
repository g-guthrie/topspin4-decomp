/*
 * R2 (gameplay core): destructors of the swing module family.
 */
extern char lbl_880F4478[];
extern char lbl_880F45D0[];
extern char lbl_880F43A4[];

struct R2DtorHost {
    void **vtbl;                      /* +0x00 */
    unsigned char pad04[0x24 - 4];
    void ***owned_object;             /* +0x24, object with virtual scalar-delete at slot 0 */
};

void ts4_destroy_owned_object(void *object);
void fn_8890F1E8(void *member);
void ts4_if_call_seq_lbl_880F4608_886954F8(void *member);
void fn_88617D28(void *self);

/* Swing_DLL.xex 0x886985B0: destroy module: delete owned object (+0x24), owned buffer (+0x590), 17 embedded members, base parts. */
void ts4_r2_module_destroy_886985B0(struct R2DtorHost *self)
{
    void ***owned;
    self->vtbl = (void **)lbl_880F4478;
    owned = self->owned_object;
    if (owned != 0) {
        ((void (*)(void *, int))(*owned)[0])(owned, 1);
    }
    if (*(void **)((char *)self + 0x590) != 0) {
        ts4_destroy_owned_object(*(void **)((char *)self + 0x590));
    }
    fn_8890F1E8((char *)self + 0x548);
    fn_8890F1E8((char *)self + 0x504);
    fn_8890F1E8((char *)self + 0x4c0);
    fn_8890F1E8((char *)self + 0x47c);
    fn_8890F1E8((char *)self + 0x438);
    fn_8890F1E8((char *)self + 0x3f4);
    fn_8890F1E8((char *)self + 0x3b0);
    fn_8890F1E8((char *)self + 0x36c);
    fn_8890F1E8((char *)self + 0x328);
    fn_8890F1E8((char *)self + 0x2e4);
    fn_8890F1E8((char *)self + 0x2a0);
    fn_8890F1E8((char *)self + 0x25c);
    fn_8890F1E8((char *)self + 0x218);
    fn_8890F1E8((char *)self + 0x1d4);
    fn_8890F1E8((char *)self + 0x190);
    fn_8890F1E8((char *)self + 0x14c);
    fn_8890F1E8((char *)self + 0x108);
    *(void **)((char *)self + 0xf4) = lbl_880F45D0;
    ts4_if_call_seq_lbl_880F4608_886954F8((char *)self + 0x48);
    self->vtbl = (void **)lbl_880F43A4;
    fn_88617D28(self);
}


struct R2ResetHost;

struct R2PtrNode {                    /* object with virtual scalar-delete at vtable slot 0 */
    void **vtbl;
    unsigned char pad04[0x18 - 4];
    unsigned int  field_18;           /* +0x18 */
    unsigned int  field_1c;           /* +0x1c */
};

struct R2EmbeddedVirtual {            /* embedded object whose vtable slot 3 is a reset hook */
    void **vtbl;
};

struct R2ResetHost {
    unsigned char pad00[8];
    unsigned char flag_08;            /* +0x08 */
    unsigned char pad09[7];
    unsigned char list_10[0xc];       /* +0x10 list header cleared by fn_881B9148 */
    unsigned int  zero_1c;            /* +0x1c */
    unsigned int  zero_20;            /* +0x20 */
    void *child_24;                   /* +0x24 */
    unsigned int  zero_28;
    unsigned int  zero_2c;            /* +0x2c */
    unsigned int  zero_30;            /* +0x30 */
    unsigned char pad34[0x48 - 0x34];
    struct R2EmbeddedVirtual hook_48; /* +0x48 */
    unsigned char pad4c[0xf4 - 0x4c];
    struct R2EmbeddedVirtual hook_f4; /* +0xf4 */
    unsigned char padf8[0x100 - 0xf8];
    struct R2PtrNode *node_100;       /* +0x100 */
    struct R2PtrNode *node_104;       /* +0x104 */
};

void fn_886CF110(struct R2PtrNode *node);
void fn_88678A10(void *child);
void fn_8890DDA8(void *member);
void fn_881B9148(void *list);

/* Swing_DLL.xex 0x886A2378: reset brain: clear and delete the two owned nodes, run embedded reset hooks, reset 17 members and state. */
void ts4_r2_swing_brain_reset_886A2378(struct R2ResetHost *self)
{
    struct R2PtrNode *node = self->node_104;
    fn_886CF110(node);
    node->field_1c = 0;
    node->field_18 = 0;
    if (self->node_104 != 0) {
        ((void (*)(void *, int))self->node_104->vtbl[0])(self->node_104, 1);
    }
    self->node_104 = 0;
    node = self->node_100;
    fn_886CF110(node);
    node->field_1c = 0;
    node->field_18 = 0;
    if (self->node_100 != 0) {
        ((void (*)(void *, int))self->node_100->vtbl[0])(self->node_100, 1);
    }
    self->node_100 = 0;
    ((void (*)(void *))self->hook_f4.vtbl[3])(&self->hook_f4);
    ((void (*)(void *))self->hook_48.vtbl[3])(&self->hook_48);
    fn_88678A10(self->child_24);
    self->zero_30 = 0;
    self->zero_2c = 0;
    fn_8890DDA8((char *)self + 0x548);
    fn_8890DDA8((char *)self + 0x504);
    fn_8890DDA8((char *)self + 0x4c0);
    fn_8890DDA8((char *)self + 0x47c);
    fn_8890DDA8((char *)self + 0x438);
    fn_8890DDA8((char *)self + 0x328);
    fn_8890DDA8((char *)self + 0x36c);
    fn_8890DDA8((char *)self + 0x3f4);
    fn_8890DDA8((char *)self + 0x3b0);
    fn_8890DDA8((char *)self + 0x2e4);
    fn_8890DDA8((char *)self + 0x2a0);
    fn_8890DDA8((char *)self + 0x25c);
    fn_8890DDA8((char *)self + 0x108);
    fn_8890DDA8((char *)self + 0x14c);
    fn_8890DDA8((char *)self + 0x190);
    fn_8890DDA8((char *)self + 0x1d4);
    fn_8890DDA8((char *)self + 0x218);
    self->zero_20 = 0;
    self->flag_08 = 0;
    fn_881B9148(self->list_10);
    self->zero_1c = 0;
}
