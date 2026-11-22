/* Q5: school (training) mode sound cues (Top Spin 4, Xbox 360, Swing_DLL.xex). */
typedef unsigned int u32;

/* Reference-counted text handle (one word); released with ts4_call_seq_u32_off0_8819AD80. */
typedef struct Q5Text { char *chars; } Q5Text;
typedef struct Q5Music Q5Music;
extern Q5Music *lbl_88D45A64;                                   /* music / sound-cue player singleton */
extern char lbl_880DA42C[], lbl_880DA444[], lbl_880DA45C[];   /* "Root/School/AddScoreOne", "...Two", "...Three" */
extern void *ts4_assign_text_from_c_string(Q5Text *out, const char *s);
extern void ts4_call_seq_u32_off0_8819AD80(Q5Text *t);
extern void ts4_obj_vcall_28_then_2c_88778E88(Q5Music *m, u32 *key, Q5Text *name, u32 f);

/* 0x888FBA90: play the "add score" cue for 1, 2-4 or 5+ points under cue category 0x2F42251F.
 * Each branch has its own key local (three stack slots in the target); the call and release are tail-merged. */
void ts4_school_play_add_score_888FBA90(int points)
{
    Q5Text t;
    u32 k1, k2, k3;
    if (points <= 1) {
        ts4_assign_text_from_c_string(&t, lbl_880DA42C);
        k1 = 0x2F42251Fu;
        ts4_obj_vcall_28_then_2c_88778E88(lbl_88D45A64, &k1, &t, 1);
        ts4_call_seq_u32_off0_8819AD80(&t);
    } else if (points <= 4) {
        ts4_assign_text_from_c_string(&t, lbl_880DA444);
        k2 = 0x2F42251Fu;
        ts4_obj_vcall_28_then_2c_88778E88(lbl_88D45A64, &k2, &t, 1);
        ts4_call_seq_u32_off0_8819AD80(&t);
    } else {
        ts4_assign_text_from_c_string(&t, lbl_880DA45C);
        k3 = 0x2F42251Fu;
        ts4_obj_vcall_28_then_2c_88778E88(lbl_88D45A64, &k3, &t, 1);
        ts4_call_seq_u32_off0_8819AD80(&t);
    }
}
