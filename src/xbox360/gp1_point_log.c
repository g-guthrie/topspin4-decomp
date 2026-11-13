/* GP1: point-end modifier log line (WP1). */

void ts4_format_text(char *buffer, unsigned int size, const char *format, ...);

extern char lbl_880F3C60[]; /* "%s %d" */

/* Small string object: first word points at the character data. */
struct Gp1String {
    const char *chars;
};

struct Gp1PlayerDebugFlags {
    unsigned char pad0[0x48];
    unsigned char flag_48;
    unsigned char pad1[0xa3 - 0x49];
    unsigned char flag_a3;
};

struct Gp1MatchDebugRef {
    unsigned char pad0[0x28];
    struct Gp1PlayerDebugFlags *flags; /* +0x28 */
};

struct Gp1PointOwner {
    unsigned char pad0[0x74c];
    unsigned char show_debug; /* +0x74c */
};

struct Gp1PointEvaluator {
    unsigned char pad0[0x34];
    struct Gp1MatchDebugRef *match;  /* +0x34 */
    struct Gp1PointOwner *owner;     /* +0x38 */
    unsigned char pad1[0x398 - 0x3c];
    int logged_lines;                /* +0x398 */
};

/* Swing_DLL.xex 0x8865C0C8: prints one "name value" line of the END OF POINT MODIFIERS list and counts it. */
void ts4_point_eval_log_modifier_8865C0C8(
    struct Gp1PointEvaluator *self,
    const struct Gp1String *name,
    int value
)
{
    struct { char unused[0x30]; char text[0x40]; } line;
    struct Gp1PlayerDebugFlags *flags = self->match->flags;

    if ((flags->flag_a3 != 0 && flags->flag_48 != 0) || self->owner->show_debug == 1) {
        ts4_format_text(line.text, 0x40, lbl_880F3C60, name->chars, value);
        self->logged_lines = self->logged_lines + 1;
    }
}
