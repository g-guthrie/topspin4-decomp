/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex) shared gameplay types: player.h
 *
 * Conventions: docs/agents/types.md. Evidence tags in the field comments:
 *   V <addr..>  the offset and width are used by byte-matched functions at these addresses (config/54540859/match.json).
 *               A trailing `~` means the function was attributed to this class by its access pattern (hub signature),
 *               not by a documented name: treat the class attribution as likely, the offset itself as proven.
 *   U <source>  unverified: read from machine code or data by an earlier analysis, no byte-matched function uses it yet.
 * Pointer targets and field names are interpretation; only offset + width are proven by a V tag.
 * First pass generated from the matched sources by a one-off miner (2026-11-23); maintained by hand since.
 */
#ifndef TS4_PLAYER_H
#define TS4_PLAYER_H

#include "base.h"
#include "math.h"
#include "containers.h"
#include "match.h"

/* Team state (Team+0x24). rt1: Rt1TeamState, Rt1LaunchInfo. */
typedef struct Ts4TeamState {
    char pad_0000[0x48];
    int f_048;                                   /* +0x048 V 8866DF18~ */
    char pad_004C[0x1C];
    int launch_frame;                            /* +0x068 V 886AFDF8 */
    char pad_006C[0x44];
    int side_tag;                                /* +0x0B0 V 88679518~ 886AB438~ */
    char pad_00B4[0x4];
    int receiver_slot;                           /* +0x0B8 V 8865EB60 88660F70~ 8867DEF0~ */
} Ts4TeamState;
TS4_ASSERT_OFFSET(Ts4TeamState, f_048, 0x48);
TS4_ASSERT_OFFSET(Ts4TeamState, launch_frame, 0x68);
TS4_ASSERT_OFFSET(Ts4TeamState, side_tag, 0xB0);
TS4_ASSERT_OFFSET(Ts4TeamState, receiver_slot, 0xB8);

/* Team / player slot (Player+0x4C). rt1: Rt1TeamView/W/R; d1g: Ts4PlayerSlot. */
typedef struct Ts4Team {
    char pad_0000[0x20];
    struct Ts4Match *match;                      /* +0x020 V 88663208~ 88682B58~ 886AFDF8 */
    struct Ts4TeamState *state;                  /* +0x024 V 8865EB60 88660F70~ 8866DF18~ 886706C8~ +4 */
    int team;                                    /* +0x028 V 8865EB60 88660F70~ 88663208~ 8866DA58~ +4 */
    int mode;                                    /* +0x02C V 88660F70~ 88671350~ 88672878~ 886782D0~ +1 */
    char pad_0030[0x173];
    unsigned char human;                         /* +0x1A3 U rt1_types.h Rt1TeamR */
} Ts4Team;
TS4_ASSERT_OFFSET(Ts4Team, match, 0x20);
TS4_ASSERT_OFFSET(Ts4Team, state, 0x24);
TS4_ASSERT_OFFSET(Ts4Team, team, 0x28);
TS4_ASSERT_OFFSET(Ts4Team, mode, 0x2C);
TS4_ASSERT_OFFSET(Ts4Team, human, 0x1A3);

/* PlayerTuning "PT" (Player+0x2C). d1g: Ts4PlayerTuning; rt1: Rt1Tuning*. */
typedef struct Ts4PlayerTuning {
    char pad_0000[0xA0];
    unsigned char f_0a0[4];                      /* +0x0A0 V 886BDB58~ (address taken; extent from the source, not proven) */
    char pad_00A4[0x1B8];
    int lead_frames;                             /* +0x25C V 8866BD00 */
    char pad_0260[0x278];
    unsigned char category_lists[0xD8];          /* +0x4D8 U d1g_types.h: 3 modes x 6 x {rel,count,capacity} */
    int ids;                                     /* +0x5B0 V 886AC7E0 886AC928 */
    unsigned int f_5b4;                          /* +0x5B4 V 886AC7E0 886AC928 */
    char pad_05B8[0x1C];
    unsigned char timing_baseline[0x1C];         /* +0x5D4 U rt1_types.h Rt1TimingCurves */
    unsigned char timing_volley[0x1C];           /* +0x5F0 U rt1_types.h Rt1TimingCurves */
    char pad_060C[0xC4];
    int window_default;                          /* +0x6D0 V 886AFDF8 */
    int limit_default;                           /* +0x6D4 V 886AFDF8 */
    int window_inside_out;                       /* +0x6D8 V 886AFDF8 */
    int limit_inside_out;                        /* +0x6DC V 886AFDF8 */
    int window_bd2;                              /* +0x6E0 V 886AFDF8 */
    int limit_bd2;                               /* +0x6E4 V 886AFDF8 */
    char pad_06E8[0x8];
    float central_corridor_z;                    /* +0x6F0 V 8866B6E0 */
    char pad_06F4[0xC];
    float max_x;                                 /* +0x700 V 8866DF60~ */
    char pad_0704[0x4];
    float max_z;                                 /* +0x708 V 8866DF60~ */
    char pad_070C[0x4];
    float min_x;                                 /* +0x710 V 8866DF60~ */
    char pad_0714[0x4];
    float min_z;                                 /* +0x718 V 8866DF60~ */
    char pad_071C[0x4];
    float max_x_720;                             /* +0x720 V 8866DF60~ */
    char pad_0724[0x4];
    float max_z_728;                             /* +0x728 V 8866DF60~ */
    char pad_072C[0x4];
    float min_x_730;                             /* +0x730 V 8866DF60~ */
    char pad_0734[0x4];
    float min_z_738;                             /* +0x738 V 8866DF60~ */
    char pad_073C[0x4];
    int swing_window;                            /* +0x740 V 88662458~ 88662510~ */
    char pad_0744[0x8];
    int f_74c;                                   /* +0x74C V 8865AB70~ */
} Ts4PlayerTuning;
TS4_ASSERT_OFFSET(Ts4PlayerTuning, f_0a0, 0xA0);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, lead_frames, 0x25C);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, category_lists, 0x4D8);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, ids, 0x5B0);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, f_5b4, 0x5B4);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, timing_baseline, 0x5D4);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, timing_volley, 0x5F0);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, window_default, 0x6D0);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, limit_default, 0x6D4);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, window_inside_out, 0x6D8);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, limit_inside_out, 0x6DC);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, window_bd2, 0x6E0);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, limit_bd2, 0x6E4);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, central_corridor_z, 0x6F0);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, max_x, 0x700);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, max_z, 0x708);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, min_x, 0x710);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, min_z, 0x718);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, max_x_720, 0x720);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, max_z_728, 0x728);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, min_x_730, 0x730);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, min_z_738, 0x738);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, swing_window, 0x740);
TS4_ASSERT_OFFSET(Ts4PlayerTuning, f_74c, 0x74C);

