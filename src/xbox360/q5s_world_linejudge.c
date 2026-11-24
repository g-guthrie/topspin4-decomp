/*
 * 0x8888AB30 (pres): line-judge / net-sensor call sound. When the sound component is enabled, plays
 *   - "Root/Sensor/Beep" at 1.0 for a net-cord (flags +0x95, +0x161, +0x1CA, +0x1CE set and +0x1C8 clear),
 *   - "Root/LineJudge/Fault" at tune+0x4CC for a fault call (+0x95, +0x161, +0x1CA set, +0x1D2 clear),
 *   - "Root/LineJudge/Out" at tune+0x4D0 when +0x95 is clear, +0xCD is set, the state hash at +0xD0 is
 *     0x5E11F1A7 and +0x1D2 is clear,
 * each through the event wrapper 8888A658 (cx32_game_b.c) with sound bank hash 0x84A3ED71.
 * LTCG route. Codegen notes: the hash is a one-member struct by value (lis r4 is scheduled before the string
 * address); the +0x161 flag is read once into a u8 local (it is loaded with +0x95 and re-tested with clrlwi);
 * the out branch re-reads the match pointer, which only a volatile read of the member reproduces.
 */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Ts4WorldCallFlags {
    char pad_000[0x95];
    u8 rally_live;                               /* +0x095 V 8888AB30 */
    char pad_096[0xCD - 0x96];
    u8 out_pending;                              /* +0x0CD V 8888AB30 */
    char pad_0ce[2];
    u32 state_hash;                              /* +0x0D0 V 8888AB30 */
    char pad_0d4[0x161 - 0xD4];
    u8 b161;                                     /* +0x161 V 8888AB30 */
    char pad_162[0x1C8 - 0x162];
    u8 b1c8;                                     /* +0x1C8 V 8888AB30 */
    u8 pad_1c9;
    u8 b1ca;                                     /* +0x1CA V 8888AB30 */
    u8 pad_1cb[3];
    u8 b1ce;                                     /* +0x1CE V 8888AB30 */
    u8 pad_1cf[3];
    u8 muted;                                    /* +0x1D2 V 8888AB30 */
} Ts4WorldCallFlags;

typedef struct Ts4WorldCallTune {
    char pad_000[0x4CC];
    float fault_volume;                          /* +0x4CC V 8888AB30 */
    float out_volume;                            /* +0x4D0 V 8888AB30 */
} Ts4WorldCallTune;

typedef struct Ts4WorldCallState {
    char pad_00[0x7E];
    u8 enabled;                                  /* +0x7E V 8888AB30 */
} Ts4WorldCallState;

typedef struct Ts4WorldCallSound {
    void **vt;
    char pad_04[0x24];
    Ts4WorldCallTune *tune;                      /* +0x28 V 8888AB30 */
    char pad_2c[4];
    Ts4WorldCallFlags *flags;                    /* +0x30 V 8888AB30 */
    char pad_34[0x6C - 0x34];
    Ts4WorldCallState *state;                    /* +0x6C V 8888AB30 */
} Ts4WorldCallSound;

typedef struct Ts4WorldSoundId {
    u32 value;
} Ts4WorldSoundId;

extern const char lbl_880DD8EC[]; /* "Root/Sensor/Beep" */
extern const char lbl_880DD900[]; /* "Root/LineJudge/Fault" */
extern const char lbl_880DD918[]; /* "Root/LineJudge/Out" */
void ts4_vcall_13_10_11_15_8888A658(Ts4WorldCallSound *o, Ts4WorldSoundId id, const char *name, float volume);

static Ts4WorldSoundId world_sound_id(u32 v)
{
    Ts4WorldSoundId r;
    r.value = v;
    return r;
}

void ts4_pres_linejudge_call_8888AB30(Ts4WorldCallSound *s)
{
    Ts4WorldCallFlags *m;
    u8 b161;
    if (!s->state->enabled)
        return;
    m = s->flags;
    b161 = m->b161;
    if (m->rally_live) {
        if (b161 && m->b1ca && m->b1ce && !m->b1c8) {
            ts4_vcall_13_10_11_15_8888A658(s, world_sound_id(0x84A3ED71), lbl_880DD8EC, 1.0f);
            return;
        }
        if (b161 && m->b1ca && !m->muted)
            ts4_vcall_13_10_11_15_8888A658(s, world_sound_id(0x84A3ED71), lbl_880DD900, s->tune->fault_volume);
    } else {
        Ts4WorldCallFlags *g = *(Ts4WorldCallFlags *volatile *)&s->flags;
        if (g->out_pending && g->state_hash == 0x5E11F1A7 && !m->muted)
            ts4_vcall_13_10_11_15_8888A658(s, world_sound_id(0x84A3ED71), lbl_880DD918, s->tune->out_volume);
    }
}
