/* Q5h3: school (training) mode sound cues (Top Spin 4, Xbox 360, Swing_DLL.xex). */
typedef unsigned int u32;

/* Reference-counted text handle (one word); released with ts4_call_seq_u32_off0_8819AD80. */
typedef struct Q5h3Text { char *chars; } Q5h3Text;
typedef struct Q5h3Music Q5h3Music;
extern Q5h3Music *lbl_88D45A64;                                   /* music / sound-cue player singleton */
extern char lbl_880DA3E0[], lbl_880DA3F8[], lbl_880DA410[];   /* "Root/School/PowerUpOne", "...Two", "...Three" */
extern void *ts4_assign_text_from_c_string(Q5h3Text *out, const char *s);
extern void ts4_call_seq_u32_off0_8819AD80(Q5h3Text *t);
extern void ts4_obj_vcall_28_then_2c_88778E88(Q5h3Music *m, u32 *key, Q5h3Text *name, u32 f);

/* 0x888FBB40: play the "power up" cue for 1, 2-3 or 4+ points under cue category 0xDAA805A2.
 * Each branch has its own key local (three stack slots in the target); the call and release are tail-merged. */
void ts4_school_play_power_up_888FBB40(int points)
{
    Q5h3Text t;
    u32 k1, k2, k3;
    if (points <= 1) {
        ts4_assign_text_from_c_string(&t, lbl_880DA3E0);
        k1 = 0xDAA805A2u;
        ts4_obj_vcall_28_then_2c_88778E88(lbl_88D45A64, &k1, &t, 1);
        ts4_call_seq_u32_off0_8819AD80(&t);
    } else if (points <= 3) {
        ts4_assign_text_from_c_string(&t, lbl_880DA3F8);
        k2 = 0xDAA805A2u;
        ts4_obj_vcall_28_then_2c_88778E88(lbl_88D45A64, &k2, &t, 1);
        ts4_call_seq_u32_off0_8819AD80(&t);
    } else {
        ts4_assign_text_from_c_string(&t, lbl_880DA410);
        k3 = 0xDAA805A2u;
        ts4_obj_vcall_28_then_2c_88778E88(lbl_88D45A64, &k3, &t, 1);
        ts4_call_seq_u32_off0_8819AD80(&t);
    }
}