/* PlayerState "S" (Player+0x74, 0x1070 bytes; field names from Layoutall via docs/gameplay). Flat: nested blocks are listed by absolute offset. */
typedef struct Ts4PlayerState {
    char pad_0000[0x38];
    float base_time;                             /* +0x038 V 8866FB60 */
    char pad_003C[0x5C];
    int frame;                                   /* +0x098 V 88662458~ 88662510~ */
    char pad_009C[0x2C0];
    unsigned int swing_class;                    /* +0x35C V 886B01A8 */
    unsigned int swing_category;                 /* +0x360 V 886AFDF8 */
    char pad_0364[0x4];
    unsigned int pro_style;                      /* +0x368 V 886AFDF8 */
    unsigned int surface;                        /* +0x36C V 886AFDF8 */
    char pad_0370[0x10];
    int swing_preference_level;                  /* +0x380 V 886AC7E0 886AC928 */
    char pad_0384[0x10];
    unsigned int f_394;                          /* +0x394 V 8866DF60~ */
    char pad_0398[0x11];
    unsigned char f_3a9;                         /* +0x3A9 V 886783B0~ */
    char pad_03AA[0xA];
    unsigned int power_grade;                    /* +0x3B4 U rt1_types.h */
    unsigned int control_grade;                  /* +0x3B8 U rt1_types.h */
    char pad_03BC[0x8];
    unsigned int shot_kind_a;                    /* +0x3C4 V 88662B60 */
    char pad_03C8[0x4];
    unsigned int shot_kind_b;                    /* +0x3CC V 88662B60 */
    char pad_03D0[0x30];
    unsigned char request[0xC];                  /* +0x400 V 8868F178 block `struct Ts4ShotRequest` (start proven; extent from the source) */
    char pad_040C[0xC];
    int shot_triggers;                           /* +0x418 V 8868F178 */
    int f_41c;                                   /* +0x41C V 8868F178 */
    char pad_0420[0x62];
    unsigned char f_482;                         /* +0x482 V 886821A0~ */
    unsigned char f_483;                         /* +0x483 V 886821A0~ */
    unsigned char f_484;                         /* +0x484 V 886821A0~ */
    unsigned char f_485;                         /* +0x485 V 886821A0~ */
    unsigned char f_486;                         /* +0x486 V 886821A0~ */
    unsigned char f_487;                         /* +0x487 V 886821A0~ */
    char pad_0488[0x44];
    int f_4cc;                                   /* +0x4CC V 8865E980~ */
    int f_4d0;                                   /* +0x4D0 V 8865E980~ */
    char pad_04D4[0x4];
    unsigned char risk;                          /* +0x4D8 V 8868F178 */
    char pad_04D9[0x1];
    unsigned char f_4da;                         /* +0x4DA V 8865AB70~ */
    char pad_04DB[0x25];
    unsigned char f_500[0x40];                   /* +0x500 V 886783B0~ block `struct W8dBlk_886783B0` (start proven; extent from the source) */
    char pad_0540[0x4];
    float manual_shot_timing;                    /* +0x544 V 886714C0~ */
    char pad_0548[0x2B];
    unsigned char f_573;                         /* +0x573 V 88662B60 */
    unsigned char f_574;                         /* +0x574 V 886783B0~ */
    unsigned char f_575;                         /* +0x575 V 88662B60 */
    char pad_0576[0x7];
    unsigned char f_57d;                         /* +0x57D V 88662B60 */
    char pad_057E[0x42];
    unsigned int f_5c0;                          /* +0x5C0 V 8866DA58~ 88671350~ */
    char pad_05C4[0x14];
    unsigned char is_serving;                    /* +0x5D8 U d1g_types.h */
    unsigned char is_volley;                     /* +0x5D9 V 886783B0~ 8867DEF0~ 886B0380 */
    unsigned char is_smash;                      /* +0x5DA V 886783B0~ 8868F178 */
    unsigned char is_inside_out;                 /* +0x5DB V 886AFDF8 */
    char pad_05DC[0x138];
    unsigned int chosen_outcome;                 /* +0x714 U rt1_types.h */
    float fault_probability;                     /* +0x718 U rt1_types.h */
    float let_probability;                       /* +0x71C U rt1_types.h */
    float outcome_net;                           /* +0x720 U rt1_types.h */
    char pad_0724[0x8C];
    float autoswing_eval_baseline;               /* +0x7B0 V 886B0380 */
    float autoswing_eval_volley;                 /* +0x7B4 V 886B0380 */
    char pad_07B8[0x14];
    float slow_down;                             /* +0x7CC V 886AFDF8 */
    char pad_07D0[0x70];
    unsigned char f_840[1];                      /* +0x840 V 8865A890~ (address taken; extent from the source, not proven) */
    char pad_0841[0x8F];
    int f_8d0;                                   /* +0x8D0 V 8866BEE0~ */
    char pad_08D4[0xC];
    Ts4Vec4 local_position;                      /* +0x8E0 V 8866BEE0~ 88672878~ 88682B58~ */
    char pad_08F0[0x30];
    Ts4Vec4 f_920[8];                            /* +0x920 V 8866DA58~ */
    Ts4Vec4 move_state;                          /* +0x9A0 V 88663208~ 88672878~ 88682B58~ */
    char pad_09B0[0x20];
    float required_move_dir;                     /* +0x9D0 V 8865E980~ */
    float required_move_power;                   /* +0x9D4 V 8865E980~ */
    float stick_move_dir;                        /* +0x9D8 V 88679518~ */
    char pad_09DC[0x20];
    unsigned int move_mode;                      /* +0x9FC V 886624C8~ 88672878~ 88682B58~ */
    char pad_0A00[0x10];
    float required_amplitude;                    /* +0xA10 V 8866FB60 */
    char pad_0A14[0x18];
    unsigned char sprint;                        /* +0xA2C V 8866FB60 */
    char pad_0A2D[0x13];
    unsigned char f_a40[0xC0];                   /* +0xA40 V 886BDB58~ (address taken; extent from the source, not proven) */
    float f_b00;                                 /* +0xB00 V 8866DA00 */
    char pad_0B04[0xC];
    unsigned char f_b10[4];                      /* +0xB10 V 886BDB58~ (address taken; extent from the source, not proven) */
    char pad_0B14[0xB4];
    int sample_index;                            /* +0xBC8 V 8866BD00 */
    char pad_0BCC[0x5];
    unsigned char is_left_line;                  /* +0xBD1 V 8869A4D0 */
    unsigned char pending;                       /* +0xBD2 V 8865DAC0 886AFDF8 */
    char pad_0BD3[0x89];
    float f_c5c;                                 /* +0xC5C V 8866BEE0~ */
    char pad_0C60[0xA4];
    int timing_base_frame;                       /* +0xD04 V 886AFDF8 */
    float timing_value;                          /* +0xD08 V 886714C0~ */
    float timing_ability;                        /* +0xD0C U symbols.md */
    unsigned char autoswing_good;                /* +0xD10 V 886B0380 */
    char pad_0D11[0x33];
    unsigned char quad[0x8];                     /* +0xD44 V 886935A0 block `struct Rt1QuadAimingState` (start proven; extent from the source) */
    char pad_0D4C[0x34];
    float stick_intensity;                       /* +0xD80 V 886630B8~ */
    char pad_0D84[0x4];
    float efficiency;                            /* +0xD88 U rt1_types.h */
    float out_efficiency;                        /* +0xD8C U rt1_types.h */
    float quad_efficiency;                       /* +0xD90 V 88693270 886935A0 */
    char pad_0D94[0x14];
    float final_efficiency;                      /* +0xDA8 U rt1_types.h */
    char pad_0DAC[0x1];
    unsigned char direction_selected;            /* +0xDAD V 886935A0 */
    unsigned char stick_override_enable;         /* +0xDAE V 886706C8~ */
    char pad_0DAF[0x39];
    float speed_override;                        /* +0xDE8 V 8866FB60 */
    unsigned char swing_flag;                    /* +0xDEC V 8866FB60 */
    char pad_0DED[0x7];
    float f_df4;                                 /* +0xDF4 V 8865DB50~ */
    char pad_0DF8[0x76];
    unsigned char src_e6e;                       /* +0xE6E V 88662B60 */
    char pad_0E6F[0xB5];
    float sum_powerful_factor;                   /* +0xF24 U symbols.md */
    char pad_0F28[0x38];
    float f_f60;                                 /* +0xF60 V 8865F858~ */
    char pad_0F64[0x8];
    float f_f6c;                                 /* +0xF6C V 8865F858~ */
    float f_f70;                                 /* +0xF70 V 8865F858~ */
    char pad_0F74[0x2C];
    unsigned char f_fa0;                         /* +0xFA0 V 8865E490~ */
    char pad_0FA1[0x1B];
    unsigned char flag_fbc;                      /* +0xFBC V 886AC7E0 */
    char pad_0FBD[0xAB];
    unsigned int f_1068;                         /* +0x1068 V 886782D0~ */
    char pad_106C[0x4];
} Ts4PlayerState;
TS4_ASSERT_OFFSET(Ts4PlayerState, base_time, 0x38);
TS4_ASSERT_OFFSET(Ts4PlayerState, frame, 0x98);
TS4_ASSERT_OFFSET(Ts4PlayerState, swing_class, 0x35C);
TS4_ASSERT_OFFSET(Ts4PlayerState, swing_category, 0x360);
TS4_ASSERT_OFFSET(Ts4PlayerState, pro_style, 0x368);
TS4_ASSERT_OFFSET(Ts4PlayerState, surface, 0x36C);
TS4_ASSERT_OFFSET(Ts4PlayerState, swing_preference_level, 0x380);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_394, 0x394);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_3a9, 0x3A9);
TS4_ASSERT_OFFSET(Ts4PlayerState, power_grade, 0x3B4);
TS4_ASSERT_OFFSET(Ts4PlayerState, control_grade, 0x3B8);
TS4_ASSERT_OFFSET(Ts4PlayerState, shot_kind_a, 0x3C4);
TS4_ASSERT_OFFSET(Ts4PlayerState, shot_kind_b, 0x3CC);
TS4_ASSERT_OFFSET(Ts4PlayerState, request, 0x400);
TS4_ASSERT_OFFSET(Ts4PlayerState, shot_triggers, 0x418);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_41c, 0x41C);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_482, 0x482);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_483, 0x483);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_484, 0x484);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_485, 0x485);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_486, 0x486);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_487, 0x487);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_4cc, 0x4CC);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_4d0, 0x4D0);
TS4_ASSERT_OFFSET(Ts4PlayerState, risk, 0x4D8);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_4da, 0x4DA);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_500, 0x500);
TS4_ASSERT_OFFSET(Ts4PlayerState, manual_shot_timing, 0x544);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_573, 0x573);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_574, 0x574);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_575, 0x575);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_57d, 0x57D);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_5c0, 0x5C0);
TS4_ASSERT_OFFSET(Ts4PlayerState, is_serving, 0x5D8);
TS4_ASSERT_OFFSET(Ts4PlayerState, is_volley, 0x5D9);
TS4_ASSERT_OFFSET(Ts4PlayerState, is_smash, 0x5DA);
TS4_ASSERT_OFFSET(Ts4PlayerState, is_inside_out, 0x5DB);
TS4_ASSERT_OFFSET(Ts4PlayerState, chosen_outcome, 0x714);
TS4_ASSERT_OFFSET(Ts4PlayerState, fault_probability, 0x718);
TS4_ASSERT_OFFSET(Ts4PlayerState, let_probability, 0x71C);
TS4_ASSERT_OFFSET(Ts4PlayerState, outcome_net, 0x720);
TS4_ASSERT_OFFSET(Ts4PlayerState, autoswing_eval_baseline, 0x7B0);
TS4_ASSERT_OFFSET(Ts4PlayerState, autoswing_eval_volley, 0x7B4);
TS4_ASSERT_OFFSET(Ts4PlayerState, slow_down, 0x7CC);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_840, 0x840);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_8d0, 0x8D0);
TS4_ASSERT_OFFSET(Ts4PlayerState, local_position, 0x8E0);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_920, 0x920);
TS4_ASSERT_OFFSET(Ts4PlayerState, move_state, 0x9A0);
TS4_ASSERT_OFFSET(Ts4PlayerState, required_move_dir, 0x9D0);
TS4_ASSERT_OFFSET(Ts4PlayerState, required_move_power, 0x9D4);
TS4_ASSERT_OFFSET(Ts4PlayerState, stick_move_dir, 0x9D8);
TS4_ASSERT_OFFSET(Ts4PlayerState, move_mode, 0x9FC);
TS4_ASSERT_OFFSET(Ts4PlayerState, required_amplitude, 0xA10);
TS4_ASSERT_OFFSET(Ts4PlayerState, sprint, 0xA2C);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_a40, 0xA40);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_b00, 0xB00);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_b10, 0xB10);
TS4_ASSERT_OFFSET(Ts4PlayerState, sample_index, 0xBC8);
TS4_ASSERT_OFFSET(Ts4PlayerState, is_left_line, 0xBD1);
TS4_ASSERT_OFFSET(Ts4PlayerState, pending, 0xBD2);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_c5c, 0xC5C);
TS4_ASSERT_OFFSET(Ts4PlayerState, timing_base_frame, 0xD04);
TS4_ASSERT_OFFSET(Ts4PlayerState, timing_value, 0xD08);
TS4_ASSERT_OFFSET(Ts4PlayerState, timing_ability, 0xD0C);
TS4_ASSERT_OFFSET(Ts4PlayerState, autoswing_good, 0xD10);
TS4_ASSERT_OFFSET(Ts4PlayerState, quad, 0xD44);
TS4_ASSERT_OFFSET(Ts4PlayerState, stick_intensity, 0xD80);
TS4_ASSERT_OFFSET(Ts4PlayerState, efficiency, 0xD88);
TS4_ASSERT_OFFSET(Ts4PlayerState, out_efficiency, 0xD8C);
TS4_ASSERT_OFFSET(Ts4PlayerState, quad_efficiency, 0xD90);
TS4_ASSERT_OFFSET(Ts4PlayerState, final_efficiency, 0xDA8);
TS4_ASSERT_OFFSET(Ts4PlayerState, direction_selected, 0xDAD);
TS4_ASSERT_OFFSET(Ts4PlayerState, stick_override_enable, 0xDAE);
TS4_ASSERT_OFFSET(Ts4PlayerState, speed_override, 0xDE8);
TS4_ASSERT_OFFSET(Ts4PlayerState, swing_flag, 0xDEC);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_df4, 0xDF4);
TS4_ASSERT_OFFSET(Ts4PlayerState, src_e6e, 0xE6E);
TS4_ASSERT_OFFSET(Ts4PlayerState, sum_powerful_factor, 0xF24);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_f60, 0xF60);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_f6c, 0xF6C);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_f70, 0xF70);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_fa0, 0xFA0);
TS4_ASSERT_OFFSET(Ts4PlayerState, flag_fbc, 0xFBC);
TS4_ASSERT_OFFSET(Ts4PlayerState, f_1068, 0x1068);
TS4_ASSERT_SIZE(Ts4PlayerState, 0x1070);

