/*
 * D2G: AI tactic condition tests (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * A condition object holds its rule (rule->name is a crc32 hash), the tuning block with the thresholds,
 * and the player's running counters. Offsets were read from machine code; names are roles inferred from usage.
 */
#include "d1g_types.h"

struct Ts4CondRule {
    ts4_u32 name;               /* +0x00 crc32 of the condition name */
    ts4_u32 unk_04;
    int current;                /* +0x08 progress value */
    int target;                 /* +0x0C value to reach */
};

struct Ts4CondTuning {          /* thresholds, compared with the counters below */
    ts4_u8 pad_00[0x0C];
    int t0c;                    /* +0x0C */
    ts4_u8 pad_10[4];
    float f14;                  /* +0x14 */
    ts4_u8 pad_18[8];
    int t20;                    /* +0x20 */
    ts4_u8 pad_24[4];
    int t28;                    /* +0x28 */
    ts4_u8 pad_2c[8];
    int t34;                    /* +0x34 */
    ts4_u8 pad_38[4];
    float f3c;                  /* +0x3C */
    ts4_u8 pad_40[4];
    int t44;                    /* +0x44 */
    int t48;                    /* +0x48 */
    ts4_u8 pad_4c[8];
    int t54;                    /* +0x54 */
    ts4_u8 pad_58[4];
    int t5c;                    /* +0x5C */
    ts4_u8 pad_60[8];
    int t68;                    /* +0x68 */
    ts4_u8 pad_6c[4];
    float f70;                  /* +0x70 */
    ts4_u8 pad_74[8];
    int t7c;                    /* +0x7C */
    ts4_u8 pad_80[4];
    float f84;                  /* +0x84 */
    int t88_unused;             /* +0x88 */
    int t8c;                    /* +0x8C */
    ts4_u8 pad_90[8];
    float f98;                  /* +0x98 */
    int t9c;                    /* +0x9C */
    ts4_u8 pad_a0[4];
    int ta4;                    /* +0xA4 */
    ts4_u8 pad_a8[8];
    int tb0;                    /* +0xB0 */
    ts4_u8 pad_b4[4];
    int tb8;                    /* +0xB8 */
    ts4_u8 pad_bc[4];
    int tc0;                    /* +0xC0 */
    ts4_u8 pad_c4[4];
    int tc8;                    /* +0xC8 */
};

/* Self-relative pointer: target = (char *)&rel + rel. */
struct Ts4CondRel {
    int rel;
};
struct Ts4CondRelTarget {
    ts4_u32 unk_00;
    ts4_u32 value;              /* +0x04 */
};
struct Ts4CondSlot {            /* 24-byte row */
    struct Ts4CondRel ref;      /* +0x00 */
    ts4_u8 pad_04[8];
    int v0c;                    /* +0x0C */
    ts4_u8 pad_10[8];
};
struct Ts4CondTable {
    ts4_u8 pad_00[0xB4];
    struct Ts4CondRel slots;    /* +0xB4 rows of Ts4CondSlot */
};
struct Ts4CondTeam {
    ts4_u8 pad_00[0x28];
    int index;                  /* +0x28 */
};
struct Ts4CondPlayerState {
    ts4_u8 pad_000[0x654];
    float forehand;             /* +0x654 rating */
    float backhand;             /* +0x658 rating */
};
struct Ts4CondPlayer {
    ts4_u8 pad_00[0x4C];
    struct Ts4CondTeam *team;   /* +0x4C */
    ts4_u8 pad_50[0x24];
    struct Ts4CondPlayerState *state; /* +0x74 */
};
/* Per-player stats rows (0x134 bytes); each row starts with a self-relative reference to its float values. */
struct Ts4CondStatRow {
    struct Ts4CondRel values;   /* +0x00 */
    ts4_u8 pad_04[0x130];
};
struct Ts4CondStats {
    ts4_u8 pad_00[0x5C];
    struct Ts4CondRel rows;     /* +0x5C rows of Ts4CondStatRow */
};
struct Ts4CondMatchSide {
    ts4_u8 pad_00[0x44];
    struct Ts4CondTable *table; /* +0x44 */
};
struct Ts4CondObj;

struct Ts4Cond {
    struct Ts4CondRule *rule;   /* +0x00 */
    ts4_u8 pad_04[8];
    struct Ts4CondTuning *tuning; /* +0x0C */
    struct Ts4CondStats *stats; /* +0x10 */
    struct Ts4CondTable *table; /* +0x14 */
    ts4_u8 pad_18[4];
    struct Ts4CondMatchSide *match_1c; /* +0x1C */
    struct Ts4CondPlayer *player_20; /* +0x20 */
    struct Ts4CondPlayer *player;   /* +0x24 */
    ts4_u8 pad_28[0x1C];
    int flag_44;                /* +0x44 */
    ts4_u8 pad_48[0x18];
    union {
        struct Ts4CondObj *ptr;
        int value;
    } obj_60;                   /* +0x60 attached object (the progress query reports the raw word) */
    ts4_u8 pad_64[0x1C];
    int c80;                    /* +0x80 */
    ts4_u8 pad_84[0xC];
    int c90;                    /* +0x90 */
    int c94;                    /* +0x94 */
    int c98;                    /* +0x98 */
    int c9c;                    /* +0x9C */
    int ca0;                    /* +0xA0 */
    int ca4;                    /* +0xA4 */
    int ca8;                    /* +0xA8 */
    int cac;                    /* +0xAC */
    int cb0;                    /* +0xB0 */
    ts4_u8 pad_b4[4];
    int cb8;                    /* +0xB8 */
    int cbc;                    /* +0xBC */
    float fc0;                  /* +0xC0 */
    float fc4;                  /* +0xC4 */
    ts4_u8 pad_c8[0x28];
    int cf0;                    /* +0xF0 */
    int cf4;                    /* +0xF4 */
    int forehand_uses;          /* +0xF8 */
    int backhand_uses;          /* +0xFC */
    int c100;                   /* +0x100 */
    int c104;                   /* +0x104 */
    int c108;                   /* +0x108 */
    int c10c;                   /* +0x10C */
};

