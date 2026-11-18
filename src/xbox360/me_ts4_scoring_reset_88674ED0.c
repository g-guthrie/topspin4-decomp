/* Swing_DLL.xex 0x88674ED0: reset the per-point scoring state: clear the score entries, mark the server side,
   and snapshot every player's local position into the self table. */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
#include "ts4_vector.h"

extern const float g_ts4_event_value;   /* 0.0f */

struct Ts4SrEntry { ts4_u8 pad_000[0xF80]; float f80; float f84; float f88; ts4_u8 pad_f8c[0x1070 - 0xF8C]; };
struct Ts4SrList { int offset; int count; };
struct Ts4SrPS { ts4_u8 pad_000[0x8E0]; __vector4 local_position; ts4_u8 pad_8f0[0xF88 - 0x8F0]; float serve_flag; };
struct Ts4SrPC { ts4_u8 pad_00[0x14]; int slot; ts4_u8 pad_18[0x5C]; struct Ts4SrPS *state; };
struct Ts4SrMembers { struct Ts4SrPC *pc[2]; };
struct Ts4SrTeam { ts4_u8 pad_00[0x10]; struct Ts4SrMembers *members; ts4_u8 pad_14[0x18]; int size; };
struct Ts4SrMode { int kind; };
struct Ts4SrMatch {
    ts4_u8 pad_00[0x4]; struct Ts4SrPC **pc_begin; struct Ts4SrPC **pc_end; ts4_u8 pad_0c[4];
    struct Ts4SrTeam **teams; ts4_u8 pad_14[0x64]; struct Ts4SrMode *mode;
};
struct Ts4SrRel { int offset; };
struct Ts4SrServe { ts4_u8 pad_00[0xC]; int server; ts4_u8 pad_10[0x14]; int receiver; };
struct Ts4SrHolder { ts4_u8 pad_00[0xB4]; struct Ts4SrRel serve; };
struct Ts4SrFlags { ts4_u8 pad_000[0x74A]; ts4_u8 flag_74a; };
struct Ts4SrSelf {
    ts4_u8 pad_000[0x20]; struct Ts4SrHolder *holder; ts4_u8 pad_024[0x8]; struct Ts4SrList *entries;
    ts4_u8 pad_030[0x4]; struct Ts4SrMatch *match; struct Ts4SrFlags *flags; ts4_u8 pad_03c[0x320 - 0x3C];
    __vector4 positions[5]; ts4_u8 pad_370[0x8]; ts4_u32 counter; ts4_u8 pad_37c; ts4_u8 flag_37d; ts4_u8 pad_37e; ts4_u8 flag_37f;
};

static struct Ts4SrEntry *sr_begin(struct Ts4SrList *l)
{
    struct Ts4SrEntry *r = 0;
    if (l->offset != -1)
        r = (struct Ts4SrEntry *)((ts4_u8 *)l + l->offset);
    return r;
}
static struct Ts4SrEntry *sr_end(struct Ts4SrList *l)
{
    struct Ts4SrEntry *r = 0;
    if (l->offset != -1)
        r = (struct Ts4SrEntry *)((ts4_u8 *)l + l->offset + l->count * 0x1070);
    return r;
}

void ts4_scoring_reset_88674ED0(struct Ts4SrSelf *self)
{
    struct Ts4SrMatch *m;
    struct Ts4SrPC **it;
    self->flags->flag_74a = 0;
    m = self->match;
    self->counter = 0;
    self->flag_37d = 1;
    self->flag_37f = 0;
    if (m->mode->kind == 1) {
        struct Ts4SrEntry *end = sr_end(self->entries);
        struct Ts4SrEntry *e;
        for (e = sr_begin(self->entries); e != end; e++) {
            e->f80 = g_ts4_event_value;
            e->f84 = g_ts4_event_value;
            e->f88 = g_ts4_event_value;
        }
    } else {
        struct Ts4SrRel *rel = &self->holder->serve;
        struct Ts4SrServe *sv = (struct Ts4SrServe *)((ts4_u8 *)rel + rel->offset);
        if (sv->server != sv->receiver) {
            int i = sv->server < sv->receiver;
            m->teams[i]->members->pc[0]->state->serve_flag = 1.0f;
            self->match->teams[1 - i]->members->pc[0]->state->serve_flag = g_ts4_event_value;
            if (self->match->teams[i]->size == 2) {
                self->match->teams[i]->members->pc[1]->state->serve_flag = 1.0f;
                self->match->teams[1 - i]->members->pc[1]->state->serve_flag = g_ts4_event_value;
            }
        }
        {
            struct Ts4SrEntry *end = sr_end(self->entries);
            struct Ts4SrEntry *e;
            for (e = sr_begin(self->entries); e != end; e++)
                e->f84 = g_ts4_event_value;
        }
    }
    {
    struct Ts4SrPC **end;
    m = self->match;
    it = m->pc_begin;
    end = m->pc_end;
    for (; it != end; it++) {
        struct Ts4SrPC *pc = *it;
        if (pc)
            *(__vector4 *)((ts4_u8 *)self + (pc->slot + 0x32) * 16) = pc->state->local_position;
    }
    }
}