/* AI record (AIController+0x28; State.bin D7C700B9). */
typedef struct Ts4AIRecord {
    char pad_0000[0x1C0];
    float swing_reaction_time;                   /* +0x1C0 V 886AFDF8 */
    char pad_01C4[0x4C];
    float serve_efficiency;                      /* +0x210 U rt1_types.h */
    float serve_out_efficiency;                  /* +0x214 U rt1_types.h */
    float serve_fault_probability;               /* +0x218 U rt1_types.h */
} Ts4AIRecord;
TS4_ASSERT_OFFSET(Ts4AIRecord, swing_reaction_time, 0x1C0);
TS4_ASSERT_OFFSET(Ts4AIRecord, serve_efficiency, 0x210);
TS4_ASSERT_OFFSET(Ts4AIRecord, serve_out_efficiency, 0x214);
TS4_ASSERT_OFFSET(Ts4AIRecord, serve_fault_probability, 0x218);

/* AI controller (Player+0x50). */
typedef struct Ts4AIController {
    char pad_0000[0x28];
    struct Ts4AIRecord *record;                  /* +0x028 V 886AFDF8 */
} Ts4AIController;
TS4_ASSERT_OFFSET(Ts4AIController, record, 0x28);

/* Body (Player+0x68). */
typedef struct Ts4Body {
    char pad_0000[0x10];
    Ts4Vec4 position;                            /* +0x010 U rt1_types.h Rt1Body.line.point */
    Ts4Vec4 facing;                              /* +0x020 U rt1_types.h Rt1Body.line.dir */
    void *f_030;                                 /* +0x030 V 8869A4D0 */
} Ts4Body;
TS4_ASSERT_OFFSET(Ts4Body, position, 0x10);
TS4_ASSERT_OFFSET(Ts4Body, facing, 0x20);
TS4_ASSERT_OFFSET(Ts4Body, f_030, 0x30);

