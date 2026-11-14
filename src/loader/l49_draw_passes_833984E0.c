/* Loader_DLL.xex 0x833984E0-0x83398604, executable version 0.0.0.3. */
/* Issue three draw-pass calls with a wrapped scroll offset taken from global state. */
typedef struct Ts4lFlags {
    char pad[0x13];
    unsigned char disabled;
} Ts4lFlags;
extern Ts4lFlags *lbl_83542CE0;
extern int lbl_83542D08;
extern int lbl_83542D10;
extern int lbl_83542D0C;
extern int lbl_83542CB0;
extern int lbl_83542BB8;
extern int lbl_83542BB4;
extern int lbl_83542BB0;
extern int lbl_83542C50;
extern int lbl_83542CAC;
extern int lbl_83542C4C;
extern void ts4l_queue_cmd_op8_833A2C30(void *a, int b, int c, int d, int e, int f, int g, int h, int i);
void ts4l_draw_passes_833984E0(void *ctx)
{
    int x, f, t, bb0, bb4, cac, c4c;
    if (lbl_83542CE0->disabled != 0)
        return;
    if (lbl_83542D08 == 0)
        return;
    x = lbl_83542D10;
    if (x > 0x1f) {
        x -= 0x40;
        lbl_83542D10 = x;
    }
    if (lbl_83542D0C == 0) {
        f = -0x40;
        t = 0x3fc0 - (x << 7);
    } else {
        f = lbl_83542D0C + 0x20;
        t = x << 6;
    }
    bb4 = lbl_83542BB4;
    bb0 = lbl_83542BB0;
    ts4l_queue_cmd_op8_833A2C30(ctx, lbl_83542BB8, lbl_83542BB8, lbl_83542CB0, lbl_83542C50, lbl_83542CB0, f, t, 0);
    cac = lbl_83542CAC;
    c4c = lbl_83542C4C;
    ts4l_queue_cmd_op8_833A2C30(ctx, bb4, bb4, cac, c4c, cac, f, 0x2000, 1);
    ts4l_queue_cmd_op8_833A2C30(ctx, bb0, bb0, cac, c4c, cac, f, 0x2000, 1);
}
