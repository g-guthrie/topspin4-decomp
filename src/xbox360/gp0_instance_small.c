#include "gp0_types.h"

/* Swing_DLL.xex float constant 0.0f used by the gameplay code. */
extern float lbl_8814B440;

struct Gp0PlayerState {
    gp0_u8 u_0000[0x430];
    float shot_float_430;
    float shot_float_434;
    gp0_u8 u_0438[8];
    float shot_float_440;
    float shot_float_444;
    float shot_float_448;
    float shot_float_44c;
    float shot_float_450;
    float shot_float_454;
    float shot_float_458;
    float shot_float_45c;
    float shot_float_460;
    float shot_float_464;
    float shot_float_468;
    float shot_float_46c;
};

struct Gp0Instance44 {
    gp0_u8 u_0000[0x84];
    gp0_u8 flag_84;
};

struct Gp0InstanceA {
    gp0_u8 u_0000[4];
    struct Gp0Player **players_begin;
    struct Gp0Player **players_end;
};

/* Swing_DLL.xex 0x8865F518: clear 14 per-player float fields (0x430..0x46C). */
void ts4_gp0_clear_player_float_block_8865F518(struct Gp0InstanceA *instance)
{
    struct Gp0Player **end = instance->players_end;
    struct Gp0Player **it = instance->players_begin;
    float zero;

    if (it == end) {
        return;
    }
    zero = lbl_8814B440;
    do {
        struct Gp0Player *player = *it;
        if (player != 0) {
            struct Gp0PlayerState *s = player->state;
            s->shot_float_430 = zero;
            s->shot_float_434 = zero;
            s->shot_float_440 = zero;
            s->shot_float_444 = zero;
            s->shot_float_448 = zero;
            s->shot_float_44c = zero;
            s->shot_float_450 = zero;
            s->shot_float_454 = zero;
            s->shot_float_458 = zero;
            s->shot_float_45c = zero;
            s->shot_float_460 = zero;
            s->shot_float_464 = zero;
            s->shot_float_468 = zero;
            s->shot_float_46c = zero;
        }
        ++it;
    } while (it != end);
}

int fn_886C1628(void *instance);

/* Swing_DLL.xex 0x886C1E80: run the queued-command step (fn_886C1628) up to 8 times, stopping when it reports nothing left. */
void ts4_gp0_run_command_steps_886C1E80(void *instance)
{
    int i = 0;

    do {
        if (!(unsigned char)fn_886C1628(instance)) {
            break;
        }
        i++;
    } while (i < 8);
}

/* ---- ts4_gp0_instance_tail_steps_8869EE60 / ts4_gp0_force_state_hash_88697B90 / fn_88669040 -------------------------- */

struct Gp0MatchStateC { gp0_u8 u_0000[0x324]; gp0_u8 mode_flag_324; };

/* instance->flags (instance + 0x44) */
struct Gp0InstanceFlagsC {
    gp0_u8 u_0000[0x54];
    int active_team;                  /* +0x54 index into instance->teams */
    gp0_u8 u_0058[0x10c];
    gp0_u8 deferred_valid_164;        /* +0x164 */
    gp0_u8 u_0165[3];
    gp0_u32 deferred_hash_168;        /* +0x168 */
};

struct Gp0PlayerAnimC { gp0_u8 u_0000[0x198]; gp0_u8 request_198; };
struct Gp0PlayerStateC { gp0_u8 u_0000[0x78]; struct Gp0PlayerAnimC *anim; };
struct Gp0TeamInfoC { gp0_u8 u_0000[0xb8]; int current_player_index; };

struct Gp0TeamC {
    gp0_u8 u_0000[0x10];
    struct Gp0PlayerStateC **players;     /* +0x10 */
    gp0_u8 u_0014[0x10];
    struct Gp0TeamInfoC *info;            /* +0x24 */
};

struct Gp0InstanceC {
    gp0_u8 u_0000[0x10];
    struct Gp0TeamC **teams;              /* +0x10 */
    gp0_u8 u_0014[0x1c];
    struct Gp0MatchStateC *match;         /* +0x30 */
    gp0_u8 u_0034[0x10];
    struct Gp0InstanceFlagsC *flags;      /* +0x44 */
    gp0_u8 u_0048[0x20];
    void *u_0068;                         /* +0x68 sub-object stepped by fn_886755E0/ts4_gp0_force_state_hash_88697B90 */
};

void fn_886755E0(void *x);
struct Gp0InstanceD;
void ts4_gp0_force_state_hash_88697B90(struct Gp0InstanceD *object);

/* Swing_DLL.xex 0x8869EE60: tail steps of one instance update (two helpers, then a deferred animation-request handoff). */
void ts4_gp0_instance_tail_steps_8869EE60(struct Gp0InstanceC *instance)
{
    struct Gp0PlayerStateC *player;
    struct Gp0TeamC *team;

    fn_886755E0(instance->u_0068);
    ts4_gp0_force_state_hash_88697B90((struct Gp0InstanceD *)instance->u_0068);
    if (instance->match->mode_flag_324 != 0) {
        team = instance->teams[instance->flags->active_team];
        player = team->players[team->info->current_player_index];
        if (player->anim->request_198 != 0) {
            instance->flags->deferred_valid_164 = 1;
            instance->flags->deferred_hash_168 = 0xA053865E;
            player->anim->request_198 = 0;
        }
    }
}

/* ---- ts4_gp0_force_state_hash_88697B90 ------------------------------------------------------- */

/* Sub-block at flags + 0x90 (same bytes as InstanceFlagsC +0x164/+0x168). */
struct Gp0FlagsSub90 {
    gp0_u8 u_0000[0xd4];
    gp0_u8 deferred_valid_d4;
    gp0_u8 u_00d5[3];
    gp0_u32 deferred_hash_d8;
};

struct Gp0InstanceFlagsD {
    gp0_u8 u_0000[0x19a];
    gp0_u8 active_19a;                /* +0x19A */
};

struct Gp0InstanceD {
    gp0_u8 u_0000[4];
    struct { gp0_u8 u_0000[0x44]; struct Gp0InstanceFlagsD *flags; } *inst;
};

void fn_88686430(void *x);

/* Swing_DLL.xex 0x88697B90: if the flag block is active, run fn_88686430 and force deferred hash 0x76250049 unless it already is 0x007925F4. */
/* Kept out of line: the original calls it from ts4_gp0_instance_tail_steps_8869EE60. */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_gp0_force_state_hash_88697B90(struct Gp0InstanceD *object)
{
    struct Gp0InstanceFlagsD *flags = object->inst->flags;
    struct Gp0FlagsSub90 *sub = (struct Gp0FlagsSub90 *)((char *)flags + 0x90);

    if (flags->active_19a != 0) {
        fn_88686430(object);
        if (sub->deferred_hash_d8 != 0x007925F4) {
            sub->deferred_valid_d4 = 1;
            sub->deferred_hash_d8 = 0x76250049;
        }
    }
}