/* Mover (Player+0x5C). */
typedef struct Ts4Mover {
    char pad_0000[0x14];
    unsigned char latched;                       /* +0x014 U symbols.md Mover_PreHitFreeze */
    unsigned char released;                      /* +0x015 U symbols.md */
    char pad_0016[0x2];
    struct Ts4Player *player;                    /* +0x018 V 8866FB60 */
    char pad_001C[0x4];
    void *sm;                                    /* +0x020 V 8866FB60 */
    char pad_0024[0x10];
    float own_time;                              /* +0x034 V 8866FB60 */
} Ts4Mover;
TS4_ASSERT_OFFSET(Ts4Mover, latched, 0x14);
TS4_ASSERT_OFFSET(Ts4Mover, released, 0x15);
TS4_ASSERT_OFFSET(Ts4Mover, player, 0x18);
TS4_ASSERT_OFFSET(Ts4Mover, sm, 0x20);
TS4_ASSERT_OFFSET(Ts4Mover, own_time, 0x34);

/* Hold counter {frames held, value}; reset together by an inlined helper.  V 88698538 */
typedef struct Ts4HoldCounter {
    int frames;                                  /* +0x00 V 88698538 */
    float value;                                 /* +0x04 V 88698538 */
} Ts4HoldCounter;
TS4_ASSERT_SIZE(Ts4HoldCounter, 0x8);

