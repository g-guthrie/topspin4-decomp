/*
 * GA6: gameplay wait loops, scene refresh and vector-initialised object constructors.
 */
#include "ts4_vector.h"

typedef unsigned int ts4_word;

struct Ga6Node { int type; };
struct Ga6Node *ts4_find_by_id_886C3DC0(void *owner, ts4_word id);
void ts4_tailcall_fn_88584548_8857AFE8(int arg);
void fn_886D2E78(void *self);
void fn_8890D918(void *obj);
void fn_886C9400(void *obj);
void fn_886E3B28(void *self);
void fn_88617D88(void *self);

static unsigned char ga6_node_is_type_0_1_or_2(void *owner, ts4_word id)
{
    volatile struct Ga6Node *node = ts4_find_by_id_886C3DC0(owner, id);
    unsigned char ok = 0;
    if (node) {
        if (node->type == 0 || node->type == 1 || node->type == 2)
            ok = 1;
    }
    return ok;
}

/* Repeat (at most 1000 times) while the node with id has type 0, 1 or 2: run the idle hook and step the owner. */
void ga6_run_while_type012_886D79D8(void *self, ts4_word id)
{
    int i;
    for (i = 0; i < 1000; i++) {
        if (!ga6_node_is_type_0_1_or_2(self, id))
            break;
        ts4_tailcall_fn_88584548_8857AFE8(1);
        fn_886D2E78(self);
    }
}

struct Ga6RefreshFlags { char pad_00[0x1C]; unsigned char flag_1c, flag_1d, flag_1e; };
struct Ga6RefreshOwner { char pad_00[0x10]; struct { char pad[0x48]; struct Ga6RefreshFlags *flags; } *info; };
struct Ga6Refresh {
    struct Ga6RefreshOwner *owner; /* +0x00 */
    char pad_04[4];
    void *sub;                 /* +0x08 */
    char pad_0c[0x14];
    void *target;              /* +0x20 */
};
/* Run the optional refresh steps selected by the owner's flag block. */
void ga6_refresh_target_886E4240(struct Ga6Refresh *self)
{
    struct Ga6RefreshFlags *flags;
    if (self->target) {
        flags = self->owner->info->flags;
        if (flags->flag_1c)
            fn_8890D918(self->target);
        if (flags->flag_1d)
            fn_886C9400(self->sub);
        if (flags->flag_1e) {
            fn_8890D918(self->target);
            fn_886E3B28(self);
        }
    }
}

extern char lbl_880F34BC[];   /* vtable */
extern char lbl_880FC770[];
extern char lbl_880FC760[];
