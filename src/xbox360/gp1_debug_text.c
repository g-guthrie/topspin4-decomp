/* GP1: debug text emitters of the shot-evaluation package (WP1). */

void ts4_format_text(char *buffer, unsigned int size, const char *format, ...);

extern char lbl_880F3EBC[]; /* "Crowd excitement %d   stress %d   IMP.: %d" */
extern char lbl_880F42A8[]; /* "Waiting" */
extern char lbl_880F42B0[]; /* "PressAndHold" */
extern char lbl_880F42C0[]; /* "Swing" */
extern char lbl_880F42C8[]; /* "Analysed" */
extern char lbl_880F42D4[]; /* "StickIntensity %.2f" */

struct Gp1PointImportance {
    unsigned char pad0[0xf4];
    unsigned int importance_hash; /* +0xf4, crc32("Important") / crc32("Crucial") */
};

struct Gp1CrowdState {
    unsigned char pad0[0x7c];
    int stress_step;     /* +0x7c */
    unsigned char pad1[0xc0 - 0x80];
    int excitement;      /* +0xc0 */
    int stress_counter;  /* +0xc4 */
};

struct Gp1ShotFlags {
    unsigned char pad0[0x48];
    unsigned char flag_48;
    unsigned char pad1[0xa3 - 0x49];
    unsigned char flag_a3;
};

struct Gp1ShotEvaluator {
    unsigned char pad0[0x2c];
    struct Gp1CrowdState *crowd;           /* +0x2c */
    unsigned char pad1[0x34 - 0x30];
    struct Gp1PointImportance *point;      /* +0x34 */
    unsigned char pad2[0x74c - 0x38];
    unsigned char show_debug;              /* +0x74c */
    unsigned char pad3[0x750 - 0x74d];
    int player_mode;                       /* +0x750 */
};

/* Swing_DLL.xex 0x88666F18: debug line with crowd excitement, stress and point importance (0/1/2). */
void ts4_shot_eval_debug_crowd_text_88666F18(
    struct Gp1ShotEvaluator *self,
    struct Gp1ShotFlags *shot
)
{
    /* The original frame keeps 0x30 bytes below the line buffer; reproduced by a wrapper struct. */
    struct { char unused[0x30]; char text[64]; } line;
    int importance;
    unsigned int hash;

    if (!((shot->flag_a3 != 0 && shot->flag_48 != 0) || self->show_debug != 0)) {
        return;
    }
    if (self->player_mode != 1) {
        return;
    }
    importance = 0;
    hash = self->point->importance_hash;
    if (hash == 0x4850af43u) {
        importance = 1;
    } else if (hash == 0xc920ac38u) {
        importance = 2;
    }
    ts4_format_text(
        line.text, 64, lbl_880F3EBC,
        self->crowd->excitement,
        self->crowd->stress_step * self->crowd->excitement + self->crowd->stress_counter,
        importance
    );
}

struct Gp1AnalyserFlags {
    unsigned char pad0[0x48];
    unsigned char flag_48;
    unsigned char pad1[0x7f - 0x49];
    unsigned char flag_7f;
};

struct Gp1AnalyserInputs {
    unsigned char pad0[0xd80];
    float stick_intensity; /* +0xd80 */
};

struct Gp1AnalyserPlayer {
    unsigned char pad0[0x28];
    struct Gp1AnalyserFlags *flags; /* +0x28 */
};

struct Gp1AnalyserNode {
    unsigned char pad0[0x48];
    struct Gp1AnalyserPlayer *player; /* +0x48 */
    unsigned char pad1[0x74 - 0x4c];
    struct Gp1AnalyserInputs *inputs; /* +0x74 */
};

struct Gp1AnalyserOwner {
    unsigned char pad0[0x08];
    struct Gp1AnalyserNode *node;   /* +0x08 */
};

struct Gp1InputAnalyser {
    unsigned char pad0[0x1c];
    struct Gp1AnalyserOwner *owner; /* +0x1c */
    unsigned char pad1[0x44 - 0x20];
    unsigned int state;             /* +0x44: 0 Waiting, 1 PressAndHold, 2 Swing, 3 Analysed */
};

/* Swing_DLL.xex 0x886630B8: input analyser debug text (state name and StickIntensity). */
void ts4_input_analyser_debug_text_886630B8(struct Gp1InputAnalyser *self)
{
    struct { char unused[0x20]; char state_name[0x20]; char text[0x40]; } line;
    struct Gp1AnalyserFlags *flags = self->owner->node->player->flags;
    const char *name;

    if (flags->flag_48 == 0 || flags->flag_7f == 0) {
        return;
    }
    switch (self->state) {
    case 0:
        name = lbl_880F42A8;
        break;
    case 1:
        name = lbl_880F42B0;
        break;
    case 2:
        name = lbl_880F42C0;
        break;
    case 3:
        name = lbl_880F42C8;
        break;
    default:
        goto no_state_name;
    }
    ts4_format_text(line.state_name, 0x20, name);
no_state_name:
    ts4_format_text(line.text, 0x40, lbl_880F42D4, (double)self->owner->node->inputs->stick_intensity);
}