/* ReceiverState (PlayerState+0xA40; SwingController+0x20). d1g: Ts4ReceiverState. */
typedef struct Ts4ReceiverState {
    char pad_0000[0x3BC];
    Ts4HoldCounter power;                        /* +0x3BC V 88698538 */
    Ts4HoldCounter risk;                         /* +0x3C4 V 88698538 */
} Ts4ReceiverState;
TS4_ASSERT_OFFSET(Ts4ReceiverState, power, 0x3BC);
TS4_ASSERT_OFFSET(Ts4ReceiverState, risk, 0x3C4);

/* Player hub: "PlayerCtx" / "PC" in docs/gameplay. d1g: Ts4PlayerController; rt1: Rt1PlayerCtx*; q5: Q5Player. Every controller component points here (+0x1C) and the planner at +0x154. */
typedef struct Ts4Player {
    char pad_0000[0x10];
    unsigned char is_human;                      /* +0x010 V 8866DA58~ 886706C8~ 886AFDF8 886B83B0 */
    char pad_0011[0x3];
    int index;                                   /* +0x014 V 8865F858~ 886714C0~ */
    int slot;                                    /* +0x018 V 8865EB60 88660F70~ 8866DA58~ 8867DEF0~ +2 also read as unsigned int (8866DA58) */
    void *f_01c;                                 /* +0x01C V 8866B6E0 */
    char pad_0020[0x4];
    void *planner;                               /* +0x024 U gp3_types.h (unverified) */
    unsigned int f_028;                          /* +0x028 V 886BCDA8~ */
    struct Ts4PlayerTuning *tuning;              /* +0x02C V 8865AB70~ 88662458~ 88662510~ 8866B6E0 +10 also read as unsigned int (886A31B8) */
    void *f_030;                                 /* +0x030 V 8866AAF8~ */
    char pad_0034[0x4];
    void *f_038;                                 /* +0x038 V 8866AAF8~ */
    unsigned int shot_id;                        /* +0x03C V 886783B0~ 8868F178 */
    void *f_040;                                 /* +0x040 V 8866DA58~ */
    struct Ts4World *world;                      /* +0x044 V 8865E490~ 8866AAF8~ 886821A0~ 88682B58~ +1 */
    struct Ts4Match *match;                      /* +0x048 V 8865A890~ 8865AD50~ 8865DB50~ 8865E490~ +29 also read as unsigned int (8865AD50) */
    struct Ts4Team *team;                        /* +0x04C V 8865EB60 8865EC70 88660F70~ 88663208~ +13 also read as unsigned int (8865EC70) */
    struct Ts4AIController *ai;                  /* +0x050 V 886AFDF8 */
    char pad_0054[0xC];
    void *rig;                                   /* +0x060 V 886624C8~ 886AC7E0 886AC928 886B83B0 */
    char pad_0064[0x4];
    struct Ts4Body *body;                        /* +0x068 V 8869A4D0 */
    char pad_006C[0x4];
    struct Ts4ShotContext *shot_ctx;             /* +0x070 V 886783B0~ */
    struct Ts4PlayerState *state;                /* +0x074 V 8865A890~ 8865AB70~ 8865DAC0 8865DB50~ +37 also read as unsigned int (8865EC70) */
    void *move_path;                             /* +0x078 V 886A5BB0~ */
    char pad_007C[0x4];
    void *swing_flags;                           /* +0x080 V 8865AD50~ 88698538 886AC7E0 also read as unsigned int (8865AD50) */
    void *f_084;                                 /* +0x084 V 886A5BB0~ */
    char pad_0088[0xC];
    void *behaviours_begin;                      /* +0x094 V 8866D930 */
    void *behaviours_end;                        /* +0x098 V 8866D930 */
    char pad_009C[0x4];
    Ts4PtrVector conditions;                     /* +0x0A0 V 8865ED78 (shot-tree condition byte pointers; d1g: Ts4ConditionVector) */
    struct Ts4ShotTree *tree;                    /* +0x0AC V 8865ED78 */
    struct Ts4ShotRow *row;                      /* +0x0B0 V 8865ED78 88662B60 8868F178 */
    struct Ts4BallLink *ball_link;               /* +0x0B4 V 8866BD00 8869D870~ */
} Ts4Player;
TS4_ASSERT_OFFSET(Ts4Player, is_human, 0x10);
TS4_ASSERT_OFFSET(Ts4Player, index, 0x14);
TS4_ASSERT_OFFSET(Ts4Player, slot, 0x18);
TS4_ASSERT_OFFSET(Ts4Player, f_01c, 0x1C);
TS4_ASSERT_OFFSET(Ts4Player, planner, 0x24);
TS4_ASSERT_OFFSET(Ts4Player, f_028, 0x28);
TS4_ASSERT_OFFSET(Ts4Player, tuning, 0x2C);
TS4_ASSERT_OFFSET(Ts4Player, f_030, 0x30);
TS4_ASSERT_OFFSET(Ts4Player, f_038, 0x38);
TS4_ASSERT_OFFSET(Ts4Player, shot_id, 0x3C);
TS4_ASSERT_OFFSET(Ts4Player, f_040, 0x40);
TS4_ASSERT_OFFSET(Ts4Player, world, 0x44);
TS4_ASSERT_OFFSET(Ts4Player, match, 0x48);
TS4_ASSERT_OFFSET(Ts4Player, team, 0x4C);
TS4_ASSERT_OFFSET(Ts4Player, ai, 0x50);
TS4_ASSERT_OFFSET(Ts4Player, rig, 0x60);
TS4_ASSERT_OFFSET(Ts4Player, body, 0x68);
TS4_ASSERT_OFFSET(Ts4Player, shot_ctx, 0x70);
TS4_ASSERT_OFFSET(Ts4Player, state, 0x74);
TS4_ASSERT_OFFSET(Ts4Player, move_path, 0x78);
TS4_ASSERT_OFFSET(Ts4Player, swing_flags, 0x80);
TS4_ASSERT_OFFSET(Ts4Player, f_084, 0x84);
TS4_ASSERT_OFFSET(Ts4Player, behaviours_begin, 0x94);
TS4_ASSERT_OFFSET(Ts4Player, behaviours_end, 0x98);
TS4_ASSERT_OFFSET(Ts4Player, conditions, 0xA0);
TS4_ASSERT_OFFSET(Ts4Player, tree, 0xAC);
TS4_ASSERT_OFFSET(Ts4Player, row, 0xB0);
TS4_ASSERT_OFFSET(Ts4Player, ball_link, 0xB4);

