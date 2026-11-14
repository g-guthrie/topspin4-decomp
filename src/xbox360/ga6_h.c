/*
 * GA6: gameplay manager loops, singleton constructor and vector blend.
 */
#include "ts4_vector.h"

typedef unsigned int ts4_word;

struct Ga6Node { int type; };

struct Ga6Node *ts4_find_by_id_886C3DC0(void *owner, ts4_word id);
void ts4_tailcall_fn_88584548_8857AFE8(int arg);
void fn_886D2E78(void *self);
void fn_886D7C28(void *a, ts4_word b);
void ga6_wait_loop_886D7970(void *a);
void fn_886DADB8(void *self);
void ts4_clear_rec8c_values_886C50D0(void *self);

/* Repeat (at most 1000 times) while the node with id is of type 4: run the idle hook and step the owner. */
void ga6_run_while_type4_886D7A60(void *self, ts4_word id)
{
    int i;
    for (i = 0; i < 1000; i++) {
        struct Ga6Node *node = ts4_find_by_id_886C3DC0(self, id);
        unsigned char is_type4 = 0;
        if (node && node->type == 4)
            is_type4 = 1;
        if (!is_type4)
            break;
        ts4_tailcall_fn_88584548_8857AFE8(1);
        fn_886D2E78(self);
    }
}

struct Ga6Task { char pad_00[0x44]; unsigned char busy; };
struct Ga6TaskInfo { char pad_00[0x40]; struct Ga6Task *task; char pad_44[4]; ts4_word w48; };
struct Ga6TaskOwner { char pad_00[0x10]; struct Ga6TaskInfo *info; };

/* Advance the owner's task by 0x1F4 ticks; then hand the task to the busy or idle path. */
void ga6_step_task_886D9000(struct Ga6TaskOwner *self)
{
    fn_886D7C28(self->info->task, self->info->w48 + 0x1F4);
    if (self->info->task->busy)
        ga6_wait_loop_886D7970(self->info->task);
    else
        fn_886D2E78(self->info->task);
}

struct Ga6Flags { unsigned char active, pending; };
struct Ga6Subsys { char pad_00[0x480]; struct Ga6Flags flags; };
struct Ga6Sys { char pad_00[0x14]; struct Ga6Subsys *sub; };

/* If the subsystem is active: run its update, flush when pending, and clear both flags. */
void ga6_flush_subsystem_886DAF38(struct Ga6Sys *self)
{
    struct Ga6Flags *flags = &self->sub->flags;
    if (flags->active) {
        fn_886DADB8(self);
        if (flags->pending)
            ts4_clear_rec8c_values_886C50D0(self);
        flags->active = 0;
        flags->pending = 0;
    }
}

/* Blend each 64-byte matrix's first row toward its second: row0' = lerp(row0, row1, t) + offset; row1 = old row0. */
struct Ga6Blend {
    __vector4 offset;          /* +0x00 */
    __vector4 t;               /* +0x10 */
    char pad_20[0x20];
    char *rows;                /* +0x40 */
    ts4_word count;            /* +0x44 */
};
