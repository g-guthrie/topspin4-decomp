/* near miss 0x886AA280: 0 instruction diffs; fails only on the 23 unrelocated jump-table entries (not accepted). */
/* 0x886AA280: reaction controller event handler (23-case switch): copies the target range into the
   current range, resets the swing-anim state (hash 0x9E51242B), sets the body's override value, refreshes
   the reaction target height (stores it when it moved by at least 0.4), or resets the ranges to the event value.
   LTCG route: every instruction and every jump-table entry agree with the target; fn_check_ltcg reports
   "local label differs" for the 23 table entries only because the target side has no relocations for the
   embedded table (candidate entries resolve to the same function offsets as the target words). */
typedef unsigned char U8;
extern double fabs(double);
#pragma intrinsic(fabs)
typedef struct Sub { char p[0x5c]; unsigned int state_hash; } Sub;
typedef struct Anim { char p[0x14]; Sub *sub; char p18[0x70 - 0x18]; U8 f70; U8 f71; } Anim;
typedef struct Pose { char p[0x1a4]; float height; char p1a8[0x34c - 0x1a8]; char target[4]; } Pose;
typedef struct Range { float lo, hi; } Range;
typedef struct Body { char p[0x8e0]; char path[0x9d4 - 0x8e0]; float f9d4; Range cur; char p9e0[0x9e8 - 0x9e0]; Range target;
    char p9f0[0xde8 - 0x9f0]; float override_value; U8 has_override; } Body;
typedef struct SwingAnim SwingAnim;
typedef struct Player { char p[0x2c]; Pose *pose; char p30[0x5c - 0x30]; Anim *anim; SwingAnim *swing_anim; char p64[0x74 - 0x64]; Body *body; } Player;
typedef struct React { char p[0x130]; Range range; char p138[0x140 - 0x138]; float last_target; char p144[0x154 - 0x144]; Player *player; } React;
extern float g_ts4_script_constants[];
extern float g_ts4_event_value;
void ts4_refresh_reaction_target_886A3868(React *r);
float ts4_anim_busy_frames_886CD3C8(SwingAnim *self);
void fn_8869C010(Anim *a);
void fn_8866BDD8(React *r, void *path);
float fn_886887C0(React *r, void *target, float t);
unsigned char fn_8866C150(React *r);
void fn_88688678(React *r);
static __inline void sync(Body *b) { Range *d = &b->cur; *d = b->target; }
static __inline void reset_anim(React *self)
{
    Anim *a = self->player->anim;
    a->f70 = 0;
    a->sub->state_hash = 0x9E51242B;
    a->f71 = 0;
    fn_8869C010(self->player->anim);
}
void ts4_reaction_event_886AA280(React *self, unsigned int ev)
{
    switch (ev) {
    case 0: case 15:
        sync(self->player->body);
        break;
    case 1:
        ts4_refresh_reaction_target_886A3868(self);
        reset_anim(self);
        sync(self->player->body);
        break;
    case 2: {
        reset_anim(self);
        self->player->body->has_override = 1;
        self->player->body->override_value = g_ts4_script_constants[0];
        self->range = self->player->body->cur;
        break;
    }
    case 3: case 12:
        fn_8866BDD8(self, self->player->body->path);
        break;
    case 6: {
        Player *p = self->player;
        float busy = ts4_anim_busy_frames_886CD3C8(p->swing_anim);
        float t = fn_886887C0(self, p->pose->target, p->pose->height + busy);
        float d = (float)fabs(self->last_target - t) - g_ts4_script_constants[70];
        if (!(*(unsigned short *)&d & 0x8000)) {
            self->player->body->has_override = 1;
            self->player->body->override_value = t;
            self->last_target = t;
        }
        break;
    }
    case 21: case 22:
        if (fn_8866C150(self))
            fn_88688678(self);
        break;
    case 8:
        self->player->body->target.hi = g_ts4_event_value;
        self->player->body->cur.hi = g_ts4_event_value;
        self->player->body->f9d4 = g_ts4_event_value;
        self->player->body->has_override = 1;
        self->player->body->override_value = g_ts4_event_value;
        break;
    case 7:
        self->player->body->has_override = 1;
        self->player->body->override_value = 1.0f;
        break;
    case 9: case 17: case 18:
        self->player->body->target.hi = g_ts4_event_value;
        self->player->body->cur.hi = g_ts4_event_value;
        self->player->body->f9d4 = g_ts4_event_value;
        break;
    }
}