/* Common prefix of the per-player controller components (class not identified; only +0x1C is shared). */
typedef struct Ts4PlayerComponent {
    char pad_0000[0x1C];
    struct Ts4Player *player;                    /* +0x01C V 8865AD50~ 8865E490~ 8866BA40 886782D0~ +2 also read as unsigned int (8865AD50) */
    unsigned int f_020;                          /* +0x020 V 8865AD50~ 88679518~ also read as Ts4Vec4 (88679518) */
    char pad_0024[0x10];
    unsigned int f_034;                          /* +0x034 V 8865AD50~ */
    unsigned int f_038;                          /* +0x038 V 8865AD50~ */
    char pad_003C[0x4];
    int f_040;                                   /* +0x040 V 8865E490~ 88679518~ */
    int f_044;                                   /* +0x044 V 8865E490~ */
    unsigned int f_048;                          /* +0x048 V 8865E490~ */
} Ts4PlayerComponent;
TS4_ASSERT_OFFSET(Ts4PlayerComponent, player, 0x1C);
TS4_ASSERT_OFFSET(Ts4PlayerComponent, f_020, 0x20);
TS4_ASSERT_OFFSET(Ts4PlayerComponent, f_034, 0x34);
TS4_ASSERT_OFFSET(Ts4PlayerComponent, f_038, 0x38);
TS4_ASSERT_OFFSET(Ts4PlayerComponent, f_040, 0x40);
TS4_ASSERT_OFFSET(Ts4PlayerComponent, f_044, 0x44);
TS4_ASSERT_OFFSET(Ts4PlayerComponent, f_048, 0x48);

