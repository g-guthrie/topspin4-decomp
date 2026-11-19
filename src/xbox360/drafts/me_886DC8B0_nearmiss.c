/* 0x886DC8B0 near miss (61 off, /Oc plain; logic complete, body shifted by one instruction). Takes a clip message:
 * binds the clip slot (fn_886DBF40), forwards it (ts4_on_clip_message_886C71C8), runs fn_886CB078 + the
 * 0x2DB2D90F track resample when sync flags are set, copies pose to prev_pose, stamps the message serial.
 * Residue: the game reads the slot data through the addi slot pointer (lwz r4,0(r3)); we fold it to lwz 4(r11),
 * which shifts the first call setup. restrict slot / accessor / arg locals: no change. */
#include "vx1_vector.h"
typedef struct Ts4ClipInfo { char p[0x60]; unsigned type; } Ts4ClipInfo;
typedef struct Ts4Clip { char p[8]; Ts4ClipInfo *info; } Ts4Clip;
typedef struct Ts4ClipSlot { void *data; } Ts4ClipSlot;
typedef struct Ts4ClipHolder { char p[4]; Ts4ClipSlot slot; Ts4ClipInfo *info; } Ts4ClipHolder;
typedef struct Ts4Msg { char p[4]; Ts4ClipHolder *holder; char p2[0x78 - 8]; int serial; } Ts4Msg;
typedef struct Ts4Flags3 { char p[0x14]; unsigned char a; char p2[5]; unsigned char b; } Ts4Flags3;
typedef struct Ts4Opt { char p[0x48]; Ts4Flags3 *flags; } Ts4Opt;
typedef struct Ts4Scene { char p[0x40]; void *root; } Ts4Scene;
typedef struct Ts4Opts { char p[0x10]; Ts4Scene *scene; char p2[0x48 - 0x14]; Ts4Flags3 *flags; } Ts4Opts;
typedef struct Ts4State { char p[0x55]; unsigned char sync; char p2[0x90 - 0x56]; __vector4 pose; __vector4 prev_pose; char p3[0x250 - 0xb0]; char track[4]; } Ts4State;
typedef struct Ts4Anim { char p[0x10]; Ts4Opts *opts; Ts4State *state; char p2[0x28c - 0x18]; int frame; char p3[0x460 - 0x290]; char sampler[4]; } Ts4Anim;
typedef struct Ts4Graph { char p[0xc]; char *nodes; } Ts4Graph;
typedef struct Ts4Player { char p[0x20]; Ts4Anim *anim; char p2[4]; Ts4Graph *graph; char p3[0x114 - 0x2c]; int serial; } Ts4Player;
void fn_886DBF40(Ts4ClipSlot *slot, void *data, char *nodes, void *root, int flag, int frame);
void ts4_on_clip_message_886C71C8(Ts4ClipSlot *slot, Ts4Anim *anim);
void fn_886CB078(Ts4Player *self, Ts4Msg *m);
void fn_886D05D8(void *sampler, void *track);
static __inline void *slot_data(Ts4ClipSlot *s) { return s->data; }
void ts4_player_take_msg(Ts4Player *self, Ts4Msg *m)
{
    Ts4Anim *a;
    {
    Ts4ClipSlot *__restrict slot = &m->holder->slot;
    fn_886DBF40(slot, slot_data(slot), self->graph->nodes + 0x60, self->anim->opts->scene->root, 1, self->anim->frame);
    }
    ts4_on_clip_message_886C71C8(&m->holder->slot, self->anim);
    a = self->anim;
    if (a->state->sync && a->opts->flags->a && a->opts->flags->b) {
        fn_886CB078(self, m);
        if (m->holder->info->type == 0x2DB2D90Fu)
            fn_886D05D8(self->anim->sampler, self->anim->state->track);
    }
    self->anim->state->prev_pose = self->anim->state->pose;
    m->serial = self->serial;
    self->serial++;
}
