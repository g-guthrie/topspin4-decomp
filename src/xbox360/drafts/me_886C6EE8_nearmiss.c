/* 886C6EE8 near-miss: 37 off (size 0x98 vs 0xa0). Target loads keys_end before keys_begin, clrrwi on track ptr, zero from g_ts4_event_value. */
/* Swing_DLL.xex 0x886C6EE8: keep the playback cursor in range: a negative time restarts at 0, a time past the
   last key is pulled back by 30 (not below 0); the rate is reset to 1 in both cases. */
typedef unsigned char ts4_u8;
extern const float g_ts4_script_constants[];
struct Ts4PbKey { ts4_u8 pad_00[0x28]; float time; };
struct Ts4PbTrack {
    ts4_u8 pad_00[0x14]; float rate; float time; ts4_u8 pad_1c[0x40]; struct Ts4PbKey **keys_begin; struct Ts4PbKey **keys_end;
};
struct Ts4PbSelf { ts4_u8 pad_00[0x20]; struct Ts4PbTrack *track; };

static const float kZero = 0.0f;
static __inline float pb_max(float a, float b) { return (a - b >= kZero) ? a : b; }

void ts4_playback_clamp_886C6EE8(struct Ts4PbSelf *self)
{
    struct Ts4PbTrack *t = self->track;
    float v;
    if (t->keys_end == t->keys_begin)
        return;
    v = t->time;
    if (!(v >= kZero)) {
        t->time = kZero;
        t->rate = g_ts4_script_constants[0];
        return;
    }
    if (t->keys_end[-1]->time < v) {
        struct Ts4PbTrack *t2 = self->track;
        t2->time = pb_max(kZero, v - 30.0f);
        t2->rate = g_ts4_script_constants[0];
    }
}