/* Swing request controller (vtable 0x880F4478; "PlayerController" in symbols.md s1a). d1g: Ts4SwingRequest; rt1: Rt1SwingRequest. */
#ifdef __cplusplus
/* Controller mode object embedded in the swing controller (human at +0x48, AI at +0xF4). Only slot 4 is identified:
 * the byte-matched ts4_controller_activate (0x886B83B0) calls it through the vtable on activation. C++ only. */
struct Ts4ControllerMode {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void enter();                        /* slot 4 (+0x10) V 886B83B0 */
};
#endif
typedef struct Ts4SwingController {
    char pad_0000[0x1C];
    struct Ts4Player *player;                    /* +0x01C V 88698538 886AFDF8 886B01A8 886B0380 +1 */
    struct Ts4ReceiverState *receiver;           /* +0x020 V 88698538 */
    char pad_0024[0x8];
    unsigned char motion_serve;                  /* +0x02C U d1g_types.h */
    char pad_002D[0xF];
    unsigned char risk_latched;                  /* +0x03C U d1g_types.h */
    unsigned char volley_repos_latched;          /* +0x03D U d1g_types.h */
    char pad_003E[0x2];
    unsigned int walk_misses;                    /* +0x040 V 88698538 886AFDF8 also read as int (886AFDF8) */
#ifdef __cplusplus
    Ts4ControllerMode *mode;                     /* +0x044 V 886B83B0 current mode (points at mode_human or mode_ai) */
    Ts4ControllerMode mode_human;                /* +0x048 V 886B83B0 (object start proven; its size is not) */
#else
    void *mode;                                  /* +0x044 V 886B83B0 */
    void *mode_human;                            /* +0x048 V 886B83B0 (vtable pointer of the embedded mode object) */
#endif
    char pad_004C[0xA8];
#ifdef __cplusplus
    Ts4ControllerMode mode_ai;                   /* +0x0F4 V 886B83B0 */
#else
    void *mode_ai;                               /* +0x0F4 V 886B83B0 (vtable pointer of the embedded mode object) */
#endif
    char pad_00F8[0x8];
    void *link;                                  /* +0x100 V 886B83B0 */
    char pad_0104[0x158];
    unsigned char rally[0x4];                    /* +0x25C V 886B0380 block `Analysers` (start proven; extent from the source) */
    char pad_0260[0x40];
    unsigned char serve[0x4];                    /* +0x2A0 V 886B0380 block `Analysers` (start proven; extent from the source) */
    char pad_02A4[0x2E8];
    unsigned char committed;                     /* +0x58C V 88698538 */
    unsigned char latched;                       /* +0x58D V 886AFDF8 */
    char pad_058E[0x2];
    unsigned char anim[4];                       /* +0x590 V 886B83B0 (address taken; extent from the source, not proven) */
    char pad_0594[0x8];
    unsigned char autoswing_due;                 /* +0x59C V 886AFDF8 */
    char pad_059D[0x1];
    unsigned char pressed;                       /* +0x59E V 88698538 */
} Ts4SwingController;
TS4_ASSERT_OFFSET(Ts4SwingController, player, 0x1C);
TS4_ASSERT_OFFSET(Ts4SwingController, receiver, 0x20);
TS4_ASSERT_OFFSET(Ts4SwingController, motion_serve, 0x2C);
TS4_ASSERT_OFFSET(Ts4SwingController, risk_latched, 0x3C);
TS4_ASSERT_OFFSET(Ts4SwingController, volley_repos_latched, 0x3D);
TS4_ASSERT_OFFSET(Ts4SwingController, walk_misses, 0x40);
TS4_ASSERT_OFFSET(Ts4SwingController, mode, 0x44);
TS4_ASSERT_OFFSET(Ts4SwingController, mode_human, 0x48);
TS4_ASSERT_OFFSET(Ts4SwingController, mode_ai, 0xF4);
TS4_ASSERT_OFFSET(Ts4SwingController, link, 0x100);
TS4_ASSERT_OFFSET(Ts4SwingController, rally, 0x25C);
TS4_ASSERT_OFFSET(Ts4SwingController, serve, 0x2A0);
TS4_ASSERT_OFFSET(Ts4SwingController, committed, 0x58C);
TS4_ASSERT_OFFSET(Ts4SwingController, latched, 0x58D);
TS4_ASSERT_OFFSET(Ts4SwingController, anim, 0x590);
TS4_ASSERT_OFFSET(Ts4SwingController, autoswing_due, 0x59C);
TS4_ASSERT_OFFSET(Ts4SwingController, pressed, 0x59E);

