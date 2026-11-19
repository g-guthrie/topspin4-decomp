/* 0x886D08F8 near miss (14 off, plain or LTCG): when sync is enabled and not muted, for every track of clip type
 * 0x490B9918 whose target moved more than script constant [97] and was last sent more than 3 frames ago, records
 * the sent value/frame and queues it (ts4_apply_886CC318). Residue: the eps load (f31) is hoisted above the size
 * check (game loads it after) and the lwzx operand order; a size guard block gives srawi. instead (50 off). */
double fabs(double);
#pragma intrinsic(fabs)
extern const float g_ts4_script_constants[];
typedef struct Ts4ClipInfo { char p[0x80]; unsigned type; } Ts4ClipInfo;
typedef struct Ts4ClipRef { char p[8]; Ts4ClipInfo *info; } Ts4ClipRef;
typedef struct Ts4Track { char p[4]; Ts4ClipRef *clip; char p2[0x4c - 8]; float target; char p3[0x70 - 0x50]; float sent; int sent_frame; } Ts4Track;
typedef struct Ts4Clock { char p[0x3fc]; int frame; } Ts4Clock;
typedef struct Ts4Opts { char p[0x1c]; unsigned char enabled; unsigned char muted; } Ts4Opts;
typedef struct Ts4Cfg { char p[0x34]; Ts4Opts *opts; } Ts4Cfg;
typedef struct Ts4Ctx { char p[0x10]; Ts4Cfg *cfg; Ts4Clock *clock; } Ts4Ctx;
typedef struct Ts4TrackVec { Ts4Track **begin; Ts4Track **end; } Ts4TrackVec;
typedef struct Ts4Sync { char p[0x20]; Ts4Ctx *ctx; char p2[0x5c - 0x24]; Ts4TrackVec tracks; char p3[0xa0 - 0x64]; char queue[4]; } Ts4Sync;
void fn_886CC318(void *queue, Ts4Track *t);
static __inline unsigned char sync_enabled(Ts4Sync *s) { Ts4Opts *o = s->ctx->cfg->opts; return o->enabled && !o->muted; }
static __inline int vec_size(Ts4TrackVec *v) { return (int)(v->end - v->begin); }
static __inline Ts4Track *vec_at(Ts4TrackVec *v, int i) { return v->begin[i]; }
void ts4_sync_send_changed(Ts4Sync *s)
{
    int i;
    float eps;
    if (!sync_enabled(s)) return;
    eps = g_ts4_script_constants[97];
    for (i = 0; i < vec_size(&s->tracks); i++) {
        Ts4Track *t = vec_at(&s->tracks, i);
        if (t->clip->info->type == 0x490B9918u) {
            float v = t->target;
            if ((float)fabs(t->sent - v) > eps && s->ctx->clock->frame - t->sent_frame > 3) {
                t->sent = v;
                t->sent_frame = s->ctx->clock->frame;
                fn_886CC318(s->queue, t);
            }
        }
    }
}