extern float g_ts4_script_constants[];
extern float g_ts4_event_value;      /* 0.0f */

int ts4_ratio_above_threshold_8865B3B0(struct Ts4Cond *self);
int ts4_ratio_ge_8865B570(struct Ts4Cond *self);
int ts4_value_at_least_8865B658(struct Ts4Cond *self);
int ts4_all_ge_8865B6C0(struct Ts4Cond *self);

/* The side's row in the table holds an empty self-relative reference. */
static int ts4_cond_slot_empty(struct Ts4Cond *self)
{
    struct Ts4CondRel *rows = &self->table->slots;
    struct Ts4CondSlot *row = (struct Ts4CondSlot *)((char *)rows + (self->player->team->index * 24 + rows->rel));
    struct Ts4CondRelTarget *t = (struct Ts4CondRelTarget *)((char *)&row->ref + row->ref.rel);
    return t->value == 0;
}

/* No object attached at +0x60 (the constant on the left of == keeps the original's `addi r11,r11,0`).
   Swing_DLL.xex 0x8865B2D8 */
int ts4_cond_obj_missing_8865B2D8(struct Ts4Cond *self)
{
    return 0 == self->obj_60.ptr;
}

/* Test the condition named by self->rule against the counters and thresholds; unknown names are false.
   Swing_DLL.xex 0x88665010 */
int ts4_cond_test_88665010(struct Ts4Cond *self)
{
    int result = 0;
    switch (self->rule->name) {
    case 0x0F5B82B4:
        result = self->c9c >= self->tuning->ta4;
        break;
    case 0x169200BF:
        {
            int above = self->tuning->f70 * self->fc0 > self->fc4;
            result = above;
        }
        break;
    case 0x127431A7:
        result = self->c104 >= self->tuning->tc0;
        break;
    case 0x3504E492:
        result = self->tuning->tc8 >= self->c108;
        break;
    case 0x4914978D:
        result = ts4_ratio_ge_8865B570(self);
        break;
    case 0x02CA3989:
    case 0x53287703:
    case 0xAFBE5D69:
    case 0xF65B10D8:
        result = ts4_cond_slot_empty(self);
        break;
    case 0x5150620D:
        result = self->cbc >= self->tuning->t8c;
        break;
    case 0x550D9671:
        result = self->c10c >= self->tuning->t68;
        break;
    case 0x21B99080:
    case 0x587730BA:
    case 0x94EB12A3:
    case 0xD1EB60E8:
        result = self->cb0 == self->tuning->t54;
        break;
    case 0x57DDA73E:
        result = self->ca4 >= self->tuning->t28;
        break;
    case 0x6C210C26:
        result = 0 == self->obj_60.ptr;
        break;
    case 0x722884EC:
        result = self->c90 >= self->tuning->tb0;
        break;
    case 0x7BEC97F1:
    case 0x97D251D8:
        result = ts4_ratio_above_threshold_8865B3B0(self);
        break;
    case 0x82EF1629:
        result = self->cb8 >= self->tuning->t5c;
        break;
    case 0x856CF2CA:
        result = self->cf4 >= self->tuning->t7c;
        break;
    case 0x5E360744:
    case 0x6B871BCB:
    case 0xA5FE8E81:
        result = self->c94 >= self->tuning->t0c;
        break;
    case 0xB291EE7A:
        result = self->ca0 >= self->tuning->t9c;
        break;
    case 0xB501BC47:
        result = ts4_all_ge_8865B6C0(self);
        break;
    case 0xB81FCC00:
        result = self->cf0 == self->tuning->t34;
        break;
    case 0xBCEA1C3D:
        result = self->c90 >= self->tuning->t20;
        break;
    case 0xCFE2E822:
        result = self->tuning->tb8 >= self->c100;
        break;
    case 0x225845C2:
    case 0xB1F46C7A:
    case 0xBC659B93:
    case 0xD2CD5B31:
        result = ts4_value_at_least_8865B658(self);
        break;
    case 0xD6F6A94E:
        {
            int above = self->tuning->f84 * self->fc0 > self->fc4;
            result = above;
        }
        break;
    case 0x10749A9B:
    case 0xA6D6FCB3:
    case 0xC17080E7:
    case 0xE8923D17:
        result = self->c80 >= self->tuning->t44;
        break;
    case 0x7B29799D:
    case 0xAC0E17A9:
    case 0xB1B7D5A3:
    case 0xDFD1FBF9:
        result = self->flag_44 == 0;
        break;
    case 0xC8D19D62:
    case 0xF664D505:
        result = self->c98 >= self->tuning->t48;
        break;
    }
    return result;
}