/* Repositioning controller "R" (rt1: Rt1Repositioning). No matched function proves it yet. */
typedef struct Ts4Repositioning {
    char pad_0000[0x1C];
    struct Ts4Player *player;                    /* +0x01C U rt1_types.h */
    Ts4Vec4 net_point;                           /* +0x020 U rt1_types.h */
    char pad_0030[0x10];
    int mode;                                    /* +0x040 U rt1_types.h (0 none, 2 go to the net) */
} Ts4Repositioning;
TS4_ASSERT_OFFSET(Ts4Repositioning, player, 0x1C);
TS4_ASSERT_OFFSET(Ts4Repositioning, net_point, 0x20);
TS4_ASSERT_OFFSET(Ts4Repositioning, mode, 0x40);

/* ---- byte-matched functions (current symbol names, config/54540859/symbols.txt). Private struct pointers of the
 * matched source that have no shared type yet are `void *`. ---- */
TS4_EXTERN_C_BEGIN
void ts4_if_get_u32_off38_8865AD50(struct Ts4PlayerComponent *a0);                                             /* 8865AD50~ */
void ts4_resync_counter_if_late_8865E490(struct Ts4PlayerComponent *s);                                        /* 8865E490~ */
unsigned int ts4_query_slot_matches_target_8865EB60(struct Ts4Player *q);                                      /* 8865EB60 */
/* PlayerCtx_LocalToWorld: writes the player's world position to *out and returns out. The matched definition
 * (asm2c style) is written as void(unsigned, unsigned); callers use this form (0x8866BD00).            8865EC70 */
__vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, struct Ts4Player *p);
void ts4_shot_select_row_8865ED78(struct Ts4Player *pc);                                                       /* 8865ED78 */
void *ts4_pick_target_88660F70(void *self, struct Ts4Player *arg);                                             /* 88660F70~ */
unsigned char ts4_z_below_limit_8866B6E0(struct Ts4Player *s);                                                 /* 8866B6E0 */
unsigned int ts4_if_get_u32_off1c_8866BA40(struct Ts4PlayerComponent *a0, float f11, float f12, float f13);    /* 8866BA40 */
unsigned char ts4_rally_active_8866D930(struct Ts4Player *player);                                             /* 8866D930 */
unsigned int ts4_abs_less_8866DA00(struct Ts4Player *o);                                                       /* 8866DA00 */
void ts4_classify_court_zone_8866DF60(struct Ts4Player *o);                                                    /* 8866DF60~ */
void ts4_phase_timer_flags_8866FB60(struct Ts4Mover *o, void *time, void *a, void *b);                         /* 8866FB60 */
int ts4_pick_aim_vector_886706C8(struct Ts4Player *pc, float *out);                                            /* 886706C8~ */
void ts4_select_approach_hash_886782D0(struct Ts4PlayerComponent *o);                                          /* 886782D0~ */
void ts4_copy_shot_state_886783B0(struct Ts4PlayerComponent *s);                                               /* 886783B0~ */
void ts4_store_heading_to_target_88679518(struct Ts4PlayerComponent *s);                                       /* 88679518~ */
void ts4_shot_request_8868F178(struct Ts4Player *pc);                                                          /* 8868F178 */
void ts4_forward_with_float_88693270(int a, int b, struct Ts4Player *c);                                       /* 88693270 */
void ts4_aim_selector_get_target_886935A0(void *self, void *out, struct Ts4Player *pc);                        /* 886935A0 */
void ts4_shot_request_repress_88698538(struct Ts4SwingController *self);                                       /* 88698538 */
void ga4_notify_same_side_8869D870(struct Ts4Player *self);                                                    /* 8869D870~ */
void ga4_arm_timed_slot_886A5BB0(struct Ts4Player *self, __vector4 pos);                                       /* 886A5BB0~ */
int ts4_min_cost_until_zero_886AC7E0(struct Ts4Player *o, int a, int b);                                       /* 886AC7E0 */
int ts4_min_cost_over_ids_886AC928(struct Ts4Player *o);                                                       /* 886AC928 */
unsigned char ts4_swing_category_walk_886AFDF8(struct Ts4SwingController *self, void *list, unsigned char autoswing); /* 886AFDF8 */
unsigned char ts4_swing_category_by_class_886B01A8(struct Ts4SwingController *self, void *lists);              /* 886B01A8 */
void ts4_latch_swing_readiness_886B0380(struct Ts4SwingController *r);                                         /* 886B0380 */
unsigned int ts4_tailcall_fn_886B0250_886B0410(struct Ts4SwingController *a0);                                 /* 886B0410 */
void ts4_controller_activate(struct Ts4SwingController *self);                                                 /* 886B83B0 */
void ts4_owner_bind_three_slots_886BACC0(void *o, struct Ts4Player *ow, unsigned int v);                       /* 886BACC0 */
void ts4_owner_bind_source_slot_886BCDA8(void *o, struct Ts4Player *ow);                                       /* 886BCDA8~ */
void ts4_analysers_init_886BDB58(void *s, struct Ts4Player *o);                                                /* 886BDB58~ */
TS4_EXTERN_C_END

#endif /* TS4_PLAYER_H */
