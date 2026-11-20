/* rough draft 0x886B2638 (ME agent B): 223 off (/Oc). PARTIAL: covers the start/resume block, the range lookup and
 * the clamp; missing the slot-hash selection by |lean| (0.2/0.6 thresholds, hashes 20E63862/CCB6E1AC/7A6A58AF/466A207E),
 * the 8-qword scheme copy into body+0x4f8, fn_886B0490 and the final fn_886A16D8 call. The clamp is an FP1 fsel
 * select (table g_ts4_script_constants[26]). */
typedef unsigned char U8;
typedef unsigned int U32;
extern double fabs(double);
#pragma intrinsic(fabs)
extern float g_ts4_script_constants[];
extern float g_ts4_event_value;
typedef struct Phase { char p[0x310]; int phase; } Phase;
typedef struct Rules { char p[0x17c]; float progress; } Rules;
typedef struct Slot { char p[0xbc]; U32 anim_hash; float lean; char pc4[0x140 - 0xc4]; } Slot;
typedef struct Slots { char p[0x104]; int slots_rel; } Slots;
typedef struct Scheme { char p[0x20]; struct SchemeData *data; } Scheme;
typedef struct SchemeData { char p[0x4e8]; __int64 words[8]; } SchemeData;
typedef struct Player { char p[0x30]; Phase *match; char p34[0x44 - 0x34]; void *rules; char p48[0x5c - 0x48]; Scheme *scheme; char p60[0x6c - 0x60]; void *sink; } Player;
typedef struct Body { char p[0x49c]; float aim[3]; char p4a8[0x4f0 - 0x4a8]; __int64 scheme_words[8]; char p530[0x544 - 0x530]; float progress; char p548[0x66c - 0x548];
    float lean; float blend; float target[3]; char p67c[0xfbc - 0x67c]; U8 dirty; } Body;
typedef struct Team { char p[0x28]; int side; } Team;
typedef struct Owner { char p[0x10]; U8 has_track; char p11[3]; int slot_index; char p18[0x2c - 0x18]; char *lookup_base; U32 state_hash; char p34[0x44 - 0x34]; Player *ctl_unused;
    Player *player; Team *team; char p50[0x74 - 0x50]; Body *body; char *range_base; char p7c[0x88 - 0x7c]; struct { char p[0xa4]; U8 frozen; } *cfg; } Owner;
typedef struct Self { char p[0x1c]; Owner *owner; int *base_tick; int f24; int max_ticks; char p2c[0x30 - 0x2c]; int start; int now; struct { char p[0x38]; U8 off; } *sel; U8 started; U8 resumed; } Self;
U32 ts4_if_get_u32_off38_8865AD50(Self *s);
void *fn_8826C388(char *tbl, U32 *key);
float ts4_range_lookup_881899D8(float t, void *rec);
void fn_886723A8(Self *s, float v);
void fn_886B0490(Owner *o);
void fn_886A16D8(void *sink, Owner *o, int on);
void fn_886B2638(Self *self)
{
    Owner *o = self->owner;
    Player *pl;
    float one;
    if (o->cfg->frozen || self->started)
        return;
    self->started = 1;
    pl = o->player;
    one = g_ts4_script_constants[0];
    if (self->resumed) {
        o->body->target[0] = o->body->aim[0];
        self->owner->body->target[1] = self->owner->body->aim[1];
        self->owner->body->target[2] = self->owner->body->aim[2];
        self->owner->body->lean = one;
    }
    if (self->owner->has_track) {
        U8 up = !self->sel->off;
        int ticks;
        void *rec;
        float lean, t, c, blend;
        int span, lim;
        ts4_if_get_u32_off38_8865AD50(self);
        ticks = self->owner->player->match->phase + *self->base_tick - self->now;
        rec = fn_8826C388(self->owner->lookup_base + 0x60c, (U32 *)(self->owner->range_base + 0x478));
        if (!rec) {
            U32 key = 0x2CE33943;
            rec = fn_8826C388(self->owner->lookup_base + 0x60c, &key);
        }
        lean = rec ? ts4_range_lookup_881899D8((float)ticks, rec) : one;
        span = self->now - self->start;
        if (span < 0) span = 0;
        lim = self->max_ticks;
        if (span < lim) lim = span; else lim = lim;
        t = (float)span / (float)self->max_ticks;
        c = t < g_ts4_event_value ? g_ts4_event_value : t;
        blend = c - one > g_ts4_event_value ? one : c;
        if (up) one = lean;
        self->owner->player->rules ? (void)0 : (void)0;
        ((Rules *)self->owner->player->rules)->progress = one;
        self->owner->body->progress = one;
        self->owner->body->lean = lean;
        self->owner->body->blend = blend;
        fn_886723A8(self, self->owner->body->blend);
    }
}
